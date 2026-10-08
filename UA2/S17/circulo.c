//circulo.c trabaja con la constante de PI
#include <stdio.h>
#define PI 3.14159265358979  //Constante simbolica: el procesador cambia PI por el numero
int main(void) {
    //Constante de cadena: no puede cambiar durante el programa
    const char UNIDAD[] = "cm";
    //Variables reales para el radio y los resultados
    double radio, area, perimetro;

    //ENTRADA: lee el radio -> radio = 4
    printf("Radio del circulo (cm): ");
    scanf("%lf", &radio);

    //PROCESO: En C no existe ^; radio al cuadrado = radio * radio -> 50.27
    area = PI * radio * radio;

    //Perimetro = 2 * PI * radio -> 25.13
    perimetro = 2 * PI * radio;

    //SALIDA: %2.f muestra 2 decimales y %s muestra la cadena UNIDAD
    printf("Area: %.2f %s2\n", area, UNIDAD);
    printf("Perimetro: %.2f %s\n", perimetro, UNIDAD);
    return 0;

}
