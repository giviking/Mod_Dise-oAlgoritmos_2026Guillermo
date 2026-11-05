/*============================================================================
             Caso: préstamo de libros de una biblioteca escolar 
Enunciado: La biblioteca de un colegio necesita un sistema para controlar el 
           préstamo de sus libros. Puede registrar hasta 5 libros. De cada 
           libro se guarda: el código (100 a 999, no se repite), el título 
           (una sola palabra, hasta 19 letras), los ejemplares disponibles y 
           si el libro está activo o dado de baja. El programa inicia con 3 
           libros ya cargados (tabla brindada). Debe mostrar un menú que se 
           repite hasta elegir 0; toda opción o dato fuera de rango se vuelve 
           a pedir. 

------------------------------------------------------------------------------
Opción del menú    Qué debe hacer 

1 Incluir libro    Si hay espacio, pide código, título y ejemplares (1 a 20). 
                   Si el código ya existe en un libro activo, avisa y no lo 
                   incluye. Un libro nuevo inicia activo y con todos sus
                   ejemplares disponibles.
 
2 Consultar libros Muestra en columnas el código, el título y los disponibles 
                   de cada libro activo, y al final cuántos libros activos hay.
 
3 Prestar un       Pide el código. Si hay ejemplares disponibles, resta uno 
  ejemplar         y muestra cuántos quedan; si no hay, avisa. 

4 Dar de baja      Pide el código y marca el libro como dado de baja: 
  un libro         ya no aparece en consultas ni búsquedas.
 
5 Buscar libro     Pide el código y muestra el código, el título y los 
                   disponibles del libro.
 
0 Salir            Muestra un mensaje de despedida y termina. 

------------------------------------------------------------------------------

En las opciones 3, 4 y 5, si el código no corresponde a un libro activo, 
el programa avisa «No existe un libro activo con el código …» y vuelve al menú. 

------------------------------------------------------------------------------
Libros cargados al iniciar: 
Código             Título           Disponibles 

 101               Quijote              3
 
 102               Principito           2 

 103               Cocori               4 

-------------------------- Caso de Prueba -----------------------------------
Antes de entregar, pruebe su programa con esta secuencia, en este orden. Los 
resultados de la derecha son los que debe obtener.
Paso   Acción              Resultado esperado 
 1     2 Consultar         Los 3 libros iniciales; libros activos: 3. 

 2     1 Incluir,         El código 102 ya existe.
       código 102   

 3     1 Incluir: 104,    Pide de nuevo los ejemplares; libro incluido (4 de 5).
       Platero, 
       25 (inválido) 
       y luego 2  

 4     3 Prestar 102,     Disponibles 1, luego 0; la tercera vez: 
       tres veces         no hay ejemplares disponibles. 
        
 5     4 Dar de baja 101  Libro Quijote dado de baja. 

 6     5 Buscar 101       No existe un libro activo con el código 101. 
 
 7     5 Buscar 103       103 Cocori: 4 disponibles. 

 8 Opción 9 (inválida)    Pide de nuevo la opción; muestra 102 (0), 103 (4) y 
   y luego 2 Consultar    104 (2); libros activos: 3.

============================================================================*/

#include <stdio.h>
#include <string.h>

//Definir las constantes
#define MAX_LIBROS 5
#define MAX_TITULO 20

//Prototipos de las funciones
int leerEntero(int min, int max);
int buscarCodigo(const int codigos[], const int estados[], int n, int codigoBusca);
void incluir(int codigos[], char titulos[][MAX_TITULO], int disponibles[], int estados[], int *n);
void consultar(const int codigos[], const char titulos[][MAX_TITULO], const int disponibles[], const int estados[], int n);
void prestar(int codigos[], int disponibles[], const int estados[], int n);
void darDeBaja(int estados[], const int codigos[], int n);
void buscarLibro(const int codigos[], const char titulos[][MAX_TITULO], const int disponibles[], const int estados[], int n);

int main(void) {
    // Arreglos para almacenar los datos de los libros
    int codigos[MAX_LIBROS] = {101, 102, 103};
    char titulos[MAX_LIBROS][MAX_TITULO] = {"Quijote", "Principito", "Cocori"};
    int disponibles[MAX_LIBROS] = {3, 2, 4};
    int estados[MAX_LIBROS] = {1, 1, 1};    // 1 = activo, 0 = dado de baja
    int n = 3;                              //Cantidad inicial de libros cargados
    int opcion;

    do {
        //Mostrar el menu
        printf("\n--- SISTEMA DE BIBLIOTECA ESCOLAR ---\n");
        printf("1. Incluir libro\n");
        printf("2. Consultar libros\n");
        printf("3. Prestar un ejemplar\n");
        printf("4. Dar de baja un libro\n");
        printf("5. Buscar un libro\n");
        printf("0. Salir \n");
        printf("Seleccione una opcion: ");

        opcion = leerEntero(0, 5);

        switch (opcion) {
            case 1:
            incluir(codigos, titulos, disponibles, estados, &n);
            break;
            case 2:
            consultar(codigos, titulos, disponibles, estados, n);
            break;
            case 3:
            prestar(codigos, disponibles, estados, n);
            break;
            case 4:
            darDeBaja(estados, codigos, n);
            break;
            case 5:
            buscarLibro(codigos, titulos, disponibles, estados, n);
            break;
            case 0:
            printf("Saliendo del sistema. Hasta la Vista!\n");
            break;
            default:
            printf("Opcion Ivalida. \n");
        }
    } while (opcion != 0);

    return 0;
}
   


// Funcion para leer y validar un numero entero dentro de un rango permitido
int leerEntero(int min, int max) {
    int valor;
    char buffer[100];

    do {
        if (scanf("%d", &valor) !=1) {
            printf("Entrada invalida. Digite un numero entero: ");
            scanf("%s", buffer); //Limpia el buffer de entrada en caso de error
            valor = min - 1;     //Forzar que repita
            continue;
        }
        if (valor < min || valor > max) {
            printf("Valor fuera de rango (%d - %d) . Intente de nuevo: ", min, max);
        }
    } while (valor < min || valor > max);
    return valor;
}

// Búsqueda secuencial de un libro ACTIVO por código
int buscarCodigo(const int codigos[], const int estados[], int n, int codigoBusca) {
    for (int i = 0; i < n; i++) {
        if (estados[i] == 1 && codigos[i] == codigoBusca) {
            return i;
        }
    }
    return -1;
}

// Incluye un libro nuevo  y aumenta la cantidad 
void incluir(int codigos[], char titulos[][MAX_TITULO], int disponibles[], int estados[], int *n) {
    if (*n >= MAX_LIBROS) {
        printf("No hay espacio disponible para mas libros.\n");
        return;
    }

    printf("Digite el codigo del libro (100 a 999): ");
    int codigo = leerEntero(100, 999);

    // Verificar si el código ya existe en un libro activo 
    for (int i = 0; i < *n; i++) {
        if (codigos[i] == codigo && estados[i] == 1) {
            printf("El codigo %d ya existe.\n", codigo);
            return;
        }
    }

    printf("Digite el titulo (una sola palabra, max 19 letras): ");
    char tempTitulo[MAX_TITULO];
    scanf("%19s", tempTitulo);

    printf("Digite la cantidad de ejemplares disponibles (1 a 20): ");
    int ejem = leerEntero(1, 20);

    // Guardar en la posición *n
    codigos[*n] = codigo;
    strcpy(titulos[*n], tempTitulo);
    disponibles[*n] = ejem;
    estados[*n] = 1; // Activo por defecto
    (*n)++;

    printf("Libro incluido exitosamente (%d de %d).\n", *n, MAX_LIBROS);
}

// Muestra la tabla de libros activos y la cantidad total de ellos
void consultar(const int codigos[], const char titulos[][MAX_TITULO], const int disponibles[], const int estados[], int n) {
    printf("\n%-10s | %-20s | %-12s\n", "Codigo", "Titulo", "Disponibles");
    printf("-----------------------------------------\n");
    int activosCount = 0;
    for (int i = 0; i < n; i++) {
        if (estados[i] == 1) {
            printf("%-10d | %-20s | %-12d\n", codigos[i], titulos[i], disponibles[i]);
            activosCount++;
        }
    }
    printf("-----------------------------------------\n");
    printf("Libros activos: %d\n", activosCount);
}

// Resta un ejemplar disponible del libro si existe 
void prestar(int codigos[], int disponibles[], const int estados[], int n) {
    printf("Digite el codigo del libro a prestar: ");
    int codigo = leerEntero(100, 999);

    int pos = buscarCodigo(codigos, estados, n, codigo);
    if (pos == -1) {
        printf("No existe un libro activo con el codigo %d\n", codigo);
        return;
    }

    if (disponibles[pos] > 0) {
        disponibles[pos]--;
        printf("Ejemplar prestado con exito. Disponibles restantes: %d\n", disponibles[pos]);
    } else {
        printf("No hay ejemplares disponibles.\n");
    }
}

// Pone el estado del libro en 0 (dado de baja)
void darDeBaja(int estados[], const int codigos[], int n) {
    printf("Digite el codigo del libro a dar de baja: ");
    int codigo = leerEntero(100, 999);

    int pos = buscarCodigo(codigos, estados, n, codigo);
    if (pos == -1) {
        printf("No existe un libro activo con el codigo %d\n", codigo);
        return;
    }

    estados[pos] = 0;
    printf("Libro dado de baja exitosamente.\n");
}

// Busca un libro activo por código y muestra su información 
void buscarLibro(const int codigos[], const char titulos[][MAX_TITULO], const int disponibles[], const int estados[], int n) {
    printf("Digite el codigo del libro a buscar: ");
    int codigo = leerEntero(100, 999);

    int pos = buscarCodigo(codigos, estados, n, codigo);
    if (pos == -1) {
        printf("No existe un libro activo con el codigo %d\n", codigo);
        return;
    }

    printf("%d %s: %d disponibles.\n", codigos[pos], titulos[pos], disponibles[pos]);
}




