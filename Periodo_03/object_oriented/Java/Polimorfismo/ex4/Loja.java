package ex4;

import java.util.Vector;

public class Loja {

    private class ItemEstoque {
        private Produtos produto;
        private int quantidade;

        public ItemEstoque(Produtos produto, int quantidade) {
            this.produto = produto;
            this.quantidade = quantidade;
        }
    }

    private Vector<ItemEstoque> estoque = new Vector<ItemEstoque>();

    private ItemEstoque buscarItem(long codigo) {
        for (ItemEstoque item : estoque) {
            if (item.produto.getCodigo() == codigo) {
                return item;
            }
        }
        return null;
    }

    public void adicionarProduto(Produtos produto, int quantidade) {
        if (quantidade <= 0) {
            System.out.println("Quantidade inválida!");
            return;
        }

        ItemEstoque item = buscarItem(produto.getCodigo());
        if (item != null) {
            item.quantidade += quantidade;
        } else {
            estoque.add(new ItemEstoque(produto, quantidade));
        }
        System.out.println(quantidade + " unidade(s) de \"" + produto.getNome() + "\" adicionada(s) ao estoque.");
    }

    public void buscarProdutoPorCodigo(long codigo) {
        ItemEstoque item = buscarItem(codigo);
        if (item != null) {
            System.out.println(item.produto.toString() + " - Quantidade em estoque: " + item.quantidade);
        } else {
            System.out.println("Nenhum produto com código " + codigo + " foi encontrado!");
        }
    }

    public void buscarProdutoPorNome(String nome) {
        int encontrou = 0;
        for (ItemEstoque item : estoque) {
            if (item.produto.getNome().equalsIgnoreCase(nome)) {
                System.out.println(item.produto.toString() + " - Quantidade em estoque: " + item.quantidade);
                encontrou = 1;
            }
        }
        if (encontrou == 0) {
            System.out.println("Nenhum produto chamado \"" + nome + "\" foi encontrado!");
        }
    }

    public void venderProduto(long codigo) {
        venderProduto(codigo, 1);
    }

    public void venderProduto(long codigo, int quantidade) {
        if (quantidade <= 0) {
            System.out.println("Quantidade inválida!");
            return;
        }

        ItemEstoque item = buscarItem(codigo);
        if (item == null) {
            System.out.println("Produto com código " + codigo + " não encontrado!");
            return;
        }
        if (item.quantidade < quantidade) {
            System.out.println("Estoque insuficiente para \"" + item.produto.getNome()
                    + "\"! Disponível: " + item.quantidade);
            return;
        }

        item.quantidade -= quantidade;
        System.out.println(quantidade + " unidade(s) de \"" + item.produto.getNome() + "\" vendida(s) com sucesso!");

        if (item.quantidade == 0) {
            estoque.remove(item);
        }
    }

    public void verificarEstoque() {
        if (estoque.isEmpty()) {
            System.out.println("\nEstoque vazio!");
            return;
        }

        int totalLivros = 0, totalCDs = 0, totalDVDs = 0;

        System.out.println("\n=== Estoque da loja ===");
        for (ItemEstoque item : estoque) {
            System.out.println(item.produto.toString() + " - Quantidade: " + item.quantidade);

            if (item.produto instanceof Livro) {
                totalLivros += item.quantidade;
            } else if (item.produto instanceof CD) {
                totalCDs += item.quantidade;
            } else if (item.produto instanceof DVD) {
                totalDVDs += item.quantidade;
            }
        }

        System.out.println("\n=== Resumo por categoria ===");
        System.out.println("Livros: " + totalLivros + " itens");
        System.out.println("CDs: " + totalCDs + " itens");
        System.out.println("DVDs: " + totalDVDs + " itens");
        System.out.println("Total geral: " + (totalLivros + totalCDs + totalDVDs) + " itens");
    }
}