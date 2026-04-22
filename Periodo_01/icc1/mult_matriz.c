#include <stdio.h>

int main() {

    int lin1, col1, lin2, col2;
    scanf("%d %d", &lin1, &col1);
    scanf("%d %d", &lin2, &col2);

    int m1[lin1][col1], m2[lin2][col2], mresult[lin1][col2], soma = 0;

    for(int i = 0; i < lin1; i++) {
        for(int j = 0; j < col1; j++) {
            scanf("%d", &m1[i][j]);
        }
    }
    for(int i = 0; i < lin2; i++) {
        for(int j = 0; j < col2; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    for(int i = 0; i < lin1; i++) {
        for(int j = 0; j < col2; j++) {
            mresult[i][j] = 0;
            for(int k = 0; k < col1; k++) {
                soma += m1[i][k] * m2[k][j];
                mresult[i][j] += soma; 
                soma = 0;
            }
        }
    }

    for(int x = 0; x < lin1; x++) {
        for(int y = 0; y < col2; y++) {
            if(y == col2 - 1) {
                printf("%d\n", mresult[x][y]);
            } else {
                printf("%d ", mresult[x][y]);
            }
        }
    }
    
    return 0;
}