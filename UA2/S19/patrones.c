/* Dibujar figuras en la terminal para entender como un ciclo interno depende
   del externo. | Se usaran for anidados donde el limite del interno es la
   fila del externo (col <= fila). */

#include <stdio.h>

int main(void) {
    //Declaracion de variables
    int filas, fila, columna;

    //Solicita la cantidad de filas
    printf("Cantidad de filas: ");
    scanf("%d", &filas);

    //Ejecuta el proceso por medio de los for

    for (fila = 1; fila <= filas; fila++) {
        for (columna = 1; columna <= fila; columna++) {
            printf("*");
        }
        printf("\n");      
    }

    for (fila = 1; fila <= filas; fila++) {
        for (columna = 1; columna <= fila; columna++) {
            printf("%d", columna);
        }
        printf("\n");
    }

    return 0;
}