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
  return 0;
}
