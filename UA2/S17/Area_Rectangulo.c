//area.c - saca el area de un rectangulo

#include <stdio.h>

int main(void) {
    //declarar variables
    double base, altura, area;

    //Entada de datos, lee la base = 5
    printf("Digite la base del rectangulo (cm): ");
    scanf("%lf", &base);

    //mensaje y lee altura que va a ser = 3
    printf("Digite la alura del rectangulo (cm) :");
    scanf("%lf", &altura);

    //Proceso: multiplica y guarda el resultado = 15
    

    area = base * altura;

    //Salida: muestra el area con 2 decimales
    printf("El area del rectangulo es %.2f cm2\n", area);
    return 0;
}