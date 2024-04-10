import java.util.function.DoubleUnaryOperator;

public class SomaTresOitavos {
public static void main(String[] args) {
        double a = 0;
        double b = 3;
        int part = 6;
        double delta = (b - a) / part;
        double soma = 0;
        DoubleUnaryOperator f = x -> 1 / (1 + x);

        double somaIncial = (f.applyAsDouble(a) + f.applyAsDouble(b));
       
        for (int i = 1; i < part; i++) {
            double xi = a + i * delta;
            if(i % 3 != 0 ){
                xi = f.applyAsDouble(xi);
                soma += 3*xi;
              
            }
                else{
                    xi = f.applyAsDouble(xi);
                    soma += 2*xi;
                }
        }
        soma += somaIncial;
        soma = ((3.0/8) * delta) * soma;
        System.out.println("Área aproximada: " + soma);
}
}