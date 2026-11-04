#include <stdio.h>
void ajustar(int *a, int b) {
    *a = *a + b;
    b = b * 10;
}
int main(void) {
    int x = 5, y = 3;
    ajustar(&x, y);
    ajustar(&x, y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
