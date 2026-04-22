from random import Random

class Dado:
    # Construtor
    def __init__(self, seed=0):
        self.rng = Random() if seed == 0 else Random(seed)
        self.valor = self.rolar()

    # Rola o dado
    def rolar(self):
        self.valor = self.rng.randint(1, 6)
        return self.valor
    
    # Retorna o valor do dado
    def getLado(self):
        return self.valor
    
    # Define a string do Dado
    def __str__(self):
        str000 = "|     |\n"
        str001 = "|    *|\n"
        str010 = "|  *  |\n"
        str100 = "|*    |\n"
        str101 = "|*   *|\n"
        str111 = "|* * *|\n"
        s = "+-----+\n"
        match self.valor:
            case 1:
                s += str000 + str010 + str000
            case 2:
                s += str100 + str000 + str001
            case 3:
                s += str100 + str010 + str001
            case 4:
                s += str101 + str000 + str101
            case 5:
                s += str101 + str010 + str101
            case 6:
                s += str111 + str000 + str111
        s += "+-----+\n"
        return s