main :: IO()
main = do
    inf <- readLn :: IO Int
    sup <- readLn :: IO Int

    let list = createList inf sup
    let (def, per, abu) = typeValues 0 0 0 list

    print def
    print per
    print abu

-- Cria uma lista de números de A a B
createList :: (Eq a, Enum a, Ord a) => a -> a -> [a]
createList inf sup
    | inf == sup = [inf]
    | inf < sup = [inf..sup]
    | inf > sup = [sup..inf]

-- Verifica se y é divisor de x
isDivisor :: (Integral a) => a -> a -> Bool
isDivisor _ 0 = False
isDivisor x y
    | mod x y == 0 = True
    | otherwise = False

-- Soma os elementos de uma lista
sumList :: (Num a) => [a] -> a
sumList [] = 0
sumList [x] = x
sumList (x:xs) = x + sumList xs

-- Encontra numa lista os divisores do número a
findDivisors :: (Integral a) => a -> [a] -> [a]
findDivisors _ [] = []
findDivisors a (b:bs)
    | isDivisor a b = b : findDivisors a bs
    | otherwise = findDivisors a bs

-- Calcula a quantidade de números de cada tipo numa lista, retornando uma tripla (def, per, abu)
typeValues :: (Integral a, Eq a, Ord a) => a -> a -> a -> [a] -> (a, a, a)
typeValues def per abu [] = (def, per, abu)
typeValues def per abu (x:xs)
    | x == 1 || sumList curr < x = typeValues (def + 1) per abu xs
    | x == 0 || sumList curr == x = typeValues def (per + 1) abu xs
    | sumList curr > x = typeValues def per (abu + 1) xs
    where
        curr = findDivisors x checkList
        checkList = createList 1 (x `div` 2)
