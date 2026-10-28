/* 
   Reto opcional · Redondeo a 5 colones → redondeo.c (10 min) 
   Escriba double redondearCinco(double monto) que redondee 
   un monto al múltiplo de 5 más cercano con round: 
   1232 → 1230; 1233 → 1235; 1237.5 → 1240. 
*/

#include <stdio.h>
#include <math.h> // Necesario para la función round()

/* ==========================================
 * PROTOTIPO DE LA FUNCIÓN
 * ========================================== */
double redondearCinco(double monto);

int main(void) {
    // Casos de prueba basados en el enunciado
    double prueba1 = 1232.0;
    double prueba2 = 1233.0;
    double prueba3 = 1237.5;

    printf("--- Pruebas de Redondeo a 5 Colones ---\n");
    printf("Monto: %.1f -> Redondeado: %.1f\n", prueba1, redondearCinco(prueba1));
    printf("Monto: %.1f -> Redondeado: %.1f\n", prueba2, redondearCinco(prueba2));
    printf("Monto: %.1f -> Redondeado: %.1f\n", prueba3, redondearCinco(prueba3));

    return 0;
}

/* ==========================================
 * IMPLEMENTACIÓN DE LA FUNCIÓN
 * Redondea un monto al múltiplo de 5 más cercano.
 * ========================================== */
double redondearCinco(double monto) {
    /* 1. Dividimos entre 5 para ver cuántos "bloques de 5" contiene.
     * 2. Usamos round() para redondear al entero más cercano.
     * 3. Multiplicamos por 5 para regresar a la escala original. */
    return round(monto / 5.0) * 5.0;
}