/*
 ============================================================================
 Enunciado:
 Un docente quiere organizar las notas de un grupo pequeño. Escriba un programa 
 en C que:
 1. Pida el nombre (una palabra) de 4 estudiantes y sus notas en 3 evaluaciones 
    (de 0 a 100). Una nota invalida muestra un mensaje y se vuelve a pedir.
 2. Guarde las notas en una matriz de 4 filas por 3 columnas.
 3. Muestre una tabla con el nombre, las tres notas y el promedio de cada 
    estudiante (dos decimales).
 4. Muestre el promedio de cada evaluacion (columna) y el estudiante con 
    mejor promedio.
 5. Al final, pida un nombre y busquelo: si esta, muestre su promedio y su 
    condicion (APROBADO con 70 o mas; si no, NO APROBADO); si no esta, 
    muestrelo con un mensaje.

 Que se logra:
 Almacenar y procesar de manera estructurada los nombres, calificaciones y 
 promedios de un grupo de estudiantes utilizando arreglos bidimensionales y 
 unidimensionales. Se realiza la validacion de entradas, calculos de promedios 
 por fila (estudiante) y por columna (evaluacion), determinacion del maximo 
 promedio y la busqueda secuencial de registros mediante funciones de cadenas.

 Como se logra:
 Se emplean ciclos 'for' anidados para la lectura, calculo y despliegue de 
 datos. El recorrido por filas procesa cada estudiante y acumula sus notas 
 para la matriz, usando (float) para divisiones exactas. El recorrido por 
 columnas calcula la media por cada evaluacion general reiniciando el acumulador. 
 La busqueda de texto se realiza con la funcion strcmp() de <string.h> y la 
 condicion final del estudiante encontrado se copia usando strcpy().

 Resultado esperado:
 Capturar la informacion solicitada con mensajes de validacion ante notas fuera 
 de rango (0-100), generar un reporte tabulado de calificaciones por estudiante, 
 mostrar promedios por evaluacion, indicar el estudiante mas sobresaliente y 
 permitir consultar el estado final ("APROBADO" o "NO APROBADO") de un alumno 
 en especifico mediante su nombre.
 ============================================================================
*/

#include <stdio.h>
#include <string.h>

// Definicion de constantes del programa
#define NUM_ESTUDIANTES 4   // Cantidad total de estudiantes
#define NUM_EVALUACIONES 3  // Cantidad total de evaluaciones por estudiante
#define NOTA_MIN 0          // Nota minima permitida
#define NOTA_MAX 100        // Nota maxima permitida
#define NOTA_APROBACION 70.0 // Nota minima para aprobar

int main(void) {
    // Declaracion de matrices, arreglos y variables principales
    int notas[NUM_ESTUDIANTES][NUM_EVALUACIONES];     // Matriz para guardar las notas de cada estudiante (filas=estudiantes, columnas=evaluaciones)
    char nombres[NUM_ESTUDIANTES][15];                // Arreglo de cadenas para almacenar los nombres de los 4 estudiantes
    float prom[NUM_ESTUDIANTES];                      // Arreglo para guardar el promedio ponderado de cada estudiante
    
    int pos_mejor_promedio = 0;                       // Indice de la fila del estudiante con el mejor promedio
    char nombre_buscado[15];                          // Cadena para almacenar el nombre que ingresa el usuario al buscar
    char condicion[15];                               // Cadena para almacenar "APROBADO" o "NO APROBADO" usando strcpy
    int encontrado = 0;                               // Bandera (0=no encontrado, 1=encontrado) para la busqueda del estudiante

    printf("=== Notas del grupo ===\n");

    // 1 y 2. Pedir datos, validar notas y llenar arreglos/matriz
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("Nombre del estudiante %d: ", i + 1);
        scanf("%s", nombres[i]);

        int suma_estudiante = 0; // Acumulador para la suma de notas del estudiante (se reinicia en cada fila)

        for (int j = 0; j < NUM_EVALUACIONES; j++) {
            do {
                printf("  Nota %d de %s: ", j + 1, nombres[i]);
                scanf("%d", &notas[i][j]);

                if (notas[i][j] < NOTA_MIN || notas[i][j] > NOTA_MAX) {
                    printf("  Nota invalida. Debe ser entre 0 y 100. Intente de nuevo.\n");
                }
            } while (notas[i][j] < NOTA_MIN || notas[i][j] > NOTA_MAX);

            suma_estudiante += notas[i][j];
        }

        // 3. Calcular promedio de cada estudiante usando (float) al dividir
        prom[i] = (float)suma_estudiante / NUM_EVALUACIONES;

        // Determinar el estudiante con el mejor promedio
        if (i == 0 || prom[i] > prom[pos_mejor_promedio]) {
            pos_mejor_promedio = i;
        }
    }

    // 3. Muestre la tabla con nombre, tres notas y el promedio
    printf("\n%-10s %4s %4s %4s %8s\n", "Nombre", "N1", "N2", "N3", "Promedio");
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("%-10s %4d %4d %4d %8.2f\n", 
               nombres[i], 
               notas[i][0], 
               notas[i][1], 
               notas[i][2], 
               prom[i]);
    }

    // 4. Recorrido por columnas: promedio de cada evaluacion
    for (int j = 0; j < NUM_EVALUACIONES; j++) {
        int suma_evaluacion = 0; // Acumulador de la columna (se reinicia en cada columna)
        for (int i = 0; i < NUM_ESTUDIANTES; i++) {
            suma_evaluacion += notas[i][j];
        }
        float promedio_eval = (float)suma_evaluacion / NUM_ESTUDIANTES;
        printf("Promedio de la evaluacion %d: %.2f\n", j + 1, promedio_eval);
    }

    // Muestre el estudiante con mejor promedio
    printf("Mejor promedio: %s (%.2f)\n", nombres[pos_mejor_promedio], prom[pos_mejor_promedio]);

    // 5. Busqueda de estudiante por nombre
    printf("\nBuscar estudiante: ");
    scanf("%s", nombre_buscado);

    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        // Uso de strcmp para comparar cadenas de texto (retorna 0 si son iguales)
        if (strcmp(nombres[i], nombre_buscado) == 0) {
            encontrado = 1;
            
            // Evaluacion de la condicion usando strcpy para asignar texto
            if (prom[i] >= NOTA_APROBACION) {
                strcpy(condicion, "APROBADO");
            } else {
                strcpy(condicion, "NO APROBADO");
            }

            printf("%s: %.2f %s\n", nombres[i], prom[i], condicion);
            break; // Termina la busqueda al encontrar la coincidencia
        }
    }

    // Si el nombre no coincide con ningun estudiante registrado
    if (!encontrado) {
        printf("El estudiante %s no se encuentra registrado.\n", nombre_buscado);
    }

    return 0;
}