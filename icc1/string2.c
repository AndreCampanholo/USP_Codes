#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[50], p[50], sp[100];
    scanf(" %[^\n]", s);
    scanf(" %[^\n]", p);

    int s_length = 0;
    int p_length = 0;

    for(int x = 0; x < 100; x++) {
        if(s[x] != '\0') {
            s_length++;
        } else {
            break;
        }
    }
    for(int y = 0; y < 100; y++) {
        if(p[y] != '\0') {
            p_length++;
        } else {
            break;
        }
    }

    for(int i = 0; i < (s_length + p_length); i++) {
        if(i < s_length) {
            printf("%c", s[i]);
        } else if (i >= s_length && i <= (s_length + p_length)) {
            printf("%c", p[i - s_length]);
        }
    } printf("\n");

    return 0;
}