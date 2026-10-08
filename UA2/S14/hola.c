// Hola.c - prueba de entorno de la UA2
#include <stdio.h>

int main(void) {
    int edad;
    // Muestra mensajes por pantalla 
    printf("Entorno listo para la UA2 \n");
    // Pide y lee un número
    printf("Digite su edad: ");
    scanf("%d", &edad);

    // Mostrar la salida
    printf("Edad Registrada: %d \n", edad);
    return 0;
}