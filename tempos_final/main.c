#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "matrizcuadradadinamica.h"

void imprimir(matrizP *m1) {
    if (m1 != 0) {
        short i, j, tam1 = tamano(m1);
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
    long tam1; /*variables tamaÃƒÂ±o y recorrido*/

    printf("introduce el tamaño maximo de la suma: ");
    scanf("%ld",&tam1);
    
    for (i = 1; i <= tam1; i++) {
        crear(&m1, i);
        inicializar(&m1);

        crear(&m2, i);
        inicializar(&m2);
        
        crear(&result, i);
        suma(&result, m1, m2);
    }

    /* FILE *fp;
     printf("Introduce el tamanho de la matriz m1: ");
     scanf("%hd", &tam1);

     fp = fopen("tiemposFibonacciRecursivo.txt", "w");
     inicio = clock();

     fin = clock();


     fclose(fp);
     return (EXIT_SUCCESS);*/
}

