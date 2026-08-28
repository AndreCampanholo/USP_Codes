def ex02():
    T = int(input())

    for i in range(T):
        n_P_Q = input().split()
        n = int(n_P_Q[0])
        P = int(n_P_Q[1])
        Q = int(n_P_Q[2])
        ovos = input().split()
        ovos = [int(ovo) for ovo in ovos]

        tigela = []
        while len(tigela) < P and sum(tigela) < Q and len(tigela) < n:
            min = 11
            for ovo in ovos:
                if ovo < min:
                    min = ovo
            ovos.remove(min)
            tigela.append(min)
            if sum(tigela) > Q:
                tigela.pop()
                break

        print(f"Caso {i + 1}: {len(tigela)}")


if __name__ == "__main__":
    ex02()