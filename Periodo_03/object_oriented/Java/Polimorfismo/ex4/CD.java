package ex4;

public class CD extends Produtos {
    private String artista;
    private String gravadora;
    private int anoLancamento;

    public CD(long codigo, String nome, String artista, String gravadora, int anoLancamento) {
        super(codigo, nome);
        this.artista = artista;
        this.gravadora = gravadora;
        this.anoLancamento = anoLancamento;
    }

    public String getArtista() {
        return artista;
    }

    public String getGravadora() {
        return gravadora;
    }

    public int getAnoLancamento() {
        return anoLancamento;
    }

    @Override
    public String toString() {
        return "CD - " + getNome() + " - Código: " + getCodigo()
                + " - Artista: " + artista + " - Gravadora: " + gravadora
                + " - Ano: " + anoLancamento;
    }
}