import java.util.Scanner;

public class VideoPoker {
    public static void main(String[] args) {
        new VideoPoker().jogar();
    }

    // Laço principal
    public void jogar() {
        int valor_aposta;
        Scanner sc = new Scanner(System.in);
        VerificarMaos vm = new VerificarMaos();

        System.out.print("Semente: ");
        int semente = sc.nextInt();

        Baralho baralho = new Baralho(semente);

        System.out.print("Saldo inicial: ");
        int saldo = sc.nextInt();

        sc.nextLine();
        String quais;

        while(true) {
            // Se o saldo zerar, encerrar jogo
            if(saldo <= 0) {
                System.out.print("Seu saldo acabou. Tente jogar outra vez.");
                sc.close();
                return;
            }

            System.out.println("Saldo atual: $" + saldo);

            // Valida entrada do valor da aposta, encerrando o programa caso seja 'F'
            while(true) {
                System.out.print("Digite o valor da aposta of 'F' para terminar ==> ");
                String entradaAposta = sc.nextLine().trim();
                if(entradaAposta.equalsIgnoreCase("F")) {
                    System.out.println("Terminando o jogo... Parabéns você ainda tem saldo de $" + saldo);
                    sc.close();
                    return;
                }
                try {
                    valor_aposta = Integer.parseInt(entradaAposta);
                    break;
                } catch(NumberFormatException e) {
                    System.out.println("Entrada inválida. Digite um valor numérico ou F para sair.");
                }
            }

            // Se o valor da aposta for válido, continua execução
            if(valor_aposta > 0 && valor_aposta <= saldo) {
                saldo -= valor_aposta;

                // Cria o deck das cartas que estão na mesa, inicializando a mão do jogador
                Mesa deck = new Mesa(baralho);

                System.out.print(deck.toString());

                System.out.print("Digite o número das cartas que você deseja trocar, separados por espaços: ");
                quais = sc.nextLine();
                deck.trocarCartas(quais, baralho);
                System.out.print(deck.toString());

                System.out.print("Digite o número das cartas que você deseja trocar, separados por espaços: ");
                quais = sc.nextLine();
                deck.trocarCartas(quais, baralho);
                System.out.print(deck.toString());

                int multiplicador = vm.verificarMao(deck.getMao());
                int retorno = vm.atualizarSaldo(valor_aposta, multiplicador);
                saldo += retorno;

                if(retorno == 0) System.out.println("Peninha... não ganhou nada nessa rodada");
                else System.out.println("Parabéns. Você acrescentou $" + retorno + " ao seu saldo");

                baralho.recomporBaralho(deck);
            } else if(valor_aposta <= 0) {
                System.out.println("A aposta deve ser maior que zero.");
                continue;
            } else if (valor_aposta > saldo) {
                System.out.print("Saldo insuficiente. ");
            }

            System.out.println("Tecle enter para continuar");
            sc.nextLine();
        }
    }
}
