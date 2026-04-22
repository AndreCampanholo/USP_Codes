import math

class tabuleiro:
    # Construtor
    def __init__(self, config_inicial=""):
        self.size = int(math.sqrt(len(config_inicial)))
        self.board = list(config_inicial)
        for i in range(len(self.board)):
            if self.board[i] == "0":
                self.posZero = i

    # Move o zero para baixo (peça abaixo do zero para cima)
    def moveUp(self):
        if(self.posZero + self.size >= self.size * self.size):
            return
        self.board[self.posZero] = self.board[self.posZero + self.size]
        self.posZero = self.posZero + self.size
        self.board[self.posZero] = "0"

    # Move o zero para cima (peça acima do zero para baixo)
    def moveDown(self):
        if(self.posZero - self.size < 0):
            return
        self.board[self.posZero] = self.board[self.posZero - self.size]
        self.posZero = self.posZero - self.size
        self.board[self.posZero] = "0"
    
    # Move o zero para a direita (peça do lado direito do zero para a esquerda)
    def moveLeft(self):
        if((self.posZero + 1) % self.size == 0):
            return
        self.board[self.posZero] = self.board[self.posZero + 1]
        self.posZero = self.posZero + 1
        self.board[self.posZero] = "0"

    # Move o zero para a esquerda (peça do lado esquerdo do zero para a direita)
    def moveRight(self):
        if(self.posZero % self.size == 0):
            return
        self.board[self.posZero] = self.board[self.posZero - 1]
        self.posZero = self.posZero - 1
        self.board[self.posZero] = "0"

    # Verifica se a solução é válida
    def isSolution(self):
        for i in range(len(self.board)):
            if self.board[i] != str(i):
                print("Posicao final: False")
                return
        print("Posicao final: True")

    # Printa o status do tabuleiro conforme a formatação
    def printStatus(self):
        line = ""
        for i in range(self.size):
            line += "+------"
        line += "+"
        print(line)
        index = 0
        for row in range(self.size):
            row_text = ""
            for col in range(self.size):
                value = self.board[index]
                if value == "0":
                    cell = "      "
                else:
                    cell = "  " + value.rjust(2) + "  "
                row_text += "|" + cell
                index += 1
            row_text += "|"
            print(row_text)
            print(line)
        print()
    
    # Aplica movimentos indicados pela string, printando estado do grafo a cada movimentação
    def applyMoves(self, moves_str):
        if(self.size == 0):
            return
        moves_list = list(moves_str)
        self.printStatus()
        for move in moves_list:
            match move:
                case 'u':
                    self.moveUp()
                case 'd':
                    self.moveDown()
                case 'l':
                    self.moveLeft()
                case 'r':
                    self.moveRight()
            self.printStatus()
        self.isSolution()