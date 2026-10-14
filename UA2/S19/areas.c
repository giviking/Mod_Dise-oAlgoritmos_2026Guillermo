/* Ejercicio 4 | areas.c | Se calculan varias areas en una misma ejecucion,
   eligiendo la figura en menu. | Se usan switch con case, break y default 
   dentro de un do ... while. Constante PI con #define.                    */

#include <stdio.h>

//Declaracion de PI como una constante
#define PI 3.141592653589793

int main(void) {

    //Declaracion de variables
    int opcion;
    double lado, base, altura, radio, area;

    //Proceso con el Do

    do {
        printf("\n1. Cuadrado  2. Rectangulo  3. Circulo  0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        //Se usa el switch donde muestran las distintas opciones
        switch (opcion) {
            case 1:
                printf("Lado: ");
                scanf("%lf", &lado);
                area = lado * lado;
                printf("Area: %.2f\n", area);
                break;

            case 2:
                printf("Base: ");
                scanf("%lf", &base);
                printf("Altura: ");
                scanf("%lf", &altura);
                area = base * altura;
                printf("Area: %.2f\n", area);
                break;

            case 3:
                printf("Radio: ");
                scanf("%lf", &radio);
                area = PI * radio * radio;
                printf("Area: %.2f\n", area);
                break;

            case 0:
                printf("Hasta luego\n");
                break;

            default:
                printf("Opcion invalida\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}
