// Eduardo Poltroniere da Silva - 16862892
// André Campanholo Paschoalini - 14558061

import java.util.*;

public class GrafoListaAdjacencia extends Grafo {

    // Cria um mapa ordenado dos vértices para seus conjuntos de vizinhos
    private final Map<String, TreeSet<String>> adj = new TreeMap<>();

    @Override
    public void adicionarVertice(String vertice) {
        // Se o vértice não existe, adiciona com conjunto vazio de vizinhos
        adj.putIfAbsent(vertice, new TreeSet<>()); // Adiciona um vértice na TreeMap
    }

    @Override
    public void removerVertice(String vertice) {
        if (!adj.containsKey(vertice))
            return;

        // Cria uma cópia da lista de vizinhos para iterar com segurança
        Set<String> vizinhos = new HashSet<>(adj.get(vertice));

        // Remove aresta de todos os vizinhos para este vértice
        for (String vizinho : vizinhos) {
            adj.get(vizinho).remove(vertice);
        }
        adj.remove(vertice); // Remove o vértice do mapa
    }

    @Override
    public void adicionarAresta(String origem, String destino) {
        // Adiciona vértices se necessário e cria aresta
        adicionarVertice(origem);
        adicionarVertice(destino);
        adj.get(origem).add(destino);
        adj.get(destino).add(origem);
    }

    @Override
    public void removerAresta(String origem, String destino) {
        // Remove aresta nos dois sentidos, se existirem
        if (adj.containsKey(origem))
            adj.get(origem).remove(destino);
        if (adj.containsKey(destino))
            adj.get(destino).remove(origem);
    }

    @Override
    public boolean existeVertice(String vertice) {
        return adj.containsKey(vertice);
    }

    @Override
    public boolean existeAresta(String origem, String destino) {
        return adj.containsKey(origem) && adj.get(origem).contains(destino);
    }

    @Override
    public int grau(String vertice) {
        // Retorna o número de vizinhos (grau) do vértice
        if (!adj.containsKey(vertice))
            return 0;
        return adj.get(vertice).size();
    }

    @Override
    public int ordem() {
        return adj.size(); // Número total de vértices
    }

    @Override
    public int tamanho() {
        // Percorre todos os conjuntos de vizinhos e conta arestas (dividido por 2)
        int soma = 0;
        for (TreeSet<String> vizinhos : adj.values()) {
            soma += vizinhos.size();
        }
        return soma / 2;
    }

    @Override
    public String toString() {
        List<String> isolados = new ArrayList<>();
        List<String> arestas = new ArrayList<>();
        
        for (Map.Entry<String, TreeSet<String>> entry : adj.entrySet()) {
            String u = entry.getKey();
            TreeSet<String> vizinhos = entry.getValue();
            
            if (vizinhos.isEmpty()) {
                // vértice sem arestas
                isolados.add("    \"" + u + "\";");
            } else {
                for (String v : vizinhos) {
                    if (u.compareTo(v) <= 0) {
                        arestas.add("    \"" + u + "\" -- \"" + v + "\";");
                    }
                }
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