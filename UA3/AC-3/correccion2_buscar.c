/*============================================================================
                           correccion2_buscar.c
Enunciado: Una pulpería guarda 4 productos con su precio. El programa lee el 
           nombre de un producto, lo busca con la función buscar y muestra su 
           precio o «No existe».

------------------------------------------------------------------------------
Datos de prueba:     Cafe y luego Pan (dos ejecuciones)
Resultado esperado:  Cafe cuesta 3200.00 - No existe     
------------------------------------------------------------------------------    

Se compila con: 
gcc -std=c11 -Wall -Wextra correccion2_buscar.c -o correccion2_buscar

------------------Mensaje de Errores del compilador-------------------------

No presenta errores de compilación.

------------------ Ejecucion con el problema de logica -----------------------

$ ./correccion2_buscar.exe       |   $ ./correccion2_buscar.exe
Producto: Cafe                   |   Producto: Pan
No existe                        |   No existe

------------------ Ejecución con las correcciones ---------------------------

$ ./correccion2_buscar.exe       |   $ ./correccion2_buscar.exe
Producto: Cafe                   |   Producto: Pan
Cafe cuesta 3200.00              |   No existe

============================================================================*/

#include <stdio.h>
#include <string.h>
#define N 4

int buscar(const char nombres[][15], int n, const char buscado[]) {
    int i;
    //ERROR: se esta usando i <= n
    //POR QUE: == compara direcciones de memoria no el contenido
    //CORRECCIÓN: se cambia la condicion a i < n
    for (i = 0; i < n; i++)     //cambiar a i < n
        //ERROR: se comparan candenas usando ==
        //POR QUE: problema para leer el arreglo
        //CORRECCIÓN: Utilizar la función strcmp(nombres[i], buscado) == 0
        if (strcmp(nombres[i], buscado) == 0)     
            return i;
    return -1;
}

int main(void) {
    char nombres[N][15] = {"Arroz", "Frijoles", "Cafe", "Azucar"};
    double precios[N] = {1200, 1500, 3200, 900};
    char buscado[15];
    int pos;
    printf("Producto: ");
    scanf("%14s", buscado);
    pos = buscar(nombres, N, buscado);
    if (pos == -1)
        printf("No existe\n");
    else
        printf("%s cuesta %.2f\n", nombres[pos], precios[pos]);
    return 0;
}
