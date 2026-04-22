#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num, fat;
    scanf("%d", &num);
    fat = num;
    if((num < 1) || (num > pow(10, 9))){
        return 1;
    }
    for(int i = num - 1; i > 0; i--){
        fat = fat * i;
    }
    printf("%d\n", fat);

    return 0;
}