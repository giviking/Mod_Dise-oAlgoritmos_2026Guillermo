#include <stdio.h>

void imprimirMensaje() {
    printf("Hola este es un programa estructurado en C\n");

}

int sumar(int a, int b) {
    return a + b;
}

int main() {
    int x=5 , y=10;

    int resultado;

    imprimirMensaje(); //llamado de la funcion

    resultado = sumar(x,y);

    printf("La suma de %d y %d es: %d\n", x, y, resultado);

    return 0;
}