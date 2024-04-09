#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

bool verificaDiagonalDominante(double **matriz, int ordem);
double max(double *Xmais1, int ordem);
double max(double *Xmais1, double *X, int ordem);

int main()
{
    int ordem = 3;

    double *solucao = new double[ordem];
    double *X = new double[ordem];
    double *Xmais1 = new double[ordem];
    double **matriz = new double *[ordem];
    for (int i = 0; i < ordem; i++)
    {
        matriz[i] = new double[ordem];
    }

    matriz[0][0] = 4;
    matriz[0][1] = 1;
    matriz[0][2] = 2;
    matriz[1][0] = -1;
    matriz[1][1] = 3;
    matriz[1][2] = 1;
    matriz[2][0] = 2;
    matriz[2][1] = 2;
    matriz[2][2] = 5;

    solucao[0] = 20;
    solucao[1] = 30;
    solucao[2] = 65;

    X[0] = 0;
    X[1] = 0;
    X[2] = 0;

    double precisao = 0.05;
    if (!verificaDiagonalDominante(matriz, ordem))
    {
        cout << "A matriz não é diagonal dominante" << endl;
        exit(0);
    }

    bool convergiu = false;
    int iteracoes = 0;

    while (convergiu == false)
    {
        iteracoes++;

        for (int i = 0; i < ordem; i++)
        {
            double soma = 0.0;

            for (int j = 0; j < ordem; j++)
            {
                if (j != i)
                {
                    soma += matriz[i][j] * Xmais1[j];
                }
            }

            Xmais1[i] = (solucao[i] - soma) / matriz[i][i];
            cout << "Xk+1[" << i << "] = " << Xmais1[i] << endl;
        }

        double numerador = max(Xmais1, X, ordem);
        cout << "d(" << iteracoes << "): " << numerador << endl;

        double denominador = max(Xmais1, ordem);
        cout << "max x" << iteracoes << ": " << denominador << endl;

        double resultado = numerador / denominador;
        cout << resultado << endl;

        if (resultado < precisao)
        {
            cout << "Convergiu em " << iteracoes << " iterações, com d parada = " << resultado << endl;
            convergiu = true;
        }
        else
        {
            for (int i = 0; i < ordem; i++)
            {
                X[i] = Xmais1[i]; // Atualiza X usando os novos valores de Xmais1
            }
        }
    }

    delete[] solucao;
    delete[] X;
    delete[] Xmais1;
    for (int i = 0; i < ordem; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}

bool verificaDiagonalDominante(double **matriz, int ordem)
{
    for (int i = 0; i < ordem; i++)
    {
        double soma = 0.0;
        for (int j = 0; j < ordem; j++)
        {
            if (i != j)
            {
                soma += abs(matriz[i][j]);
            }
        }

        if (soma >= abs(matriz[i][i]))
        {
            return false;
        }
    }

    return true;
}

double max(double *Xmais1, int ordem)
{
    double max = abs(Xmais1[0]);
    for (int i = 1; i < ordem; i++)
    {
        if (abs(Xmais1[i]) > max)
        {
            max = abs(Xmais1[i]);
        }
    }
    return max;
}

double max(double *Xmais1, double *X, int ordem)
{
    double max = abs(Xmais1[0] - X[0]);
    for (int i = 1; i < ordem; i++)
    {
        if (abs(Xmais1[i] - X[i]) > max)
        {
            max = abs(Xmais1[i] - X[i]);
        }
    }
    return max;
}
