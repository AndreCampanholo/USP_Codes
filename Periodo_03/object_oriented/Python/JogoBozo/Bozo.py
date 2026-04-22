import RolaDados as rd
import Placar as pl

# Main do jogo de Bozó

rodadas = 10 # 10 rodados como default
print("Digite a semente (zero para aleatório): ", end="")
seed = int(input())
r = rd.RolaDados(seed) # Cria um objeto da classe RolaDados
p = pl.Placar() # Cria um objeto da classe placar
print(str(p))
for rodada in range(rodadas): # Corpo do jogo, loop das 10 rodadas
    print("****** Rodada " + str(rodada+1))
    print("Pressione ENTER para lançar os dados")
    input()

    # Primeira tentativa
    r.rolarDados()
    print("1          2          3          4          5")
    print(str(r))
    
    # Segunda tentativa
    print("Digite os números dos dados que quiser TROCAR. Separados por espaços.")
    muda = input()
    nums = [int(tok) for tok in muda.split() if tok.isdigit()] # Elimina tokens que não são exclusicamente numéricos
    muda = " ".join(str(n) for n in nums)
    r.rolarDados(s=muda)
    print("1          2          3          4          5");
    print(str(r));

    # Terceira tentativa
    print("Digite os números dos dados que quiser TROCAR. Separados por espaços.")
    muda = input()
    nums = [int(tok) for tok in muda.split() if tok.isdigit()] # Elimina tokens que não são exclusicamente numéricos
    muda = " ".join(str(n) for n in nums)
    values = r.rolarDados(s=muda)
    print("1          2          3          4          5");
    print(str(r));

    # Laço de inserção no placar
    print("\n\n")
    print(str(p))
    pos = 0
    while(pos <= 0):
        try:
            print("Escolha a posição que quer ocupar com essa jogada ===> ", end="")
            pos = int(input())
            if(pos > rodadas or pos <= 0): pos = 0
            elif(not p.add(pos, values)):
                pos = 0
        except:
            pos = 0
        if(pos == 0):
            print("Valor inválido. Posição ocupada ou inexistente.")
    print("\n\n")
    print(str(p))

# Impressão do score final
print("***********************************");
print("***");
print("*** Seu escore final foi: " + str(p.getScore()));
print("***");
print("***********************************", end = "");