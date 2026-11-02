#include <stdio.h>
int main(void) {
    int tipo = 1;
    switch (tipo) {
        case 1: printf("Residencial\n");
        case 2: printf("Comercial\n");
        default: printf("Tipo invalido\n");
    }
    return 0;
}
