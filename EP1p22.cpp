#include <iostream>
#include <cmath>    //biblioteca math
#include <complex>  //numeros complexos
#include <stdio.h>  //'fopen'
#include <stdlib.h> //'exit'
#include <graphics.h>
using namespace std;

/*  Parte 2: 
    Método de Newton
    Algoritmo que gera uma imagem que ilustra as bacias de convergência de uma função.
*/

#define TAU 6.283185307

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
    cout<< "O metodo de Newton para achar uma raiz da função f falhou apos "<< it << " iteracoes.\n";
    return false;
}

void gnuplot(){
    int x = 0, y = 0;
    FILE *fp = NULL;
    FILE *gnupipe = NULL;
    char *gnuCommands[] = {"set title \"Bacias de convergencia\"", "plot 'pontos.txt'  using 1:2:(arg($3*{0,1})) '(%lf,%lf) (%lf)' palette"};

    fp = fopen("data.tmp", "w");
    if(fp == NULL) {
        perror ("Erro: ");
        getchar();
        exit (1);
    }
    gnupipe = popen("gnuplot -persistent", "w");

    for (int i = 0; i < 11; i++){
        fprintf(fp, "%d %d\n", x, y);
        x++; y++;
    }
    fclose(fp);

    for(int i = 0; i < 2; i++){
        fprintf(gnupipe, "%s\n", gnuCommands[i]);
    }

    fclose(gnupipe);
    return;
}

//acha as bacias de convergência da função f no domínio [l1, u1]x[l2, u2] e gera um arquivo output.txt que contém os dados para a geração da imagem das bacias
void newton_basins(double l[], double u[], double pi, double pii, fct_ptr funcao){
    FILE *pontos;
    pontos = fopen ( "pontos.txt", "w" );
    if(pontos == NULL) {
        perror ("Erro: "); //<- para comprocar é com perror e não com printf
        getchar();
        exit (1);
    }

    int shift = 5;

    for(int i = 0; i <= pi; i++){
        for(int j = 0; j <= pii; j++){
            double z;

            u[0] = i * 4.0/pii;
			u[1] = j * 4.0/pii;

            std::complex<double> complex(u[0] + l[0], -u[1] + l[1]);
            newton(abs(complex), 0.000001, 100, funcao, &z);

            fprintf(pontos, "%d    ", z.real);
            fprintf(pontos, "%d \n", z.imag);
            putpixel(u[0]/(4.0/600),u[1]/(4.0/600),1+int(shift+100+(arg(z)*14/TAU+8))%14);

            fclose(pontos);
            gnuplot();
            return;
        }
    }
    
}

void parteii(){
    cout<< "Parte 2: Metodo de Newton\nAlgoritmo que gera uma imagem que ilustra as bacias de convergencia de uma funcao f.\n";
    double l[2]; double u[2];    //domínio
    l[0] = -2; l[1] = 2;
    double pi = 500, pii = 500;   //pontos
    
    int gd,gm;
    detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	delay(2000);

    //iniciar a função abaixo com o 4º argumento sendo umas das 3 funções: funcaoi, funcaoii ou funcaoiii                    
    newton_basins(l, u, pi, pii, funcaoii);
    return;
}

int main(){

    parteii();
    return 0;
}