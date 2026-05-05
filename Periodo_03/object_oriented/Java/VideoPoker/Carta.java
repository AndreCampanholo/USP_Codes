public class Carta {
    private int naipe;
    private int valor;

    // Construtor da classe Carta
    public Carta(int valor, int naipe) {
        this.valor = valor;
        this.naipe = naipe;
    }

    // Dado um inteiro, retorna o naipe como char
    private char mapNumToNaipe(int num) {
        switch(num) {
            case 1:
                return '♣';                
            case 2:
                return '♥';
            case 3:
                return '♠';
            default:
                return '♦';
        }
    }

    // Dado um inteiro, retorna o valor da carta equivalente como string
    private String mapNumToValue(int num) {
        switch (num) {
            case 2:
                return "2";
            case 3:
                return "3";
            case 4:
                return "4";
            case 5:
                return "5";
            case 6:
                return "6";
            case 7:
                return "7";
            case 8:
                return "8";
            case 9:
                return "9";
            case 10:
                return "10";
            case 11:
                return "J";
            case 12:
                return "Q";
            case 13:
                return "K";
            case 14:
                return "A";
            default:
                return null;
        }
    }

    // retorna o naipe da carta como inteiro
    public int getNaipe() {
        return naipe;
    }

    // retorna o valor da carta como inteiro
    public int getValue() {
        return valor;
    }

    // definição da string da carta
    public String toString() {
        String s = "\n+-----+\n|     |";
        if(valor != 10) s += "\n| " + mapNumToValue(valor) + " " + mapNumToNaipe(naipe) + " |";
        else s += "\n| " + mapNumToValue(valor) + mapNumToNaipe(naipe) + " |";
        s += "\n|     |\n+-----+\n";
        return s;
    }
}