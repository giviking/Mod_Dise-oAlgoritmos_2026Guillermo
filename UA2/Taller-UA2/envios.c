/*
 * Archivo: envios.c
 * Problema: Cobro de envios de paquetes
 * Descripcion: Registra paquetes del dia (1 a 10), calcula el tarifa segun la zona, 
 *              peso adicional por kg/fraccion y recargo por peso mayor a 20kg.
 * Compilacion: gcc -Wall -Wextra envios.c -o envios -lm
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

#define PRECIO_GAM 2500
#define PRECIO_RURAL 3500
#define PRECIO_COSTAS 4000
#define COSTO_KG_EXTRA 900
#define LIMITE_PESO_RECARGO 20.0
#define PORC_RECARGO 0.15

typedef struct {
    char codigo[30];
    int zona;
    float peso;
    float costo;
} Paquete;

// Prototipos de funciones
float calcular_costo(int zona, float peso);

int main(void) {
    int n = 0;
    Paquete paquetes[10];
    float total_dia = 0.0;
    float max_costo = -1.0;
    char codigo_mas_caro[30] = "";
    int cant_recargo = 0;

    // Lectura y validacion de la cantidad de paquetes
    do {
        printf("Ingrese la cantidad de paquetes del dia (1 a 10): ");
        scanf("%d", &n);
    } while (n < 1 || n > 10);

    // Procesamiento de paquetes
    for (int i = 0; i < n; i++) {
        printf("\n--- Paquete %d ---\n", i + 1);
        printf("Codigo: ");
        scanf("%s", paquetes[i].codigo);

        do {
            printf("Zona (1-GAM, 2-Rural, 3-Costas): ");
            scanf("%d", &paquetes[i].zona);
        } while (paquetes[i].zona < 1 || paquetes[i].zona > 3);

        do {
            printf("Peso en kg (0.1 a 30): ");
            scanf("%f", &paquetes[i].peso);
        } while (paquetes[i].peso < 0.1f || paquetes[i].peso > 30.0f);

        // Calculo de costo individual
        paquetes[i].costo = calcular_costo(paquetes[i].zona, paquetes[i].peso);
        total_dia += paquetes[i].costo;

        if (paquetes[i].peso > LIMITE_PESO_RECARGO) {
            cant_recargo++;
        }

        if (paquetes[i].costo > max_costo) {
            max_costo = paquetes[i].costo;
            strcpy(codigo_mas_caro, paquetes[i].codigo);
        }
    }

    // Reporte final / Tabla
    printf("\n=========================================\n");
    printf("%-12s %-10s %-12s\n", "Codigo", "Peso (kg)", "Costo (CRC)");
    printf("-----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-12s %-10.1f %-12.2f\n", paquetes[i].codigo, paquetes[i].peso, paquetes[i].costo);
    }
    printf("=========================================\n");
    printf("Total del dia: CRC %.2f\n", total_dia);
    printf("Envio mas caro: %s (CRC %.2f)\n", codigo_mas_caro, max_costo);
    printf("Cantidad de envios con recargo: %d\n", cant_recargo);

    return 0;
}

float calcular_costo(int zona, float peso) {
    float base = 0.0;
    
    switch (zona) {
        case 1: base = PRECIO_GAM; break;
        case 2: base = PRECIO_RURAL; break;
        case 3: base = PRECIO_COSTAS; break;
    }

    float subtotal = base;
    if (peso > 1.0f) {
        int kg_adicionales = (int)ceil(peso - 1.0f);
        subtotal += kg_adicionales * COSTO_KG_EXTRA;
    }

    if (peso > LIMITE_PESO_RECARGO) {
        subtotal += subtotal * PORC_RECARGO;
    }

    return subtotal;
}