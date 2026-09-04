def pode_dividir(duracoes, K, limite):
    dias_usados = 1
    soma_dia_atual = 0

    for d in duracoes:
        if soma_dia_atual + d <= limite:
            soma_dia_atual += d
        else:
            dias_usados += 1
            soma_dia_atual = d
            if dias_usados > K:
                return False
    return True

def ex03():
    N = int(input())

    for n in range(N):

        T_K = input().split()
        T = int(T_K[0])
        K = int(T_K[1])

        duracoes = input().split()
        for i in range(T):
            duracoes[i] = int(duracoes[i])

        baixo = max(duracoes)
        alto = sum(duracoes)
        resposta = alto

        while baixo <= alto:
            meio = (baixo + alto) // 2
            if pode_dividir(duracoes, K, meio):
                resposta = meio
                alto = meio - 1
            else:
                baixo = meio + 1

        print(f"Caso {n + 1}: {resposta}")

if __name__ == "__main__":
    ex03()