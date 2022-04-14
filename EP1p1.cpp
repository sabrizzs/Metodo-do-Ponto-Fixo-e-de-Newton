#include <iostream>
#include <cmath> //biblioteca math.h
using namespace std;

/*  parte 1
    Método do ponto fixo para encontrar as 3 raízes da função
    f(x) = exp(x) - 2x^2
*/

//avalia se g(x) e g'(x) são continuas
bool continua(){ 
    return true;
}

//avalia se o módulo de g'(x) <= k < 1
bool modulo(){ 
    //usar como argumento um ponteiro para o intervalo de x0
    return true;
}

//verifica se a g(x) converge
bool convergencia(){ //receber a função g(x)??
    if(continua() && modulo()) return true;
    else return false;
}

//verifica se |xk+1 - xk| < E1
bool erroi(){
    return true;
}

//verifica se |f(xk+1)| < E2
bool erroii(){
    return true;
}

//recebe os valores dos erros e de x0 do usuário
void recebe(double ei, double eii, double xo, double intervalo){
    cout<< "Insira o E1 (erro 1)\n";
    cin>> ei;
    cout<< "Insira o E2 (erro 2)\n";
    cin>> eii;
    cout<< "Insira o valor de x0 no intervalo x0 > " << intervalo << "\n";
    cin>> xo;
    while(xo < intervalo){
        cout<< "Valor de x0 incorreto. Por favor, insira x0 no intervalo x0 > " << intervalo << "\n";
        cin>> xo;
    }
    return;
}

main(){
    double gi, gii, giii;
    double x, xo;
    double ei, eii;
    double intervalo = 0.02; //só pra testar

    //funções g(x) encontradas
    gi = log(2*pow(x, 2));
    gii = sqrt(exp(x)/2);
    giii = -sqrt(exp(x)/2);

    //se converge o usuario digita os valores dos erros
    if(convergencia()){ //receber as 3 funções g(x)
        recebe(ei, eii, xo, intervalo);
        //iterar para achar x1, x2...
        if(erroi() || erroii()){
            //encontrou um critério de parada
        }
    }
}

