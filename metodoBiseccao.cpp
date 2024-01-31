#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
double f(const double x) {//retorna valor da funcao
// aqui é definida qual a função.
return (pow(x,3) + 2*x + 8);
}

double new_x(const double a, const double b) {//encontra o novo valor do x baseado no a e b
return (a+b)/2.0;
}

int main() {
    cout<< "Digite o valor de a,b e a precisao,respctivamente:";
double a,b,x,precisao;
cin>>a>>b>>precisao;

if(f(a) * f(b)<=0)
{
    cout<<"existe raiz no intervalo. iremos calcular."<<endl;
    const double n = (b-a);
   const double K = ceil((log10(n) - log10(precisao)) / log10(2.0));//numero de vezes que o loop irá rodar. o ceil arredonda pra cima.
    cout<<K<<endl;

    x = new_x(a,b);
    for(int i = 0;i<=K;i++)
    {
        if( abs(b-a) <= precisao) //módulo do número.
        {
            cout<<"a raiz proxima e "<< x<<endl;
            cout<<"foi achada na rodada "<<i<<endl;
            break;
        }

            if (f(a) * f(x) <= 0)
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
