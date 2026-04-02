#include <stdio.h>

int main() {
    float media;
    int qtd_questoes, qtd_alunos, acertos = 0;
    scanf("%d %d", &qtd_questoes, &qtd_alunos);

    char gabarito[qtd_questoes], resposta[qtd_questoes];
    scanf("%s", &gabarito);

    for(int i = 0; i < qtd_alunos; i++) {
        scanf("%s", &resposta);
        for(int j = 0; j < qtd_questoes; j++) {
            if(resposta[j] == gabarito[j]) {
                acertos++;
            }
        }
        media = (10.0 / qtd_questoes) * acertos;
        printf("%.2f\n", media);
        acertos = 0;
    }
    
    return 0;
}