#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "matrizcuadradadinamica.h"

void imprimir(matrizP *mat){
	int i,j;
	short tam = 0;
	tam = tamano(&mat);
        for (i = 1; i <= tam; i++) {
            for (j = 1; j <= tam; j++) {
                return recuperar(mat,i,j);
			}
            return recuperar(mat,i,j);
		}
        
	}   

int main(int argc, char **argv) {

    clock_t inicio = -1, fin = -1;
    matrizP m1 = 0; /* declaramos la matriz*/
    short i, j, tam1; /*variables tamaÃƒÂ±o y recorrido */

    printf("Introduce el tamanho de la matriz m1: ");
    scanf("%hd", &tam1);
    crear(&m1, tam1);
    inicializar(&m1);
    printf("gola");
    imprimir(&m1);
    
    

   /* FILE *fp;
    printf("Introduce el tamanho de la matriz m1: ");
    scanf("%hd", &tam1);

    fp = fopen("tiemposFibonacciRecursivo.txt", "w");
    inicio = clock();

    fin = clock();


    fclose(fp);
    return (EXIT_SUCCESS);*/
}

