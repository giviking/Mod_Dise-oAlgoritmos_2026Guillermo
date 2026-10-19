/*
  Evaluación de desempemo  | PR_P2_Desempeno.c
 
  ENUNCIADO:
  Una empresa evalúa a sus colaboradores en tres criterios: puntualidad,
  calidad y trabajo en equipo. El programa debe:
  1. Recibir el nombre del colaborador y el puntaje de cada criterio (0 a 10).
     Un puntaje fuera de rango se vuelve a pedir. El mensaje debe mostrar
     el nombre del criterio.
  2. Calcular el promedio y el nivel:
     - EXCELENTE (9 o más)
     - BUENO (7 o más, pero menos de 9)
     - NECESITA MEJORAR (menos de 7)
  3. Indicar el criterio con el puntaje más bajo y su puntaje.
 
  QUÉ SE LOGRA:
  Validar los tres puntajes, calcular el promedio, determinar el nivel de
  desempeño y encontrar el criterio más débil del colaborador.
 
  CÓMO SE LOGRA:
   - Arreglo de cadenas con los nombres de los criterios.
  - Arreglo de double con los puntajes en la misma posición.
  - Ciclo for + do-while para leer y validar cada puntaje.
  - Acumulador para la suma y cálculo del promedio.
  - Búsqueda del menor guardando su posición (índice).
  - Decisión para asignar el nivel según el promedio.
 
  RESULTADO ESPERADO (datos: Laura Solis, 9, 11→8.5, 10):
  Promedio: 9.17
  Nivel: EXCELENTE
  Puntaje mas bajo: calidad (8.5)
 */

#include <stdio.h>
#include <string.h>

#define CRITERIOS 3          // Cantidad de criterios de evaluación
#define MIN_PUNTAJE 0.0      // Puntaje mínimo permitido
#define MAX_PUNTAJE 10.0     // Puntaje máximo permitido

int main(void) {
    char nombre[50];                         // Nombre del colaborador
    char criterios[CRITERIOS][30] = {        // Nombres de los criterios
        "puntualidad",
        "calidad",
        "trabajo en equipo"
    };
    double puntajes[CRITERIOS];              // Puntajes de cada criterio
    double suma = 0.0;                       // ACUMULADOR de los puntajes
    double promedio;                         // Promedio de los tres puntajes
    int posMenor = 0;                        // Posición (índice) del puntaje más bajo
    int i;                                   // Contador de ciclos
    char nivel[25];                          // Texto del nivel de desempeño

    printf("=== Evaluacion de desempeno ===\n");

    // Solicitar el nombre del colaborador
    printf("Nombre del colaborador: ");
    fgets(nombre, sizeof(nombre), stdin);
    
    nombre[strcspn(nombre, "\n")] = '\0';

    // Solicitar los puntajes de cada criterio
    for (i = 0; i < CRITERIOS; i++) {
        do {
            printf("Puntaje de %s (0 a 10): ", criterios[i]);
            scanf("%lf", &puntajes[i]);

            if (puntajes[i] < MIN_PUNTAJE || puntajes[i] > MAX_PUNTAJE) {
                printf("Puntaje invalido, debe estar entre 0 y 10\n");
            }
        } while (puntajes[i] < MIN_PUNTAJE || puntajes[i] > MAX_PUNTAJE);

        suma = suma + puntajes[i];   // Acumular para el promedio
    }

    // Calcular el promedio
    promedio = suma / CRITERIOS;

    // Determinar el nivel según el promedio
    if (promedio >= 9.0) {
        strcpy(nivel, "EXCELENTE");
    } else if (promedio >= 7.0) {
        strcpy(nivel, "BUENO");
    } else {
        strcpy(nivel, "NECESITA MEJORAR");
    }

    // Buscar el puntaje más bajo guardando
    for (i = 1; i < CRITERIOS; i++) {
        if (puntajes[i] < puntajes[posMenor]) {
            posMenor = i;
        }
    }

    // Mostrar resultados por pantalla
    printf("\nColaborador: %s\n", nombre);
    printf("Promedio: %.2f\n", promedio);
    printf("Nivel: %s\n", nivel);
    printf("Puntaje mas bajo: %s (%.1f)\n", criterios[posMenor], puntajes[posMenor]);

    return 0;
}