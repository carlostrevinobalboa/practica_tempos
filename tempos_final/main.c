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
    long primera, ultima, salto; /*variables tamaÃƒÂ±o y recorrido*/
    char *opcion;

    if (argc > 1) {
        primera = atol(argv[1]);
        ultima = atol(argv[2]);
        salto = atol(argv[3]);
        opcion = argv[4];
    }

    if (*opcion == 's') {
        FILE *fp;
        fp = fopen("timemposuma.txt", "w");

        for (i = primera; i <= ultima; i += salto) {
            crear(&m1, i);
            inicializar(&m1);

            crear(&m2, i);
            inicializar(&m2);

            crear(&result, i);

            inicio = clock();
            suma(&result, m1, m2);
            fin = clock();

            printf("i:%ld\tini.:%d\tfin:%d\ttiempo:%.4lf\n", i, (int) fin, (int) inicio,
                    (fin - inicio) / (double) CLOCKS_PER_SEC);
            fprintf(fp, "%ld\t%.4lf\n", i, (fin - inicio) / (double) CLOCKS_PER_SEC);
            liberar(&m1);
            liberar(&m2);
            liberar(&result);
        }
        fclose(fp);

    } else if (*opcion == 'm') {

        FILE *fp2;
        fp2 = fopen("tiempoprod.txt", "w");
        for (i = primera; i <= ultima; i += salto) {
            crear(&m1, i);
            inicializar(&m1);

            crear(&m2, i);
            inicializar(&m2);

            crear(&result, i);

            inicio = clock();
            mult(&result, m1, m2);
            fin = clock();

            printf("i:%ld\tini.:%d\tfin:%d\ttiempo:%.4lf\n", i, (int) fin, (int) inicio,
                    (fin - inicio) / (double) CLOCKS_PER_SEC);
            fprintf(fp2, "%ld\t%.4lf\n", i, (fin - inicio) / (double) CLOCKS_PER_SEC);
            liberar(&m1);
            liberar(&m2);
            liberar(&result);
        }
        fclose(fp2);
    } else {
        printf("ERROR al introducir parametros:\nIntroduce s para la suma y m para la multiplicacion");
    }
}

