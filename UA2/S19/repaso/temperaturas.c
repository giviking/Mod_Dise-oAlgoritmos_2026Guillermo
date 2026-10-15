#include <stdio.h>

// Definicion de constantes
#define DIAS 7
#define MINIMA -10
#define MAXIMA 45

int main(void) {

    //Deifinicion de variables
    int temp;
    int suma = 0;
    int maxima = MINIMA;
    int calurosos = 0;
    int i;
    float promedio;

    printf("=== Temperaturas de la semana ===\n");

    //proceso
    for (i = 0; i < DIAS; i++) {
        do {
            printf("Temperatura dia %d: ", i + 1);
            scanf("%d", &temp);

            if (temp < MINIMA || temp > MAXIMA) {
                printf("  Fuera de rango (%d a %d)\n", MINIMA, MAXIMA);
            }
        } while (temp < MINIMA || temp > MAXIMA);

        suma = suma + temp;

        if (temp > maxima) {
            maxima = temp;
        }

        if (temp > 30) {
            calurosos++;
        }
    }

    promedio = (float)suma / DIAS;

    //Presentacion de la informacion
    printf("\nPromedio: %.1f grados\n", promedio);
    printf("Maxima: %d grados\n", maxima);
    printf("Dias calurosos: %d\n", calurosos);

    return 0;
}
