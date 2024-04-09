#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
double f(const double x) {//retorna valor da funcao
// aqui é definida qual a função.
return (pow(x,3) + 2*x + 8);
}

double new_x(const double a, const double b) {//encontra o novo valor do x baseado no a e b
return (a * f(b) - b * f(a)) / (f(b) - f(a));// x = a * f(b) - b * f(a)
}

int main() {
    cout<< "Digite o valor de a,b e a precisao,respctivamente:";
double a,b,x,precisao;
cin>>a>>b>>precisao;

if(f(a) * f(b)<0)
{
    cout<<"existe raiz no intervalo. iremos calcular."<<endl;
    const double n = (b-a);
   const double K = ceil((log10(n) - log10(precisao)) / log10(2.0));//numero de vezes que o loop irá rodar. o ceil arredonda pra cima.
    cout<<K<<endl;

    x = new_x(a,b);
    for(int i = 0;i<=K;i++)
    {
        if( fabs(b-a) < precisao || f(x)<precisao) //módulo do número.
        {
            cout<<"a raiz proxima e "<< x<<endl;
            cout<<"foi achada na rodada "<<i<<endl;
            break;
        }

            if (f(a) * f(x) < 0)
        {
            b = x;
            x = new_x(a, b);
        }
          else
        {
            a = x;
            x = new_x(a, b);
        }
    }
}
else
{
    cout<<"nao existe raiz no intervalo";
}

}

