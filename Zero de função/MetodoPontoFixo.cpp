#include <iostream>
#include <cmath>
#include <limits>
#include <functional>

using namespace std;

double funcao(double x) {
    return std::pow(x, 3) - x - 1;
}

double g(double x) {
    return cbrt(x + 1);
}

void ponto_fixo(double x_inicial, double erro, int max_iter) {
    double x_iterativo, x_temporario;
    bool temresultado = false;

    for (int i = 1; i <= max_iter; ++i) {
        x_iterativo = g(x_inicial);
        x_temporario = x_inicial;

        if (std::fabs(funcao(x_iterativo)) < erro || std::fabs(x_iterativo - x_temporario) < erro) {
            cout << "O resultado é " << x_iterativo << " e foi encontrado com " << i << " iterações\n";
            temresultado = true;
            break;
        } else {
            x_inicial = x_iterativo;
        }
    }

    if (!temresultado)
        cout << "O programa não encontrou raízes em até " << max_iter << " iterações";
}

int main() {
    double erro, x_inicial;
    std::cout << "Digite a precisão E: ";
    std::cin >> erro;
    std::cout << "Digite o chute inicial: ";
    std::cin >> x_inicial;

    ponto_fixo(x_inicial, erro, 1000); // 1000 iterações como exemplo, ajuste conforme necessário

    return 0;
}
