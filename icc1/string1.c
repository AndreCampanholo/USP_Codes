#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;
    str = (char *)calloc(100, sizeof(char));

    int string_length = 0;

    scanf(" %[^\n]", str);

    for(int i = 0; i < 100; i++) {
        if(str[i] != '\0') {
            string_length++;
        } else {
            break;
        }
    }

    printf("%d\n", string_length);

    free(str);

    return 0;
}