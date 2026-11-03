#include <stdio.h>
int main(void) {
    int op;
    do {
        printf("Opcion (1 a 3): ");
        scanf("%d", &op);
    } while (op < 1 || op > 3);
    printf("Elegida: %d\n", op);
    return 0;
}
