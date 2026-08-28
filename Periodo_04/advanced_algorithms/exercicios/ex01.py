def ex01():
    T = int(input())

    for _ in range(T):
        N = int(input())
        cores = input().split()

        M = int(input())
        pares = []

        for _ in range(M):
            pares.append(input().split())

        pintura = []
        pinturas_validas = []
        pintar(cores, pares, pintura, pinturas_validas)

        print(len(pinturas_validas))
        for cor in pinturas_validas[0]:
            if cor == pinturas_validas[0][-1]:
                print(cor)
            else:
                print(cor, end=" ")

def pintar(cores, pares, pintura, pinturas_validas):
    if len(pintura) == len(cores):
        pinturas_validas.append(pintura.copy())
        return
    
    for cor in cores:
        if cor in pintura:
            continue

        if pintura:
            if [pintura[-1], cor] in pares or [cor, pintura[-1]] in pares:
                continue

        pintura.append(cor)
        pintar(cores, pares, pintura, pinturas_validas)
        pintura.pop()        

if __name__ == "__main__":
    ex01()