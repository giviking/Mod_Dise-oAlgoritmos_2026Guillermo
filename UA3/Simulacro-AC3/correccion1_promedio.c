#include <stdio.h>

double promedio(const int notas[], int n) {
    int i, suma = 0;
    for (i = 0; i < n; i++)
        suma = notas[i];
    return suma / n;
}

int main(void) {
    int notas[3] = {80, 75, 90};
    printf("Promedio: %.2f\n", promedio(notas, 3));
    return 0;
}
