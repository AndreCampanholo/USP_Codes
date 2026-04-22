main :: IO()
main = do
    -- leitura dos inteiros de entrada como double
    lado1 <- readLn :: IO Double
    lado2 <- readLn :: IO Double
    lado3 <- readLn :: IO Double

    -- impressão da string equivalente à área pela fórmula de heron
    putStrLn (heron lado1 lado2 lado3)

-- fórmula de heron que retorna strings ("-" para triângulos inválidos e a área em texto caso contrário)
heron a b c
    | a < 0 || b < 0 || c < 0 || a + b < c || a + c < b || b + c < a = "-"
    | otherwise = show area
    where
        p = (a + b + c) / 2
        area = sqrt(p * (p - a) * (p - b) * (p - c))