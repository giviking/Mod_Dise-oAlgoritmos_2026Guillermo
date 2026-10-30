//Caso integrador de la unidad 2 del curso Diseño de Algoritmos
//Enunciado: El sistema registra notas de un grupo de 16 estudiantes
//contiene un menú 1. Agregar (nota de 0 100 validarla). 2. Ver notas (cada una con aprobado si es 70 o más, o reprobado), 3. Estadisticas (Promedio, mayor y menos). y 0 para salir

#include <stdio.h>
#define MAX 16

//definicion de prototipos
//leer nota no recibe datos y devuelve una nota valida
double leerNota(void);

//Recibe el erreglo y dirección de la cantidad
void agregarNota(double notas[], int *cantidad);

//Mostar notas: recibe el erreglo y la cantidad por valor
void mostrarNotas(const double notas[], int cantidad);

//Calcula estadisticas: recibe el erreglo y cantidad, y tres punteros
void calcularEstadisticas(const double notas[], int cantidad, double *promedio, double *mayor, double *menor);

void limpiarEntrada(void);

int main(void){
    //arrelo de notas 16
    double notas[MAX];
    //cantidad de notas  guardadas y opcion del menu
    int cantidad = 0, opcion;

    //resultado de las estadisticas
    double promedio, mayor, menor;

    //Ciclo del menu para repetir hasta 0
    do {
        //mostrar el menu
        printf("\n1. Agregar 2. Ver notas 3. Estadisticas 0. Salir\n");
        //Pedir la opcion del menu
        printf("Opcion: ");
        //Leer opcion
        //ERROR (menu): antes era  scanf("%d", &opcion);  sin revisar si
        //   leyo algo. Con una letra (o la ",5" que sobraba de 65,5) scanf
        //   devuelve 0, opcion conserva su valor anterior y el texto sigue en
        //   el teclado: el menu se repetia sin fin.
        // CORRECCION: scanf devuelve cuantos datos leyo; si no es 1, se
        //   limpia el teclado y se pone una opcion invalida (-1) para que
        //   el switch muestre "Opcion invalida".
        if (scanf("%d", &opcion) != 1) {
            limpiarEntrada();
            opcion = -1;
        }
        //elige la rama segun la opcion
        switch (opcion) {
            //opcion 1 agregar
            case 1:
            agregarNota(notas, &cantidad);
            break;//sale del switch

            //lista de notas
            case 2:
            mostrarNotas(notas, cantidad);
            break;

            //estadisticas
            case 3:
            //revisa si no hay notas
            if (cantidad == 0){
                printf("No hay notas registradas\n");

            }else {
                //hacer la llamada que devuela 3 resultados.
                calcularEstadisticas(notas, cantidad, &promedio, &mayor, &menor);
                //mostrar resultados
                //ERROR: antes era  printf("Proemdio: %0.f ...")
                //   %0.f significa ancho 0 y precision 0 (CERO decimales):
                //   78.33 se mostraba como 78. Ademas "Proemdio" estaba mal escrito.
                // CORRECCION: %.2f muestra 2 decimales y se corrige el texto.
                printf("Promedio: %.2f Mayor: %.1f Menor: %.1f\n", promedio, mayor, menor);
            }
            break;
            //opcion cero para salir
            case 0:
            printf("Hasta luego\n");
            break;

            //Cualquier otra opcion que no sea del menu
            default:
            //Observacion: decia "Opcion invalidad" (error de escritura).
            printf("Opcion invalida\n");
        }
        //Repita mientas no se elija 0

    } while (opcion != 0);
    //termine con main
    return 0;
}

//definicion de leer nota repitiendo hasta  que nota este entre 0 y 100
double leerNota(void){
    double nota;
    //ciclo de validacion
    do {
        //pedir nota
        printf("Nota (0 a 100): ");
        //leer nota
        // ERROR  (nota): antes era  scanf("%lf", &nota);  sin revisar.
        //   En C el decimal se escribe con PUNTO. Con 65,5 scanf lee 65 y
        //   deja ",5" en el teclado; con una letra no lee nada y nota queda
        //   con basura. El texto sobrante dañaba las lecturas siguientes.
        // CORRECCION: si scanf no devuelve 1, o si despues del numero no
        //   viene el Enter (caso 65,5: sigue la coma), se avisa, se limpia
        //   el teclado y se pone nota = -1 para que el do-while la pida otra
        //   vez. Asi 65,5 no se guarda en silencio como 65.
        if (scanf("%lf", &nota) != 1 || getchar() != '\n') {
            printf("  Digite un numero; use punto decimal (ejemplo 65.5)\n");
            limpiarEntrada();
            nota = -1;
        // ERROR: el rango SI se validaba bien (nota < 0 || nota > 100),
        //   pero sin mensaje: con 105 solo volvia a salir "Nota (0 a 100):"
        //   y parecia que la habia aceptado. El usuario digitaba entonces la
        //   opcion del menu (por ejemplo 2) y ese 2 quedaba guardado como nota.
        // CORRECCION: avisar que la nota esta fuera de rango.
        } else if (nota < 0 || nota > 100) {
            printf("  Nota fuera de rango: debe estar entre 0 y 100\n");
        }
        //repite si esta fuera de rango
    } while (nota < 0 || nota > 100);
    //devuelve una nota valida
    return nota;
}

//Definicion agregar nota
void agregarNota(double notas[], int *cantidad){
    //reviasr si esta vacio
    if (*cantidad < MAX) {
        //guarde la nota
        notas[*cantidad] = leerNota();
        //aumentar la cantidad
        (*cantidad)++;
    } else {
        printf("El grupo ya tiene %d notas\n", MAX);
    }
}

//definicon patra mostrar notas
void mostrarNotas(const double notas[], int cantidad){
    //indice local para recorrer el arreglo
    int i;
    //for para recorrer las notas
    for (i = 0; i < cantidad; i++){
        //mostrar nuemro, nota y condicion
        // ERROR: antes era  printf("%2d. %5.lf %s\n", ...)
        //   En "%5.lf" el punto sin numero significa precision 0: la nota se
        //   muestra REDONDEADA sin decimales. 65.5 se veia como 66 y 69.5
        //   como 70 con "Reprobado" (porque el valor real 69.5 es < 70).
        //   La nota si estaba guardada bien; el problema era solo al mostrarla.
        // CORRECCION: %5.1f muestra 1 decimal (65.5, 69.5, 100.0).
        printf("%2d. %5.1f %s\n", i + 1, notas[i], notas[i] >= 70 ? "Aprobado" : "Reprobado");
    }
}

//Definicon de calcular estad´siticas
void calcularEstadisticas(const double notas[], int cantidad, double *promedio, double *mayor, double *menor) {
    //Acumulador local
    double suma = 0;
    //indice local para recorrer el erreglo
    int i;
    //se supone que la primera nota es mayor
    // ERROR: antes solo estaba  *menor = notas[0];  y *mayor NUNCA se
    //   iniciaba: la primera comparacion (notas[i] > *mayor) se hacia contra
    //   un valor basura de main. A veces funciona y a veces no.
    // CORRECCION: el mayor Y el menor empiezan con la primera nota.
    *mayor = notas[0];
    *menor = notas[0];
    //for para recorrer las notas
    for (i = 0; i < cantidad; i++){
        //suma la nota
        suma += notas[i];
        //compare con el mayor
        if (notas[i] > *mayor){
            //guarde el nuevo mayor
            *mayor = notas[i];
        }
        // ERROR 6: faltaba comparar con el menor. Por eso el menor siempre
        //   era la primera nota (con 50 y 40 mostraba Menor: 50).
        // CORRECCION: igual que el mayor, pero con <.
        if (notas[i] < *menor){
            //guarde el nuevo menor
            *menor = notas[i];
        }
    }
    //calcule el promedio
    *promedio = suma / cantidad;
}

// NUEVO: definicion de limpiarEntrada.
//   getchar lee un caracter a la vez; el ciclo descarta todo lo que quedo
//   escrito hasta el Enter ('\n') o hasta el fin de la entrada (EOF).
void limpiarEntrada(void){
    //caracter leido; es int porque EOF no cabe en un char
    int c;
    //descarta caracteres hasta el Enter
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}
