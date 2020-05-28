#include <stdio.h>
#include <stdlib.h>

void map(int *array, int (*block)(int), int array_length) {
  for (size_t i = 0; i < array_length; i++) array[i] = (*block)(array[i]);
}

int double_x(int x) {
  return x*2;
}

int main() {
  int *array = (int*) malloc(10 * sizeof(int));
  for (size_t i = 0; i < 10; i++) array[i] = i + 1;
  for (size_t i = 0; i < 10; i++) printf("%d - ", array[i]);
  printf("\n");

  map(array, &double_x, 10);

  for (size_t i = 0; i < 10; i++) printf("%d - ", array[i]);
  printf("\n");
  return 0;
}
