package ex1;
import java.util.Vector;

class Agenda {
    private Vector<Contato> contatos = new Vector<Contato>();

    public void adicionarContato(Contato ctt) {
        contatos.add(ctt);
    }

    public void removerContato(Contato ctt) {
        contatos.remove(ctt);
    }

    public void buscarContatoNome(String nome) {
        int encontrou = 0;
        System.out.println("\nBuscando por contatos cujo nome é " + nome + ":");
        for(Contato ctt : contatos) {
            if(ctt.getNome() == nome) {
                if(ctt instanceof PessoaFisica) {
                    PessoaFisica pf = (PessoaFisica) ctt;
                    System.out.println(pf.toString());
                } else {
                    PessoaJuridica pj = (PessoaJuridica) ctt;
                    System.out.println(pj.toString());
                }
                encontrou = 1;
            }
        }
        if(encontrou == 0) System.out.println("Nenhuma pessoa chamada " + nome + " foi encontrada!\n");
    }

    public void buscarContatoDocumento(long doc) {
        System.out.println("\nBuscando por contatos cujo CPF ou CNPJ é " + doc + ":");
        int encontrou = 0;
        for(Contato ctt : contatos) {
            if(ctt instanceof PessoaFisica) {
                PessoaFisica pf = (PessoaFisica) ctt;
                if(pf.getCpf() == doc) {
                    System.out.println(pf.toString());
                    encontrou = 1;
                }
            } else {
                PessoaJuridica pj = (PessoaJuridica) ctt;
                if(pj.getCnpj() == doc) {
                    System.out.println(pj.toString());
                    encontrou = 1;
                }
            }
        }
        if(encontrou == 0) System.out.println("Nenhuma pessoa com CPF ou CNPJ " + doc + " foi encontrada!\n");
    }

    public void listarContatos() {
        if(contatos.isEmpty()) System.out.println("\nAgenda vazia!");
        System.out.println("\nExibindo todos os contatos da agenda:");
        for(Contato ctt : contatos) {
            if(ctt instanceof PessoaFisica) {
                PessoaFisica pf = (PessoaFisica) ctt;
                System.out.println(pf.toString());
            } else {
                PessoaJuridica pj = (PessoaJuridica) ctt;
                System.out.println(pj.toString());
            }
        }
    }
}