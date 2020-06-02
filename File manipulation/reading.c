#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE *file;
  file = fopen("teste.nat", "r");
  if (file == NULL) {
    printf("Arquivo não pode ser aberto\n");
    return 0;
  }
  char *a = (char*) malloc(20*sizeof(char));
  char *b = (char*) malloc(20*sizeof(char));
  char *c = (char*) malloc(20*sizeof(char));
  char *d = (char*) malloc(20*sizeof(char));
  fscanf(file, "%s %s %s %s", a, b, c, d);
  printf("%s %s %s %s\n", a, b, c, d);
  fclose(file);
  return 0;
}
