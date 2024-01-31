#include <iostream>
#include <cmath>

double f(double x) {
    return (pow(x,3) + 2*x + 8);
}


double denominador(double x1, double x0) {
    return (f(x1) - f(x0)) / (x1 - x0);
}

int main() {
    double x0, x1, E;

    std::cout << "Digite o valor de x0: ";
    std::cin >> x0;
    std::cout << "Digite o valor de x1: ";
    std::cin >> x1;
    std::cout << "Digite o valor da precisão: ";
    std::cin >> E;

    double xnmenos1 = x0;
    double xn = x1;
    int k = 0;
    double xnmais1= 0.0;

    while (true) {
        double Fxn = f(xn);
        double denom = denominador(xn, xnmenos1);
         xnmais1 = xn - (Fxn / denom);
        k += 1;

        if (std::abs(xnmais1 - xn) < E || std::abs(Fxn) < E) {
            break;
        } else {
            xnmenos1 = xn;
            xn = xnmais1;
        }
    }

    std::cout << "\n\nxn+1 - xn = " << std::abs(xnmais1 - xn) << std::endl;
    std::cout << "O resultado final é: " << xn << " e foi encontrado em " << k << " iterações." << std::endl;

    return 0;
}

