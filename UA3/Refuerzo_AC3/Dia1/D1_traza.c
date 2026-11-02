#include <stdio.h>
int main(void) {
    int n = 4, i, s = 0;
    for (i = 1; i <= n; i++) {
        if (i % 2 == 0)
            s += i * 2;
        else
            s += i;
    }
    printf("s = %d\n", s);
    return 0;
}
