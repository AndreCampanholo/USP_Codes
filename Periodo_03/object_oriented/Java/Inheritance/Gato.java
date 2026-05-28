package Periodo_03.object_oriented.Java.Inheritance;

public class Gato extends Animal {
    private String sobrenome;

    public Gato(String nome, String sobre) {
        super(nome);
        sobrenome = sobre;
    }

    @Override // Esse comando faz com que esse método sobreescreva o método fazerSom que já existe na superClasse.
    public void fazerSom() {
        System.out.println("O gato mia!");
    }

    @Override
    public String getNome() {
        return (super.getNome() + " " + sobrenome);
    }
}
