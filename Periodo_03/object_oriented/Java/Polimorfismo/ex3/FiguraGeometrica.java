package ex3;

public abstract class FiguraGeometrica {
    private String cor;
    private boolean filled;

    public FiguraGeometrica(String cor, boolean filled) {
        this.cor = cor;
        this.filled = filled;
    }

    public abstract double getArea();
    public abstract double getPerimetro();

    public String getCor() {
        return cor;
    }
    public boolean isFilled() {
        return filled;
    }
}
