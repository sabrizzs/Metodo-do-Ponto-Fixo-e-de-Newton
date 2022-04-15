#include <iostream>
#include <cmath>
using namespace std;

/*  parte 2
    Método de Newton
    Algoritmo que gera uma imagem que ilustra as bacias de convergência de uma função.
*/

//ponteiro para uma funcao double que aceita double e int como parametro
typedef double (*fct_ptr)(double, int);

//funcao I = x^6-1
double funcaoi(double x, int param){
    // se param == 0 calcula a funcao, se != 0 calcula a derivada
    if(param) return 6*pow(x, 5);
    else return pow(x, 6) - 1; 
}

//funcao II = x^3 - 2
double funcaoii(double x, int param){
    if(param) return 2*pow(x, 2);
    else return pow(x, 3) - 2;
}

//calcula o valor da função f aplicada em x
double evalf(double x, fct_ptr funcao){
    return funcao(x, 0);
}

//calcula o valor da derivada da função f aplicada em x
double evalDf(double x, fct_ptr funcao){
    return funcao(x, 1);
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

    cout<< "Funcao I com x = 2\n" << evalf(2, funcaoi) << "\n";
    cout<< "Derivada da funcao I com x = 2\n" << evalDf(2, funcaoi) << "\n";

    return 0;
}