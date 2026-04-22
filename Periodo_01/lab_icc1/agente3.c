#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *s, *t, *prefixo;
    s = (char *)calloc(10001, sizeof(char));
    t = (char *)calloc(10001, sizeof(char));

    scanf(" %[^\n] %[^\n]", s, t);

    int sizeS, sizeT, tamanho, maior = 0;
    sizeS = strlen(s);
    sizeT = strlen(t);

    for(int i = 0; i < sizeS; i++) {
        if(s[i] == t[0]) {
            int k = i;
            tamanho = 0;
            for(int j = 0; j < sizeT && k < sizeS; j++, k++) {
                if(s[k] == t[j]) {
                    tamanho++;
                    if(tamanho > maior) {
                        maior = tamanho;
                    }
                } else {
                    break;
                }
            }
        }
    }

    prefixo = (char *)calloc(maior + 1, sizeof(char));

    for(int i = 0; i < maior; i++) {
        prefixo[i] = t[i];
    }

    printf("%d ", maior);
    for(int i = 0; i < maior; i++) {
        printf("%c", prefixo[i]);
    }

    free(s);
    free(t);
    free(prefixo);

    return 0;
}