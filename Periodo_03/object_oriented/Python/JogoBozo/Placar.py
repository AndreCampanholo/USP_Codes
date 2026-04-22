import Dado

class Placar:
    # Construtor
    def __init__(self):
        self.posicoes = 10
        self.placar = [0] * 10
        self.taken = [False] * 10

    # Insere a pontuação em alguma posição do placar
    def add(self, posicao=1, dados=[]):
        if(posicao < 1 or posicao > self.posicoes):
            return False
        if(self.taken[posicao - 1]):
            return False
        k = 0
        match(posicao):
            case 1:
                k = self.conta(1, dados)
            case 2:
                k = 2 * self.conta(2, dados)
            case 3:
                k = 3 * self.conta(3, dados)
            case 4:
                k = 4 * self.conta(4, dados)
            case 5:
                k = 5 * self.conta(5, dados)
            case 6:
                k = 6 * self.conta(6, dados)
            case 7: # Trinca
                if(self.checkFull(dados)):
                    k = 15
            case 8: # Sequência
                if(self.checkSequencia(dados)):
                    k = 20
            case 9: # Quadra
                if(self.checkQuadra(dados)):
                    k = 30
            case 10: # General
                if(self.checkGeneral(dados)):
                    k = 40
            case _:
                return False
        self.placar[posicao - 1] = k
        self.taken[posicao - 1] = True
        return True

    # Retorna o placar
    def getScore(self):
        t = 0
        for i in range(10):
            if(self.taken[i]):
                t += self.placar[i]
        return t
    
    # Conta a quantidade de elementos = n numa lista
    def conta(self, n=0, vet=[]):
        cont = 0
        for i in vet:
            if(i == n): cont += 1
        return cont
    
    # Verifica se os dados (após serem ordenados) estão no formato aaabb ou aabbb (Full)
    def checkFull(self, dados=[]):
        dados_ordenandos = sorted(dados)
        return (dados_ordenandos[0] == dados_ordenandos[1] and dados_ordenandos[1] == dados_ordenandos[2] and dados_ordenandos[3] == dados_ordenandos[4]) or (dados_ordenandos[0] == dados_ordenandos[1] and dados_ordenandos[2] == dados_ordenandos[3] and dados_ordenandos[3] == dados_ordenandos[4])
    
    # Verifica se os dados (após serem ordenados) formam uma sequência incremental (12345 ou 23456)
    def checkSequencia(self, dados=[]):
        dados_ordenados = sorted(dados)
        for i in range(1, len(dados_ordenados)):
            if(dados_ordenados[i] - 1 != dados_ordenados[i - 1]):
                return False
        return True
    
    # Verifica se existem quatro dados com o mesmo valor
    def checkQuadra(self, dados=[]):
        dados_ordenados = sorted(dados)
        return (dados_ordenados[0] == dados_ordenados[1] and dados_ordenados[1] == dados_ordenados[2] and dados_ordenados[2] == dados_ordenados[3]) or (dados_ordenados[1] == dados_ordenados[2] and dados_ordenados[2] == dados_ordenados[3] and dados_ordenados[3] == dados_ordenados[4]);

    # Verifica se os cinco dados são iguais
    def checkGeneral(self, dados=[]):
        return (dados[0] == dados[1] == dados[2] == dados[3] == dados[4])
    
    # Define a string do placar
    def __str__(self):
        num = "" 
        s = ""
        for i in range(3):
            num = f" {self.placar[i]:<3d}" if self.taken[i] else "(" + str(i+1) + ") "
            s +=   num + "   |   "
            num = f" {self.placar[i + 6]:<3d}" if self.taken[i + 6] else "(" + str(i+7) + ") "
            s +=   num + "   |  "
            num = f" {self.placar[i + 3]:<3d}" if self.taken[i + 3] else "(" + str(i+4) + ") "
            s+= num + "\n-------|----------|-------\n"
        num = f" {self.placar[9]:<3d}" if self.taken[9] else "(" + str(10) + ")"
        s += "       |   " + num + "   |"
        s += "\n       +----------+\n"
        return s