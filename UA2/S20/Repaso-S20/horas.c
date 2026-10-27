//horas.c - Horas de estudio a la semana
/*ENUNCIADO: Registrar las horas de estudio de 3 estudiantes de lunes a jueves
Se digite el nombre y las horas de estudio de cada día.
Mostrar una tabla con el total de cada estudiante, quien estudio más, el día con mas horas y buscar a una persona del grupo por su nombre*/

#include <stdio.h>  //Entradas y salidas
#include <string.h> //Manipulación de texto

//Definir constantes
#define EST 3       //Filas de la matriz
#define DIAS 4      //Columnas de la matriz

int main(void){
    //ARREGLO DE CADENAS para los 3 nombres
    char nombres [EST][15];//DE LOS 15 CARACTERES 14 SON PARA EL NOMBRE Y 1 para '/0' (fin de linea)

    //MATRIZ de horas: 3 filas para estudiantes y 4 columnas para los días
    int horas [EST][DIAS];

    //ARREGLO DE CADENAS: CON LOS NOMBRES CORTOS DE LOS DÍAS
    char dias[DIAS][4] = {"Lun", "Mar", "Mie", "Jue"};
    //Se crean los indices de fila y columnas
    int e;
    int d;

    //ARREGLO: total por estudiante. total[e] es la suma de la fila e. Guardar y buscar al mayor
    int total[EST];

    //POSICIÓN: de quien estudio mas
    int mejor;

    //ACUMULADO de columna (horas del grupo en un día)
    int sumaDia;

    //suma mayor de dia
    int sumaMayor;

    //POSICION: dia con mas horas
    int diaMejor;

    //cadena con el nombre a buscar
    char buscado[15];

    //POSICION donde aparece el nombre buscado
    int encontrado;

    // ========== LECTURA con los for anidados ==========
    //ciclo externo: una vuelta por estudiante (fila).

    for (e = 0; e < EST; e++){
        //pedimos nombre del estudiante
        printf("Nombre del estudiante %d:", e + 1);
        //leer una palabra en la fila de nombres
        scanf("%14s", nombres[e]); //No requiere & ya que el arreglo ya le da la dirección

        //ciclo interno una vuelta por dia
        for (d = 0; d < DIAS; d++){
            //pedir las horas del dia
            printf("Horas del %s: ", dias[d]);
            scanf("%d", &horas[e][d]);
        }
    }
    
    //================= TABLA =================
    //Con encabezado con la palabra "Nombre"
    printf("\n%-8s", "Nombre");

    //FOR para recorrer los dias para el encabezado
    for (d = 0; d < DIAS; d++){
        //mostrar cada dia 
        printf("%5s", dias[d]);

        //titulo de la ultima columna y salto de linea
        printf("%7s\n", "Total");

        //una fila de la tabla por estudiante
        for (e = 0; e < EST; e++){
            //Reinicia el total de la fila e
            total[e] = 0;
            //Mostrar el nombre
            printf("%-8s", nombres[e]);

            //recorre la columna de la fila e
            for (d = 0; d < DIAS; d++){
                //mostrar las horas de la celda
                printf("%5d", horas[e][d]);
                //sumar la celda al total
                total[e] += horas[e][d];
            }
            //Mostrar el total
            printf("%7d\n", total[e]);
        }
    }

    //=================== MAYOR del arreglo total ===============
    //Supone que el primero estudio mas
    mejor = 0;
    //recorrer los demas estudiantes (posiciones 1 y 2)
    for (e = 1; e < EST; e++){
        //comparar totales
        if (total[e] > total [mejor]){
            mejor = e;
        }
    }

    //mostrar quien estudio mas
    printf("\nEstudio mas: %s (%d horas)\n", nombres[mejor], total[mejor]);

    //=================Dia con mas horas (suma por columna)===================
    //mayor suma incial en 0
    sumaMayor = 0;
    diaMejor = 0;

    //recorrer columnas
    for (d = 0; d < DIAS; d++){
        //REINICIAMOS EL ACUMULADOR
        sumaDia = 0;

        //recorrer filas de esa columna
        for (e = 0; e < EST; e++){
            //suma de celda
            sumaDia+= horas [e][d];

            //comparar la suma del dia con la mayor

            if (sumaDia > sumaMayor){
                //guardar la nueva mayor
                sumaMayor = sumaDia;
                //guarda la posicion
                diaMejor = d;
            }
        }
    }
    //mostrar el dia con mas horas
    printf("Dia con mas horas: %s (%d horas)\n", dias[diaMejor], sumaMayor);

    //============== Busqueda por nombre ===================

    //pedir nombre a buscar
    printf("\nBuscar estudiante: ");
    //lee la palabra
    scanf("%14s", buscado);
    //marca que todavia no aparece
    encontrado = -1; //si el for no encuentra el nombre sigue en -1
    //recorrer los nombres
    for (e = 0; e < EST; e++){
        //compara las dos cadenas
        //strcmp devuelve 0 si son iguales letra por letra
        if (strcmp(buscado, nombres[e])  == 0){
            encontrado = e;
        }
    }

    //revisa si encontro
    if (encontrado >= 0){
        //muestra el total encontrado
        printf("%s estudio %d horas\n", nombres[encontrado], total[encontrado]);
    } else {
        printf("%s no esta en la lista\n", buscado);
    }

    //finalizamos
    return 0;
}