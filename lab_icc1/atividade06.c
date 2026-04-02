#include <stdio.h>

int main() {
    float a, b, c, d, menor, media;
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);

    if(a <= b && a <= c && a <= d){
        menor = a;
    } else if(b <= a && b <= c && b <= d){
        menor = b;
    } else if(c <= a && c <= b && c <= d){
        menor = c;
    } else if(d <= a && d <= b && d <= c){
        menor = d;
    }

    media = (a + b + c + d - menor) / 3;

    printf("%.4f\n", media);

    return 0;
}