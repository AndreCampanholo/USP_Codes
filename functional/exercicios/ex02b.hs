main :: IO ()
main = do
    inf <- readLn :: IO Int
    sup <- readLn :: IO Int

    print $ largestPrimeGap inf sup

-- Cria uma lista crescente de razão 1 entre dois números
createList :: Enum a => a -> a -> [a]
createList inf sup = [inf..sup]

-- Verifica se um número é primo
isPrime :: (Integral a) => a -> Bool
isPrime n
    | n == 2 = True -- 2 é o único primo par
    | n < 2 || even n = False -- se menor que 2 ou par, não é primo
    | otherwise = divisorCandidates 3 -- caso contrário, busca por divisores (começa com 3)
  where
    divisorCandidates d
        | d * d > n = True -- se o candidato a divisor d ao quadrado for maior do que o número n, d não é divisor, n é primo
        | n `mod` d == 0 = False -- se o candidato for mesmo divisor, n não é primo
        | otherwise = divisorCandidates (d + 2) -- caso contrário, testa para números ímpares até esgotar candidatos válidos

-- Calcula tamanho intervalos entre números de uma lista crescente, e forma uma lista com esses tamanhos
intervals :: (Integral a) => [a] -> [a]
intervals (x:y:xs) = (y - x) : intervals (y : xs)
intervals _ = []

-- Encontra maior elemento de uma lista
maxList :: (Integral a) => [a] -> a
maxList [] = 0
maxList [x] = x
maxList (x:xs) = max x (maxList xs)

-- Calcula maior intervalo entre primos dentre dois números
largestPrimeGap :: (Integral a, Enum a) => a -> a -> a
largestPrimeGap inf sup = maxList gaps
  where
    gaps = intervals (filter isPrime (createList inf sup))