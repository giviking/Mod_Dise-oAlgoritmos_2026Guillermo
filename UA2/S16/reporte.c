// reporte.c - Programa con errores
#include <stdio.h>

 int main(void) {                       //1. int tiene que estar en minúscula
    printf("Reporte de ventas\n");       //2. Falta punto y coma al final de la línea
    printf("Total: 25000\n");           //3. Printf debe estar en minúscula
    printf("Gracias por su compra\n");  //4. Falta comilla de cierre
    return 0;
}                                       //5. Falta cierre de llave para la función main



//reporte.c:2:1: error: expected identifier or ‘(’ before numeric constant
//    2 | 2 #include <stdio.h>
//      | ^
//reporte.c:2:3: error: stray ‘#’ in program
//    2 | 2 #include <stdio.h>
//      |   ^
//reporte.c:7:10: warning: missing terminating " character
//    7 | 7 printf("Gracias por su compra\n);
//      |          ^
//reporte.c:7:10: error: missing terminating " character
//    7 | 7 printf("Gracias por su compra\n);
//      |          ^~~~~~~~~~~~~~~~~~~~~~~~~~
//
