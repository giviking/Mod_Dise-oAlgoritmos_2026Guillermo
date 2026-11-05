/*============================================================================
                         correccion1_puntos.c
Enunciado: Un comercio da 1 punto por cada 1000 colones de compra. El programa
           lee 3 compras, suma los puntos de cada una con la función 
           sumarPuntos y muestra el total. 

------------------------------------------------------------------------------

Datos de prueba: Compras 5000, 12500 y 800 
Resultado esperado: Puntos acumulados: 17 (5 + 12 + 0)

------------------------------------------------------------------------------

  Se compila con: 
  gcc -std=c11 -Wall -Wextra correccion1_puntos.c -o correccion1_puntos

  ------------------Mensaje de Errores del compilador-------------------------
  
  correccion1_puntos.c: In function 'main':
  correccion1_puntos.c:11:17: warning: format '%d' expects argument of type 
  'int *', but argument 2 has type 'int' [-Wformat=]
   11 |         scanf("%d", compra);
      |                ~^   ~~~~~~
      |                 |   |
      |                 |   int
      |                 int *
correccion1_puntos.c:11:9: warning: 'compra' may be used uninitialized 
[-Wmaybe-uninitialized]
   11 |         scanf("%d", compra);
      |         ^~~~~~~~~~~~~~~~~~~
correccion1_puntos.c:8:21: note: 'compra' was declared here
    8 |     int puntos = 0, compra, i;
      |                     ^~~~~~
------------------ Ejecucion con el problema de logica -----------------------
$ ./correccion1_puntos.exe
Compra 1: 5000
Compra 2: 12500
Compra 3: 800
Puntos acumulados: 0

------------------ Ejecución con las correcciones ---------------------------
$ ./correccion1_puntos.exe
Compra 1: 5000
Compra 2: 12500
Compra 3: 800
Puntos acumulados: 17

============================================================================*/


#include <stdio.h>
//ERROR: no esta sumando los puntos 
//POR QUE: hacer falta el * en puntos para defirnir el puntero
//CORRECCIÓN: se agrega * a puntos
void sumarPuntos(int *puntos, int compra) { //se agrega * a puntos *puntos
    *puntos = *puntos + compra / 1000;
}

int main(void) {
    int puntos = 0, compra, i;
    for (i = 1; i <= 3; i++) {
        printf("Compra %d: ", i);
        //ERROR: falta el especificador & en el scanf
        //POR QUE: scanf lo necesita para poder almacenar el dato en la variable
        //CORRECCIÓN: se añade & a la variable compra: &compra
        scanf("%d", &compra);            //falta el & en compra:   &compra
         //ERROR: falta el especificador & en puntos
        //POR QUE: la funcion lo necesita para poder almacenar el dato en la variable
        //CORRECCIÓN: se añade & a puntos: &puntos
        sumarPuntos(&puntos, compra);
    }
    printf("Puntos acumulados: %d\n", puntos);
    return 0;
}



