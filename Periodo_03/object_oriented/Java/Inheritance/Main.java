package Periodo_03.object_oriented.Java.Inheritance;

public class Main {
    public static void main(String[] args) {
        Cachorro cachorro = new Cachorro("Fangio");
        Gato gato = new Gato("Petróleo", "Delas");

        cachorro.fazerSom();
        gato.fazerSom();
        System.out.println(cachorro.getNome());
        System.out.println(gato.getNome());
        cachorro.levantarPata();
    }
}
