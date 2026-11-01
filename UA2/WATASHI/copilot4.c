/*===========================================================================*\
=                       El Tesoro del Aventurero                              =
=        Un aventurero llega a la ciudad y desea registrar su tesoro.         =
= El programa debe: 1. Solicitar el nombre del aventurero.                    =
=                   2. Solicitar su inicial.                                  =
=                   3. Solicitar su edad.                                     =
=                   4. Solicitar la cantidad de moneds de oro que posee.      =
=                   5. Declarar una constante.                                =
=                   6. Calcular cuanto impuesto debe pagar (0.13)             =
=                   7. Calcular cuanto oro le queda despues de pagar impuesto.=
=                   8. Mostrar una ficha completa.                            =
\*===========================================================================*/

#include <stdio.h>

int main(void) {
    //Declaracion e inicializacion de variables
    char nombre[30];
    char inicial;
    int edad = 0;
    double monedas = 0;
    double restante = 0;
    double impuesto = 0;
    const double IMPUESTO = 0.13;

    //Solicitud de datos
    printf("Ingrese su nombre: ");
    scanf("%29s", nombre);
    printf("Ingrese su inicial: ");
    scanf(" %c", &inicial);
    printf("Ingrese su edad: ");
    scanf("%d", &edad);
    printf("Ingrese sus monedas de oro: ");
    scanf("%lf", &monedas);

    //Calculos
    impuesto = IMPUESTO * monedas;
    restante = monedas - impuesto;

    //Imformacion a presentar por pantalla
    printf("\n===== REGISTRO DEL TESORO =====\n\n");
    printf("Nombre: %s\n", nombre);
    printf("Inicial: %c\n", inicial);
    printf("Edad: %d\n", edad);
    printf("\nMonedas de oro: %f\n", monedas);
    printf("Impuesto (13%%): %f\n", impuesto);
    printf("Oro restante: %f\n", restante);

    return 0;
}

