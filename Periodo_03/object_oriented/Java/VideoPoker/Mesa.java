import java.util.Scanner;
import java.util.Vector;

public class Mesa {
	private Carta[] mao = new Carta[5];
	private Vector<Carta> descartadas = new Vector<Carta>();

	public Mesa(Baralho baralho) {
        // esvaizia o vetor de cartas descartadas e embaralha o baralho
        descartadas.clear();
        baralho.baralhoEmbaralhar();

		// Pega as 5 primeiras cartas do baralho, adicionam à mão do jogador, e reinsere-as no final do bralho
		for(int i = 0; i < 5; i++) {
			pegarCarta(i, baralho.getBaralho());
		} 
	}

    // Adiciona uma carta à mão no índice informado e insere a carta removida na pilha de descarte
    private void pegarCarta(int idx, Vector<Carta> baralho) {
        if (mao[idx] != null) {
            descartadas.add(mao[idx]);
        }
        mao[idx] = baralho.remove(0);
    }

    // Troca as cartas da mão informadas pelo usuário
	public void trocarCartas(String quais, Baralho baralho) {
        if(quais == null || quais.trim().isEmpty()) { // Se o usuário não informar nenhuma carta, não troca nenhuma
            return;
        } else { // Caso contrário, troca as cartas informadas
            boolean[] trocar = new boolean[5];
            Scanner sc = new Scanner(quais);
            while(sc.hasNextInt()) {
                int posicao = sc.nextInt() - 1;
                if(posicao >= 0 && posicao < 5) {
                    trocar[posicao] = true;
                }
            }
            sc.close();

            for(int i = 0; i < 5; i++) {
                if(trocar[i]) {
                    pegarCarta(i, baralho.getBaralho());
                }
            }
        }
    }

	// Retorna o vetor das 5 cartas atuais
    public Carta[] getMao() {
        return mao;
    }	

    // Retorna o vetor das cartas na pilha de descarte
    public Vector<Carta> getDescartadas() {
        return descartadas;
    }

	// Definição da string da Mão
    public String toString() {
        String s = "\n";
		for (int i = 0; i < 5; i++)
		{
            int base = 1 + i * 8;  // Offset by 1 to skip the leading \n in Carta.toString()
			for(Carta c : mao)
			{
				String p = c.toString();
                s += p.substring(base, base + 7);
				s += " ";
			}
			s+= "\n";
		}
        s += "  (1)     (2)     (3)     (4)     (5)  \n";
		return s;
    }
}