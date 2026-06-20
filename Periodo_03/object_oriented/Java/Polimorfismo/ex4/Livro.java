package ex4;

public class Livro extends Produtos {
    private String autor;
    private String editora;
    private int anoPublicacao;

    public Livro(long codigo, String nome, String autor, String editora, int anoPublicacao) {
        super(codigo, nome);
        this.autor = autor;
        this.editora = editora;
        this.anoPublicacao = anoPublicacao;
    }

    public String getAutor() {
        return autor;
    }

    public String getEditora() {
        return editora;
    }

    public int getAnoPublicacao() {
        return anoPublicacao;
    }

    @Override
    public String toString() {
        return "Livro - " + getNome() + " - Código: " + getCodigo()
                + " - Autor: " + autor + " - Editora: " + editora
                + " - Ano: " + anoPublicacao;
    }
}