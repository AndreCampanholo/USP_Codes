import java.util.Scanner;

public class Main {
    static public void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        String linha1 = scanner.nextLine();
        String[] partes = linha1.split(" ");

        int posZero = 0;
        int[] nums = new int[partes.length];
        for (int i = 0; i < partes.length; i++) {
            nums[i] = Integer.parseInt(partes[i]);
            if(nums[i] == 0)
                posZero = i;
        }

        Tabuleiro puzzle = new Tabuleiro(nums);

        String linha2 = scanner.nextLine();

        scanner.close();

        for (int i = 0; i < linha2.length(); i++) {
            puzzle.printState();
            char direcao = linha2.charAt(i);
            switch(direcao) {
                case 'u':
                    posZero = puzzle.moveDown(posZero);
                    break;
                case 'd':
                    posZero = puzzle.moveUp(posZero);
                    break;
                case 'r':
                    posZero = puzzle.moveLeft(posZero);
                    break;
                case 'l':
                    posZero = puzzle.moveRight(posZero);
                    break;   
            }
            System.out.println();
        }
        puzzle.printState();
        System.out.println();
        boolean solucao = puzzle.eSolucao();
        System.out.println("Posicao final: " + solucao);
    }
}