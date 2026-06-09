// Eduardo Poltroniere da Silva - 16862892
// André Campanholo Paschoalini - 14558061

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Instancia objetos de cada uma das três classes de grafos
        GrafoListaAdjacencia grafoLista = new GrafoListaAdjacencia();
        GrafoMatrizAdjacencia grafoMatriz = new GrafoMatrizAdjacencia();
        GrafoPonderadoMatrizAdjacencia grafoPonderado = new GrafoPonderadoMatrizAdjacencia();

        Scanner sc = new Scanner(System.in);

        // Lê as entradas linha a linha até o fim
        while (sc.hasNextLine()) {
            String linha = sc.nextLine().trim();

            // if (linha.length() > 0 && linha.charAt(0) == '\uFEFF') {
            //     linha = linha.substring(1);
            // }

            // Se a linha é vazia vai para próxima linha
            if (linha.isEmpty())
                continue;

            // Divide a linha em partes
            String[] partes = linha.split("\\s+");
            String cmd = partes[0]; // 'i', 'd' ou 'p'

            // Determina o que fazer para cada comando
            switch (cmd) {
                case "i": { // inserir
                    // i v1 v2 p
                    if (partes.length < 4) {
                        System.err.println("Comando 'i' requer: i v1 v2 peso");
                        break;
                    }
                    String v1 = partes[1];
                    String v2 = partes[2];
                    int peso = Integer.parseInt(partes[3]);

                    grafoLista.adicionarAresta(v1, v2);
                    grafoMatriz.adicionarAresta(v1, v2);
                    grafoPonderado.adicionarAresta(v1, v2, peso);
                    break;
                }
                case "d": { // deletar
                    if (partes.length == 2) {
                        // Remover vértice
                        String v = partes[1];
                        grafoLista.removerVertice(v);
                        grafoMatriz.removerVertice(v);
                        grafoPonderado.removerVertice(v);
                    } else if (partes.length >= 3) {
                        // Remover aresta
                        String v1 = partes[1];
                        String v2 = partes[2];
                        grafoLista.removerAresta(v1, v2);
                        grafoMatriz.removerAresta(v1, v2);
                        grafoPonderado.removerAresta(v1, v2);
                    } else {
                        System.err.println("Comando 'd' requer: d v1 v2 ou d v1");
                    }
                    break;
                }
                case "p": { // printar
                    System.out.println("Lista de Adjacencia");
                    System.out.println(grafoLista.toString());
                    
                    System.out.println("Matriz de Adjacencia");
                    System.out.println(grafoMatriz.toString());
                    
                    System.out.println("Ponderado - Matriz de Adjacencia");
                    System.out.println(grafoPonderado.toString());
                    break;
                }
                default:
                    System.err.println("Comando desconhecido: " + cmd);
            }
        }

        sc.close();
    }
}