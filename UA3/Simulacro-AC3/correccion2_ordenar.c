#include <stdio.h>

void ordenar(int *a, int *b) {
    int temp;
    if (*a > *b) {
        temp = a;
        *a = *b;
        *b = temp;
    }
}

int main(void) {
    int x, y;
    printf("Primer numero: ");
    scanf("%d", &x);
    printf("Segundo numero: ");
    scanf("%d", &y);
    ordenar(x, y);
    printf("Menor: %d  Mayor: %d\n", x, y);
    return 0;
}
