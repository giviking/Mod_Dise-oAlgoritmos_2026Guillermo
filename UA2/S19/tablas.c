//tablas.c resuelve la tabla del 7 para varios numeros
#include <stdio.h>

#define CENTINELA 0 // el 0 indica que no hay tablas

int main(void) {
    //declaracion de variables
    int numero, i;
    int tablas = 0;

    //LECTURA PREVIA: El primer numero se lee antes del while -> 7
    printf("Numero de la tabla (0 para terminar): ");
    scanf("%d", &numero);

    //WHILE con centinela: repite mientras en numero no sea 0
    while (numero != CENTINELA) {
        //FOR anidado: 10 vueltas por cada numero -> = 1, 2 ..., 10
        for (i = 1; i <= 10; i++) {
            //%2d alinea en 2 espacios -> 7 x 1 = 7 ... 7 x 10 = 70
            printf("%d x %2d = %2d\n", numero, i, numero * i);
        }
        tablas++; //cuenta la tabla mostada -> 1 luego 2
        //siguiente dato al fina del cuerpo -> 3, luego 0
        printf("Numero de la tabla (0 para terminar); ");
        scanf("%d", &numero);
    }
    //Despues del while (se digito 0) -> tablas mostradas 2
    printf("Tablas mostradas: %d\n", tablas);
    
    return 0; //terminar sin errores
}