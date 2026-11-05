#include <stdio.h>
int main(void) {
    char placa[10];
    printf("Placa: ");
    scanf("%9s", placa);
    if (placa == "FIN")
        printf("Terminar\n");
    else
        printf("Seguir\n");
    return 0;
}
