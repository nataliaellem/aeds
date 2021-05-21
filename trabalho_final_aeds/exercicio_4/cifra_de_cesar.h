#ifndef CIFRA_DE_CESAR_H
#define CIFRA_DE_CESAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"


char *criptografa_senha(char *senha);

char *descriptografa_senha(char *senha_crip);

Fila* insere_senha_na_lista(Fila *fila, char *senha);



#endif