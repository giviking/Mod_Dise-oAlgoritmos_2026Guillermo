/*==========================================================================*\
=  Ejercicio dado por copilot en base a lo estudiado de la S17: variables,   =
=  tipos de datos, prinft(), scanf(), constantes, formatos y la regla del &  =
\*==========================================================================*/

#include <stdio.h>

int main() {
    // Variables
    char nombre[30];
    char inicial;
    int edad;
    double monedas;

    //Solicitud de datos
    printf("Ingrese su nombre: ");
    scanf("%30s", nombre);

    printf("Ingrese su inicial: ");
    scanf(" %c", &inicial);

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    printf("Ingrese sus monedas de oro: ");
    scanf("%lf", &monedas);

    //Presentacion de datos por pantalla
    printf("===== FICHA DEL JUGADOR =====\n\n");
    printf("Nombre: %s\n", nombre);
    printf("Inicial: %c\n", inicial);
    printf("Edad: %d\n", edad);
    printf("Monedas de oro: %f\n", monedas);

    return 0;
}