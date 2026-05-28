main :: IO ()
main = do
    print "HW"
    print $ p nums

p [] = []
p (x:xs) = x:p [y | y <- xs, mod y x /= 0]

nums = [2..100]

{-Currying
Em Haskell, as funções podem receber mais de dois parâmetros devido ao processo de currying, que converte uma função com múltiplos argumentos em uma sequência de funções com um único argumento. O currying pode ser notado ao observar o tipo de funções que possuem mais do que um argumento.-}
    
{-Estado Imutável 
Em Haskell o estado de variáveis é imutável, ao passo que numa linguagem como C, valores de variáveis mudam ao longo do código.
Ex: Em C, para debugs, printa-se o valor de uma variável para entender seu estado atual. Em Haskell isso não é possível ou necessário.
Isso, embora excelente para previsibilidade do código, é ineficiente computacionalmente em comparação com implementações de estado mutável.-}
-- nums = [3, 2, 4, 1, 4, 5]
-- nums = [2, 3, 4, 1, 4, 5]
{-A simples troca de dois elementos de uma lista não é permitida devido ao estado imutável.-}

{-Lazy Computation
A operação abaixo é extremamente cara, mas compilar este código sem instanciar o 's' na main faz com que o compilador não o calcule. Isso é o conceito de lazy computation: não faça computações desnecessárias, a fim de evitar operações que podem prejudicar a velocidade de compilação.-}
-- nums = [1..100000]
-- s = sum nums
{-Suponha que queremos, na main, printar (f 1 s)... o 's' não será computado, pois a resposta para (f 1 _) independe do segundo argumento.-}
-- f 0 _ = 42
-- f 1 _ = 101
-- f x y = x + y

{-Estado Imutável x Lazy Computation
Já vimos que definir a mesma variável diferentemente duas vezes não é permitido devido ao estado imutável de variáveis. Vimos também que declarar elementos que não são instanciados na main não geram erro de compilação. Vejamos então, o que acontece em cada caso abaixo:-}
-- m = m + 1
{-Esta linha, apesar de inválida, não provoca falha de compilação pois o 'm' não é instanciado na main.-}
-- m = 0
-- m = m + 1
{-Estas duas linhas, porém, geram falha de compilação pois, embora o 'm' não seja chamado na main, viola o estado imutável das variáveis.
Nota-se, portanto, que o estado imutável é um conceito com maior precedência em relação ao lazy computation.-}

