#include <stdio.h>
#include <stdlib.h>


void main(){
    void apaga_char(char *string, char caracter){
        printf("*string: %c, caracter: %c\n", *string, caracter);
        if (*string == '\0'){
            return;
        }
        if (*string == '0'){
            *string = '\0';
            return;
        }
        if (*string == caracter){
            *string = *(string+1);
            apaga_char(string+1, *(string+1));
            return apaga_char(string, caracter);

        }
        return apaga_char(string+1, caracter);
    }

    char caracter;
    char *string = (char*) calloc(50, sizeof(char));
    scanf("%s", string);
    getc(stdin);
    scanf("%c", &caracter);
    apaga_char(string, caracter);
    printf("%s\n", string);


}