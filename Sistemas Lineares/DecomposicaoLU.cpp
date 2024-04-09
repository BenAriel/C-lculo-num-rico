#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void decomposicaoLU(double **matriz, int ordem, double **L, double **U);
double *resolverSistemaL(double **L, double *b, int ordem);
double *resolverSistemaU(double **U, double *y, int ordem);
void mostrarSolucao(double *solucao, int ordem);
bool zerada(double * vetor, int tamanho);
bool linhaColunaZerada(double ** matriz,int ordem);
bool iguais(double * vetorlinha,double * vetorcoluna,double ** matriz,int ordem,int atual);
bool linhaColunaIguais(double ** matriz,int ordem);
bool verificaProporcionalidade(double** matriz, int ordem);
void inverterLinha(double ** matriz, int ordem,double * resultado);


int main()
{
    int ordem = 3;

    double **matriz = new double *[ordem];
    double **L = new double *[ordem];
    double **U = new double *[ordem];

    for (int i = 0; i < ordem; i++)
    {
        matriz[i] = new double[ordem];
        L[i] = new double[ordem];
        U[i] = new double[ordem];
    }

    double *b = new double[ordem];
    double *resultado = new double[ordem];

    // Preencher a matriz e o vetor b (lado direito do sistema)
    matriz[0][0] = 3;
    matriz[0][1] = -4;
    matriz[0][2] = 1;
    matriz[1][0] = 1;
    matriz[1][1] = 2;
    matriz[1][2] = 2;
    matriz[2][0] = 4;
    matriz[2][1] = 0;
    matriz[2][2] = -3;

    b[0] = 9;
    b[1] = 3;
    b[2] = -2;
    if(linhaColunaZerada(matriz,ordem)== true)
     {
         cout<<" nemhuma linha ou coluna pode ser zerada";
         exit(0);
     }

     if(linhaColunaIguais(matriz,ordem)==true)
     {
         cout<<" nemhuma linha ou coluna pode ser igual a outra";
          exit(0);

     }
     if(verificaProporcionalidade(matriz,ordem)==true)
     {

         cout<<" nenhuma linha ou coluna pode ser proporcional a outra";
          exit(0);
     }
    decomposicaoLU(matriz, ordem, L, U);
    double *y = resolverSistemaL(L, b, ordem);
    resultado = resolverSistemaU(U, y, ordem);
    mostrarSolucao(resultado, ordem);
    for (int i = 0; i < ordem; i++)
    {
        delete[] matriz[i];
        delete[] L[i];
        delete[] U[i];
    }
    delete[] matriz;
    delete[] L;
    delete[] U;
    delete[] b;
    delete[] y;
    delete[] resultado;

    return 0;
}

void decomposicaoLU(double **matriz, int ordem, double **L, double **U)
{
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            U[i][j] = matriz[i][j];
            L[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int k = 0; k < ordem - 1; k++)
    {
        for (int i = k + 1; i < ordem; i++)
        {
            double fator = U[i][k] / U[k][k];
            L[i][k] = fator;

            for (int j = k; j < ordem; j++)
            {
                U[i][j] -= fator * U[k][j];
            }
        }
    }
}

double *resolverSistemaL(double **L, double *b, int ordem)
{
    double *y = new double[ordem];
    for (int i = 0; i < ordem; i++)
    {
        y[i] = b[i];
        for (int j = 0; j < i; j++)
        {
            y[i] -= L[i][j] * y[j];
        }
    }
    return y;
}

double *resolverSistemaU(double **U, double *y, int ordem)
{
    double *resultado = new double[ordem];
    for (int i = ordem - 1; i >= 0; i--)
    {
        resultado[i] = y[i];
        for (int j = i + 1; j < ordem; j++)
        {
            resultado[i] -= U[i][j] * resultado[j];
        }
        resultado[i] /= U[i][i];
        if(abs(resultado[i])<0.00001)
        {
            resultado[i] = 0;
        }
    }
    return resultado;
}

void mostrarSolucao(double *solucao, int ordem)
{
    cout << "Solucao:" << endl;
    for (int i = 0; i < ordem; i++)
    {
        cout << "x" << i + 1 << " = " << solucao[i] << endl;
    }
}
bool zerada ( double* vetor,int tamanho) {

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] != 0)
        {
            return false;
        }
    }

    return true;
}

bool linhaColunaZerada(double ** matriz,int ordem)
{
    double * linha = new double[ordem];
    double * coluna = new double[ordem];


    for(int i =0;i<ordem;i++)
    {
    for(int j = 0;j<ordem;j++)
    {
        linha[j] = matriz[i][j];
        coluna[j] = matriz[j][i];
    }

        if(zerada(linha,ordem)==true || zerada(coluna,ordem)== true)
        {

            delete [] linha;
            delete [] coluna;
            return true;
        }
    }
    delete [] linha;
    delete [] coluna;
    return false;
}

bool iguais(double * vetorlinha,double * vetorcoluna,double ** matriz,int ordem,int atual)
{
    //esse if � usado para nao comprar a ultima coluna ou linha com ele mesmo
    if(atual != ordem)
    {
        //loop para verificar se a linha atual � igual as subsequentes. EXEMPLO: se a linha 1 � igual a linha 2,3 ou 4.
        for(int i = atual+1;i<ordem;i++)
        {
            bool linhaigual=true;bool colunaigual=true;
           for(int j=0;j<ordem;j++)
           {    //verifica se a linha atual � igual a outra
                if(vetorlinha[j]!= matriz[i][j])
                {
                 linhaigual = false;
                }
                //verifica se a coluna atual � igual a outra
                if(vetorcoluna[j]!= matriz[j][i])
                {
                colunaigual=false;
                }
          }
                //se alguma linha for igual a outra,retorna true.
          if(linhaigual != false || colunaigual != false)
                {
                    return true;
                }
        }
        return false;
    }

    else
        return false;

}

bool linhaColunaIguais(double ** matriz,int ordem)
{

    double * linha = new double[ordem];
    double * coluna = new double[ordem];


    for(int i =0;i<ordem;i++)
    {
    for(int j = 0;j<ordem;j++)
    {
        linha[j] = matriz[i][j];
        coluna[j] = matriz[j][i];
    }
    int l=i;

                if(iguais(linha,coluna,matriz,ordem,l)==true)
        {
            delete [] linha;
            delete [] coluna;
            return true;
        }

    }
    delete [] linha;
    delete [] coluna;
    return false;
}

bool verificaProporcionalidade(double** matriz, int ordem) {
    for (int i = 0; i < ordem; ++i) {
        for (int j = i + 1; j < ordem; ++j) {
            // Verifica se a linha i � proporcional � linha j
            bool proporcionalPorLinhas = true;
            for (int k = 0; k < ordem; ++k) {
                if (matriz[j][k] != 0 && matriz[i][k] / matriz[j][k] != matriz[i][0] / matriz[j][0]) {
                    proporcionalPorLinhas = false;
                    break;
                }
            }

            // Verifica se a coluna i � proporcional � coluna j
            bool proporcionalPorColunas = true;
            for (int k = 0; k < ordem; ++k) {
                if (matriz[k][j] != 0 && matriz[k][i] / matriz[k][j] != matriz[0][i] / matriz[0][j]) {
                    proporcionalPorColunas = false;
                    break;
                }
            }

            // Se encontrou proporcionalidade, retorna verdadeiro
            if (proporcionalPorLinhas || proporcionalPorColunas) {
                return true;
            }
        }
    }
    return false;  // Se nenhum par de linhas ou colunas for proporcional, retorna falso
}


void inverterLinha(double ** matriz, int ordem,double * resultado)
{

    for (int i = 0;i<ordem;i++)
    {

        if(matriz[i][i]==0)
        {
            for (int j = i+1;j<ordem;j++)
            {
                if(matriz[j][i] != 0)
                {
                    swap(matriz[i],matriz[j]);
                    swap(resultado[i],resultado[j]);
                    break;
                }
            }
        }
    }
}

