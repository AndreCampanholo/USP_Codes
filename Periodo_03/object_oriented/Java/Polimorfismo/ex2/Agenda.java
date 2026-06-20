package ex2;
import java.util.Vector;

class Agenda {
    private Vector<Contato> contatos = new Vector<Contato>();

    public void adicionarContato(Contato ctt) {
        contatos.add(ctt);
    }

    public void removerContato(Contato ctt) {
        contatos.remove(ctt);
    }

    private boolean vemAntes(Contato a, Contato b) {
        boolean aEhFisica = a instanceof PessoaFisica;
        boolean bEhFisica = b instanceof PessoaFisica;

        if(aEhFisica && !bEhFisica) return true;
        if(!aEhFisica && bEhFisica) return false;

        if(aEhFisica) {
            return ((PessoaFisica) a).getCpf() <= ((PessoaFisica) b).getCpf();
        } else {
            return ((PessoaJuridica) a).getCnpj() <= ((PessoaJuridica) b).getCnpj();
        }
    }

    public void ordenarPorDocumento() {
        int n = contatos.size();
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - 1 - i; j++) {
                Contato atual = contatos.get(j);
                Contato proximo = contatos.get(j + 1);
                if(!vemAntes(atual, proximo)) {
                    contatos.set(j, proximo);
                    contatos.set(j + 1, atual);
                }
            }
        }
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
        ordenarPorDocumento();
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