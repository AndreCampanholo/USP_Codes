#include <stdio.h>
#include <string.h>

int main() {
  char buffer[5];
  int copas[14] = {0};
  int ouros[14] = {0};
  int paus[14] = {0};
  int espadas[14] = {0};

  while (scanf("%s", buffer) != EOF) {
    int valor;
    char naipe = buffer[strlen(buffer) - 1];

    if (buffer[0] == 'A') {
      valor = 1;
    }
    else if (buffer[0] == '2') {
      valor = 2;
    }
    else if (buffer[0] == '3') {
      valor = 3;
    }
    else if (buffer[0] == '4') {
      valor = 4;
    }
    else if (buffer[0] == '5') {
      valor = 5;
    }
    else if (buffer[0] == '6') {
      valor = 6;
    }
    else if (buffer[0] == '7') {
      valor = 7;
    }
    else if (buffer[0] == '8') {
      valor = 8;
    }
    else if (buffer[0] == '9') {
      valor = 9;
    }
    else if (buffer[0] == '1' && buffer[1] == '0') {
      valor = 10;
    }
    else if (buffer[0] == 'J') {
      valor = 11;
    }
    else if (buffer[0] == 'Q') {
      valor = 12;
    }
    else if (buffer[0] == 'K') {
      valor = 13;
    }
    else {
      continue;
    }

    if (naipe == 'C') {
      copas[valor]++;
    }
    else if (naipe == 'O') {
      ouros[valor]++;
    }
    else if (naipe == 'P') {
      paus[valor]++;
    }
    else if (naipe == 'E') {
      espadas[valor]++;
    }
  }

  printf("Naipe: Copas\n");
  printf("A: %d\n", copas[1]);
  for (int i = 2; i <= 10; i++) {
    printf("%d: %d\n", i, copas[i]);
  }
  printf("J: %d\n", copas[11]);
  printf("Q: %d\n", copas[12]);
  printf("K: %d\n", copas[13]);

  printf("Naipe: Ouros\n");
  printf("A: %d\n", ouros[1]);
  for (int i = 2; i <= 10; i++) {
    printf("%d: %d\n", i, ouros[i]);
  }
  printf("J: %d\n", ouros[11]);
  printf("Q: %d\n", ouros[12]);
  printf("K: %d\n", ouros[13]);

  printf("Naipe: Paus\n");
  printf("A: %d\n", paus[1]);
  for (int i = 2; i <= 10; i++) {
    printf("%d: %d\n", i, paus[i]);
  }
  printf("J: %d\n", paus[11]);
  printf("Q: %d\n", paus[12]);
  printf("K: %d\n", paus[13]);

  printf("Naipe: Espadas\n");
  printf("A: %d\n", espadas[1]);
  for (int i = 2; i <= 10; i++) {
    printf("%d: %d\n", i, espadas[i]);
  }
  printf("J: %d\n", espadas[11]);
  printf("Q: %d\n", espadas[12]);
  printf("K: %d\n", espadas[13]);

  return 0;
}