/*==========================================================================*\
=      Un aventurero acaba de iniciar su viaje en un reino fantástico.       =
=      Crea un programa que:                                                 =
=              Solicite el nombre del aventurero.                            =
=              Solicite la edad.                                             =
=              Solicite la cantidad de monedas de oro que posee.             =
=              Defina una constante llamada COSTO_ESPADA con valor 75.       =
\*==========================================================================*/

#include <stdio.h>

int main() {
    //Variables
    char nombre[30];
    int edad = 0;
    double monedas = 0;
    double restante = 0;
    const double COSTO_ESPADA = 75;

    //Solicitud de datos
    printf("Cual es su nombre o gran aventurero.: ");
    scanf("%29s", nombre);
    printf("Cual es su edad o gran aventurero...: ");
    scanf("%d", &edad);
    printf("Cuantas monedaas traes en tu bolso..: ");
    scanf("%lf", &monedas);

    //Calculos
    restante = monedas - COSTO_ESPADA;

    //Informacion a presentar en pantalla
    printf("\n===== FICHA DEL AVENTURERO =====\n");
    printf("Nombre: %s\n", nombre);
    printf("Edad: %d\n", edad);
    printf("Monedas: %f\n\n", monedas);
    printf("Costo de una espada: %f\n", COSTO_ESPADA);
    printf("Monedas restantes si compra la espada: %f\n", restante);

    return 0;
}