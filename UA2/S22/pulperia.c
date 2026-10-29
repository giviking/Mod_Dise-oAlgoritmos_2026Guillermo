/*
================================================================================
pulperia.c
================================================================================
Que se logra:
Programar el inventario de una pulperia con un menu que permita listar los
productos, vender (solo si hay existencias), reponer y consultar el valor
del inventario.

Elementos que se practican:
- Menu con do ... while y switch
- Arreglos paralelos y un arreglo de cadenas
- Funcion de lectura validada que recibe un mensaje (cadena)
- Funciones que reciben arreglos con const
- vender y reponer reciben &existencias[p] para modificar el arreglo de main

Resultado esperado:
Vende 5 de Cafe (quedan 7), rechaza 20 de Aceite ("Solo hay 8 unidades"),
repone 10 de Aceite (quedan 18) y el valor final del inventario es 164100.00.
================================================================================
*/

#include <stdio.h>

/* Prototipos de las funciones */
int leerEntero(const char mensaje[], int minimo, int maximo);
void listar(const char nombres[][20], const double precios[], const int existencias[], int n);
int vender(int *existencia, int cantidad);
void reponer(int *existencia, int cantidad);
double valorInventario(const double precios[], const int existencias[], int n);

int main(void) {
    /* Arreglo de nombres de productos (cadenas) */
    char nombres[4][20] = {
        "Arroz 2 kg",
        "Frijoles 1 kg",
        "Cafe 1 kg",
        "Aceite 1 L"
    };

    /* Arreglo de precios unitarios */
    double precios[4] = {2400.0, 1800.0, 4500.0, 3200.0};

    /* Arreglo de existencias iniciales */
    int existencias[4] = {20, 15, 12, 8};

    int opcion;          /* Opcion del menu */
    int producto;        /* Numero de producto elegido (1 a 4) */
    int cantidad;        /* Cantidad a vender o reponer */
    int resultado;       /* Resultado de la venta (1 = exito, 0 = fallo) */
    double valor;        /* Valor total del inventario */

    /* Ciclo principal del menu: se repite hasta que el usuario elija 0 */
    do {
        /* Muestra el menu de opciones en una sola linea (horizontal) */
        printf("1. Listar  2. Vender  3. Reponer  4. Valor  0. Salir\n");

        /* Lee la opcion validada entre 0 y 4 */
        opcion = leerEntero("Opcion (0 a 4): ", 0, 4);

        /* Procesa la opcion elegida */
        switch (opcion) {
            case 1:
                /* Lista todos los productos */
                listar(nombres, precios, existencias, 4);
                break;

            case 2:
                /* Lee el numero de producto (1 a 4) */
                producto = leerEntero("Producto (1 a 4): ", 1, 4);

                /* Lee la cantidad a vender (1 a 50) */
                cantidad = leerEntero("Cantidad (1 a 50): ", 1, 50);

                /* Intenta vender pasando la direccion de la existencia */
                resultado = vender(&existencias[producto - 1], cantidad);

                if (resultado == 1) {
                    /* Venta exitosa: muestra el detalle */
                    printf("Vendido: %d x %s = %.2f\n",
                           cantidad,
                           nombres[producto - 1],
                           cantidad * precios[producto - 1]);
                } else {
                    /* No hay suficientes existencias */
                    printf("Solo hay %d unidades\n", existencias[producto - 1]);
                }
                break;

            case 3:
                /* Lee el numero de producto (1 a 4) */
                producto = leerEntero("Producto (1 a 4): ", 1, 4);

                /* Lee la cantidad a reponer (1 a 50) */
                cantidad = leerEntero("Cantidad (1 a 50): ", 1, 50);

                /* Suma la cantidad a las existencias */
                reponer(&existencias[producto - 1], cantidad);

                /* Muestra las nuevas existencias */
                printf("Existencias de %s: %d\n",
                       nombres[producto - 1],
                       existencias[producto - 1]);
                break;

            case 4:
                /* Calcula y muestra el valor total del inventario */
                valor = valorInventario(precios, existencias, 4);
                printf("Valor del inventario: %.2f\n", valor);
                break;

            case 0:
                /* Sale del programa */
                printf("Hasta luego\n");
                break;
        }

    } while (opcion != 0);

    return 0;
}

/* Lee un entero validado entre minimo y maximo inclusive */
int leerEntero(const char mensaje[], int minimo, int maximo) {
    int valor;   /* Valor leido del usuario */

    do {
        /* Muestra el mensaje recibido */
        printf("%s", mensaje);

        /* Lee el valor */
        scanf("%d", &valor);

        /* Si esta fuera de rango, informa al usuario */
        if (valor < minimo || valor > maximo) {
            printf("Valor invalido. Debe estar entre %d y %d.\n", minimo, maximo);
        }

    } while (valor < minimo || valor > maximo);

    return valor;
}

/* Muestra la lista de productos con su precio y existencias */
void listar(const char nombres[][20], const double precios[], const int existencias[], int n) {
    int i;   /* Contador del ciclo */

    for (i = 0; i < n; i++) {
        /* Imprime numero, nombre, precio y existencias de cada producto */
        printf("%d. %s %.2f %d\n", i + 1, nombres[i], precios[i], existencias[i]);
    }
}

/* Descuenta la cantidad si hay existencias suficientes.
   Devuelve 1 si la venta fue exitosa, 0 si no hay suficientes unidades. */
int vender(int *existencia, int cantidad) {
    /* Verifica si hay suficientes existencias */
    if (*existencia >= cantidad) {
        /* Descuenta la cantidad vendida */
        *existencia = *existencia - cantidad;
        return 1;   /* Venta exitosa */
    } else {
        return 0;   /* No hay suficientes unidades */
    }
}

/* Suma la cantidad recibida a las existencias del producto */
void reponer(int *existencia, int cantidad) {
    /* Incrementa las existencias */
    *existencia = *existencia + cantidad;
}

/* Calcula el valor total del inventario (existencias * precio de cada producto) */
double valorInventario(const double precios[], const int existencias[], int n) {
    double total = 0.0;   /* Acumulador del valor total */
    int i;                /* Contador del ciclo */

    for (i = 0; i < n; i++) {
        /* Suma el valor de cada producto */
        total = total + (existencias[i] * precios[i]);
    }

    return total;
}