#include <stdio.h>
#include <math.h>

// float hipotenusa(float a, float b, float c) {
//     float L = sqrt(pow(a, 2) + pow(b, 2));
//     float D = sqrt(pow(L, 2) + pow(c, 2));
//     return D;
// }

// int main() {
//     float a, b, c;
//     scanf("%f %f %f", &a, &b, &c);
//     printf("%.2f\n", hipotenusa(a, b, c));
// }

float hipotenusa(float *a, float *b, float *c) {
    float L = sqrt(pow(*a, 2) + pow(*b, 2));
    float D = sqrt(pow(L, 2) + pow(*c, 2));
    return D;
}

int main() {
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    printf("%.2f\n", hipotenusa(&a, &b, &c));
}