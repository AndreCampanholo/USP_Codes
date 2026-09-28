#include <iostream>
#include <vector>

using namespace std;

// Encontra o maior subvetor (em soma) de um vetor. (O(N))
int soma_subvetor(const vector<int>& vetor) {
  int max_atual = vetor[0], max_global = vetor[0];
  for(int i = 1; i < vetor.size(); i++) {
    max_atual = max(vetor[i], max_atual + vetor[i]);
    max_global = max(max_global, max_atual);
  }
  return max_global;
}

int main() {
  int N, soma_retangulo;
  cin >> N;

  // Ler como: "Vetor de vetores (matriz) com N vetores de N inteiros."
  vector<vector<int>> matriz(N, vector<int>(N));

  // Leitura da matriz
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      cin >> matriz[i][j];
    }
  }

  int maior_soma = -9999; // Valor muito baixo

  for(int L = 0; L < N; L++) {
    vector<int> soma_linhas(N);
    for(int R = L; R < N; R++) {
      for(int i = 0; i < N; i++) {
        // Para cada coluna entre L e R soma a i-ésima linha e adiciona ao vetor de soma_linhas
        soma_linhas[i] += matriz[i][R];
      }
      soma_retangulo = soma_subvetor(soma_linhas); // Encontra o maior subvetor de soma_linhas
      if(soma_retangulo > maior_soma) // Se esse subvetor é maior do que o máximo atual, atualiza o máximo
        maior_soma = soma_retangulo;
    }
  }
  cout << maior_soma << endl; // Imprime a resposta

  return 0;
}