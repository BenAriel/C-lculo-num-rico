import java.util.function.DoubleUnaryOperator;
public class SomaUmTerco {
    public static void main(String[] args) {
        double a = 1;
        double b = 2;
        int part = 1000;
        double delta = (b - a) / part;
        double soma = 0;
        DoubleUnaryOperator f = x -> Math.pow(x, 2);

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
