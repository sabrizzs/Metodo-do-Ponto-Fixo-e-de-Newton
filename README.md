# EP1 - MAC0210 Laboratório de Métodos Numéricos

### Luísa Menezes da Costa
### Sabrina Araújo da Silva

## Parte 1 - Método do Ponto Fixo (MPF)

### Breve introdução ao MPF
Precisamos encontrar x ∈ R tal que f(x) = 0. Para isso, segundo o MPF, devemos encontrar x ∈ R tal que g(x) = x e, a partir de um ponto inicial x0 ∈ R, definir xk+1 = g(xk), k = 0, 1, ....

### Escolha das funções 
Em nossa implementação do ponto fixo, utilizamos três equações g(x) diferentes:
* g1(x) = ln2x^2
* g2(x) = sqrt(e^x/2)
* g3(x) = -sqrt(e^x/2)

Essas equações foram escolhidas, pois atendem aos seguintes critérios de uma
função de iteração para o MPF:
* g(x) e g'(x) são contínuas em um intervalo I;
* |g'(x)| < 1, ∀x ∈ I.

#### Manipulação de f(x) para encontrar g(x)
1. **g1(x)**

![image](https://user-images.githubusercontent.com/93349105/169684432-7a06bb2d-69bf-42b0-8aec-d2e72d247b78.png)

Por definição, o polinômio `2x^2` é sempre contínuo, e a função exponencial `f(x) = e^x`
também é contínua para todo x ∈ R. Já que a função `f(x) = ln(x)` é a inversa da função exponencial, então `f(x) = ln(x)` também é contínua em todo seu domínio (R com x ̸= 0). Logo, `g1(x) = ln(2x^2)` é contínua.

A derivada de g1(x) é g1'(x) = 2/x. Aplicando o segundo critério para a escolha de g(x), temos que:

![image](https://user-images.githubusercontent.com/93349105/169684569-a7068acf-e4b2-4e5c-a042-a53cb5ef008c.png)

2. **g2(x) e g3(x)**

![image](https://user-images.githubusercontent.com/93349105/169684587-38608dd9-5a38-4f59-9343-d5f3c6166671.png)

A função exponencial `f(x) = e^x` é contínua para todo x ∈ R, e a raiz quadrada é contínua em x ≥ 0. Logo, as funções `g2(x) = sqrt(e^x/2)` e `g3(x) = −sqrt(e^x/2)` são contínuas.

A derivada de g2(x) é `g2'(x) = e^x/(2sqrt(2)sqrt(e^x))`, que é contínua em [−∞, ∞]. Analogamente, a derivada de g3(x) é `g3'(x) =  = e^x/(2sqrt(2)sqrt(e^x))`, que também é contínua em [−∞, ∞].

#### Funções descartadas

Além das funções mencionadas acima, também encontramos a função `g4(x) = e^x/2x`. Entretanto, essa função não é contínua no intervalo desejado e, portanto, foi descartada.

### Resultados encontrados

Os resultados abaixo foram computados com um erro de 10^-3. k representa o número da iteração e xk representa o ponto encontrado na iteração k.

#### Análise dos resultados de g1(x) = ln(2x^2)

Considerando x0 = 2.4, obtivemos os seguintes resultados:

![image](https://user-images.githubusercontent.com/93349105/169684793-c88858b8-ea22-4594-9521-ed73a4494266.png)

A raiz encontrada para g1(x) foi 2.61515. O gráfico abaixo mostra a convergência da função.

![image](https://user-images.githubusercontent.com/93349105/169684824-599d205b-3960-4b5a-a8e0-c75b1466a40c.png)

#### Análise dos resultados de g2(x) = sqrt(e^x/2)

Considerando x0 = 1.7, obtivemos os seguintes resultados:

![image](https://user-images.githubusercontent.com/93349105/169684887-cbf58ee9-b179-41f1-b00d-7e115341f126.png)

A raiz encontrada para g2(x) foi 1.49031. O gráfico abaixo mostra a convergência da função.

![image](https://user-images.githubusercontent.com/93349105/169684910-36510f5a-bcab-4ec6-9333-6c1291086ef2.png)

#### Análise dos resultados de g3(x) = -sqrt(e^x/2)

Considerando x0 = 1.7, obtivemos os seguintes resultados:

![image](https://user-images.githubusercontent.com/93349105/169684940-ce539ce8-2b5f-4e94-aacf-0a1c6d09421a.png)

A raiz encontrada para g3(x) foi -0.540181. O gráfico abaixo mostra a convergência da função.

![image](https://user-images.githubusercontent.com/93349105/169684958-543bf936-dec2-4baa-b335-22cc571e49cc.png)

### Critérios de parada

No código, o usuário deve inserir E1 e E2 (erro 1 e erro 2, respectivamente), os quais irão definir os seguintes critérios de parada:
1. |xk+1 − xk| < E1
2. |f(xk+1)| < E2

## Parte 2 - Método de Newton

### Escolha das funções

Para a implementação do método de Newton, foram escolhidas as seguintes funções:
* f1(x) = x^6 − 1
* f2(x) = x^3 − 1
* f3(x) = x^3 − 7

As derivadas dessas funções são:
* f1(x) = 6x^5
* f2(x) = f3(x) = 3x^2 

Já que tanto as funções quanto suas derivadas são polinômios, elas são contínuas, o que facilita sua aplicação para o método de Newton.

