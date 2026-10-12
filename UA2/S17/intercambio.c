// Algoritmo de intercambio de Pseint a intercambio.c

#include <stdio.h>


int main(void) {
    //Declaracion y asignacion de variables
    int a, b, aux;

    a = 5;
    b = 9;
    //Antes del intercambio
    printf("Antes:   a = %d    b = %d\n", a, b);

    aux = a;
    a = b;
    b = aux;

    //Despues del intercambio
    printf("Despues: a = %d    b = %d\n", a, b);

    return 0;
}