package Periodo_03.object_oriented.Java.Inheritance;

public class Animal {
    private String nome;

    public Animal(String nome) {
        this.nome = nome;
    }

    public void fazerSom() {
        System.out.println("O animal fez um som indefinido.");
    }

    public String getNome() {
        return nome;
    }
}