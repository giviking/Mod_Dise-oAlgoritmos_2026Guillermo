#include <stdio.h>
int main(void) {
    // 5 casillas: de notas[0] a notas[4]
    int notas[5] = {80, 75, 90, 65, 100};
    int i;
    for (i = 0; i < 5; i++) {
        printf("notas[%d] = %d\n", i, notas[i]);
    }
return 0;
}