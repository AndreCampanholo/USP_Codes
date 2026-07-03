import java.util.*;

class Produto {
    private final String nome;
    private int quantidade;
    private final TipoProduto tipoProduto;
 
    public Produto(String nome, int quantidade, TipoProduto tipoProduto) {
        this.nome = nome;
        this.quantidade = quantidade;
        this.tipoProduto = tipoProduto;
    }
 
    public String getNome() {
        return nome;
    }
 
    public int getQuantidade() {
        return quantidade;
    }
 
    public TipoProduto getTipoProduto() {
        return tipoProduto;
    }
}
 
enum TipoProduto {
    ALIMENTO,
    LIMPEZA,
    OUTROS
}


public class Main {
	public static void main(String[] args) {
		List<Produto> produtos = new ArrayList<Produto>();
			produtos.add(new Produto("Sabao", 10, TipoProduto.LIMPEZA));
			produtos.add(new Produto("Macarrao", 20, TipoProduto.ALIMENTO));
			produtos.add(new Produto("Panela", 5, TipoProduto.OUTROS));
			produtos.add(new Produto("Rodo", 11, TipoProduto.LIMPEZA));
			produtos.add(new Produto("Feijao", 15, TipoProduto.ALIMENTO));
			produtos.add(new Produto("Batata", 2, TipoProduto.ALIMENTO));
			produtos.add(new Produto("Toalha", 10, TipoProduto.OUTROS));
			produtos.add(new Produto("Arroz", 4, TipoProduto.ALIMENTO));

    	produtos
	        .stream()
	        .peek(p -> {System.out.println("Linha 47: " + p.getNome()); })
	        .filter(p -> (p.getQuantidade() > 3))
	        .peek(p -> {System.out.println("Linha 49: " + p.getNome()); })
	        .filter(p -> (p.getTipoProduto() == TipoProduto.ALIMENTO))
	        .peek(p -> {System.out.println("Linha 51: " + p.getNome()); })
	        .limit(2)
	        .peek(p -> {System.out.println("Linha 53: " + p.getNome()); })
	        .map(Produto::getNome) // map(p -> p.getNome())
            .forEach(System.out::println); // .forEach(n -> System.out.println(n));

	    int s = produtos
	        .stream()
	        .peek(p -> {System.out.println("Linha 58: " + p.getNome()); })
	        .filter(p -> p.getTipoProduto() == TipoProduto.LIMPEZA)
	        .mapToInt(p -> p.getQuantidade())
	        .sum();
        System.out.println(s);

	   Optional<Produto> p = produtos
	        .stream()
	        .filter(p1 -> p1.getQuantidade() > 50)
	        .findFirst();
	   p.ifPresent(p1 -> System.out.println(p1.getNome()));
	   String nome = p
	        .map(p1 -> p1.getNome())
	        .orElse("Sem Nome!");
	   System.out.println(nome);

	   String n1 = produtos
	        .stream()
	        .filter(p1 -> p1.getTipoProduto() == TipoProduto.LIMPEZA)
	        .findFirst()
	        .map(p1 -> p1.getNome())
	        .orElse("Sem Produto");
	   produtos // <- List<Produto>
	        .stream() // <- Stream<Produto>
	        .peek(p1 -> System.out.println("Linha 69:" + p1.getNome()))
	        .filter(p1 -> p1.getTipoProduto() == TipoProduto.LIMPEZA) // <- Sream<Produto>
	        .findFirst() // <- Optional<Produto>
	        .filter(p1 -> p1.getQuantidade() > 50) // <- Optional<Produto>
	        .map(p1 -> p1.getNome()) // Optional<String>
	        .ifPresent(n -> System.out.println(n));
        System.out.println(n1);
        
	   final int c = 42;
	   // c++;
	   produtos
	        .stream()
	        .map(p1 -> (p1.getQuantidade() + c)) // clousure
	        .forEach(p1 -> System.out.println(p1));
	}    
}
