#include <stdio.h>
void duplicar(int x) {
    x = x * 2;
}
int main(void) {
    int n = 8;
    duplicar(n);
    printf("n = %d\n", n);
    return 0;
}
