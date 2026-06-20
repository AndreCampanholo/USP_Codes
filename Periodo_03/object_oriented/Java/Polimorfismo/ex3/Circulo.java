package ex3;

public class Circulo extends FiguraGeometrica {
    private int raio;

    public Circulo(int raio, String cor, boolean filled) {
        super(cor, filled);
        this.raio = raio;
    }

    public double getArea() {
        return Math.PI * raio * raio;
    }

    public double getPerimetro() {
        return 2 * Math.PI * raio;
    }
}
