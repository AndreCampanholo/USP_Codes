// Eduardo Poltroniere da Silva - 16862892
// André Campanholo Paschoalini - 14558061

import java.util.*;

public class GrafoMatrizAdjacencia extends Grafo {

    // Cria uma lista dos vértices do grafo e a matriz de booleanos
    private final List<String> vertices = new ArrayList<>(); 
    private boolean[][] matriz = new boolean[0][0];

    // Retorna o indice do vértice na lista de vértices
    private int indexOf(String v) {
        return vertices.indexOf(v);
    }

    // Aumenta o tamanho da matriz quando há uma inserção
    private void expandirMatriz(int novoTamanho) {
        boolean[][] nova = new boolean[novoTamanho][novoTamanho];
        int antigo = matriz.length;
        for (int i = 0; i < antigo; i++)
            for (int j = 0; j < antigo; j++)
                nova[i][j] = matriz[i][j];
        matriz = nova;
    }

    @Override
    public void adicionarVertice(String vertice) {
        // Se o vértice já está contido na matriz, sai
        if (vertices.contains(vertice))
            return;
        vertices.add(vertice); // Adiciona na lista de vértices
        expandirMatriz(vertices.size()); // Adiciona na matriz expandindo-a
    }

    @Override
    public void removerVertice(String vertice) {
        int idx = indexOf(vertice);
        if (idx < 0)
            return;
        int n = vertices.size();
        boolean[][] nova = new boolean[n - 1][n - 1]; // Cria uma matriz com uma linha e coluna a menos
        int ni = 0;
        for (int i = 0; i < n; i++) {
            if (i == idx)
                continue;
            int nj = 0;
            for (int j = 0; j < n; j++) {
                if (j == idx)
                    continue;
                nova[ni][nj] = matriz[i][j]; // Preenche a nova matriz
                nj++;
            }
            ni++;
        }
        vertices.remove(idx); // Remove o vértice da lista
        matriz = nova; // A matriz de adjacências passa a ser a nova matriz que foi reduzida
    }

    @Override
    public void adicionarAresta(String origem, String destino) {
        // Marca aresta como existente (não ponderado — usa booleano true)
        adicionarVertice(origem);
        adicionarVertice(destino);
        int i = indexOf(origem), j = indexOf(destino);
        matriz[i][j] = true;
        matriz[j][i] = true;
    }

    @Override
    public void removerAresta(String origem, String destino) {
        int i = indexOf(origem), j = indexOf(destino);
        if (i < 0 || j < 0)
            return;
        matriz[i][j] = false;
        matriz[j][i] = false;
    }

    @Override
    public boolean existeVertice(String vertice) {
        return vertices.contains(vertice);
    }

    @Override
    public boolean existeAresta(String origem, String destino) {
        int i = indexOf(origem), j = indexOf(destino);
        if (i < 0 || j < 0)
            return false;
        return matriz[i][j];
    }

    @Override
    public int grau(String vertice) {
        // Percorre a linha de um vértice na matriz e calcula o grau desse vértice
        int i = indexOf(vertice);
        if (i < 0)
            return 0;
        int grau = 0;
        for (int j = 0; j < vertices.size(); j++)
            if (matriz[i][j])
                grau++;
        return grau;
    }

    @Override
    public int ordem() {
        return vertices.size(); // Número total de vértices
    }

    @Override
    public int tamanho() {
        // Percorre a matriz e calcula a quantidade de arestas
        int count = 0;
        int n = vertices.size();
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (matriz[i][j])
                    count++;
        return count;
    }

    @Override
    public String toString() {
        List<String> isolados = new ArrayList<>();
        List<String> arestas = new ArrayList<>();
        int n = vertices.size();
        
        for (int i = 0; i < n; i++) {
            boolean isolado = true; // Assume que é isolado até achar uma aresta
            for (int j = 0; j < n; j++) {
                if (matriz[i][j]) {
                    isolado = false; 
                    if (i <= j) { // Adiciona aresta só uma vez
                        String u = vertices.get(i);
                        String v = vertices.get(j);
                        String a = u.compareTo(v) <= 0 ? u : v;
                        String b = u.compareTo(v) <= 0 ? v : u;
                        arestas.add("    \"" + a + "\" -- \"" + b + "\";");
                    }
                }
            }
            if (isolado) {
                isolados.add("    \"" + vertices.get(i) + "\";");
            }
        }
        
        Collections.sort(isolados);
        Collections.sort(arestas);
        
        StringBuilder sb = new StringBuilder();
        sb.append("graph {\n");
        for (String linha : isolados) sb.append(linha).append("\n");
        for (String linha : arestas) sb.append(linha).append("\n");
        sb.append("}");
        return sb.toString();
    }
}