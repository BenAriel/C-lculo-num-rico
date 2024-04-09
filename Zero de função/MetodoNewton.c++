#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double f(double x) {
    return 4 * sin(x) - exp(x);
}

double derivative(double x, double h) {
 double soma = x+h;
 double sub = x -h;
    return (f(soma) - f(sub)) / (2 * h);
}

int main() {
    double xn, E, h;
    cout << "Digite o valor de x: ";
    cin >> xn;
    cout << "Digite o valor da precisão: ";
    cin >> E;
    cout << "Digite o valor do h (se deixar em branco, o h será o mesmo da precisão): ";
    cin >> h;

    if (!cin) {
        // Clear the error flags
        cin.clear();
        // Ignore the rest of the line
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        h = E;
    }

    double x0 = 0.0;
    int k = 0;

    while (true) {
        x0 = xn;
        double Fxn = f(x0);
        double Fdxn = derivative(xn, h);
        xn = x0 - (Fxn / Fdxn);
        k += 1;

        if (abs(xn - x0) < E || abs(Fxn) < E) {
            break;
        }
    }

    cout << "\n\nxn - x0 = " << abs(xn - x0) << endl;
    cout << "O resultado final é: " << xn << " e foi encontrado em " << k << " iterações." << endl;

    return 0;
}
