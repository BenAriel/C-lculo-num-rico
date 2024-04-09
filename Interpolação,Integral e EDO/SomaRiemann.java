import java.util.function.DoubleUnaryOperator;

public class SomaRiemann {
    public static void main(String[] args) {
        DoubleUnaryOperator f = x -> Math.pow(x, 2);
        double a = 1;
        double b = 2;
        int part = 4; 
        double delta = (b - a) / part;
        double soma = 0;

        for (int i = 0; i <=part; i++) {
            double xi = a + i * delta;
            soma += f.applyAsDouble(xi) * delta;
        }

        System.out.println("Área aproximada: " + soma);

    }
}
