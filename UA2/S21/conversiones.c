//conversiones.c ENUNCIADO: Convertir en funciones cuatro algoritmos
// Conversion de temperatura / conversion de moneda (colones por dolar)

#include <stdio.h>
#define TIPO_CAMBIO 510.0  //colones por dolar

//PROTOTIOS DE LAS FUNCIONES
double celsiusAFahrenheit(double celsius); //devuelve los grados F
double colonesADolares(double colones);   //devuelve los dolares
int esBisiesto(int anio);                 //1 o 0
int esNotaValida(double nota);            //1 o 0

//Funcion principal
int main(void) {
    //Prueba de temperatura 77.0
    printf("25 c = %.1f F (esperado 77.0)\n", celsiusAFahrenheit(25) );

    //Prueba la moneda 10.00
    printf("5100 colones = %.2f dolares (esperado 10.00)\n", colonesADolares(5100) );

    //Prueba anio bisiesto -> 1 Verdadero
    printf("2024 bisiesto: %d (esperado 1)\n", esBisiesto(2024));

    //Prueba anio no bisiesto -> 0 falso
    printf("1900 bisiesto: %d (esperado 0)\n", esBisiesto(1900));

    //Prueba la nota invalida -> 0
    printf("Nota 105 valida: %d (esperado 0)\n", esNotaValida(105) );

    //Prueba la nota invalida -> 1 verdadero
    printf("Nota 85 valida: %d (esperado 1)\n", esNotaValida(85) );
    return 0;
}

//Conversion de Temperatura
double celsiusAFahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32;
}

//Conversion de moneda
double colonesADolares(double colones) {
    return colones / TIPO_CAMBIO;
}
//Anio bisiesto

int esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
}

//Validar nota
int esNotaValida(double nota) {
    return (nota >= 0 && nota <= 100);
}