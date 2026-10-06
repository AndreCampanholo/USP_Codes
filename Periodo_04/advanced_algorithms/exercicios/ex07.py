def solve(saldo: int, produtos: list) -> int:
    dp_sem_bonus = [0] * (saldo + 1)
    for preco, satisfacao in produtos:
        for w in range(saldo, preco - 1, -1):
            dp_sem_bonus[w] = max(dp_sem_bonus[w], dp_sem_bonus[w - preco] + satisfacao)
    
    resposta = max(dp_sem_bonus)

    limite_com_bonus = saldo + 200
    if limite_com_bonus > 2000:
        dp_bonus = [-1] * (limite_com_bonus + 1)
        dp_bonus[0] = 0

        for preco, satisfacao in produtos:
            for w in range(limite_com_bonus, preco - 1, -1):
                if dp_bonus[w - preco] != -1:
                    dp_bonus[w] = max(dp_bonus[w], dp_bonus[w - preco] + satisfacao)

        for gasto in range(2001, limite_com_bonus + 1):
            if dp_bonus[gasto] != -1:
                resposta = max(resposta, dp_bonus[gasto])

    return resposta

def ex07():
    nro_casos_teste = int(input())

    for _ in range(nro_casos_teste):
        qtd_itens_e_saldo = input().split()
        qtd_itens_lista = int(qtd_itens_e_saldo[0])
        saldo_disponivel = int(qtd_itens_e_saldo[1])

        produtos = []

        for _ in range(qtd_itens_lista):
            dados_item = input().split()
            preco = int(dados_item[0])
            satisfacao = int(dados_item[1])
            produtos.append((preco, satisfacao))

        print(solve(saldo_disponivel, produtos))

if __name__ == "__main__":
    ex07()