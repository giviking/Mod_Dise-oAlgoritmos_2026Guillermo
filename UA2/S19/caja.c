//caja.c - Caja registradora con menu
#include <stdio.h>

int main(void) {
    //declaracion de variables
    int opcion;              //opcion elegida en el menu
    int productos = 0;       //CONTADOR de productos de la venta
    double precio;           //precio para cada producto
    double total = 0;        //ACUMULADOR de la venta

    //DO ... WHILE: El menu se muestra al menos una vez
    do {
        //mostrar el menu y lee la opcion -> 1
        printf("\n1. Agregar 2. Ver total 3. Cobrar 0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        //SWITCH: (segun): salta al case que coincida con la opcion elegidas
        switch (opcion) {
            case 1:
            //validacion: reite mientras el precio no sea positivo
            do {
                printf("Precio del producto: ");
                scanf("%lf", &precio); //-> 1500 (-200)
                if (precio <= 0) {
                    printf("Precio invalido\n");
                }

            } while (precio <= 0);
            productos++; //cuenta productos
            total += precio; //suma el precio
            break;           //Sale del switch
            case 2:
            //Muestra el avance -> Productos: 2 Total 4000
            printf("Productos: %d Total: %.2f\n", productos, total);
            break;
            case 3:
            //Cobra y reinicia el contador y acumulador
            printf("Cobrado: %.2f. Nueva veta \n", total);
            productos = 0;
            total = 0;
            break;
            case 0:
            printf("Caja Cerrada\n");
            break;
            default:
            //Ningun case coincide -> 9
            printf("Opcion invalida\n");
        }
        //Repita el menu mientras no se elija 0

    }while (opcion != 0);
    return 0;    
}