package Periodo_03.object_oriented.Java.Inheritance;

public class Cachorro extends Animal {
    public Cachorro(String nome) {
        super(nome);
    }

    @Override
    public void fazerSom() {
        System.out.println("O cachorro late!");
    }

    public void levantarPata() {
        System.out.println("O " + super.getNome() + " levanta a pata para mijar.");
    }
}
