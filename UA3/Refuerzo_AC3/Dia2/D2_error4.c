#include <stdio.h>
void contar(int *total) {
    *total++;
}
int main(void) {
    int t = 0;
    contar(&t);
    contar(&t);
    printf("Total: %d\n", t);
    return 0;
}
