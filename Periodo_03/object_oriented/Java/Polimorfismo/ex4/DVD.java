package ex4;

public class DVD extends Produtos {
    private String diretor;
    private int duracaoMinutos;
    private String classificacaoIndicativa;

    public DVD(long codigo, String nome, String diretor, int duracaoMinutos, String classificacaoIndicativa) {
        super(codigo, nome);
        this.diretor = diretor;
        this.duracaoMinutos = duracaoMinutos;
        this.classificacaoIndicativa = classificacaoIndicativa;
    }

    public String getDiretor() {
        return diretor;
    }

    public int getDuracaoMinutos() {
        return duracaoMinutos;
    }

    public String getClassificacaoIndicativa() {
        return classificacaoIndicativa;
    }

    @Override
    public String toString() {
        return "DVD - " + getNome() + " - Código: " + getCodigo()
                + " - Diretor: " + diretor + " - Duração: " + duracaoMinutos + " min"
                + " - Classificação: " + classificacaoIndicativa;
    }
}