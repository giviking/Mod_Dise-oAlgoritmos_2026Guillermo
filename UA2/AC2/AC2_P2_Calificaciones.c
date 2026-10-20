/*
   Validación de calificaciones estudiantiles  | AC2_P2_Calificaciones.c
  
   ENUNCIADO:
   Un centro educativo necesita automatizar el cálculo de notas finales.
   El programa debe:
   1. Recibir el nombre completo del estudiante.
   2. Recibir tres calificaciones de 0 a 100 y guardarlas en un arreglo.
      Cada calificación fuera de rango se rechaza con un mensaje y se vuelve a pedir.
   3. Calcular el promedio de las tres calificaciones y buscar la calificación
      más alta recorriendo el arreglo.
   4. Determinar la condición:
      - APROBADO si el promedio es 70 o más
      - EN RIESGO si es 60 o más, pero menor que 70
      - NO APROBADO si es menor que 60
      Guardar la condición en una cadena.
   5. Mostrar el nombre, las tres calificaciones, el promedio (dos decimales),
      la calificación más alta y la condición.
  
   QUÉ SE LOGRA:
   Validar tres notas, calcular el promedio, encontrar la nota más alta
   y determinar automáticamente la condición del estudiante.
  
   CÓMO SE LOGRA:
   - Arreglo float notas[3] recorrido con for.
   - do-while para validar cada nota (0 a 100).
   - Constantes para los límites de calificación y de condición.
   - strcpy para guardar la condición en una cadena.
   - Acumulador para el promedio y variable para la nota más alta.
  
   RESULTADO ESPERADO (datos: Juan Perez, 75, 82, 68):
   Promedio: 75.00
   Nota mas alta: 82.0
   Condicion: APROBADO
 */

#include <stdio.h>
#include <string.h>   // Para strcpy y strcspn

#define NUM_NOTAS      3      // Cantidad de calificaciones
#define NOTA_MIN       0.0    // Calificación mínima permitida
#define NOTA_MAX       100.0  // Calificación máxima permitida
#define LIMITE_APROBADO 70.0  // Promedio mínimo para APROBADO
#define LIMITE_RIESGO   60.0  // Promedio mínimo para EN RIESGO

int main(void) {
    char nombre[80];              // Nombre completo del estudiante
    float notas[NUM_NOTAS];       // Arreglo con las tres calificaciones
    float suma = 0.0;             // ACUMULADOR para calcular el promedio
    float promedio;               // Promedio de las tres notas
    float notaMasAlta;            // Calificación más alta encontrada
    char condicion[20];           // Cadena que guarda la condición del estudiante
    int i;                        // Contador para los ciclos for

    printf("=== Calificaciones del estudiante ===\n");

    // Solicita el nombre completo del estudiante
    printf("Nombre del estudiante: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';   // Eliminar el salto de línea

    // Proceso para validar las tres calificaciones
    for (i = 0; i < NUM_NOTAS; i++) {
        do {
            printf("Calificacion %d (0 a 100): ", i + 1);
            scanf("%f", &notas[i]);

            if (notas[i] < NOTA_MIN || notas[i] > NOTA_MAX) {
                printf("Error: la calificacion debe estar entre 0 y 100. Intente de nuevo.\n");
            }
        } while (notas[i] < NOTA_MIN || notas[i] > NOTA_MAX);

        suma = suma + notas[i];   // Acumular para el promedio
    }

    // Calcular el promedio
    promedio = suma / NUM_NOTAS;

    // Buscar la calificación más alta recorriendo el arreglo
    notaMasAlta = notas[0];
    for (i = 1; i < NUM_NOTAS; i++) {
        if (notas[i] > notaMasAlta) {
            notaMasAlta = notas[i];
        }
    }

    // Determinar la condición y guardarla con strcpy
    if (promedio >= LIMITE_APROBADO) {
        strcpy(condicion, "APROBADO");
    } else if (promedio >= LIMITE_RIESGO) {
        strcpy(condicion, "EN RIESGO");
    } else {
        strcpy(condicion, "NO APROBADO");
    }

    // Mostrar resultados
    printf("\n------- Resultado -------\n");
    printf("Estudiante: %s\n", nombre);
    for (i = 0; i < NUM_NOTAS; i++) {
        printf("Calificacion %d: %.1f\n", i + 1, notas[i]);
    }
    printf("Promedio:      %.2f\n", promedio);
    printf("Nota mas alta: %.1f\n", notaMasAlta);
    printf("Condicion:     %s\n", condicion);

    return 0;
}