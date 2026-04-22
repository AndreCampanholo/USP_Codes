#include <stdio.h>
#include <math.h>

float dist(float *pos_x, float *pos_y, int N) {
    float distancia = 0.0;
    for(int i = 0; i < N - 1; i++) {    
        distancia += sqrt((pow(pos_x[i + 1] - pos_x[i], 2)) + (pow(pos_y[i + 1] - pos_y[i], 2)));
    }
    return distancia;
}

int main() {
    int N;
    scanf("%d", &N);
    float eixo_x[N], eixo_y[N], d_total;
    for(int i = 0; i < N; i++) {
        scanf("%f %f", &eixo_x[i], &eixo_y[i]);
    }
    d_total = dist(eixo_x, eixo_y, N);

    printf("%.4f\n", d_total);
}