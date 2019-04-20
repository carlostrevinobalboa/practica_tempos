#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "matrizcuadradadinamica.h"

void imprimir(matrizP *m1) {
    if (m1 != 0) {
        long i, j, tam1 = tamano(m1);
        TELEMENTO r;
        for (i = 1; i < tam1 + 1; i++) {
            for (j = 1; j < tam1 + 1; j++) {
                r = recuperar(m1, i, j);
                printf("%f ", r);
            }
            printf("\n");
        }
    } else {
        printf("a mattriz non existe\n");

    }
}

int main(int argc, char **argv) {
    long i;
    clock_t inicio = -1, fin = -1;
    matrizP m1, m2, result; /*declaramos la matriz*/
    long tam; /*variables tamaÃƒÂ±o y recorrido*/

    printf("introduce el tamaño maximo de la suma: ");
    scanf("%ld",&tam);
    
    
    for (i = 1; i <= tam; i++) {
        crear(&m1, i);
        inicializar(&m1);
        imprimir(&m1);
        printf("\n");
        
        crear(&m2, i);
        inicializar(&m2);
        imprimir(&m2);
        printf("\n");
        
        crear(&result, i);
        suma(&result, m1, m2);
        imprimir(&result);
        printf("\n");
        
    }
}

