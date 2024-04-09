#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void decomposicaoCholesky(double **matriz, double **L, int ordem);
void resolverSistemaL(double **L, double *b, double *resultado, int ordem);
void resolverSistemaU(double **LT, double *y, double *resultado, int ordem);
bool simetrica(double **matriz, int ordem);

int main()
{
    cout<<fixed<<setprecision(2);
    int ordem = 3;

    double *resultado = new double[ordem];
    double **matriz = new double *[ordem];
    for (int i = 0; i < ordem; i++)
    {
        matriz[i] = new double[ordem];
    }

    matriz[0][0] = 1;
    matriz[0][1] = 2;
    matriz[0][2] = 3;
    matriz[1][0] = 2;
    matriz[1][1] = 4;
    matriz[1][2] = 5;
    matriz[2][0] = 3;
    matriz[2][1] = 5;
    matriz[2][2] = 6;

    resultado[0] = 10;
    resultado[1] = 20;
    resultado[2] = 30;

    double **L = new double *[ordem];
    for (int i = 0; i < ordem; i++)
    {
        L[i] = new double[ordem];
    }
    if (!simetrica(matriz, ordem))
    {
        cout<<"matriz não simetrica";
        exit(0);
    }
    
    decomposicaoCholesky(matriz, L, ordem);
    cout << "Matriz L: " << endl;
    for(int i = 0; i < ordem; i++)
    {
        for(int j = 0; j < ordem; j++)
        {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatriz LT (transposta de L):" << endl;
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            cout << L[j][i] << "\t";
        }
        cout << endl;
    }
    
    
   
    double *y = new double[ordem];

    resolverSistemaL(L, resultado, y, ordem);

    resolverSistemaU(L, y, resultado, ordem);


    for (int i = 0; i < ordem; i++)
    {
        std::cout << "x" << i + 1 << " = " << resultado[i] << std::endl;
    }

    for (int i = 0; i < ordem; i++)
    {
        delete[] matriz[i];
        delete[] L[i];
    }
    delete[] matriz;
    delete[] L;
    delete[] resultado;
    delete[] y;

    return 0;
}

void decomposicaoCholesky(double **matriz, double **L, int ordem)
{
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            double soma = 0.0;
            if (j == i)
            {
                for (int k = 0; k < j; k++)
                {
                    soma += pow(L[j][k], 2);
                }
                L[j][j] = sqrt(matriz[j][j] - soma);
            }
            else
            {
                for (int k = 0; k < j; k++)
                {
                    soma += (L[i][k] * L[j][k]);
                }
                L[i][j] = (matriz[i][j] - soma) / L[j][j];
            }
        }
    }
}

void resolverSistemaL(double **L, double *b, double *resultado, int ordem)
{
    for (int i = 0; i < ordem; i++)
    {
        resultado[i] = b[i];
        for (int j = 0; j < i; j++)
        {
            resultado[i] -= L[i][j] * resultado[j];
        }
        resultado[i] /= L[i][i];
    }
}

void resolverSistemaU(double **LT, double *y, double *resultado, int ordem)
{
    for (int i = ordem - 1; i >= 0; i--)
    {
        resultado[i] = y[i];
        for (int j = i + 1; j < ordem; j++)
        {
            resultado[i] -= LT[j][i] * resultado[j];
        }
        resultado[i] /= LT[i][i];
        if(abs(resultado[i])<0.00001)
        {
            resultado[i] = 0;
        }
    }
}


bool simetrica(double **matriz, int ordem) {

    for (int i = 0; i < ordem; ++i) {
        for (int j = 0; j < ordem; ++j) {
            if (matriz[i][j] != matriz[j][i]) {
                return false;
            }
        }
    }
    return true;
}