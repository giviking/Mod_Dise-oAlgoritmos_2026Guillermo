/*               Traduccion de Pseint de PagoSemanal -> pago.c               */
// Calcula el pago semanal de una persona colaboradora

#include <stdio.h>

int main(void) {
    double horas, pagoHora, salario;

    #define BONO 5000.00

    //Solicitud de la informacion a procesar   
    printf("Horas trabajadas en la semana: ");
    scanf("%lf", &horas);
    printf("Pago por hora: ");
    scanf("%lf", &pagoHora);

    // Proceso
    salario = (horas * pagoHora) + BONO;

    //Salida
    printf("=================================\n");
    printf("Salida de Pseint: \n");
    printf("Pago semanal: %.0lf\n", salario);
    printf("=================================\n\n\n");

    printf("**************************\n");
    printf("* Salida solicitada en C *\n");
    printf("**************************\n\n");
    printf("Horas trabajadas en la semana: %lf\n", horas);
    printf("Pago por hora: %lf\n", horas);
    printf("---------------------------------\n");
    printf("%-18s %10.2f\n", "horas: ", horas);
    printf("%-18s %10.2f\n", "Pago por hora: ", pagoHora);
    printf("%-18s %10.2f\n","Bono: ", BONO);
    printf("%-18s %10.2f\n","Pago semanal: ", salario);
    printf("---------------------------------\n");

    return 0;

}




