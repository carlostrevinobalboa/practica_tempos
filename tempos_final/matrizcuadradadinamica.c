#include <stdlib.h>
#include <stdio.h>
/*Se vuelve a definir el tipo de datos que contiene la matriz*/
typedef float TELEMENTO;

/*ImplementaciÃ³n del TAD matrizP */
typedef struct {
    TELEMENTO *datos; /*valores de la matriz*/
    long tam; /*tamaÃ±o de la matriz*/
} STMATRIZ; /*definiciÃ³n de la estructura*/
typedef STMATRIZ *matrizP; /*puntero a estructura*/
/*Funciones de manipulaciÃ³n de datos */

/*FunciÃ³n crear: asigna memoria y devuelve la asignaciÃ³n a la matriz*/
void crear(matrizP *m1, long tam1) {
    long i;

    *m1 = (matrizP) malloc(sizeof (STMATRIZ));
    (*m1)->datos = (TELEMENTO*) malloc(tam1 * tam1 * sizeof (TELEMENTO));
    //printf("el tamanio asignado es %d\n",tam1);
    (*m1)->tam = tam1;
    //printf("el tamanio asignado es.. %d\n",(*m1)->tam);
    for (i = 1; i <= tam1 * tam1; i++)
        /*InicializaciÃ³n a 0 de las componentes de la matriz*/
        *((*m1)->datos + i - 1) = 0.0;
}

/*FunciÃ³n asignar: Asigna un valor a una posiciÃ³n de la matriz */
void asignar(matrizP *m1, long fila, long columna, TELEMENTO valor) {
    *((*m1)->datos + (fila - 1)*(*m1)->tam + columna - 1) = valor;
}

void liberar(matrizP *m1) {
    if (*m1 != 0) {
        free((*m1)->datos);
        free(*m1);
        *m1 = 0;
    }
}

long tamano(matrizP *m1) {
    long t = 0;
    if (m1 != NULL) {
        t = (*m1)->tam;
        //printf("tamanio...- %d\n", t);
    }
    return t;
}

TELEMENTO recuperar(matrizP *m1, long fila, long columna) {
    TELEMENTO valor = 0;
    //declarar aqui las variables fila y columna

    if (fila <= (*m1)->tam && columna <= (*m1)->tam && fila > 0 && columna > 0) {//comparar si es mayor
        //printf("Posicion (%d,%d) equivale a posicion lineal %d\n",fila, columna, (fila-1) * (*m1)->tam + (columna -1));
        valor = *((*m1)->datos + (fila - 1) * (*m1)->tam + (columna - 1));
        return valor;
    }
    printf("Acceso inadecuado a la matriz\n");
    return valor;
}

void inicializar(matrizP *matrix) {
    long i, j;
    TELEMENTO valor;
    long tam = (*matrix)->tam;
    for (i = 1; i <= tam; i++) {
        for (j = 1; j <= tam; j++) {
            valor = 10.0 * (TELEMENTO) rand() / RAND_MAX;
            asignar(matrix, i, j, valor);
        }
    }
}

void suma(matrizP* result, matrizP m1, matrizP m2) {

    long i, j;
    TELEMENTO valorresult=0,valorm1=0,valorm2=0;
    
     for (i = 0; i < m1->tam; i++) {
            for (j = 0; j < m2->tam; j++) {
                
                valorm1 = recuperar(&m1, i + 1, j + 1);
                valorm2 = recuperar(&m2, i + 1, j + 1);
                valorresult = valorm1 + valorm2;
                
                asignar(result, i+1, j+1, valorresult);
            }
        }
}

void mult(matrizP* result, matrizP m1, matrizP m2) {
    long i, j, k;
    TELEMENTO resultmult = 0, valorm1 = 0, valorm2 = 0;

    for (i = 0; i < m1->tam; i++) {
        for (j = 0; j < m2->tam; j++) {
            for (k = 0; k < m1->tam; k++) {
                valorm1 = recuperar(&m1, i + 1, k + 1);
                valorm2 = recuperar(&m2, k + 1, j + 1);
                resultmult += valorm1 * valorm2;
            }
            asignar(result, i + 1, j + 1, resultmult);
        }
    }
}
