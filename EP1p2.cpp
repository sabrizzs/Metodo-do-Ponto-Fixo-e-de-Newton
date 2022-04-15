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
 //funcao III = x^3 - 7
double funcaoiii(double x, int param){
    if(param) return 3*pow(x, 2);
    else return pow(x, 3)-7;
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

//https://sites.icmc.usp.br/andretta/ensino/aulas/sme0500-1-12/newton.pdf slide 7
//aplica o método de Newton para achar uma raiz da função f (com primeira derivada f0), partindo do ponto x0.
bool newton(double xo, double tol, double it, fct_ptr funcao, double *raiz){
    //xo = aproximacao inicial, tol = tolerancia, it = numero de iteracoes
    int k = 0;
    while(k < it){
        double x = xo - (evalf(xo, funcao)/evalDf(xo, funcao));
        if(abs(x-xo) < tol || abs(x-xo)/fabs(x) < tol || abs(evalf(x, funcao)) < tol){
            *raiz = x;
            return true;
        }
        k += 1;
        xo = x;
    }
    cout<< "O metodo falhou apos "<< it << " iteracoes.\n";
    return false;
}

void parteii(){
    //testes
    cout<< "Funcao I com x = 2\n" << evalf(2, funcaoi) << "\n";
    cout<< "Derivada da funcao I com x = 2\n" << evalDf(2, funcaoi) << "\n";
    //testes com o metodo de newton
    double raiz;
    if(newton(2, 0.0001, 20, funcaoii, &raiz)) cout<< "Convergiu e a raiz eh: " << raiz << endl;
    else cout<< "Nao convergiu\n";
    return;
}

int main(){
    parteii();
    return 1;
}