public class Tabuleiro {
    private int[][] table;
    private int tamanho;

    public Tabuleiro(int arr[]) {
        tamanho = (int) Math.sqrt(arr.length);
        table = new int[tamanho][tamanho];
        
        for(int i = 0; i < tamanho * tamanho; i++) {
            table[i / tamanho][i % tamanho] = arr[i];
        }
    }

    public int moveUp(int posZero) {
        int i = posZero / tamanho;
        int j = posZero % tamanho;
        
        if(i == 0)
            return posZero;

        table[i][j] = table[i-1][j];
        table[i-1][j] = 0;
        return tamanho * (i - 1) + j;
    }

    public int moveDown(int posZero) {
        int i = posZero / tamanho;
        int j = posZero % tamanho;

        if(i == tamanho - 1)
            return posZero;

        table[i][j] = table[i+1][j];
        table[i+1][j] = 0;
        return tamanho * (i + 1) + j;
    }
    
    public int moveRight(int posZero) {
        int i = posZero / tamanho;
        int j = posZero % tamanho;
        
        if(j == tamanho - 1)
            return posZero;

        table[i][j] = table[i][j+1];
        table[i][j+1] = 0;
        return tamanho * i + j + 1;
    }

    public int moveLeft(int posZero) {
        int i = posZero / tamanho;
        int j = posZero % tamanho;
        
        if(j == 0)
            return posZero;

        table[i][j] = table[i][j-1];
        table[i][j-1] = 0;
        return tamanho * i + j - 1;
    }

    public void printState() {
        for(int i = 0; i < tamanho * tamanho; i++) {
            if(i == 0) {
                int j = 0;
                while(j < tamanho) {
                    System.out.print("+------");
                    j++;
                }
                System.out.println("+");
            }
            if(i % tamanho == tamanho - 1) {
                if(table[i/tamanho][i%tamanho] < 10)
                    System.out.println("|   " + table[i/tamanho][i%tamanho] + "  |");
                else
                    System.out.println("|  " + table[i/tamanho][i%tamanho] + "  |");
            } else {
                if(table[i/tamanho][i%tamanho] < 10)
                    System.out.print("|   " + table[i/tamanho][i%tamanho]  + "  ");
                else
                    System.out.print("|  " + table[i/tamanho][i%tamanho]  + "  ");
            }
            if(i % tamanho == tamanho - 1) {
                int j = 0;
                while(j < tamanho) {
                    System.out.print("+------");
                    j++;
                }
                System.out.println("+");
            }
        }
    }

    public boolean eSolucao() {
        for(int i = 0; i < tamanho * tamanho - 1; i++) {
            if(table[i/tamanho][i%tamanho] != table[(i + 1)/tamanho][(i + 1)%tamanho] - 1)
                return false;
        }
        return true;
    }
}