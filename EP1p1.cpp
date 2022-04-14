#include <iostream>
#include <cmath> //biblioteca math.h
using namespace std;

/*  parte 1
    Método do ponto fixo para encontrar as 3 raízes da função
    f(x) = exp(x) - 2x^2
*/

//verifica se |xk+1 - xk| < E1
bool erroi(double xki, double xk, double ei){
    if(fabs(xki-xk) < ei) return true;
    return false;
}

//verifica se |f(xk+1)| < E2
bool erroii(double xki, double eii){
    double f = fabs(exp(xki) - 2*pow(xki, 2));
    if(f < eii) return true;
    return false;
}

//funções g(x) encontradas
double gi(double x){
    double gi = log(2*pow(x, 2));
    return gi;
}

double gii(double x){
    double gii = sqrt(exp(x)/2);
    return gii;
}

double giii(double x){
    double giii = -sqrt(exp(x)/2);
    return giii;
}

//funções recursivas para achar as raizes das funções g(x)
double iteracaogi(double xk, double ei, double eii){
    double xki = gi(xk);
    if(erroi(xki, xk, ei) || erroii(xki, eii)) return xki;
    return iteracaogi(xki, ei, eii);
}

double iteracaogii(double xk, double ei, double eii){
    double xki = gii(xk);
    if(erroi(xki, xk, ei) || erroii(xki, eii)) return xki;
    return iteracaogii(xki, ei, eii);
}

double iteracaogiii(double xk, double ei, double eii){
    double xki = giii(xk);
    if(erroi(xki, xk, ei) || erroii(xki, eii)) return xki;
    return iteracaogiii(xki, ei, eii);
}

//recebe os valores dos erros e de x0 do usuário
void recebe(double *ei, double *eii, double *xo, double *intervalo){
    cout<< "Insira o E1 (erro 1)\n";
    cin>> *ei;
    cout<< "Insira o E2 (erro 2)\n";
    cin>> *eii;
    cout<< "Insira o valor de x0 no intervalo x0 > " << *intervalo << "\n";
    cin>> *xo;
    while(*xo < *intervalo){
        cout<< "Valor de x0 incorreto. Por favor, insira x0 no intervalo x0 > " << intervalo << "\n";
        cin>> *xo;
    }
    return;
}

main(){
    double gi, gii, giii; 
    double ei, eii;
    double xo;
    //temos que calcular o intervalo para cada g(x)
    double intervalo = 0.02; 

    recebe(&ei, &eii, &xo, &intervalo); //recebe parametros do usuario

    //iteração para achar xk
    double resulti = iteracaogi(xo, ei, eii);
    cout<< "raiz 1: " <<resulti << "\n";
    double resultii = iteracaogii(xo, ei, eii);
    cout<< "raiz 2: " <<resultii << "\n";
    double resultiii = iteracaogiii(xo, ei, eii);
    cout<< "raiz 3: " <<resultiii << "\n";

}

