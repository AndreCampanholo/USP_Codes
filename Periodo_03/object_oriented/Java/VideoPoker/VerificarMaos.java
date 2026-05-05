import java.util.Arrays;

// Classe de verificação das mãos obtidas ao final de cada rodada
public class VerificarMaos {
    // Verifica qual a mão obtida, retornando o respectivo multiplicador do valor da aposta
    public int verificarMao(Carta[] cartas) {
        if(checkRoyalStraightFlush(cartas)) return 200;
        else if(checkStraightFlush(cartas)) return 100;
        else if(checkQuadra(cartas)) return 50;
        else if(checkFullHand(cartas)) return 20;
        else if(checkFlush(cartas)) return 10;
        else if(checkStraight(cartas)) return 5;
        else if(checkTrinca(cartas)) return 2;
        else if(checkTwoPairs(cartas)) return 1;
        else return 0;
    }

    // Retorna a recompensa obtida pela aposta, igual ao valor da aposta vezes o multiplicador
    public int atualizarSaldo(int valor_aposta, int multiplicador) {
        return valor_aposta * multiplicador;
    }

    // Verifica se a mão é Dois Pares
    private boolean checkTwoPairs(Carta[] cartas) {
        if(cartas != null && cartas.length == 5) {
            int[] v = new int[5];
            for(int i = 0; i < 5; i++) {
                v[i] = cartas[i].getValue();
            }
            Arrays.sort(v);
            if(v[0] == v[1] && v[2] == v[3] && v[4] != v[1] && v[4] != v[2] ||
            v[0] == v[1] && v[3] == v[4] && v[2] != v[0] && v[2] != v[4] ||
            v[1] == v[2] && v[3] == v[4] && v[0] != v[1] && v[0] != v[3]) {
                return true;
            }
        }
        return false;
    }

    // Verifica se a mão é uma trinca
    private boolean checkTrinca(Carta[] cartas) {
        if(cartas != null && cartas.length == 5) {
            int[] v = new int[5];
            for(int i = 0; i < 5; i++) {
                v[i] = cartas[i].getValue();
            }
            Arrays.sort(v);
            if(v[0] == v[1] && v[1] == v[2] && v[3] != v[4] && v[3] != v[0] && v[4] != v[0] ||
            v[1] == v[2] && v[2] == v[3] && v[0] != v[4] && v[0] != v[1] && v[4] != v[1] ||
            v[2] == v[3] && v[3] == v[4] && v[0] != v[1] && v[0] != v[2] && v[1] != v[2]) {
                return true;
            }
        }
        return false;
    }

    // Verifica se a mão é um Straight
    private boolean checkStraight(Carta[] cartas) {
        if(cartas != null && cartas.length == 5) {
            int[] v = new int[5];
            int[] n = new int[5];
            for(int i = 0; i < 5; i++) {
                v[i] = cartas[i].getValue();
                n[i] = cartas[i].getNaipe();
            }
            if(n[0] == n[1] && n[1] == n[2] && n[2] == n[3] && n[3] == n[4]) return false;
            Arrays.sort(v);
            for(int i = 0; i < 4; i++) {
                if(v[i] != v[i + 1] - 1) return false;
            }
            return true;
        }
        return false;
    }

    // Verifica se a mão é um flush
    private boolean checkFlush(Carta[] cartas) {
        if (cartas == null || cartas.length != 5) return false;
        int naipe = cartas[0].getNaipe();
        for (int i = 1; i < 5; i++) if (cartas[i].getNaipe() != naipe) return false;
        int[] v = new int[5];
        for (int i = 0; i < 5; i++) v[i] = cartas[i].getValue();
        Arrays.sort(v);
        boolean seguidos = true;
        for(int i = 0; i < 4; i++) {
            if(v[i] != v[i + 1] - 1) { seguidos = false; break; }
        }
        return !seguidos;
    }

    // Verifica se a mão é um Full
    private boolean checkFullHand(Carta[] cartas) {
        if(cartas == null || cartas.length != 5) return false;
        int[] v = new int[5];
        for(int i = 0; i < 5; i++) {
            v[i] = cartas[i].getValue();
        }
        Arrays.sort(v);
        if(v[0] == v[1] && v[2] == v[3] && v[3] == v[4] || v[0] == v[1] && v[1] == v[2] && v[3] == v[4]) return true;
        else return false;
    }

    // Verifica se a mão é uma quadra
    private boolean checkQuadra(Carta[] cartas) {
        if(cartas == null || cartas.length != 5) return false;
        int[] v = new int[5];
        for(int i = 0; i < 5; i++) {
            v[i] = cartas[i].getValue();
        }
        Arrays.sort(v);
        if(v[0] == v[1] && v[1] == v[2] && v[2] == v[3] || v[1] == v[2] && v[2] == v[3] && v[3] == v[4]) return true;
        else return false;
    }

    // Verifica se a mão é um Straight Flush
    private boolean checkStraightFlush(Carta[] cartas) {
        if(cartas == null || cartas.length != 5) return false;
        int[] v = new int[5];
        int[] n = new int[5];
        for(int i = 0; i < 5; i++) {
            v[i] = cartas[i].getValue();
            n[i] = cartas[i].getNaipe();
        }
        if(n[0] == n[1] && n[1] == n[2] && n[2] == n[3] && n[3] == n[4]) {
            Arrays.sort(v);
            for(int i = 0; i < 4; i++) {
                if(v[i] != v[i + 1] - 1) return false;
            }
            return true;
        }
        return false;
    }

    // Verifica se a mão é um Royal Straight Flush
    private boolean checkRoyalStraightFlush(Carta[] cartas) {
        if(cartas == null || cartas.length != 5) return false;
        int[] v = new int[5];
        int[] n = new int[5];
        for(int i = 0; i < 5; i++) {
            v[i] = cartas[i].getValue();
            n[i] = cartas[i].getNaipe();
        }
        Arrays.sort(v);
        if(n[0] == n[1] && n[1] == n[2] && n[2] == n[3] && n[3] == n[4]) {
            if(v[0] == 10 && v[1] == 11 && v[2] == 12 && v[3] == 13 && v[4] == 14) return true; 
        }
        return false;
    }
}
