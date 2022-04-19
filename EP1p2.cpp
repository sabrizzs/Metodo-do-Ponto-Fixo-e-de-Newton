#include <iostream>
#include <cmath> //biblioteca math
#include <complex> //numeros complexos
#include <stdio.h> //'fopen'
#include <stdlib.h> //'exit'
using namespace std;

/*  parte 2
    Método de Newton
    Algoritmo que gera uma imagem que ilustra as bacias de convergência de uma função.
*/

//ponteiro para uma funcao double que aceita double e int como parametro
typedef double (*fct_ptr)(double, int);

//funcao I = x^6 - 1
double funcaoi(double x, int param){
    // se param == 0 calcula a funcao, se != 0 calcula a derivada
    if(param) return 6*pow(x, 5);
    else return pow(x, 6) - 1; 
}

//funcao II = x^3 - 1
double funcaoii(double x, int param){
    if(param) return 2*pow(x, 2);
    else return pow(x, 3) - 1;
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

//https://sites.icmc.usp.br/andretta/ensino/aulas/sme0500-1-12/newton.pdf slide 7
//aplica o método de Newton para achar uma raiz da função f (com primeira derivada f0), partindo do ponto x0.
bool newton(double xo, double tol, double it, fct_ptr funcao, double *raiz){
    //xo = aproximacao inicial, tol = tolerancia, it = numero de iteracoes
    int k = 0;
    while(k < it){
        double x = xo - (evalf(xo, funcao)/evalDf(xo, funcao));
        if(abs(x-xo) < tol || abs(x-xo)/abs(x) < tol || abs(evalf(x, funcao)) < tol){
            *raiz = x;
            return true;
        }
        k += 1;
        xo = x;
    }
    cout<< "O metodo falhou apos "<< it << " iteracoes.\n";
    return false;
}

//acha as bacias de convergência da função f no domínio [l1, u1]x[l2, u2] e gera um arquivo output.txt que contém os dados para a geração da imagem das bacias
void newton_basins(double l, double u, double p, fct_ptr funcao){
    //cria o ponteiro
    FILE *pontos;
    
    //abre o arquivo para escritura, cada abertura o arquivo novo sobreescreve o antigo
    pontos = fopen ( "pontos.dat", "w" );

    //comprova se abriu
    if(pontos == NULL) {
        perror ("Erro: ");//<- para comprocar é com perror e não com printf
        getchar();
        exit (1);
    }

    //newton para cada um dos pontos
    for(int y = 1; y <= p; y++){
        double zy = y * (u - (-u))/(p-1) + (-u);
        for(int x = 1; x <= p; x++){
            double zx = x * (l - (-l))/(p-1) + (-l);
            std::complex<double> complex(zx, zy); //cria um numero complexo com zx e zy
            double raiz;
            newton(abs(complex), 1, 100000, funcao, &raiz); //calcula newton p/ o ponto
            fprintf(pontos, "%f\n", raiz); //imprime no arquivo
        }
    }
    fclose(pontos); //fecha o arquivo

    return;
}

void parteii(){
    //testes
    cout<< "Funcao I com x = 2\n" << evalf(2, funcaoii) << "\n";
    cout<< "Derivada da funcao I com x = 2\n" << evalDf(2, funcaoii) << "\n";
    //testes com o metodo de newton
    double raiz;
    if(newton(2, 0.0001, 20, funcaoii, &raiz)) cout<< "Convergiu e a raiz eh: " << raiz << endl;
    else cout<< "Nao convergiu\n";
    cout<< "Teste de newton_basins\n";
    newton_basins(1, 1, 4, funcaoii);
    return;
}

int main(){
    parteii();
    return 1;
}