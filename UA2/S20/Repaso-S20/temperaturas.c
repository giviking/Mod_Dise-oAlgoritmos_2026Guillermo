/*
 ============================================================================
 Enunciado:
 El Instituto Meteorologico registra la temperatura maxima de cada dia. 
 Escriba un programa en C que pida la temperatura maxima de cada dia de la 
 semana (de lunes a domingo, de 0 a 45 grados C), guarde las temperaturas en 
 un arreglo, calcule el promedio, encuentre el dia mas caluroso y muestre 
 un reporte con la temperatura de cada dia, el promedio, el dia mas caluroso 
 y la lista de dias que superaron el promedio junto con su cantidad.

 Que se logra:
 Almacenar de forma estructurada las temperaturas maximas semanales, validar 
 que los datos ingresados se encuentren dentro de un rango logico (0 a 45), 
 calcular metricas estadisticas basicas (promedio y maximos) y realizar 
 un analisis comparativo posterior para identificar cuales dias superaron 
 la media semanal.

 Como se logra:
 Se utilizan arreglos paralelos o indexados: un arreglo bidimensional de caracteres 
 (dias[7][4]) para los nombres abreviados de los dias y un arreglo unidimensional 
 de numeros flotantes (temperaturas[7]) para los valores. Mediante un ciclo 'for' 
 combinado con un 'do-while', se valida cada entrada de usuario. Se acumulan 
 los valores para obtener el promedio y se rastrea el indice del mayor valor. 
 Finalmente, se realiza un segundo recorrido sobre el arreglo para comparar 
 cada temperatura frente al promedio previamente calculado.

 Resultado esperado:
 Solicitar por consola la temperatura de cada dia con validacion de errores 
 ante rangos invalidos, y desplegar un reporte formateado que incluya cada 
 temperatura con un decimal, el promedio semanal con dos decimales, el dia 
 mas caluroso con su respectiva temperatura, y los dias que estuvieron por 
 encima del promedio junto al conteo total de estos.
 ============================================================================
*/

#include <stdio.h>

// Definicion de constantes globales para el programa
#define DIAS_SEMANA 7   // Numero de dias de la semana a procesar
#define TEMP_MIN 0      // Temperatura minima permitida en grados C
#define TEMP_MAX_VAL 45 // Temperatura maxima permitida en grados C

int main(void) {
    // Declaracion de arreglos y variables con sus comentarios de uso
    char dias[DIAS_SEMANA][4] = {"Lun", "Mar", "Mie", "Jue", "Vie", "Sab", "Dom"}; // Almacena los nombres abreviados de los dias de la semana
    float temperaturas[DIAS_SEMANA]; // Almacena las temperaturas maximas ingresadas para cada dia correspondiente
    float suma = 0.0;                // Acumulador que guarda la suma total de las temperaturas de la semana
    float promedio = 0.0;            // Almacena el resultado del calculo del promedio semanal (suma / DIAS_SEMANA)
    int pos_mas_caluroso = 0;        // Almacena el indice (posicion) dentro del arreglo del dia con la temperatura mas alta
    int contador_sobre_promedio = 0; // Cuenta la cantidad total de dias cuyas temperaturas superaron el promedio semanal

    printf("=== Temperaturas de la semana ===\n");

    // 1 y 2. Pedir la temperatura de cada dia con validacion de rango y guardarla en el arreglo
    for (int i = 0; i < DIAS_SEMANA; i++) {
        do {
            printf("Temperatura del %s (0 a 45): ", dias[i]);
            scanf("%f", &temperaturas[i]);
            
            // Validacion de rango: muestra un mensaje si esta fuera de los limites y vuelve a pedir
            if (temperaturas[i] < TEMP_MIN || temperaturas[i] > TEMP_MAX_VAL) {
                printf("Dato fuera de rango. Intente de nuevo.\n");
            }
        } while (temperaturas[i] < TEMP_MIN || temperaturas[i] > TEMP_MAX_VAL);
        
        // Acumular la temperatura para el calculo posterior del promedio
        suma += temperaturas[i];

        // 3. Buscar el dia mas caluroso guardando su posicion (indice)
        if (i == 0 || temperaturas[i] > temperaturas[pos_mas_caluroso]) {
            pos_mas_caluroso = i;
        }
    }

    // 3. Calcular el promedio de la semana
    promedio = suma / DIAS_SEMANA;

    // 4. Mostrar el reporte de la semana
    printf("\n------- Reporte de la semana -------\n");
    
    // Mostrar la temperatura registrada de cada dia
    for (int i = 0; i < DIAS_SEMANA; i++) {
        printf("%s: %.1f C\n", dias[i], temperaturas[i]);
    }

    // Mostrar el promedio con dos decimales
    printf("Promedio:          %.2f C\n", promedio);

    // Mostrar el dia mas caluroso y su temperatura
    printf("Mas caluroso:      %s (%.1f C)\n", dias[pos_mas_caluroso], temperaturas[pos_mas_caluroso]);

    // 4. Recorrer el arreglo otra vez para buscar los dias que superaron el promedio y contar su cantidad
    printf("Sobre el promedio: ");
    for (int i = 0; i < DIAS_SEMANA; i++) {
        if (temperaturas[i] > promedio) {
            printf("%s ", dias[i]);
            contador_sobre_promedio++;
        }
    }
    printf("(%d dias)\n", contador_sobre_promedio);

    return 0;
}