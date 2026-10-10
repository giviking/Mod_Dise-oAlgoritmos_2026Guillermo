//Se traduce a c el ejercicio de salario de Pseint=============================
#include <stdio.h>

int main(void) {
    double horas, tarifaHora, bruto, deduccion, neto;

    //Se solicitan los datos a calcular
    printf("Horas trabajadas: ");
    scanf("%lf", &horas);

    printf("Pago por hora: ");
    scanf("%lf", &tarifaHora);

    //Proceso
    bruto = horas * tarifaHora;

    deduccion = bruto * 0.10;

    neto = bruto - deduccion;

    //Informacion a presentar por pantalla
    printf("Salario bruto: %.2f \n", bruto);
    printf("Deduccion: %.2f \n", deduccion);
    printf("Salario neto: %.2f \n", neto);

    return 0;


}