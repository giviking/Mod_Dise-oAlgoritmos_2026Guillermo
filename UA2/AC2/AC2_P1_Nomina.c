/*
   Sistema de cálculo de nómina    |  AC2_P1_Nomina.c
 
   ENUNCIADO:
   Una empresa de consultoría necesita calcular el salario neto de sus empleados.
   El programa debe:
   1. Recibir el nombre completo del empleado (puede tener espacios; no se acepta un nombre vacío).
   2. Recibir el salario bruto, que debe ser mayor que 0; si no, muestra un mensaje y lo vuelve a pedir.
   3. Calcular los descuentos sobre el salario bruto:
      - CAJA (9.5 %)
      - IESS (2.5 %)
      - Impuesto sobre la renta (10 %, solo si el salario bruto supera 800).
   4. Calcular el salario neto (bruto menos todos los descuentos).
   5. Mostrar un comprobante con el nombre, el salario bruto, cada descuento y el salario neto,
      con dos decimales y los montos alineados.
  
   QUÉ SE LOGRA:
   Validar el nombre y el salario bruto, calcular correctamente los descuentos
   (incluyendo el impuesto condicional) y mostrar un comprobante ordenado.
  
   CÓMO SE LOGRA:
   - fgets para leer el nombre completo (con espacios).
   - strlen para verificar que el nombre no esté vacío.
   - do-while para validar que el salario bruto sea mayor que 0.
   - Constantes (#define) para las tasas y el límite de impuesto.
   - Cálculos con double y salida formateada con %.2f alineada.
  
   RESULTADO ESPERADO (datos: Maria Lopez, 1000):
   Salario bruto: 1000.00
   Descuento CAJA (9.5%): 95.00
   Descuento IESS (2.5%): 25.00
   Impuesto renta (10%):  100.00
   Salario neto:          780.00
 */

#include <stdio.h>
#include <string.h>   // Para strlen y strcspn

#define TASA_CAJA     0.095   // 9.5 % de descuento CAJA
#define TASA_IESS     0.025   // 2.5 % de descuento IESS
#define TASA_RENTA    0.10    // 10 % de impuesto sobre la renta
#define LIMITE_RENTA  800.0   // Límite a partir del cual se aplica el impuesto

int main(void) {
    char nombre[80];          // Nombre completo del empleado
    double salarioBruto;      // Salario bruto ingresado
    double descCaja;          // Descuento por Caja Costarricense del Seguro Social
    double descIess;          // Descuento por IESS
    double descRenta = 0.0;   // Descuento por impuesto sobre la renta (0 si no aplica)
    double salarioNeto;       // Salario neto final
    int i;                    // Variable auxiliar para limpiar el nombre

    printf("=== Calculo de nomina ===\n");

    // Leer y validar el nombre (no puede estar vacío)
    do {
        printf("Nombre del empleado: ");
        fgets(nombre, sizeof(nombre), stdin);

        // Eliminar el salto de línea que deja fgets
        nombre[strcspn(nombre, "\n")] = '\0';

        // Quitar espacios al inicio (por si solo presionó espacio)
        i = 0;
        while (nombre[i] == ' ') {
            i++;
        }
        if (i > 0) {
            // Mover el contenido hacia el inicio
            int j = 0;
            while (nombre[i] != '\0') {
                nombre[j++] = nombre[i++];
            }
            nombre[j] = '\0';
        }

        if (strlen(nombre) == 0) {
            printf("Error: el nombre no puede estar vacio. Intente de nuevo.\n");
        }
    } while (strlen(nombre) == 0);

    // Leer y validar el salario bruto (debe ser mayor que 0)
    do {
        printf("Salario bruto: ");
        scanf("%lf", &salarioBruto);

        if (salarioBruto <= 0) {
            printf("Error: el salario bruto debe ser mayor que 0. Intente de nuevo.\n");
        }
    } while (salarioBruto <= 0);

    // Cálculo de descuentos
    descCaja = salarioBruto * TASA_CAJA;
    descIess = salarioBruto * TASA_IESS;

    if (salarioBruto > LIMITE_RENTA) {
        descRenta = salarioBruto * TASA_RENTA;
    }

    // Cálculo del salario neto
    salarioNeto = salarioBruto - descCaja - descIess - descRenta;

    // Mostrar el comprobante con montos alineados
    printf("\n------- Comprobante de pago -------\n");
    printf("Empleado:               %s\n", nombre);
    printf("Salario bruto:          %10.2f\n", salarioBruto);
    printf("Descuento CAJA (9.5%%):  %10.2f\n", descCaja);
    printf("Descuento IESS (2.5%%):  %10.2f\n", descIess);
    printf("Impuesto renta (10%%):   %10.2f\n", descRenta);
    printf("Salario neto:           %10.2f\n", salarioNeto);

    return 0;
}