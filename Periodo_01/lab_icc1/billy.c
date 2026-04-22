#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, b;
    scanf("%d %d", &n, &b);

    char *musica;
    musica = (char *)calloc(100, sizeof(char));
    
    for(int i = 0; i < n; i++) {
        scanf(" %[^\n]", musica);
        getchar();
        
        for(int j = 0; j < strlen(musica); j++) {
            if((b == 0) && (musica[j] >= 65) && (musica[j] <= 90)) {
                musica[j] = musica[j] + 32;
            } else if ((b == 1) && (musica[j] >= 97) && (musica[j] <= 122)) {
                musica[j] = musica[j] - 32;
            }
        }
        printf("%s\n", musica);
    }

    free(musica);
    return 0;
}