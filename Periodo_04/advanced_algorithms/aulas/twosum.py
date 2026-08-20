def twosum(target: int, numbers: list) -> tuple:
    curr = numbers.pop(0)
    dicionario = {}
    while(numbers):
        complement = target - curr
        dicionario[curr] = complement
        curr = numbers.pop(0)
        for chave, valor in dicionario.items():
            if curr == valor:
                return chave, valor

if __name__ == "__main__":
    target = int(input())
    numbers = [9, 0, 2, 5, 7, 18]
    print(twosum(target, numbers))