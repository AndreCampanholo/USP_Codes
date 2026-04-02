//A keyword 'public' torna a classe acessível por outras classes, isto é, outras classes de outros pacotes podem instanciar objetos desta classe.
public class Cadeira {
        //'private' significa que esse membro só pode ser acessado dentro da própria classe onde foi definido. Permite encapsulamento de daods.
        private String posicao;
        private boolean ocupado;

        //os dois métodos abaixo são os CONSTRUTORES da nossa classe, isto é, ao criar um objeto da classe Cadeira, usa-se métodos construtores como os abaixos (um cria uma cadeira sem determinar posição ou ocupação, outro recebe parâmetros para pre-definir estes atributos).
        public Cadeira() {
                posicao = "Em pé";
                ocupado = false;
        }

        public Cadeira(String p, boolean oc) {
                if(p.equals("Invertida") && oc) 
                        System.out.println("Não é possível ter uma cadeira invertida ocupada.");
                
                posicao = p;
                ocupado = oc;
        }

        //Métodos definidos como 'public' podem ser acessados fora da classe em que foram criados
        public void sentar() {
                if(!ocupado && posicao.equals("Em pé"))
                        ocupado = true;
                else    
                        System.out.println("Não é possível sentar numa cadeira invertida.");
        }
        public void levantar() {
                ocupado = false;
                if(posicao.equals("Em pé")) {
                        posicao = "Invertida";
                } else {
                        posicao = "Em pé";
                }
        }
        public void virar() {
                posicao = "Invertida";
        }
        public String getPosicao() {
                return posicao;
        }
}   

/*Tipos de dados:
- int: 4 bytes
- long: 8 bytes
- float: 4 bytes
- double: 8 bytes
- char: 2 bytes
- short: 2 bytes
- byte: 1 byte
- boolean: 1 bit*/