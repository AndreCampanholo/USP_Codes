import java.util.Collections;
import java.util.Random;
import java.util.Vector;

public class Baralho {
    private Vector<Carta> baralho = new Vector<Carta>();
    private Random rand;

    // Gera as 52 cartas do baralho (naipes em ordem reversa)
    public Baralho(int seed) {
        for(int naipe = 1; naipe < 5; naipe++) {
            for(int valor = 2; valor < 15; valor++) {
                baralho.add(new Carta(valor, naipe));
            }
        }

        // Inicializa rand de acordo com a seed
        if (seed == 0)
            rand = new Random();
        else
            rand = new Random(seed);

        // Embaralha as 52 cartas 
        baralhoEmbaralhar();
    }

    // Embaralha
    public void baralhoEmbaralhar() {
        Collections.shuffle(baralho, rand);
    }

    public Vector<Carta> getBaralho() {
        return baralho;
    }

    public void recomporBaralho(Mesa mesa) {
        Carta[] mao = mesa.getMao();
        for(Carta c: mao) {
            baralho.add(c);
        }
        Vector<Carta> descartadas = mesa.getDescartadas();
        for(Carta c: descartadas) {
            baralho.add(c);
        }
    }
}
