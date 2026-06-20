package ex3;

public class Retangulo extends FiguraGeometrica {
    private int ladoA, ladoB;
    
    public Retangulo(int ladoA, int ladoB, String cor, boolean filled) {
        super(cor, filled);
        this.ladoA = ladoA;
        this.ladoB = ladoB;
    }

    public double getArea() {
        return ladoA * ladoB;
    }

    public double getPerimetro() {
        return 2 * ladoA + 2 * ladoB;
    }
}
