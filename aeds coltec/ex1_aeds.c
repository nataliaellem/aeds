#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    FILE *file = fopen("arquivo_ex1.txt", "r");
    int count_file_lines = 0;
    for (char c = getc(file); c != EOF; c = getc(file))
        if (c == '\n')
            count_file_lines ++;

    printf("lines: %d\n", count_file_lines);
    int *vetor = (int *) malloc(count_file_lines * sizeof(int));
    rewind(file);
    int aux = count_file_lines-1;
    while(!feof(file)){
        char *value_aux = (char*) malloc(10 * sizeof(char));
        fscanf(file, "%s\n", value_aux);
        vetor[aux] = atoi(value_aux);
        aux--;
    }
    for (int i = 0; i < count_file_lines; i++){
        printf("%d\n", vetor[i]);

    }
    rewind(file);
    fclose(file);
}