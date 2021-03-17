#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_TAMANHO_DA_PALAVRA 100
#define NUMERO_DE_OPERACOES 5
#define NUMERO_DE_FIGURAS_PLANAS 7
#define NUMERO_DE_FIGURAS_ESPACIAS 7
#define PI 3.14159265358979323846
#define INDICE_RESULTADO 3

//Definir variáveis globais
// [tipo operação] [operaçao1] [operação2] [Resultado]
float historico[21][4];
int cont = 0;

//função criar linha para menus
void criarlinha(int n) {
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
}

//função ler histórico de operações
void lerhistorico() {
    
    if (cont != 0) { 
        for (int i = 0; i < cont; i++) {
            criarlinha(90);
            if (historico[i][0] == 1) {
                printf("[%d] Operacoes basicas, ", i + 1);
                    if (historico[i][1] == 1) {
                        printf("soma, resultado = %.4f\n", historico[i][INDICE_RESULTADO]);
                    } else if (historico[i][1] == 2) {
                        printf("subtracao, resultado = %.4f\n", historico[i][INDICE_RESULTADO]);
                    } else if (historico[i][1] == 3) {
                        printf("multiplicacao, resultado = %.4f\n", historico[i][INDICE_RESULTADO]);
                    } else if (historico[i][1] == 4) {
                        printf("divisao, resultado = %.4f\n", historico[i][INDICE_RESULTADO]);
                    } else {
                        printf("potenciacao, resultado = %.4f\n", historico[i][INDICE_RESULTADO]);
                    }

            } else if (historico[i][0] == 2) {
                printf("[%d] Funcoes matematicas, ", i + 1);

            } else {
                printf("[%d] Areas de figuras geometricas, ", i + 1);
                    if(historico[i][1] == 0) {
                        printf("figuras planas, ");
                            if (historico[i][2] == 1) {
                                printf("area do quadrado, resultado: %.4f\n", historico[i][INDICE_RESULTADO]);
                            } else if (historico[i][2] == 2) {
                                printf("area do retangulo, resultado: %.4f\n", historico[i][INDICE_RESULTADO]);
                            } else if (historico[i][2] == 3) {
                                printf("area do triangulo, resultado: %.4f\n", historico[i][INDICE_RESULTADO]);
                            } else if (historico[i][2] == 4) {
                                printf("area do trapezio, resultado: %.4f\n", historico[i][INDICE_RESULTADO]);
                            } else if (historico[i][2] == 5) {
                                printf("area do circulo, resultado: %.4f\n", historico[i][INDICE_RESULTADO]);
                            } else {
                                printf("area do losango, resultado: %.4f\n", historico[i][INDICE_RESULTADO]);
                            }
                    } else {
                        printf("figuras espaciais, ");
                    }
            }
        }
        criarlinha(90);
    } else {
        printf("Nenhuma operacao realizada anteriormente\n");
    }
}

void imprimeListaDePalavras( char arr[][MAX_TAMANHO_DA_PALAVRA], int tam){
    
    printf("\nEscolha o tipo de operacao desejada:\n");
    criarlinha(34);

    for(int i =0; i < tam; i++  ){
        printf("|(%d) %s \n",i, arr[i]);
        criarlinha(34);
    }

}



float potencia(float base, int numeroDeFatores){

    float resultado = 0;

    if(numeroDeFatores ==0){
        return 1;
    }
    else {
        resultado = base * potencia(base, numeroDeFatores-1);
        return resultado;
    }

}


void imprimeValorDaArea(char  arr[][MAX_TAMANHO_DA_PALAVRA], float resultado, int posicao){
    printf("Valor da area do %s : %.2f\n", arr[posicao], resultado);
    return ;
}

float calculoQuadrado(){
    float lado;

    printf("Digite o valor de um lado:\n");

    scanf("%f",&lado);

    float resultado = potencia(lado, 2);

    return resultado;
}

float calculoTrianguloOuRetangulo(int id){
    
    float base;
    float altura;

    printf("Digite o valor da base :");
    scanf("%f", &base);

    printf("digite o valor da altura :");
    scanf("%f", &altura);

    if(id == 0){
        return (base * altura)/2;
    }

    return (base * altura);
}


float calculoTrapezio(){
    float baseMaior;
    float baseMenor;
    float altura;

    printf("Digite o valor da base maior :");
    scanf("%f", &baseMaior);

    
    printf("Digite o valor da base menor :");
    scanf("%f", &baseMenor);

    printf("digite o valor da altura :");
    scanf("%f", &altura);

    return (baseMaior * baseMenor * altura)/2;

}

float calculoCirculo(){
    float raio;

    printf("Digite o valor do raio :");
    scanf("%f", &raio);

    return PI * potencia(raio, 2);

}

float calculoLosango(){
    float diagonalMaior;
    float diagonalMenor;

    printf("Digite o valor da diagonal maior :");
    scanf("%f", &diagonalMaior);

    printf("digite o valor da diagonal menor :");
    scanf("%f", &diagonalMenor);

    return (diagonalMaior * diagonalMenor)/2;

}

float AreaCubo()
{
    float A, areacubo;

    printf("Digite o valor de uma das dimensoes: \n");
    scanf("%f", &A);

    areacubo = potencia(A,3);

    return areacubo;
}

float AreaPrisma()
{
     float n, lado, altura, areaLateral, areaP, AreaTotal, base,l, h, AreaBase;

     printf("Digite o número de lados: \n");
     scanf("%f", &n);
     if (n == 3)
      {
        printf("Digite o valor da base do triangulo: \n");
        scanf("%f", &base);

        printf("Digite o valor da altura do triangulo: \n");
        scanf("%f", &h);

        AreaBase= (base*h)/2;

       }

        else if (n == 4)
        {
         printf("Digite o valor da base quadrilatero: \n");
         scanf("%f", &base);

         printf("Digite o valor da altura do quadrilatero: \n");
         scanf("%f", &h);

         AreaBase= (base*h);

        }

          else if (n == 5)
          {
            printf("Digite o valor da lado do pentagono: \n");
            scanf("%f", &l);

            printf("Digite o valor da altura do pentagono: \n");
            scanf("%f", &h);

            AreaBase= ((5*l)*h);

          }

            else if (n == 6)
            {
             printf("Digite o valor da lado hexagono: \n");
             scanf("%f", &l);

             AreaBase= ((3*(l*l))*(sqrt(3)))/2;

            }


     printf("Lado do paralelogramo: \n");
     scanf("%f", &lado);

     printf("Altura do paralelogramo: \n");
     scanf("%f", &altura);

     areaP= lado*altura;
     areaLateral= n*areaP;

     AreaTotal = areaLateral + (2* AreaBase);

     return AreaTotal;
}

float AreaPiramide()
{
    float n, a, m, areaLateral,areaBase, AreaTotal, base,l, h, AreaBase;

    printf("Digite o número de lados: \n");
    scanf("%f", &n);
      if (n == 3)
      {
        printf("Digite o valor da base do triangulo: \n");
        scanf("%f", &base);

        printf("Digite o valor da altura do triangulo: \n");
        scanf("%f", &h);

        AreaBase= (base*h)/2;

       }

        else if (n == 4)
        {
         printf("Digite o valor da base quadrilatero: \n");
         scanf("%f", &base);

         printf("Digite o valor da altura do quadrilatero: \n");
         scanf("%f", &h);

         AreaBase= (base*h);

        }

          else if (n == 5)
          {
            printf("Digite o valor da lado do pentagono: \n");
            scanf("%f", &l);

            printf("Digite o valor da altura do pentagono: \n");
            scanf("%f", &h);

            AreaBase= ((5*l)*h);

          }

            else if (n == 6)
            {
             printf("Digite o valor da lado hexagono: \n");
             scanf("%f", &l);

             AreaBase= ((3*(l*l))*(sqrt(3)))/2;

            }




        printf("Digite o valor da apótema: \n");
    scanf("%f", &a);

    printf("Digite o valor da aresta da base: \n");
    scanf("%f", &m);

    areaLateral = n*((a*m)/2);

    AreaTotal = areaLateral + AreaBase;

    return AreaTotal;

}

float AreaCilindro()
{
    float raio, altura, AreaTotal;

    printf("Digite o valor do raio");
    scanf("%f", &raio);

    printf("Digite o valor do altura");
    scanf("%f", &altura);

    AreaTotal = 2*PI*(raio*(raio + altura));

    return AreaTotal;

}

float AreaEsfera()
{
    float raio, AreaTotal;

    printf("Digite o valor do raio: \n");
    scanf("%f", &raio);

    AreaTotal = 4*PI*(potencia(raio,2));

    return AreaTotal;
}
float AreaCone()
{
    float altura, raio, geratriz, AreaTotal;

    printf("Digite o valor da altura: \n");
    scanf("%f", &altura);

    printf("Digite o valor do raio: \n");
    scanf("%f", &raio);

    printf("Digite o valor da geratriz: \n");
    scanf("%f", &geratriz);

    AreaTotal= PI*raio*(geratriz+raio);

    return AreaTotal;
}


void calculaFigurasespaciais() {
    int operacao;
    float resultado;
    char resultadoString[MAX_TAMANHO_DA_PALAVRA];

    char listaDeFigurasEspaciais[NUMERO_DE_FIGURAS_ESPACIAS][MAX_TAMANHO_DA_PALAVRA] = {"Sair","Cubo", "Cone", "Prisma", "Piramide", "Esfera/Superficie Esferica", "Cilindro"};


    printf("Voce escolheu o calculo de Figuras Espaciais!\n");
    criarlinha(34);


    imprimeListaDePalavras(listaDeFigurasEspaciais, NUMERO_DE_FIGURAS_ESPACIAS);

    scanf("%d", &operacao);

        while(operacao != 0){
        historico[cont][1] = 0;
        switch(operacao) {
            case 1 :
                historico[cont][2] = 1;
                resultado = AreaCubo();
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
            case 2 :
                historico[cont][2] = 2;
                resultado = AreaCone(0);
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
            case 3 :
                historico[cont][2] = 3;
                resultado = AreaPrisma(1);
                historico[cont][INDICE_RESULTADO] = resultado;
                break;

            case 4:
                historico[cont][2] = 4;
                resultado = AreaPiramide();
                historico[cont][INDICE_RESULTADO] = resultado;
                break;

            case 5 :
                historico[cont][2] = 5;
                resultado = AreaEsfera();
                historico[cont][INDICE_RESULTADO] = resultado;
                break;

            case 6 :
                historico[cont][2] = 6;
                resultado = AreaCilindro();
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
            default :
                printf("Operação inválida !");
                if (cont != 0) {
                    cont--;
                }
                break;
        }
        imprimeValorDaArea(listaDeFigurasEspaciais, resultado, operacao);
        imprimeListaDePalavras(listaDeFigurasEspaciais, NUMERO_DE_FIGURAS_ESPACIAS );


        scanf("%d",&operacao);
        if (operacao != 0){
            cont++;
        }
        }

    return;

}
    


 

void calculaFigurasPlanas(){
    
    int operacao;
    float resultado;
    char resultadoString[MAX_TAMANHO_DA_PALAVRA];


    char listaDeFigurasPlanas[NUMERO_DE_FIGURAS_PLANAS][MAX_TAMANHO_DA_PALAVRA] = {"Sair","Quadrado", "Triangulo", "Retangulo", "Trapezio", "Circulo", "Losango"};


    printf("Voce escolheu o calculo de Figuras planas!\n");
    criarlinha(34);
    

    imprimeListaDePalavras(listaDeFigurasPlanas, NUMERO_DE_FIGURAS_PLANAS );

    scanf("%d", &operacao);

   
    while(operacao != 0){
        historico[cont][1] = 0;
        switch(operacao) {
            case 1 :
                historico[cont][2] = 1;
                resultado = calculoQuadrado();
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
            case 2 :
                historico[cont][2] = 2;
                resultado = calculoTrianguloOuRetangulo(0);
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
            case 3 :
                historico[cont][2] = 3;
                resultado = calculoTrianguloOuRetangulo(1);
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
            
            case 4:
                historico[cont][2] = 4;
                resultado = calculoTrapezio();
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
               
            case 5 :
                historico[cont][2] = 5;
                resultado = calculoCirculo();
                historico[cont][INDICE_RESULTADO] = resultado;
                break;

            case 6 :
                historico[cont][2] = 6;
                resultado = calculoLosango();
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
            default :
                printf("Operação inválida !");
                if (cont != 0) {
                    cont--;
                }
                break;
        }
        imprimeValorDaArea(listaDeFigurasPlanas, resultado, operacao);
        imprimeListaDePalavras(listaDeFigurasPlanas, NUMERO_DE_FIGURAS_PLANAS );
        // itoa(resultadoString, resultado, MAX_TAMANHO_DA_PALAVRA);
        
        scanf("%d",&operacao);
        if (operacao != 0){
            cont++;
        }
        }

    return;





}

void defineCalculoDeFiguras() {

    int tipo;

    printf("Você escolheu o calculo de Figuras!\n");
    criarlinha(34);


    printf("Selecione qual tipo voce deseja :\n|(0)        |Figuras planas\n|(1)        |Figuras espacias\n");

    scanf("%d", &tipo);

    switch(tipo){
        case 0 : 
            calculaFigurasPlanas();
            break;

        case 1 : 
            calculaFigurasespaciais();
            break;
        
        default :
            break;

    }

    return;
}
void operacoesbasicas() {
    float a, b, esc = 0;
    char op;

    printf("Digite o primeiro numero:\n");
    scanf("%f", &a);
    printf("Digite a operacao (+, -, *, /, ^): \n");
            scanf(" %c", &op);
    printf("Digite o segundo numero:\n");
            scanf("%f", &b);

    while (1 == 1) {
              switch (op) {

                case '+':
                    criarlinha(20);
                    printf("%.2f %c %.2f = %.4f\n", a, op, b, (a + b));
                    criarlinha(20);
                    a = a + b;
                    historico[cont][1] = 1;
                    historico[cont][INDICE_RESULTADO] = a;
                    cont++;
                    break;
                case '-':
                    criarlinha(20);
                    printf("%.2f %c %.2f = %.4f\n", a, op, b, (a - b));
                    criarlinha(20);
                    a = a - b;
                    historico[cont][1] = 2;
                    historico[cont][INDICE_RESULTADO] = a;
                    cont++;
                    break;
                case '*':
                    criarlinha(20);
                    printf("%.2f %c %.2f = %.4f\n", a, op, b, (a*b));
                    criarlinha(20);
                    a = (a*b);
                    historico[cont][1] = 3;
                    historico[cont][INDICE_RESULTADO] = a;
                    cont++;
                    break;
                case '/':
                    criarlinha(20);
                    printf("%.2f %c %.2f = %.4f\n", a, op, b, (a/b));
                    criarlinha(20);
                    a = (a/b);
                    historico[cont][1] = 4;
                    historico[cont][INDICE_RESULTADO] = a;
                    cont++;
                    break;
                case '^':
                    criarlinha(20);
                    printf("%.2f %c %.2f = %.4f\n", a, op, b, potencia(a,b));
                    criarlinha(20);
                    a = potencia(a,b);
                    historico[cont][1] = 5;
                    historico[cont][INDICE_RESULTADO] = a;
                    cont++;
                    break;
                default:
                    printf("Operacao invalida! Digite novamente\n");
                    break;

            }
            printf("Digite a operacao (+, -, *, /, ^): \nPara sair, digite 's'\n");
                scanf(" %c", &op);
                if ((op == 's') || (op == 'S')) {
                    break;
                } else if ((op == '+') || (op == '-') || (op == '*') || (op == '/') || (op == '^')) {
                    historico[cont][0] = 1;
                    printf("Digite o proximo numero:\n");
                        scanf("%f", &b);
                }
    }
}

void funcoesmatematicas() {
    printf("2");
}




int main(){
    
    //Definição de variáveis
    //escolha de operações
    int escolha;
  
   //auxiliar do historico
    int aux = 0;

    // Lista de operações 
    char arr[NUMERO_DE_OPERACOES][MAX_TAMANHO_DA_PALAVRA] = {"Operacoes basicas","funcoes matematicas", "Areas de figuras geometricas", "Historico de operacoes", "Sair"};

    // impressão inicial

    printf("Bem vindo ao UFABCalc\n");

    imprimeListaDePalavras(arr, NUMERO_DE_OPERACOES);

    scanf("%d",&escolha);


    while(escolha != 4){
        if (cont >= 20) {
            printf("Mais de 20 operacoes realizadas! O historico foi apagado.\n");
            cont = 0;
        }
        switch(escolha) {
            case 0:
                historico[cont][0] = 1;
                operacoesbasicas();
                break;
            case 1:
                historico[cont][0] = 2;
                funcoesmatematicas();
                cont++;
                break;
            case 2:
                historico[cont][0] = 3;
                defineCalculoDeFiguras();
                cont++;
                break;
            case 3:
                printf("[1] Apagar historico de operacoes\n[2] Ler historico\n");
                scanf("%d", &aux);
                if (aux == 1) {
                    cont = 0;
                } else {
                    lerhistorico();
                }
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida! Por favor, digite novamente.\n");
        }

        imprimeListaDePalavras(arr, NUMERO_DE_OPERACOES);
        scanf("%d",&escolha);
        
    }

    printf("BYE BYE");
}
