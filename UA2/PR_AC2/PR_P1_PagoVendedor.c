/*
  Pago de comisión a vendedores  |  PR_P1_PagoVendedor.c
 
  ENUNCIADO:
  Una distribuidora paga a sus vendedores una comisión sobre las ventas del mes.
  El programa debe:
  1. Recibir el nombre del vendedor y las ventas de cada una de las 4 semanas
     del mes en un arreglo. Ninguna venta puede ser negativa (se vuelve a pedir).
  2. Calcular las ventas del mes, la comisión (5 % de las ventas) y un bono de 50
     si las ventas del mes superan 2000.
  3. Calcular la retención (2 % de la comisión más el bono) y el pago
     (comisión + bono − retención).
  4. Mostrar las ventas de cada semana, las ventas del mes y el detalle del pago
     con dos decimales.
 
  QUÉ SE LOGRA:
  Validar cada venta semanal, acumular el total del mes y calcular de forma
  correcta comisión, bono, retención y pago neto del vendedor.
 
  CÓMO SE LOGRA:
  - Arreglo double ventas[4] para las 4 semanas.
  - Ciclo for + do-while para leer y validar que ninguna venta sea negativa.
  - Acumulador para las ventas del mes.
  - Constantes para tasas, bono y límite.
  - Cálculos y salida formateada con %.2f.
 
  RESULTADO ESPERADO (datos: Carlos Vega, 600, 450, 700, 500):
  Ventas del mes: 2250.00
  Comisión (5%):  112.50
  Bono:            50.00
  Retención (2%):   3.25
  Pago del mes:   159.25
 */

#include <stdio.h>

#define SEMANAS      4       // Cantidad de semanas del mes
#define TASA_COMISION 0.05   // 5 % de comisión sobre las ventas
#define TASA_RETENCION 0.02  // 2 % de retención sobre (comisión + bono)
#define BONO         50.0    // Bono fijo cuando las ventas superan el límite
#define LIMITE_BONO  2000.0  // Límite de ventas para recibir el bono

int main(void) {
    char nombre[50];             // Nombre del vendedor
    double ventas[SEMANAS];      // Ventas de cada una de las 4 semanas
    double ventasMes = 0.0;      // ACUMULADOR: total de ventas del mes
    double comision;             // Comisión calculada (5 %)
    double bono = 0.0;           // Bono (50 si ventasMes > 2000, sino 0)
    double retencion;            // Retención (2 % de comisión + bono)
    double pago;                 // Pago neto final
    int i;                       // Contador del ciclo for

    printf("=== Pago del vendedor ===\n");

    // Solicitar el nombre del vendedor
    printf("Nombre del vendedor: ");
    fgets(nombre, sizeof(nombre), stdin);
    
    for (i = 0; nombre[i] != '\0'; i++) {
        if (nombre[i] == '\n') {
            nombre[i] = '\0';
            break;
        }
    }

    // Solicitar las ventas de cada semana
    for (i = 0; i < SEMANAS; i++) {
        do {
            printf("Ventas de la semana %d: ", i + 1);
            scanf("%lf", &ventas[i]);
            if (ventas[i] < 0) {
                printf("  Error: la venta no puede ser negativa. Intente de nuevo.\n");
            }
        } while (ventas[i] < 0);

        ventasMes = ventasMes + ventas[i];   // Acumular ventas del mes
    }

    // Procesos
    comision = ventasMes * TASA_COMISION;

    if (ventasMes > LIMITE_BONO) {
        bono = BONO;
    }

    retencion = (comision + bono) * TASA_RETENCION;
    pago = comision + bono - retencion;

    // Mostrar resultados por pantalla
    printf("\n  ------- Pago de %s -------\n", nombre);
    for (i = 0; i < SEMANAS; i++) {
        printf("Semana %d:           %10.2f\n", i + 1, ventas[i]);
    }
    printf("Ventas del mes:      %10.2f\n", ventasMes);
    printf("Comision (5%%):       %10.2f\n", comision);
    printf("Bono:                %10.2f\n", bono);
    printf("Retencion (2%%):      %10.2f\n", retencion);
    printf("Pago del mes:        %10.2f\n", pago);

    return 0;
}