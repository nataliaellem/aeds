#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dias_transcorridos(int dia, int mes, int ano) {
    int dia_referencia = 17, mes_referencia = 9, ano_referencia = 2020;
    int dias = 0;
    if (ano < ano_referencia) {
        if (mes > mes_referencia) {
            dias = dias + ((ano_referencia - ano -1) * 365);
            dias = dias + ((12 - mes + mes_referencia) * 30);
            if (dia > dia_referencia) {
                dias = dias + (30 - dia + dia_referencia);
            }
            else if (dia < dia_referencia) {
                dias = dias + (dia_referencia - dia);
            }
        }
        else if ()
    }
}

int main () {
    return 0;
}