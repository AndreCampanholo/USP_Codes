package ex3;

public class Quadrado extends FiguraGeometrica {
    private int lado;

    public Quadrado(int lado, String cor, boolean filled) {
        super(cor, filled);
        this.lado = lado;
    }

    public double getArea() {
        return lado * lado;
    }

    public double getPerimetro() {
        return 4 * lado;
    }
}
