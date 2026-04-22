#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int hora, minuto, segundo;
} Hora;

typedef struct {
    Data data;
    Hora hora;
    char descr[150];
} Atividade;

int main() {
    int n;
    scanf("%d", &n);

    Atividade atividade[n];

    for(int i = 0; i < n; i++) {
    scanf("%d %d %d", &atividade[i].data.dia, &atividade[i].data.mes, &atividade[i].data.ano);
    scanf("%d %d %d", &atividade[i].hora.hora, &atividade[i].hora.minuto, &atividade[i].hora.segundo);
    scanf(" %[^\n]", &atividade[i].descr);
    }
    
    for(int j = 0; j < n; j++) {
        printf("%02d/%02d/%02d - %02d:%02d:%02d\n", atividade[j].data.dia, atividade[j].data.mes, atividade[j].data.ano,
             atividade[j].hora.hora, atividade[j].hora.minuto, atividade[j].hora.segundo);
        printf("%s\n", atividade[j].descr);
    }

    return 0;
}