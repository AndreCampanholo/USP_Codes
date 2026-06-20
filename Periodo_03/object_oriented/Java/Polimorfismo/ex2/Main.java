package ex2;

public class Main {
    public static void main(String[] args) {
        Contato pessoa1 = new PessoaFisica(22222222222L, "Janni", "Rua São Carlos, 13", "26/23/2009", "janni@usp.br", "casado");
        Contato pessoa2 = new PessoaJuridica(33333333333L, "Pego", "Rua São Carlos, 13", "pego@usp.br", "inscrito", "JavaCORP");
        Contato pessoa3 = new PessoaFisica(11111111111L, "Dela", "Rua Itália, 7", "10/08/1985", "dela@icmc.usp.br", "solteiro");
        Agenda agenda = new Agenda();
        agenda.adicionarContato(pessoa1);
        agenda.adicionarContato(pessoa2);
        agenda.buscarContatoDocumento(22222222222L);
        agenda.buscarContatoNome("Pego");
        agenda.listarContatos();
        agenda.adicionarContato(pessoa3);
        agenda.listarContatos();
        agenda.removerContato(pessoa2);
        agenda.listarContatos();
    }
}
