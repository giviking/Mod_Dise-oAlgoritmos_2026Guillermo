//ENUNCIADO: Una empresa de mensajería registra los paquetes del día (de 1 a 10). 
// De cada uno se digita el código (una palabra), la zona de destino (1 GAM 2500, 2 Rural 3500, 3 Costas 4000; el precio incluye 1 kg) 
// y el peso en kg (de 0.1 a 30, con decimales); un dato inválido se vuelve a pedir. 
// Cada kg adicional, o fracción, cuesta 900. Si el paquete pesa más de 20 kg se cobra un recargo del 15 %. 
// Mostrar una tabla con código, peso y costo, el total del día, el envío más caro y cuántos tuvieron recargo.

#include <stdio.h>
#include <math.h> // Necesario para usar la función ceil() que redondea hacia arriba los kilos extra

// Definir constantes para que el código sea fácil de leer y modificar
#define MAX_PAQUETES 10
#define PRECIO_GAM 2500.0
#define PRECIO_RURAL 3500.0
#define PRECIO_COSTAS 4000.0
#define COSTO_KG_EXTRA 900.0
#define UMBRAL_RECARGO 20.0
#define TASA_RECARGO 0.15

// PROTOTIPOS DE FUNCIONES (el índice de lo que va a hacer el programa más adelante)
int leerEntero(const char mensaje[], int minimo, int maximo);
float leerFlotante(const char mensaje[], float minimo, float maximo);
double precioBaseZona(int zona);
double calcularCostoPaquete(int zona, float peso);
void resumir(const float pesos[], const double costos[], int n, double *totalDia, int *posMayor, int *conRecargo);

int main(void) {
    // Definir arreglos para guardar los datos de hasta 10 paquetes
    char codigos[MAX_PAQUETES][15]; // Cada código puede tener hasta 14 letras + el fin de cadena '\0'
    int zonas[MAX_PAQUETES];       // Zona de destino de cada paquete
    float pesos[MAX_PAQUETES];     // Peso en kg de cada paquete
    double costos[MAX_PAQUETES];   // Costo total calculado de cada paquete
    
    int n, i, zonaActual;
    double totalVendido;           // Aquí guardaremos el total del día usando punteros
    int posMayor, conRecargo;      // Posición del paquete más caro y cantidad de paquetes con recargo

    // Título principal y guía de zonas para el usuario
    printf("===== Empresa de Mensajeria =====\n");
    printf("Zonas: 1. GAM (2500), 2. Rural (3500), 3. Costas (4000)\n");

    // Leer la cantidad de paquetes a registrar (validando que sea de 1 a 10)
    n = leerEntero("Cantidad de paquetes del dia", 1, MAX_PAQUETES);

    // CICLO FOR: se repite una vez por cada paquete que vamos a registrar
    for (i = 0; i < n; i++) {
        printf("\nPaquete %d\n", i + 1);
        
        // Pedir el código del paquete
        printf(" Codigo: ");
        scanf("%14s", codigos[i]);
        
        // Limpiar el teclado para evitar que queden letras o espacios basuras
        int c; 
        while ((c = getchar()) != '\n' && c != EOF);

        // Leer y validar la zona (debe ser 1, 2 o 3)
        zonaActual = leerEntero(" Zona (1-3)", 1, 3);
        zonas[i] = zonaActual;

        // Leer y validar el peso (con decimales, entre 0.1 y 30.0 kg)
        pesos[i] = leerFlotante(" Peso en kg (0.1 - 30.0)", 0.1f, 30.0f);

        // Calcular el costo de este paquete usando la función y guardarlo en el arreglo
        costos[i] = calcularCostoPaquete(zonas[i], pesos[i]);
    }

    // Calcular el resumen final de un solo golpe usando punteros (&)
    resumir(pesos, costos, n, &totalVendido, &posMayor, &conRecargo);

    // Mostrar el encabezado de la tabla de resultados
    printf("\n%-12s%10s%12s\n", "Codigo", "Peso(kg)", "Costo");
    printf("------------------------------------\n");

    // CICLO FOR solo para imprimir la tabla (lo único que se repite fila por fila)
    for (i = 0; i < n; i++) {
        printf("%-12s%10.1f%12.2f\n", codigos[i], pesos[i], costos[i]);
    } 

    // Imprimir los resultados finales del resumen fuera del ciclo
    printf("\nTotal vendido del dia:    %12.2f\n", totalVendido);
    printf("Envio mas caro:           %s (%.2f)\n", codigos[posMayor], costos[posMayor]);
    printf("Paquetes con recargo:     %d paquete(s)\n", conRecargo);

    return 0; // Fin del programa con éxito
}

// ===========================
// DEFINICIÓN DE LAS FUNCIONES 
// ===========================

// Función para leer y validar números enteros (como la cantidad o la zona)
int leerEntero(const char mensaje[], int minimo, int maximo) {
    int valor;
    int c;
    do {
        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        if (scanf("%d", &valor) != 1) {
            // Si escriben letras en lugar de un número, limpiamos la entrada
            while ((c = getchar()) != '\n' && c != EOF);
            valor = minimo - 1; // Forzamos a que falle para que vuelva a preguntar
        }
    } while (valor < minimo || valor > maximo);
    return valor;
}

// Función nueva para leer y validar números con decimales (como el peso)
float leerFlotante(const char mensaje[], float minimo, float maximo) {
    float valor;
    int c;
    do {
        printf("%s (%.1f a %.1f): ", mensaje, minimo, maximo);
        if (scanf("%f", &valor) != 1) {
            // Si escriben texto en vez de número decimal, limpiamos la entrada
            while ((c = getchar()) != '\n' && c != EOF);
            valor = minimo - 1.0f; // Forzamos a repetir la pregunta
        }
    } while (valor < minimo || valor > maximo);
    return valor;
}

// Función para saber el precio base según la zona elegida
double precioBaseZona(int zona) {
    switch (zona) {
        case 1:
            return PRECIO_GAM;    // Zona 1: 2500
        case 2:
            return PRECIO_RURAL;   // Nota: Usamos PRECIO_RURAL equivalente
        default:
            return PRECIO_COSTAS; // Zona 3: 4000
    }
}

// Función principal para calcular el costo de cada paquete con sus reglas especiales
double calcularCostoPaquete(int zona, float peso) {
    // 1. Obtener el precio base (que ya incluye el primer kilo)
    double base = 0.0;
    if (zona == 1) base = PRECIO_GAM;
    else if (zona == 2) base = PRECIO_RURAL;
    else base = PRECIO_COSTAS;

    double subtotal = base;

    // 2. Si pesa más de 1 kg, cada kilo adicional o fracción se cobra a 900
    if (peso > 1.0f) {
        // ceil() redondea hacia arriba (ej: si pasa por un poquito, cuenta como un kilo entero extra)
        int kgAdicionales = (int)ceil(peso - 1.0f);
        subtotal += kgAdicionales * COSTO_KG_EXTRA;
    }

    // 3. Si pesa más de 20 kg, se le aplica un recargo del 15% sobre el subtotal
    if (peso > UMBRAL_RECARGO) {
        subtotal = subtotal + (subtotal * TASA_RECARGO);
    }

    return subtotal;
}

// Función de resumen que modifica las variables originales usando punteros (*)
void resumir(const float pesos[], const double costos[], int n, double *totalDia, int *posMayor, int *conRecargo) {
    int i;
    
    // Inicializamos las variables que están en el main a través de sus punteros
    *totalDia = 0;
    *posMayor = 0;
    *conRecargo = 0;

    // Recorremos todos los paquetes para acumular y comparar
    for (i = 0; i < n; i++) {
        // Sumar al total del día
        *totalDia += costos[i];

        // Buscar cuál fue el envío más caro
        if (costos[i] > costos[*posMayor]) {
            *posMayor = i; // Guardamos la posición del más caro
        }

        // Contar cuántos paquetes pesaron más de 20 kg (tuvieron recargo)
        if (pesos[i] > UMBRAL_RECARGO) {
            (*conRecargo)++;
        }
    }
}





