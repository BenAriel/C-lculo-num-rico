import java.util.function.DoubleUnaryOperator;
public class SomaTrapezio {
    public static void main(String[] args) {
        double a = 0;
        double b = 3;
        int part = 6;
        double delta = (b - a) / part;
        double soma = 0;
        DoubleUnaryOperator f = x -> 1 / (1 + x);
        
        double somaIncial = (f.applyAsDouble(a) + f.applyAsDouble(b));
        for (int i = 1; i <part ; i++) {
            double xi = a + i * delta;
            xi = f.applyAsDouble(xi);
            soma += 2 * xi;
        }

        soma+= somaIncial;
        soma = (soma/2) * delta;
        System.out.println("Área aproximada: " + soma);
    }
}
