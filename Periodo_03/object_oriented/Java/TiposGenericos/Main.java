class Par<T,Q> {
    private T t;
    private Q q;

    public Par(T dado1, Q dado2) {
        this.t = dado1;
        this.q = dado2;
    }

    public T getX() {
        return t;
    }

    public Q getY() {
        return q;
    }
}

class NoLista<T> {
    private T valor;
    private NoLista<T> proximo;

    public NoLista(T valor) {
        this.valor = valor;
        this.proximo = null;
    }

    public T getValor() {
        return valor;
    }

    public NoLista<T> getProximo() {
        return proximo;
    }

    public void setProximo(NoLista<T> proximo) {
        this.proximo = proximo;
    }
}

class ListaLigada<T> {
    private NoLista<T> inicio;
    private NoLista<T> fim;
    private int tamanho;

    public ListaLigada() {
        inicio = null;
        fim = null;
        tamanho = 0;
    }

    public boolean listaVazia() {
        return tamanho == 0 ? true : false;
    }

    public int getTamanho() {
        return tamanho;
    }

    public void inserirInicio(T valor) {
        NoLista<T> novo = new NoLista<T>(valor);
        if(listaVazia()) {
            inicio = novo;
            fim = novo;
        } else {
            novo.setProximo(inicio);
            inicio = novo;
        }
        tamanho++;        
    }

    public void inserirFim(T valor) {
        NoLista<T> novo = new NoLista<T>(valor);
        if(listaVazia()) {
            inicio = novo;
            fim = novo;
        } else {
            fim.setProximo(novo);
            fim = novo;
        }
        tamanho++;
    }
}

public class Main {
    public static void main(String args[]) {
        ListaLigada<Par<Integer, Double>> lista = new ListaLigada<Par<Integer, Double>>();
        lista.inserirInicio(new Par<Integer, Double>(1, 3.6));
        lista.inserirFim(new Par<Integer, Double>(5, 7.2));
        System.out.println(lista);
    }
}
