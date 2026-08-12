qtd_casos_teste = int(input().strip())
for _ in range(qtd_casos_teste):
    qtd_instrucoes = int(input().strip())
    instrucoes = []
    x = 0
    for _ in range(qtd_instrucoes):
        instrucao = input().strip()
        parts = instrucao.split()
        if parts[0] == "REPETE":
            instrucoes.append(instrucoes[int(parts[1])])
            instrucao = instrucoes[-1]
        else:
            instrucoes.append(instrucao)
        if instrucao == "ESQUERDA":
            x -= 1
        elif instrucao == "DIREITA":
            x += 1
    print(x)