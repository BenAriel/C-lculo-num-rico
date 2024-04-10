import java.util.function.DoubleUnaryOperator;
public class SomaUmTerco {
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
            xi = f.applyAsDouble(xi);
            if (i % 2 == 0) {
                soma += 2 * xi;
            } else {
                soma += 4 * xi;
            }
        }
        soma += somaIncial;
        soma = (delta / 3) * soma;
        System.out.println("Área aproximada: " + soma);
    }
}
