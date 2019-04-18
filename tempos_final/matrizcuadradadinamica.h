
#ifndef MATRIZCUADRADADINAMICA_H
#define MATRIZCUADRADADINAMICA_H

typedef float TELEMENTO;
/*tipo opaco, los detalles de implementación están ocultos al usuario*/
typedef void * matrizP;
/*Función crear: asigna memoria y devuelve la asignación a la matriz. Recibe m1 por referencia para devolver al programa principal la dirección de memoria reservada por este procedimiento*/
void crear(matrizP *m1,short tam1);
/*Función asignar: Llena una posición de la matriz con un valor. Recibe una copia de la dirección de memoria reservada para la matriz m1*/
void asignar(matrizP *m1, short fila, short columna, TELEMENTO valor);

void inicializar(matrizP *matrix);

void liberar(matrizP *m1);

short tamano(matrizP m1);

TELEMENTO recuperar(matrizP m1, short fila, short columna);

void suma(matrizP* result, matrizP m1, matrizP m2);

#endif	// MATRIZCUADRADADINAMICA_H
