package ex4;

public abstract class Produtos {
    private long codigo;
    private String nome;

    public Produtos(long codigo, String nome) {
        this.codigo = codigo;
        this.nome = nome;
    }

    public long getCodigo() {
        return codigo;
    }

    public String getNome() {
        return nome;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Produtos)) return false;
        Produtos outro = (Produtos) obj;
        return this.codigo == outro.codigo;
    }

    @Override
    public int hashCode() {
        return Long.hashCode(codigo);
    }

    @Override
    public abstract String toString();
}