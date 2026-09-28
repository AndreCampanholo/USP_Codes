#include <iostream>
#include <vector>

using namespace std;

int encontrar_maximo(const vector<int>& v) {
  int max = v[0];
  for(int j = 1; j < v.size(); j++) {
    if(v[j] > max) {
      max = v[j];
    }
  }
  return max;
}

int main() {
  int nro_casos_teste, comprimento_prancha, qtd_prisoneiros;

  // int *minimas_distancias;
  // int *maximas_distancias;

  cin >> nro_casos_teste;

  for(int i = 0; i < nro_casos_teste; i++) {
    cin >> comprimento_prancha;
    cin >> qtd_prisoneiros;


    vector<int> minimas_distancias;
    vector<int> maximas_distancias;
    // minimas_distancias = (int *)malloc(qtd_prisoneiros * sizeof(int));
    // maximas_distancias = (int *)malloc(qtd_prisoneiros * sizeof(int));

    vector<int> pos_prisoneiros(qtd_prisoneiros);
    // vector<bool> prancha(comprimento_prancha);

    for(int j = 0; j < qtd_prisoneiros; j++) {
      cin >> pos_prisoneiros[j];
      minimas_distancias.push_back(min(pos_prisoneiros[j], comprimento_prancha - pos_prisoneiros[j]));
      maximas_distancias.push_back(max(pos_prisoneiros[j], comprimento_prancha - pos_prisoneiros[j]));
    }

    int menor_tempo = encontrar_maximo(minimas_distancias), maior_tempo = encontrar_maximo(maximas_distancias);

    cout << menor_tempo << " " << maior_tempo << endl;
  }
}