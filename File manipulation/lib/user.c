#include "../includes/user.h"

User* list_users(FILE *file) {
  int count_file_lines = 0;

  if (file == NULL) {
    printf("Arquivo não pode ser aberto\n");
    return 0;
  }

  for (char c = getc(file); c != EOF; c = getc(file))
    if (c == '\n')
      count_file_lines ++;

  User *users = (User*) malloc(count_file_lines * sizeof(User));
  int i = 0;
  rewind(file);
  char first_column[50], second_column[50], third_column[50], fourth_column[50], fifth_column[50];
  while(!feof(file)) {
    fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],\n", first_column, second_column, third_column, fourth_column, fifth_column);
    // Initializing user object
    new_user(&users[i]);
    set_user_name(&users[i], first_column);
    set_user_email(&users[i], second_column);
    set_user_password(&users[i], third_column);
    set_user_age(&users[i], atoi(fourth_column));
    set_user_id(&users[i], atoi(fifth_column));
    i++;
  }
  //each_user(users, printf_user_attributes, count_file_lines);
  return users;
}

void print_list_users(){
  FILE *file = fopen("storage/users.csv", "r");
  int count_file_lines = 0;

  if (file == NULL) {
    printf("Arquivo não pode ser aberto\n");
    return;
  }

  for (char c = getc(file); c != EOF; c = getc(file))
    if (c == '\n')
      count_file_lines ++;

  rewind(file);
  User *users = list_users(file);
  fclose(file);
  each_user(users, printf_user_attributes, count_file_lines);
  printf("\n\n");
}

void print_list_emails() {
  FILE *file = fopen("storage/users.csv", "r");
  int count_file_lines = 0;

  for (char c = getc(file); c != EOF; c = getc(file))
    if (c == '\n')
      count_file_lines ++;
  rewind(file);

  User *users = list_users(file);
  char **emails = map_users(users, get_user_email, count_file_lines);

  for (int i = 0; i < count_file_lines; i++) {
    printf("%s\n", emails[i]);
  }
  printf("\n\n");
}


void create_user(){
  char *name = (char*) malloc(50*sizeof(char));
  char *email = (char*) malloc(50*sizeof(char));
  char *pass = (char*) malloc(50*sizeof(char));
  int age;
  int id;
  printf("Digite o nome do usuario: ");
  scanf("%s", name);
  printf("\n");
  printf("Digite o email: ");
  scanf("%s", email);
  printf("\n");
  printf("Digite a senha: ");
  scanf("%s", pass);
  printf("\n");
  printf("Digite a idade: ");
  scanf("%d", &age);
  printf("\n");
  printf("%s, %s, %s, %d, \n", name, email, pass, age);
  FILE *users_id_seq = fopen("storage/users_id.val", "r");
  fscanf(users_id_seq, "%d\n", &id);
  fclose(users_id_seq);
  id++;
  users_id_seq = fopen("storage/users_id.val", "w");
  fprintf(users_id_seq, "%d", id);
  fclose(users_id_seq);
  FILE *file = fopen("storage/users.csv", "a");
  fprintf(file, "%s,%s,%s,%d,%d\n", name, email, pass, age, id);
  fclose(file);
}

void update_user(User *authenticated_user){
  int option;
  int n = 1;
  while (n){
    printf("Qual informacao voce deseja atualizar? \n");
    printf("\t(1): Nome de usuario\n");
    printf("\t(2): Email\n");
    printf("\t(3): Senha\n");
    printf("\t(4): Idade\n");
    printf("ESCOLHA UMA OPCAO:");
    scanf("%d", &option);
    printf("\n");
    switch (option){
      case 1:
        change_user_name(authenticated_user);
        n = 0;
        break;
      case 2:
        change_email(authenticated_user);
        n = 0;
        break;
      case 3:
        change_password(authenticated_user);
        n = 0;
        break;
      case 4:
        change_age(authenticated_user);
        n = 0;
        break;
      default:
        printf("Opcao invalida, tente novamente\n");
        break;
    }
  }
}

void change_user_name(User *authenticated_user){
  //fflush(stdin);
  //scanf("%[^\n]", new_name);
  //fgets(new_name, 100, stdin);
  char *new_name = (char*) malloc(100 * sizeof(char));
  printf("Digite o novo nome de usuario: ");
  scanf("%s", new_name);
  printf("\n");
  int count_file_lines = 0;
  FILE *file = fopen("storage/users.csv", "r");
  for (char c = getc(file); c != EOF; c = getc(file)){
    if (c == '\n'){
      count_file_lines ++;
    }
  }
  rewind(file);
  User *users = list_users(file);
  rewind(file);
  fclose(file);
  char *authenticated_name = get_user_name(*authenticated_user);
  int j;
  for (int i = 0; i < count_file_lines; i++){
    char *user_name = get_user_name(users[i]);
    if (strcmp(authenticated_name, user_name) == 0){
      j = i;
      i = count_file_lines;
    }
  }
  set_user_name(&users[j], new_name);
  printf("\n");
  file = fopen("storage/users.csv", "w");
  for (int n = 0; n < count_file_lines; n++){
    fprintf(file, "%s,", users[n].name);
    fprintf(file, "%s,", users[n].email);
    fprintf(file, "%s,", users[n].password);
    fprintf(file, "%d,", users[n].age);
    fprintf(file, "%d,", users[n].id);
    fprintf(file, "\n");
  }
  rewind(file);
  fclose(file);
}


void change_email(User *authenticated_user){
  char *new_email = (char*) malloc(100 * sizeof(char));
  printf("Digite o novo email de usuario: ");
  scanf("%s", new_email);
  printf("\n");
  int count_file_lines = 0;
  FILE *file = fopen("storage/users.csv", "r");
  for (char c = getc(file); c != EOF; c = getc(file)){
    if (c == '\n'){
      count_file_lines ++;
    }
  }
  rewind(file);
  User *users = list_users(file);
  rewind(file);
  fclose(file);
  char *authenticated_email = get_user_email(*authenticated_user);
  int j;
  for (int i = 0; i < count_file_lines; i++){
    char *user_email = get_user_email(users[i]);
    if (strcmp(authenticated_email, user_email) == 0){
      j = i;
      i = count_file_lines;
    }
  }
  set_user_email(&users[j], new_email);
  printf("\n");
  file = fopen("storage/users.csv", "w");
  for (int n = 0; n < count_file_lines; n++){
    fprintf(file, "%s,", users[n].name);
    fprintf(file, "%s,", users[n].email);
    fprintf(file, "%s,", users[n].password);
    fprintf(file, "%d,", users[n].age);
    fprintf(file, "%d,", users[n].id);
    fprintf(file, "\n");
  }
  rewind(file);
  fclose(file);
}


void change_password(User *authenticated_user){
  char *new_password = (char*) malloc(100 * sizeof(char));
  printf("Digite a nova senha do usuario: ");
  scanf("%s", new_password);
  printf("\n");
  int count_file_lines = 0;
  FILE *file = fopen("storage/users.csv", "r");
  for (char c = getc(file); c != EOF; c = getc(file)){
    if (c == '\n'){
      count_file_lines ++;
    }
  }
  rewind(file);
  User *users = list_users(file);
  rewind(file);
  fclose(file);
  char *authenticated_password = get_user_password(*authenticated_user);
  int j;
  for (int i = 0; i < count_file_lines; i++){
    char *user_password = get_user_password(users[i]);
    if (strcmp(authenticated_password, user_password) == 0){
      j = i;
      i = count_file_lines;
    }
  }
  set_user_password(&users[j], new_password);
  printf("\n");
  file = fopen("storage/users.csv", "w");
  for (int n = 0; n < count_file_lines; n++){
    fprintf(file, "%s,", users[n].name);
    fprintf(file, "%s,", users[n].email);
    fprintf(file, "%s,", users[n].password);
    fprintf(file, "%d,", users[n].age);
    fprintf(file, "%d,", users[n].id);
    fprintf(file, "\n");
  }
  rewind(file);
  fclose(file);
}

void change_age(User *authenticated_user){
  int new_age;
  printf("Digite a nova idade do usuario: ");
  scanf("%d", &new_age);
  printf("\n");
  int count_file_lines = 0;
  FILE *file = fopen("storage/users.csv", "r");
  for (char c = getc(file); c != EOF; c = getc(file)){
    if (c == '\n'){
      count_file_lines ++;
    }
  }
  rewind(file);
  User *users = list_users(file);
  rewind(file);
  fclose(file);
  int authenticated_age = get_user_age(*authenticated_user);
  int j;
  for (int i = 0; i < count_file_lines; i++){
    int user_age = get_user_age(users[i]);
    if (authenticated_age == user_age){
      j = i;
      i = count_file_lines;
    }
  }
  set_user_age(&users[j], new_age);
  printf("\n");
  file = fopen("storage/users.csv", "w");
  for (int n = 0; n < count_file_lines; n++){
    fprintf(file, "%s,", users[n].name);
    fprintf(file, "%s,", users[n].email);
    fprintf(file, "%s,", users[n].password);
    fprintf(file, "%d,", users[n].age);
    fprintf(file, "%d,", users[n].id);
    fprintf(file, "\n");
  }
  rewind(file);
  fclose(file);
}


// Initializer
void new_user(User *user) {
  user->name = (char*) malloc(50 * sizeof(char));
  user->email = (char*) malloc(50 * sizeof(char));
  user->password = (char*) malloc(50 * sizeof(char));
}

// Enumerable
void each_user(User *users, void (*block)(User), int users_length){
  for (int i = 0; i < users_length; i++) {
    (*block)(users[i]);
    printf("\n");
  }
}

List* map_list(User *users, char* (*block)(User), int length){
  List *new_list = create_list();
  for (int i = 0; i < length; i++) {
    new_list = insert(new_list, (*block)(users[i]));
  }
  return new_list;
}

char** map_users(User *users, char* (*block)(User), int length){
  char **mapping = (char**) malloc(length * sizeof(char*));

  for (int i = 0; i < length; i++)
    mapping[i] = (char*) malloc(50 * sizeof(char));

  for (int i = 0; i < length; i++) {
    char *aux = (*block)(users[i]);
    strcpy(mapping[i], aux);
  }

  return mapping;
}

User *filter_char_attributes(User *users, char* (*block)(User), char *filter_attribute, int length){
  int count = 1;
  User *filtered_users = (User*) malloc(1 * sizeof(User));
  for (int i = 0; i < length; i++){
    char *attribute = (*block)(users[i]);
    if (strcmp(attribute, filter_attribute) == 0){
      count++;
      char *name = get_user_name(users[i]);
      char *email = get_user_email(users[i]);
      char *password = get_user_password(users[i]);
      int age = get_user_age(users[i]);
      int id = get_user_id(users[i]);
      new_user(&filtered_users[count-2]);
      set_user_name(&filtered_users[count-2], name);
      set_user_email(&filtered_users[count-2], email);
      set_user_password(&filtered_users[count-2], password);
      set_user_age(&filtered_users[count-2], age);
      set_user_id(&filtered_users[count-2], id);
    }
  }
  each_user(filtered_users, printf_user_attributes, count-1);
  return filtered_users;
}

User *filter_int_attributes(User *users, int (*block)(User), int filter_attribute, int length){
  int count = 1;
  User *filtered_users = (User*) malloc(1 * sizeof(User));
  for (int i = 0; i < length; i++){
    int attribute = (*block)(users[i]);
    if (attribute == filter_attribute){
      count++;
      filtered_users = (User*) realloc(filtered_users, count * sizeof(User));
      char *name = get_user_name(users[i]);
      char *email = get_user_email(users[i]);
      char *password = get_user_password(users[i]);
      int age = get_user_age(users[i]);
      int id = get_user_id(users[i]);
      new_user(&filtered_users[count-2]);
      set_user_name(&filtered_users[count-2], name);
      set_user_email(&filtered_users[count-2], email);
      set_user_password(&filtered_users[count-2], password);
      set_user_age(&filtered_users[count-2], age);
      set_user_id(&filtered_users[count-2], id);
    }
  }
  each_user(filtered_users, printf_user_attributes, count-1);
  return filtered_users;
}

// Inspect
void printf_email(User user){
  printf("%s\n", user.email);
}

void printf_name(User user){
  printf("%s\n", user.name);
}

void printf_password(User user){
  printf("%s\n", user.password);
}

void printf_age(User user){
  printf("%d\n", user.age);
}

void printf_user_attributes(User user){
  printf("%s,", user.name);
  printf(" %s,", user.email);
  printf(" %s,", user.password);
  printf(" %d.", user.age);
}

// Getters
char* get_user_name(User user){
  char *name = (char*) malloc(50*sizeof(char));
  strcpy(name, user.name);
  return name;
}

char* get_user_email(User user){
  char *email = (char*) malloc(50*sizeof(char));
  strcpy(email, user.email);
  return email;
}

char* get_user_password(User user){
  char *password = (char*) malloc(50*sizeof(char));
  strcpy(password, user.password);
  return password;
}

int get_user_age(User user){
  int age = user.age;
  return age;
}

int get_user_id(User user){
  int id = user.id;
  return id;
}

// Setters
void set_user_name(User *user, char* name){
  strcpy(user->name, name);
  //printf("NAME: %s\nUSER->NAME: %s\n", name, user->name);
}

void set_user_email(User *user, char* email){
  strcpy(user->email, email);
}

void set_user_password(User *user, char* password){
  strcpy(user->password, password);
}

void set_user_age(User *user, int age){
  user->age = age;
}

void set_user_id(User *user, int id){
  user->id = id;
}
