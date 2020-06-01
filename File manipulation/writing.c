#include <stdio.h>

int main(){
  FILE *file; //criando um ponteiro que aponta para tipos de data FILE
  file = fopen("/home/alan/Desktop/Natália/github/aeds/File manipulation/storage/teste.nat", "w"); //significa que o meu ponteiro está apontando para um arquivo
  fprintf(file, "\n testando manipulação de arquivos");
  fclose(file);
  return 0;
}
