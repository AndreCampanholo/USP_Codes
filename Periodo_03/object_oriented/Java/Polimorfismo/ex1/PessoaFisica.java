package ex1;

public class PessoaFisica extends Contato {
    private long cpf;
    private String dataNascimento;
    private String estadoCivil;

    public PessoaFisica(long cpf, String nome, String endereco, String dataNascimento, String email, String estadoCivil) {
        super(nome, endereco, email);
        this.cpf = cpf;
        this.dataNascimento = dataNascimento;
        this.estadoCivil = estadoCivil;
    }

    public long getCpf() {
        return cpf;
    }

    public String toString() {
        return (super.getNome() + " - " + cpf + " - " + super.getEmail() + " - " + dataNascimento + " - " + estadoCivil);
    }
}
