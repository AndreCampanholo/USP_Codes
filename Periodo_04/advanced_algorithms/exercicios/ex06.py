def ex06():
    qtd_casos_teste = int(input())

    for _ in range(qtd_casos_teste):
        qtd_aventureiros, qtd_clientes = map(int, input().split())

        precos_aventureiros = list(map(int, input().split()))
        precos_clientes = list(map(int, input().split()))

        eventos = {}

        for preco in precos_aventureiros:
            eventos[preco] = eventos.get(preco, 0) - 1

        for preco in precos_clientes:
            eventos[preco + 1] = eventos.get(preco + 1, 0) + 1

        pessoas_irritadas = qtd_aventureiros

        melhor_preco = 0
        menor_irritacao = pessoas_irritadas

        for preco in sorted(eventos):
            pessoas_irritadas += eventos[preco]

            if pessoas_irritadas < menor_irritacao:
                menor_irritacao = pessoas_irritadas
                melhor_preco = preco

        print(melhor_preco, menor_irritacao)


if __name__ == "__main__":
    ex06()