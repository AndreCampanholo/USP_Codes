import Dado as dd
from random import Random

class RolaDados:
    # Construtor
    def __init__(self, seed=0):
        self.dados = []
        rd = None
        if seed != 0:
            rd = Random()
            rd.seed(seed)
        for i in range(5):
            if seed == 0:
                d = dd.Dado() # instancia Dado com construtor sem semente
            else:
                d = dd.Dado(rd.randint(1,10000)) # Instacia um Dado com semente
            self.dados.append(d)

    # Rola os dados (todos ou somente os especificados numa lista)
    def rolarDados(self, quais=None, s=None):
        # Rola todos os dados
        if quais is None and s is None:
            r = [0] * len(self.dados)
            for i in range(len(self.dados)):
                r[i] = self.dados[i].rolar()
            return r
        # Rola os dados especificados na lista 'quais'
        if(quais != [] and quais is not None):
            dados_rolados = [0] * len(self.dados)
            for i in range(len(quais)):
                if(i >= 5): break
                if quais[i]:
                    self.dados[i].rolar()
                dados_rolados[i] = self.dados[i].getLado()
            return dados_rolados
        # A partir de uma string, gera a lista com os dados a serem rolados
        elif(s is not None):
            if s == "": # Se p usuário apertou somente 'Enter' (não informou dados a sere rolados), mantém os dados atuais
                r = [0] * len(self.dados)
                for i in range(len(self.dados)):
                    r[i] = self.dados[i].getLado()
                return r
            bool_list = [False] * len(self.dados)
            for valor in s.split():
                j = int(valor) - 1
                if(j >= 0 and j < len(self.dados)):
                    bool_list[j] = True
            return self.rolarDados(bool_list) # Chama a própria função com a lista de dados a serem rolados
        # Retorna os lados dos dados
        r = [0] * len(self.dados)
        for i in range(len(self.dados)):
            r[i] = self.dados[i].getLado()
        return r

    # Define a string de RolaDados    
    def __str__(self):
        s = ""
        for i in range(5):
            base = i * 8
            for dado in self.dados:
                p = str(dado)
                s += p[base:base+7]
                s += "    "
            s += "\n"
        return s