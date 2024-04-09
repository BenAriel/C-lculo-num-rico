import java.util.Scanner;
import java.util.function.DoubleUnaryOperator;

public class PolinomioNewton {
    public static void main(String[] args) {
        int pontos = 3;
        double[] x = {-1, 0, 2};
        double[] Fx = new double[pontos];
        DoubleUnaryOperator f = y -> Math.pow(y, 2);
        for(int i = 0; i <pontos; i++) {
            Fx[i] = f.applyAsDouble(x[i]);
            System.out.println(Fx[i]);
        }


        double[] coeficientes = calcularCoeficientesNewton(x, Fx);

        System.out.println("\nA fórmula de interpolação de Newton é:");
        System.out.println("f(x) = " + coeficientes[0]);
        for (int i = 1; i < coeficientes.length; i++) {
            System.out.print(" + " + coeficientes[i]);
            for (int j = 0; j < i; j++) {
                System.out.print("*(x - " + x[j] + ")");
            }
        }

        System.out.println("\nDigite o valor de x para calcular a função interpolada:");
        Scanner scanner = new Scanner(System.in);
        double x0 = scanner.nextDouble();
        scanner.close();

        double resultado = calcularInterpolacaoNewton(x0, x, coeficientes);
        System.out.println("\nO valor da função interpolada em x = " + x0 + " é " + resultado);
    }

    public static double[] calcularCoeficientesNewton(double[] x, double[] Fx) {
        int n = x.length;
        double[][] tabelaDiferencasDivididas = new double[n][n];
        double[] coeficientes = new double[n];

        for (int i = 0; i < n; i++) {
            tabelaDiferencasDivididas[i][0] = Fx[i];
        }


        for (int j = 1; j < n; j++) {
            for (int i = 0; i < n - j; i++) {
                tabelaDiferencasDivididas[i][j] = (tabelaDiferencasDivididas[i + 1][j - 1] - tabelaDiferencasDivididas[i][j - 1]) / (x[i + j] - x[i]);
            }
        }

        for (int i = 0; i < n; i++) {
            coeficientes[i] = tabelaDiferencasDivididas[0][i];
        }
        return coeficientes;
    }

    public static double calcularInterpolacaoNewton(double x0, double[] x, double[] coeficientes) {
        int n = x.length;
        double resultado = coeficientes[0];
        double termo = 1;
        for (int i = 1; i < n; i++) {
            termo *= (x0 - x[i - 1]);
            resultado += coeficientes[i] * termo;
        }
        return resultado;
    }
}
