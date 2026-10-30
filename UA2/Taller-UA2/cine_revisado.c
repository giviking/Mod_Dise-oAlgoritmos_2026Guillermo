//ENUNCIADO: Un cine registra las compras de una funcion (de 1 a 10). De cada compra se dugita el nombredel cliente (una palabra), el tipo de entrada (1. general 3500. 2. Nino 2500. 3. Adulto mayor 2000) y la cantidad de entradas (1 a 8). Un dato inválido se vuelve a pedir. Si se comparn 5 o más entradas tienen descuento de 10%. Mostrar: una tabla con cliente, las entradas y el total de cada compra, total vendido, compara mayor y cunatas tuvieros descuento.
#include <stdio.h>
//definir constantes
#define MAX_COMPRAS 10
#define PRECIO_GENERAL 3500.0
#define PRECIO_NINO 2500.0
#define PRECIO_MAYOR 2000.0
//OBSERVACION 1: el nombre MIN_DECUENTO esta mal escrito (DESCUENTO) y TAZA_DESCUENTO deberia ser TASA_DESCUENTO.
//No es un error de calculo: como se escribe igual en todas partes, funciona. Es solo de redaccion.
#define MIN_DECUENTO 5
#define TAZA_DESCUENTO 0.10

//PROTOTIPOS DE FUNCIONES
int leerEntero(const char mensaje[], int minimo, int maximo);
double precioEntrada(int tipo);
double calcularTotal(int tipo, int cantidad);
void resumir(const int cant[], const double tot[], int n, double *total, int *posMayor, int *conDescuento);

int main(void) {
    //definir arreglos y variables
//OBSERVACION 2: 15 caracteres = 14 letras + el '\0'. Un nombre mas largo no cabe (ver ERROR 2 en la linea del scanf).
    char clientes[MAX_COMPRAS][15]; //Nombres de los CLIENTES DE LA COMPRA
    int cantidades[MAX_COMPRAS]; //Cantidad de compras posibles 10
    double totales[MAX_COMPRAS]; //total de cada compra
    //cantidad de compras, indice y el tipo de entrada
    int n, i, tipo;
    //cantidad de compras
    double totalVendido;
    //resultados resumen
    int posMayor, conDescuento;

//Titulo y lista de tipos
printf("===== Venta de Entradas =====\n");
printf("Tipos: 1. General 3500, 2. Nino 2500, 3. Adulto mayor 2000\n");

//Leer cantidad de compras -> 4
n = leerEntero("Cantidad de compras", 1, MAX_COMPRAS);

//FOR para una vuelta por compra
for (i = 0; i < n; i++) {
printf("Compra %d\n Cliente: ", i + 1);//numero de compra y pedido de cliente
//ERROR 1: scanf("%14s") solo toma 14 letras; las que sobran se quedan en el teclado y la siguiente lectura (el %d de leerEntero) las intenta leer como numero.
//Con un nombre de mas de 14 letras, Tipo y Entradas no se piden bien y la compra sale con datos equivocados (y por eso puede perder el descuento).
//Correccion: limpiar el resto de la linea despues del scanf, con:  int c; while ((c = getchar()) != '\n' && c != EOF);
scanf("%14s", clientes[i]);
int c; while ((c = getchar()) != '\n' && c != EOF);
//leer el tipo de entrada
tipo = leerEntero(" Tipo", 1, 3); //valida 
//leer cantidad de entradas
cantidades[i] = leerEntero(" Entradas", 1, 8); //valida 

//calcular el total de la compra
totales[i] = calcularTotal(tipo, cantidades[i]);

}
//Calcular el resumen en UNA pasada
resumir(cantidades, totales, n, &totalVendido, &posMayor, &conDescuento);

//encabezado de al tabla

//ERROR 2 (YA CORREGIDO en la linea de abajo): el formato %12.2s cortaba el texto a 2 letras y mostraba 'To' en vez de 'Total'. Ahora es %12s.
printf("\n%-12s%9s%12s\n", "Cliente", "Entradas", "Total");
//recorrer las compras
//ERROR 3 la llave { de este for se cerraba
//   ANTES del "}" final de main, despues del return 0. Asi, el resumen y el
//   return 0 quedaban DENTRO del ciclo: en la primera vuelta (i = 0) imprimia
//   la fila de Ana, luego el resumen, y el return 0 terminaba el programa.
//   La segunda vuelta (i = 1, Luis) nunca se ejecutaba.
// CORRECCION: la llave } del for se cierra justo despues del printf de la fila.
//   Dentro del for solo va lo que se repite (una fila por compra); el resumen
//   y el return 0 van FUERA, una sola vez.
// Leccion: el error no lo detecta el compilador (no da advertencia); se descubre
//   probando con datos conocidos y comparando con el resultado esperado.
for (i = 0; i < n; i++) {
//mostrar fila (lo UNICO que se repite: una fila por compra)
printf("%-12s%9d%12.2f\n", clientes[i], cantidades[i], totales[i]);
}   //AQUI se cierra el for (antes estaba despues del return 0)

//total vendido
printf("Total vendido:      %12.2f\n", totalVendido);
//compra mayor
printf("Compra Mayor:       %s (%.2f)\n", clientes[posMayor], totales[posMayor]);
//Compras con descuento
printf("Con descuento:     %d compra(s)\n", conDescuento);
//termina main con el return por valor (FUERA del for)
return 0;
}   //cierre de main

//Definiciones. Leer entero
int leerEntero(const char mensaje[], int minimo, int maximo){
    int valor;
    int c;
    do {
        printf("%s (%d a %d): ", mensaje, minimo, maximo);
        if (scanf("%d", &valor) != 1) {
            /* No se escribio un numero: se descarta el resto de la linea */
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            valor = minimo - 1; /* fuerza a que se repita la pregunta */
        }
    } while (valor < minimo || valor > maximo);
    return valor;
}

//Definicion precioEntrada
double precioEntrada(int tipo){
    switch (tipo){
        case 1:
        return PRECIO_GENERAL;//retunr termina la funcion no hace falta el breack

        case 2:
        return PRECIO_NINO;

        default:
        return PRECIO_MAYOR;

    }
}

//DEFINICION DE CALCULAR TOTAL

double calcularTotal(int tipo, int cantidad) {
    double total = precioEntrada(tipo) * cantidad;

    if (cantidad >= MIN_DECUENTO)
    total = total * (1 -TAZA_DESCUENTO);

    return total;
}

//Definir resumir
void resumir(const int cant[], const double tot[], int n, double *total, int *posMayor, int *conDescuento){
    int i;
    //inicializo los tres resultados en la memoria de main
    *total = 0;
    *posMayor = 0;
    *conDescuento = 0;

    //recorrer las compras
    for (i = 0; i < n; i++){
        *total += tot[i];
        //comparar la compra mayor
        if (tot[i] > tot[*posMayor])
        *posMayor = i;

        if (cant[i] >= MIN_DECUENTO)
        (*conDescuento)++;
    }
}





