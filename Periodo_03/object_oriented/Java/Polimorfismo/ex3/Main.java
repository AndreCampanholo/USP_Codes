package ex3;

public class Main {
    public static void main(String[] args) {
        int raio = 3, ladoA = 6, ladoB = 7, lado = 4;
        String cor1 = "Azul", cor2 = "Amarelo", cor3 = "Preto";
        boolean bool1 = true, bool2 = false, bool3 = false;

        FiguraGeometrica circulo = new Circulo(raio, cor1, bool1);
        FiguraGeometrica retangulo = new Retangulo(ladoA, ladoB, cor2, bool2);
        FiguraGeometrica quadrado = new Quadrado(lado, cor3, bool3);

        System.out.println("Círculo:");
        System.out.println("Raio = " + raio);
        double circArea = circulo.getArea();
        double circPerimetro = circulo.getPerimetro();
        String circCor = circulo.getCor();
        boolean circFilled = circulo.isFilled();
        if(circFilled)
            System.out.println("Área: " + circArea + " - Perímetro: " + circPerimetro + " - Cor: " + circCor + "Preenchido: Sim");
        else
            System.out.println("Área: " + circArea + " - Perímetro: " + circPerimetro + " - Cor: " + circCor + "Preenchido: Não");

        System.out.println("\nRetângulo:");
        System.out.println("Largura = " + ladoA + " - Altura = " + ladoB);
        double retArea = retangulo.getArea();
        double retPerimetro = retangulo.getPerimetro();
        String retCor = retangulo.getCor();
        boolean retFilled = retangulo.isFilled();
        if(retFilled)
            System.out.println("Área: " + retArea + " - Perímetro: " + retPerimetro + " - Cor: " + retCor + " - Preenchido: Sim");
        else
            System.out.println("Área: " + retArea + " - Perímetro: " + retPerimetro + " - Cor: " + retCor + " - Preenchido: Não");

        System.out.println("\nQuadrado:");
        System.out.println("Lado = " + lado);
        double quadArea = quadrado.getArea();
        double quadPerimetro = quadrado.getPerimetro();
        String quadCor = quadrado.getCor();
        boolean quadFilled = quadrado.isFilled();
        if(quadFilled)
            System.out.println("Área: " + quadArea + " - Perímetro: " + quadPerimetro + " - Cor: " + quadCor + "Preenchido: Sim");
        else
            System.out.println("Área: " + quadArea + " - Perímetro: " + quadPerimetro + " - Cor: " + quadCor + "Preenchido: Não");
    }
}
