/*
   Crea un programa que: 
   -Pida el nombre del jugador.
   -Pida: Nivel del personaje | Fuerza | Inteligencia.     Inicio 4:40 pm
   -Calcule:
        -Poder Total = Fuerza + Inteligencia
        -Poder Épico = Poder Total × Nivel
        -Muestre todos los datos en pantalla.
   -Muestre todos los datos en pantalla.
*/

#include <stdio.h>

int main() {

    //Variables
    char nombre[20];
    int nivel, fuerza, inteligencia;

    int total, epico;

    printf("Ingrese su nombre: ");
    scanf("%s", nombre);

    printf("Ingrese el nivel: ");
    scanf("%d", &nivel);

    printf("Ingrese la fuerza: ");
    scanf("%d", &fuerza);

    printf("Ingrese la inteligencia: ");
    scanf("%d", &inteligencia);

    //Calculos
    total = fuerza + inteligencia;
    epico = total * nivel;

    //Datos a presentar por pantalla
    printf("===== FICHA DEL PERSONAJE =====\n");
    printf("Nombre: %s\n", nombre);
    printf("Nivel: %d\n", nivel);
    printf("Fuerza: %d\n", fuerza);
    printf("Inteligencia: %d\n", inteligencia);
    printf("Poder Total: %d\n", total);
    printf("Poder Epico: %d\n", epico);

    return 0;
}

