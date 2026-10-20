/*
  Pedido de la librería
 
  ENUNCIADO:
  Una librería registra los libros de cada pedido. El programa debe:
  1. Leer el título de cada libro hasta que se digite FIN o fin (máximo 10 títulos).
     Para cada libro leer el precio y la cantidad, ambos positivos.
  2. Contar las unidades (suma de cantidades) y acumular el total de libros.
  3. Aplicar un descuento del 10 % si el pedido tiene 5 unidades o más.
  4. Calcular el envío: 8 si el total de libros es menor que 50,
     4 si es menor que 150 y gratis desde 150.
  5. Calcular el impuesto (13 % del total con descuento) y el total a pagar
     (total − descuento + impuesto + envío).
  6. Mostrar el detalle de cada libro y el resumen del pedido.
 
  QUÉ SE LOGRA:
  Registrar hasta 10 libros, validar precio y cantidad, calcular descuento,
  envío, impuesto y total a pagar, y mostrar el detalle completo del pedido.
 
  CÓMO SE LOGRA:
  - While con lectura previa y centinela de texto "FIN"/"fin" comparado con strcmp.
  - Arreglos paralelos para títulos, precios, cantidades y subtotales.
  - strcpy para guardar cada título.
  - Acumuladores para unidades y total de libros.
  - Constantes para tasas, límites de envío y máximo de libros.
 
  RESULTADO ESPERADO (datos: Cocori 12.50 2, El principito 8 3, FIN):
  Unidades: 5
  Total de libros: 49.00
  Descuento: 4.90
  Impuesto (13%): 5.73
  Envio: 8.00
  TOTAL A PAGAR: 57.83
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIBROS 10            // Máximo de títulos permitidos
#define TASA_DESCUENTO 0.10      // 10 % de descuento
#define TASA_IMPUESTO 0.13       // 13 % de impuesto
#define LIMITE_UNIDADES 5        // Unidades mínimas para aplicar descuento
#define ENVIO_BAJO 8.0           // Envío si total < 50
#define ENVIO_MEDIO 4.0          // Envío si total < 150
#define LIMITE_ENVIO1 50.0       // Primer límite de envío
#define LIMITE_ENVIO2 150.0      // Segundo límite de envío

int main(void) {
    char titulos[MAX_LIBROS][50];    // Arreglo de títulos
    double precios[MAX_LIBROS];      // Arreglo de precios
    int cantidades[MAX_LIBROS];      // Arreglo de cantidades
    double subtotales[MAX_LIBROS];   // Subtotal de cada libro (precio * cantidad)

    char tituloActual[50];           // Título leído en cada iteración
    int numLibros = 0;               // Cantidad de libros registrados
    int unidades = 0;                // ACUMULADOR: suma de todas las cantidades
    double totalLibros = 0.0;        // ACUMULADOR: suma de (precio * cantidad)
    double descuento = 0.0;          // Monto del descuento
    double impuesto;                 // Impuesto (13 % del total con descuento)
    double envio;                    // Costo de envío
    double totalPagar;               // Total final a pagar
    int i;                           // Contador de ciclos

    printf("=== Pedido de la libreria ===\n");

    // Se solicita el primer libro
    printf("Titulo del libro (FIN para terminar): ");
    fgets(tituloActual, sizeof(tituloActual), stdin);
    tituloActual[strcspn(tituloActual, "\n")] = '\0';  

    // While con centinela de texto (se compara con strcmp, no con ==)
    while (strcmp(tituloActual, "FIN") != 0 &&
           strcmp(tituloActual, "fin") != 0 &&
           numLibros < MAX_LIBROS) {

        // Guardar el título con strcpy
        strcpy(titulos[numLibros], tituloActual);

        // Leer y validar precio (positivo)
        do {
            printf("Precio: ");
            scanf("%lf", &precios[numLibros]);
            if (precios[numLibros] <= 0) {
                printf("  El precio debe ser positivo. Intente de nuevo.\n");
            }
        } while (precios[numLibros] <= 0);

        // Leer y validar cantidad (positiva)
        do {
            printf("Cantidad: ");
            scanf("%d", &cantidades[numLibros]);
            if (cantidades[numLibros] <= 0) {
                printf("  La cantidad debe ser positiva. Intente de nuevo.\n");
            }
        } while (cantidades[numLibros] <= 0);

        // Limpiar el buffer después de scanf
        while (getchar() != '\n');

        // Calcular subtotal del libro y acumular
        subtotales[numLibros] = precios[numLibros] * cantidades[numLibros];
        totalLibros += subtotales[numLibros];
        unidades += cantidades[numLibros];

        numLibros++;

        // Leer el siguiente título
        printf("Titulo del libro (FIN para terminar): ");
        fgets(tituloActual, sizeof(tituloActual), stdin);
        tituloActual[strcspn(tituloActual, "\n")] = '\0';
    }

    // Calcular descuento
    if (unidades >= LIMITE_UNIDADES) {
        descuento = totalLibros * TASA_DESCUENTO;
    }

    // Calcular envío según el total de libros
    if (totalLibros < LIMITE_ENVIO1) {
        envio = ENVIO_BAJO;
    } else if (totalLibros < LIMITE_ENVIO2) {
        envio = ENVIO_MEDIO;
    } else {
        envio = 0.0;   // Envío gratis
    }

    // Calcular impuesto y total a pagar
    impuesto = (totalLibros - descuento) * TASA_IMPUESTO;
    totalPagar = totalLibros - descuento + impuesto + envio;

    // Mostrar detalle de cada libro
    printf("\n%-20s %8s %6s %10s\n", "Titulo", "Precio", "Cant", "Subtotal");
    for (i = 0; i < numLibros; i++) {
        printf("%-20s %8.2f %6d %10.2f\n",
               titulos[i], precios[i], cantidades[i], subtotales[i]);
    }

    // Mostrar resumen del pedido
    printf("\nUnidades: %d\n", unidades);
    printf("Total de libros: %.2f\n", totalLibros);
    printf("Descuento: %.2f\n", descuento);
    printf("Impuesto (13%%): %.2f\n", impuesto);
    printf("Envio: %.2f\n", envio);
    printf("TOTAL A PAGAR: %.2f\n", totalPagar);

    return 0;
}