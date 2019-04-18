#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "matrizcuadradadinamica.h"

void imprimir(matrizP *m1) {
    if (m1 != 0) {
        short i, j,tam1 = tamano(m1);
        TELEMENTO r;
        for (i = 1; i < tam1 + 1; i++) {
            for (j = 1; j < tam1 + 1; j++){
                r = recuperar(m1, i, j);
                printf("%f ", r);
            }
            printf("\n");
        }
    } else {
        printf("a mattriz non existe\n");

    }
}

void suma(matrizP* result, matrizP m1, matrizP m2){

}

int main(int argc, char **argv) {

    clock_t inicio = -1, fin = -1;
    matrizP m1,m2,mresultado; /*declaramos la matriz*/
    short tam1,tam2; /*variables tamaÃƒÂ±o y recorrido*/

    //creando primera matriz para la suma
    printf("Introduce el tamanho de la matriz m1: ");
    scanf("%hd", &tam1);
    crear(&m1, tam1);
    inicializar(&m1);   
    imprimir(&m1); //no funciona.
    printf("matriz 1 creada\n");
    
    //creando segunda matriz para la suma
    printf("introduce el tamanho de la matriz m2: ");
    scanf("%hd", &tam2);
    crear(&m2, tam2);
    inicializar(&m2);   
    imprimir(&m2); //no funciona.
    printf("matriz 2 creada \n");
    
    

    /* FILE *fp;
     printf("Introduce el tamanho de la matriz m1: ");
     scanf("%hd", &tam1);

     fp = fopen("tiemposFibonacciRecursivo.txt", "w");
     inicio = clock();

     fin = clock();


     fclose(fp);
     return (EXIT_SUCCESS);*/
}

