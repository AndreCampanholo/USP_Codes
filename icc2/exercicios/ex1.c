#include <stdio.h>
#include <math.h>

float exponencial(int base, int expoente) {
    int potencia = 1;
    for(int i = 0; i < expoente; i++) {
        potencia = potencia * base;
    }
    return potencia;
}

int fatorial(int n) {
    int fat = 1;
    for(int i = 1; i <= n; i++) {
        fat = fat * i;
    }
    return fat;
}

int main() {
    int n, parada;
    scanf("%d %d", &n, &parada);

    float S;
    int j = 0;
    for(int i = 0; i < 2 * parada; i += 2) {
        if(j % 2 == 0) {
            S += exponencial(n, 2 * i) / fatorial(2 * i + 1);
        } else {
            S += -exponencial(n, 2 * i) / fatorial(2 * i + 1);           
        }
        j++;
    }

    printf("%f\n", S);

    return 0;
}