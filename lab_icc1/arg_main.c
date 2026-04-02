#include <stdio.h> 
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 4) {
        return 1;
    }
    float x, y, r;
    char operador = argv[2][0];
    x = atof(argv[1]);
    y = atof(argv[3]);
    switch (operador)
    {
    case '+':
        r = x + y;
        break;
    case '-':
        r = x - y;
        break;
    case 'x':
        r = x * y;
        break;
    case '/':
        r = x / y;
        break;
    }
    printf("%f\n", r);
    return 0;
}

    
    