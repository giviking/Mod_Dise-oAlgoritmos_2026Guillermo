/*
   Gestión de compras en una tienda    |    AC2_P3_Compras.c
  
   ENUNCIADO:
   Una tienda de electrónica necesita procesar las compras de sus clientes.
    El programa debe:
   1. Recibir el nombre del cliente.
   2. Permitir registrar varios productos (máximo 10): nombre (puede tener espacios),
      precio unitario y cantidad. Después de cada producto pregunta si desea agregar
      otro (S/N); solo acepta S o N (mayúscula o minúscula).
   3. Validar que el precio y la cantidad sean positivos.
   4. Mostrar el subtotal de cada producto (precio × cantidad) al ingresarlo y acumular el total.
   5. Aplicar el descuento según el total:
      - menos de 100 → sin descuento
      - de 100 a menos de 500 → 5 %
      - de 500 a 1000 → 10 %
      - más de 1000 → 15 %
   6. Calcular el total con descuento y el impuesto (13 % sobre el total con descuento).
   7. Mostrar una factura con el cliente, el detalle de cada producto (nombre, precio,
      cantidad y subtotal), la cantidad de productos, el subtotal, el descuento,
      el total con descuento, el impuesto y el total a pagar.
  
   QUÉ SE LOGRA:
   Registrar hasta 10 productos con validaciones, calcular subtotales, aplicar
   descuento e impuesto correctamente y mostrar una factura completa.
  
   CÓMO SE LOGRA:
   - Arreglos paralelos para nombres, precios y cantidades.
   - fgets para leer nombres (cliente y productos).
   - getchar() para limpiar el buffer después de scanf.
   - do-while para validar precio, cantidad y respuesta S/N.
   - Constantes para límites, tasas de descuento e impuesto.
  
   RESULTADO ESPERADO (datos: Ana Garcia, Teclado 60 2, Mouse 25 1, Monitor 350 1):
   Subtotal: 495.00
   Descuento: 24.75 (5%)
   Total con descuento: 470.25
   Impuesto (13%): 61.13
   TOTAL A PAGAR: 531.38
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>   

#define MAX_PRODUCTOS 10          // Máximo de productos permitidos
#define TASA_IMPUESTO 0.13        // 13 % de impuesto
#define LIMITE1 100.0             // Límite inferior para 5 %
#define LIMITE2 500.0             // Límite inferior para 10 %
#define LIMITE3 1000.0            // Límite inferior para 15 %
#define DESC1 0.05                // 5 % de descuento
#define DESC2 0.10                // 10 % de descuento
#define DESC3 0.15                // 15 % de descuento

int main(void) {
    char cliente[80];                         // Nombre del cliente
    char nombres[MAX_PRODUCTOS][50];          // Nombres de los productos
    double precios[MAX_PRODUCTOS];            // Precio unitario de cada producto
    int cantidades[MAX_PRODUCTOS];            // Cantidad de cada producto
    double subtotales[MAX_PRODUCTOS];         // Subtotal de cada producto (precio * cantidad)

    int numProductos = 0;                     // Cantidad de productos registrados
    double total = 0.0;                       // ACUMULADOR del total de la compra
    double descuento = 0.0;                   // Monto del descuento aplicado
    double totalConDescuento;                 // Total después de aplicar descuento
    double impuesto;                          // Impuesto (13 %)
    double totalPagar;                        // Total final a pagar
    char respuesta;                           // Respuesta S/N del usuario
    int i;                                    // Contador para ciclos

    printf("=== Compra en la tienda ===\n");

    // Solicita el nombre del cliente
    printf("Nombre del cliente: ");
    fgets(cliente, sizeof(cliente), stdin);
    cliente[strcspn(cliente, "\n")] = '\0';   // Quitar salto de línea

    // Se ingresan los productos
    do {
        printf("\nProducto %d\n", numProductos + 1);

        // Se ingresa el nombre del producto 
        printf("Nombre: ");
        fgets(nombres[numProductos], sizeof(nombres[numProductos]), stdin);
        nombres[numProductos][strcspn(nombres[numProductos], "\n")] = '\0';

        // Se inrgesa el precio unitario (positivo)
        do {
            printf("Precio unitario: ");
            scanf("%lf", &precios[numProductos]);
            if (precios[numProductos] <= 0) {
                printf("Error: el precio debe ser positivo. Intente de nuevo.\n");
            }
        } while (precios[numProductos] <= 0);

        // Se ingresa la cantidad 
        do {
            printf("Cantidad: ");
            scanf("%d", &cantidades[numProductos]);
            if (cantidades[numProductos] <= 0) {
                printf("Error: la cantidad debe ser positiva. Intente de nuevo.\n");
            }
        } while (cantidades[numProductos] <= 0);

        // Limpiar
        while (getchar() != '\n');

        // Calcular subtotal del producto y sumar
        subtotales[numProductos] = precios[numProductos] * cantidades[numProductos];
        total += subtotales[numProductos];

        printf("Subtotal: %.2f\n", subtotales[numProductos]);

        numProductos++;

        // Preguntar si desea agregar otro producto (solo S o N)
        if (numProductos < MAX_PRODUCTOS) {
            do {
                printf("Desea agregar otro producto? (S/N): ");
                scanf(" %c", &respuesta);
                respuesta = toupper(respuesta);   // Convertir a mayúscula

                if (respuesta != 'S' && respuesta != 'N') {
                    printf("Error: solo se acepta S o N. Intente de nuevo.\n");
                }
            } while (respuesta != 'S' && respuesta != 'N');

            // Limpiar 
            while (getchar() != '\n');
        } else {
            respuesta = 'N';   // Se alcanzó el máximo
            printf("Se alcanzo el maximo de %d productos.\n", MAX_PRODUCTOS);
        }

    } while (respuesta == 'S' && numProductos < MAX_PRODUCTOS);

    // Calcular descuento según el total
    if (total < LIMITE1) {
        descuento = 0.0;
    } else if (total < LIMITE2) {
        descuento = total * DESC1;          // 5 %
    } else if (total <= LIMITE3) {
        descuento = total * DESC2;          // 10 %
    } else {
        descuento = total * DESC3;          // 15 %
    }

    // Calcular total con descuento, impuesto y total a pagar
    totalConDescuento = total - descuento;
    impuesto = totalConDescuento * TASA_IMPUESTO;
    totalPagar = totalConDescuento + impuesto;

    // Mostrar la factura
    printf("\n================= FACTURA =================\n");
    printf("Cliente: %s\n\n", cliente);
    printf("%-20s %10s %6s %10s\n", "Producto", "Precio", "Cant", "Subtotal");
    
    for (i = 0; i < numProductos; i++) {
        printf("%-20s %10.2f %6d %10.2f\n",
               nombres[i], precios[i], cantidades[i], subtotales[i]);
    }

    printf("Productos registrados: %d\n", numProductos);
    printf("Subtotal:              %10.2f\n", total);
    printf("Descuento:             %10.2f", descuento);

    // Mostrar el porcentaje de descuento aplicado
    if (total < LIMITE1) {
        printf(" (0%%)\n");
    } else if (total < LIMITE2) {
        printf(" (5%%)\n");
    } else if (total <= LIMITE3) {
        printf(" (10%%)\n");
    } else {
        printf(" (15%%)\n");
    }

    printf("Total con descuento:   %10.2f\n", totalConDescuento);
    printf("Impuesto (13%%):        %10.2f\n", impuesto);
    printf("TOTAL A PAGAR:         %10.2f\n", totalPagar);

    return 0;
}