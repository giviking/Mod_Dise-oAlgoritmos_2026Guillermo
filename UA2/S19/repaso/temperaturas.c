#include <stdio.h>

// Definicion de constantes
#define DIAS 7
#define MINIMA -10
#define MAXIMA 45

int main(void) {

    //Deifinicion de variables
    int temp;
    int suma = 0;
    int maxima = MINIMA;
    int calurosos = 0;
    int i;
    float promedio;

    printf("=== Temperaturas de la semana ===\n");

    //proceso
    for (i = 0; i < DIAS; i++) {
        do {
            printf("Temperatura dia %d: ", i + 1);
            scanf("%d", &temp);

            if (temp < MINIMA || temp > MAXIMA) {
                printf("  Fuera de rango (%d a %d)\n", MINIMA, MAXIMA);
            }
        } while (temp < MINIMA || temp > MAXIMA);

        suma = suma + temp;

        if (temp > maxima) {
            maxima = temp;
        }

        if (temp > 30) {
            calurosos++;
        }
    }

    promedio = (float)suma / DIAS;

    //Presentacion de la informacion
    printf("\nPromedio: %.1f grados\n", promedio);
    printf("Maxima: %d grados\n", maxima);
    printf("Dias calurosos: %d\n", calurosos);

    return 0;
}


/*

Ejercicio Original

temperaturas.c (con errores)
 1  // temperaturas.c - Temperaturas de una semana
 2  // ENUNCIADO: pedir la temperatura (grados enteros) de cada uno de los 7
 3  //   dias de la semana. Un dato fuera del rango -10 a 45 se rechaza y se
 4  //   vuelve a pedir para el mismo dia. Al final mostrar el promedio con un
 5  //   decimal, la temperatura maxima y cuantos dias fueron calurosos (mas
 6  //   de 30 grados).
 7  // QUE SE LOGRA: validar cada dato y resumir la semana en tres resultados.
 8  // COMO SE LOGRA: un for de 7 vueltas (un dia por vuelta); dentro, un
 9  //   do-while que repite la pregunta mientras el dato sea invalido; un
10  //   acumulador para la suma, una comparacion para la maxima y un contador
11  //   para los dias calurosos; el promedio se calcula con casting a float.
12  // RESULTADO ESPERADO: con 28 31 50 29 33 27 30 26 -> el 50 se rechaza,
13  //   Promedio: 29.1 grados, Maxima: 33 grados, Dias calurosos: 2
14  #include <stdio.h>                    // printf y scanf
15  #define DIAS 7                        // cantidad de dias de la semana
16  #define MINIMA -10                    // menor temperatura aceptada
17  #define MAXIMA 45                     // mayor temperatura aceptada
18   
19  int main(void) {
20      int temp;              // temperatura digitada para un dia
21      int suma = 0;          // ACUMULADOR: suma de las temperaturas validas
22      int maxima = MINIMA;   // mayor temperatura (inicia en el minimo posible)
23      int calurosos = 0;     // CONTADOR de dias con mas de 30 grados
24      int i;                 // contador del for: dia actual (0 a 6)
25      float promedio;        // promedio de la semana, con decimales
26   
27      printf("=== Temperaturas de la semana ===\n");
28      // FOR: una vuelta por dia -> i = 0, 1, ..., 6
29      for (i = 1; i < DIAS; i++) {
30          // DO-WHILE: pide el dato y lo repite mientras este fuera de rango
31          do {
32              printf("Temperatura dia %d: ", i + 1);
33              scanf("%d", temp);
34              if (temp < MINIMA || temp > MAXIMA)
35                  printf("  Fuera de rango (%d a %d)\n", MINIMA, MAXIMA);
36          } while (temp >= MINIMA && temp <= MAXIMA)
37   
38          suma = suma + temp;           // acumula -> 28, 59, 88, ...
39          if (temp > maxima)            // guarda la mayor -> 33
40              maxima = temp;
41          if (temp > 30);               // cuenta los calurosos -> 31 y 33
42              calurosos++;
43      }
44   
45      promedio = suma / DIAS;           // 204 / 7 -> 29.142857
46      printf("\nPromedio: %.1f grados\n", promedio);
47      printf("Maxima: %d grados\n", maxima);
48      printf("Dias calurosos: %d\n", calurosos);
49      return 0;
50  }






*/
