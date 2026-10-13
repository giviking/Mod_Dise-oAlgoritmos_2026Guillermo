/* Ejercicio 2 - promedio.c - Promediar notas sin aceptar datos imposibles: 
   ni una cantidad fuera de 1 a 10 ni notas fuera de 0 a 100. 
   Elementos que se practican: for para correr las notas y  do ... while 
   para validar (dos veces: la cantidad y cada nota); acumulador*/

#include <stdio.h>

int cantidad, i;
double nota, suma, promedio;

int main(void) {
    //Solicita la cantidad de notas a digitar
    //Y se realiza el proceso.
    do {
        printf("Cuantas notas va a digitar? ");
        scanf("%d", &cantidad);
    } while (cantidad < 1 || cantidad > 10);

    for (i = 1; i <= cantidad; i++) {
        do {
            printf("Nota %d: ", i);
            scanf("%lf", &nota);
        } while (nota < 0 || nota > 100);

        suma += nota;
    }

    promedio = suma / cantidad;

    //Salida de la informacion por pantalla
    printf("Suma: %.2f\n", suma);
    printf("Promedio: %.2f\n", promedio);

    return 0;
}