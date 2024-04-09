import java.util.function.DoubleUnaryOperator;

public class SomaTresOitavos {
public static void main(String[] args) {
        double a = 1;
        double b = 3;
        int part = 3;
        double delta = (b - a) / part;
        double soma = 0;
        DoubleUnaryOperator f = x -> 1/x;

        double somaIncial = (f.applyAsDouble(a) + f.applyAsDouble(b));

        for (int i = 1; i < part; i++) {
            double xi = a + i * delta;
            xi = f.applyAsDouble(xi);
                soma += xi;
        
        }
        soma *= 3;
        soma += somaIncial;
        soma = ((3.0/8) * delta) * soma;
        System.out.println("Área aproximada: " + soma);
}
}