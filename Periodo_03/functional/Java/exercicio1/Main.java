import java.util.*;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

class Pais {
    final String country;
    final int confirmed;
    final int deaths;
    final int recovery;
    final int active;

    Pais(String country, int confirmed, int deaths, int recovery, int active) {
        this.country = country;
        this.confirmed = confirmed;
        this.deaths = deaths;
        this.recovery = recovery;
        this.active = active;
    }
}

class Main {
    public static void clausula1(List<Pais> paises, int n1) {
        long result = paises.stream()
        .filter(p -> (p.confirmed >= n1))
        .mapToLong(p -> (p.active))
        .sum();
        System.out.println(result);
    }

    public static void clausula2(List<Pais> paises, int n2, int n3) {
        long result = paises.stream()
        .sorted(Comparator.comparingInt((Pais p) -> p.active).reversed())
        .limit(n2)
        .sorted(Comparator.comparingInt((Pais p) -> p.confirmed))
        .limit(n3)
        .mapToLong(p -> (p.deaths))
        .sum();
        System.out.println(result);
    }

    public static void clausula3(List<Pais> paises, int n4) {
        paises.stream()
        .sorted(Comparator.comparingInt((Pais p) -> p.confirmed).reversed())
        .limit(n4)
        .map(p -> p.country)
        .sorted()
        .forEach(System.out::println);
    }

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String parts[] = line.split(" ");
        int n1 = Integer.parseInt(parts[0]);
        int n2 = Integer.parseInt(parts[1]);
        int n3 = Integer.parseInt(parts[2]);
        int n4 = Integer.parseInt(parts[3]);

        List<Pais> paises =
            Files.lines(Paths.get("dados.csv"))
            .map(linha -> {
                String[] campos = linha.split(",");
                String country = campos[0];
                int confirmed = Integer.parseInt(campos[1]);
                int deaths = Integer.parseInt(campos[2]);
                int recovery = Integer.parseInt(campos[3]);
                int active = Integer.parseInt(campos[4]);
                Pais p = new Pais(country, confirmed, deaths, recovery, active);
                return p;
            })
            .toList();
        
        clausula1(paises, n1); 
        clausula2(paises, n2, n3);
        clausula3(paises, n4);
        
        sc.close();
    }
}

