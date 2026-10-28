/* Qué se logra: leer una frase, mostrarla en mayúsculas y contar vocales, 
   consonantes y dígitos.

   Elementos que se practican: getchar y putchar (sesión 20), isalpha, isdigit,
   toupper y tolower de ctype.h, y una función propia int esVocal(int c) que 
   devuelve 1 o 0. 
*/

#include <stdio.h>
#include <ctype.h>

/* ==========================================
 * PROTOTIPO DE LA FUNCIÓN
 * Indica al compilador que la función existe 
 * antes de que sea utilizada en el main().
 * ========================================== */
int esVocal(int c);

int main(void) {
    char buffer[256];
    int i = 0;
    int c;

    printf("Frase: ");
    
    /* Leer caracteres uno a uno usando getchar hasta encontrar un salto de línea o EOF */
    while ((c = getchar()) != '\n' && c != EOF && i < 255) {
        buffer[i++] = (char)c;
    }
    buffer[i] = '\0'; // Fin de cadena

    int vocales = 0;
    int consonantes = 0;
    int digitos = 0;

    /* 1. Mostrar la frase convertida a mayúsculas usando putchar y toupper */
    for (int j = 0; j < i; j++) {
        putchar(toupper(buffer[j]));
    }
    putchar('\n');

    /* 2. Recorrer la frase para contar vocales, consonantes y dígitos */
    for (int j = 0; j < i; j++) {
        char ch = buffer[j];
        
        if (isdigit(ch)) {
            digitos++;
        } else if (isalpha(ch)) {
            if (esVocal(ch)) {
                vocales++;
            } else {
                consonantes++;
            }
        }
        /* Los espacios y símbolos se ignoran automáticamente */
    }

    /* Mostrar los resultados finales */
    printf("Vocales: %d  Consonantes: %d  Digitos: %d\n", vocales, consonantes, digitos);

    return 0;
}

/* ==========================================
 * IMPLEMENTACIÓN DE LA FUNCIÓN
 * Cuerpo real de la función esVocal. 
 * Devuelve 1 si es vocal (mayúscula/minúscula) y 0 si no.
 * ========================================== */
int esVocal(int c) {
    char lower = tolower(c);
    return (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u');
}