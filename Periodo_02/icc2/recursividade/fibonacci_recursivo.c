#include <stdio.h>

int fibonacci(int n) {
    if(n <= 3) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    printf("%d\n", fibonacci(10));

    return 0;
}