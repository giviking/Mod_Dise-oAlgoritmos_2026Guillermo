/*               Traduccion de Pseint de PagoSemanal -> pago.c               */
// Calcula el pago semanal de una persona colaboradora

#include <stdio.h>

int main(void) {
    double horas, pagoHora, salario;

    #define BONO 5000

    //Solicitud de la informacion a procesar   
    printf("Horas trabajadas en la semana: ");
    scanf("%lf", &horas);
    printf("Pago por hora: ");
    scanf("%lf", &pagoHora);

    // Proceso
    salario = (horas * pagoHora) + BONO;

    //Salida
    printf("Pago semanal: %.0lf\n", salario);

    return 0;

}




