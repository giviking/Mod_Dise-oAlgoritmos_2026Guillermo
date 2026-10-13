/* Practica autonoma-Planilla Semanal-planilla.c-Calcular la planilla de un
   grupo de personas sin saber de antemano cuantas son: el -1 indica el final*/

#include <stdio.h>

//Declaracion de las variables
int main(void) {
    double horas, tarifa, horasExtra, pago, totalPlanilla = 0.0;
    int personas = 0;
    int conExtra = 0;

    //Solicitud de la informacion
    printf("Horas de la semana (-1 para terminar): ");
    scanf("%lf", &horas);

    //Proceso de la informacion solicitada dentro del while
    while (horas != -1) {
        printf("Tarifa por hora: ");
        scanf("%lf", &tarifa);

        if (horas > 48) {
            horasExtra = horas - 48;
            pago = 48 * tarifa + horasExtra * tarifa * 1.5;
            conExtra++;
        } else {
            pago = horas * tarifa;
        }

        printf("Pago: %.2f\n", pago);

        totalPlanilla += pago;
        personas++;

        printf("Horas de la semana (-1 para terminar): ");
        scanf("%lf", &horas);
    }

    //Presentacion de la informacion con los resultados
    printf("Personas: %d\n", personas);
    printf("Con horas extra: %d\n", conExtra);
    printf("Total de la planilla: %.2f\n", totalPlanilla);

    return 0;
}




