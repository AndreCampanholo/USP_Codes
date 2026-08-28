#include <iostream>
#include <vector>

using namespace std;

// Encontrar o maior número possível de um vetor podendo realizar apenas N trocas (swaps).
int main() {
    vector<int> algs{3, 5, 5, 4, 3};
    const int N = 3;

    int trocas = 0;
    for(int i = 0; i < algs.size(); i++) {
        int maior = algs[i];
        int maior_idx = i;
        for(int j = i + 1; j < algs.size(); j++) {
            if(algs[j] >= maior) {
                maior = algs[j];
                maior_idx = j;
            }
        }
        if(maior != algs[i]) {
            int tmp = algs[maior_idx];
            algs[maior_idx] = algs[i];
            algs[i] = tmp;
            trocas++;
        }
        if(trocas == N)
            break;
    }

    for(auto x: algs)
        cout << x;
    cout << endl << trocas << endl;
}