#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int array[5] = {8,7,5,4,2};
  int maior = 0;
  for (int i = 0; i < 5; i++){
    if (array[i] > maior){
      maior = array[i];
    }
  }
  int *aux_array = (int*) calloc(maior, sizeof(int));
  for (int i = 0; i < 5; i++){
    int n = array[i];
    aux_array[n] = aux_array[n] + 1;
  }
  int new_array[5];
  int count = 0;
  for (int i = 0; i <= maior; i++){
    if (aux_array[i] == 1){
      new_array[count] = i;
      count++;
    }
  }
  for (int i = 0; i < 5; i++){
    printf("%d\n", new_array[i]);
  }


/////////COUNTING WITH THE FILES////////////////////
int max_id = 5;
typedef struct user{
  struct user *next;
  struct user *prev;
  char data1;
  char data2;
} User;

User *users = (User*) calloc(max_id, sizeof(User));
FILE *file = fopen("addresses.csv", "r");
while (i < 5){
  int id;
  char scol[4], tcol[4];
  fscanf(file, "%d,%[^,],%[,],\n", &id, scol, tcol);
  strcpy(users[id]->data1, scol);
  strcpy(users[id]->data2, tcol);
  i++;
}

  return 0;
}
