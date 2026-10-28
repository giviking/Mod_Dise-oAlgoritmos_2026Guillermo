/*
   El ejemplo del profe en clase, se envio en la materia
   S22_Presentacion_Parametros_punteros.pdf
   Leer y cambiar a través de un puntero
*/

#include <stdio.h>

int main(void) {
    int edad = 20;
    int *p = &edad;             // p guarda la direccion
    printf("edad = %d\n", edad);
    printf("*p   = %d\n", *p);  // lee lo que hay alli
    *p = 21;                    // cambia edad a traves de p
    
    printf("edad = %d\n", edad);
    
    return 0;
}