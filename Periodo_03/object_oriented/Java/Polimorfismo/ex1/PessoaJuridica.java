package ex1;

public class PessoaJuridica extends Contato {
    private long cnpj;
    private String inscricaoEstadual;
    private String razaoSocial;

    public PessoaJuridica(long cnpj, String nome, String endereco, String email, String inscricaoEstadual, String razaoSocial) {
        super(nome, endereco, email);
        this.cnpj = cnpj;
        this.inscricaoEstadual = inscricaoEstadual;
        this.razaoSocial = razaoSocial;
    }

    public long getCnpj() {
        return cnpj;
    }

    public String toString() {
        return (super.getNome() + " - " + cnpj + " - " + super.getEmail() + " - " + inscricaoEstadual + " - " + razaoSocial);
    }
}   
