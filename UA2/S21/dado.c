/* Enunciado: simular 600 lanzamientos de un dado y mostrar cuántas veces salió
   cada cara con una barra de asteriscos. 

   Elementos que se practican: rand y srand de stdlib.h, una función que devuelve un valor (int 
   lanzarDado(void)), otra void (void mostrarBarra(int cantidad), un * por cada 10 lanzamientos) y 
   un arreglo de contadores (sesión 20). 
*/

#include <stdio.h>
#include <stdlib.h>

/* Función que simula el lanzamiento de un dado (devuelve un valor entre 1 y 6) */
int lanzarDado(void) {
    return (rand() % 6) + 1;
}

/* Función que muestra una barra de asteriscos (un * por cada 10 lanzamientos) */
void mostrarBarra(int cantidad) {
    int asteriscos = cantidad / 10;
    for (int i = 0; i < asteriscos; i++) {
        printf("*");
    }
}

int main(void) {
    // Inicializar la semilla para los números aleatorios
    srand(2026);

    // Arreglo de contadores para las caras del 1 al 6 (índice 0 no se utiliza)
    int frecuencia[7] = {0};
    int totalLanzamientos = 600;

    // Simular los 600 lanzamientos
    for (int i = 0; i < totalLanzamientos; i++) {
        int cara = lanzarDado();
        frecuencia[cara]++; // Incrementa el contador de la cara obtenida
    }

    // Mostrar los resultados y las barras correspondientes
    for (int i = 1; i <= 6; i++) {
        printf("Cara %d: %3d ", i, frecuencia[i]);
        mostrarBarra(frecuencia[i]);
        printf("\n");
    }

    return 0;
}