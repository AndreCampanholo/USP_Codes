#include <stdio.h>

int readInt()
{
    int N;
    scanf("%d", &N);
    return N;
}

double readDouble()
{
    double real;
    scanf("%lf", &real);
    return real;
}

void printDouble(double val)
{
    printf("%.2lf\n", val);
}

int main()
{
    int N = readInt();
    double trabalho[N], den = 0.0, media = 0.0;
    for (int i = 0; i < N; i++)
    {
        trabalho[i] = readDouble();
    }
    for (int x = 0; x < N; x++)
    {
        den = den + (1 / (trabalho[x] + 1));
    }
    media = media + (N / den - 1);
    printDouble(media);
    return 0;
}