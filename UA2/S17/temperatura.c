//Algoritmo que convierte grados Celsius a Fahrenheit
#include <stdio.h>

int main(void) {
    //Variables
    double celsius, farenheit;

    //Datos de entrada
    printf("Temperatura en grados Celsius: \n");
    scanf("%lf", &celsius);

    //Proceso 
    farenheit = celsius * 9 / 5 + 32;

    //Salida
    printf("%.2f celsius equivalen a %.2f farenheit \n", celsius, farenheit);

    return 0;



}



