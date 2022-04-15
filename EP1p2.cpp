#include <iostream>
#include <cmath>
using namespace std;

/*  parte 2
    Método de Newton
    Algoritmo que gera uma imagem que ilustra as bacias de convergência de uma função.
*/

//ponteiro para uma funcao double que aceita double como parametro
typedef double (*fct_ptr)(double);

//funcao 1 = x^6-1
double funcaoi(double x){
    return pow(x, 6) - 1;
}

//funcao 2 = x^3 - 2
double funcaoii(double x){
    return pow(x, 3) - 2; 
}

//calcula o valor da função f aplicada em x
double evalf(double x, fct_ptr funcao){
    return funcao(x);
}

//calcula o valor da derivada da função f aplicada em x
void evalDf(double x){
    return;
}

//acha as bacias de convergência da função f no domínio [l1, u1]x[l2, u2] e gera um arquivo output.txt que contém os dados para a geração da imagem das bacias
void newton_basis(double l, double u, double p){
    return;
}

//aplica o método de Newton para achar uma raiz da função f (com primeira derivada f0), partindo do ponto x0.
void newton(double xo){
    return;
}

void parteii(){
    return;
}

int main(){
    parteii();
    double result = evalf(2, funcaoi);
    cout<< "teste\n";
    cout<< result << "\n";
    cout<< evalf(2, funcaoii) << " teste 2\n";

    return 0;
}