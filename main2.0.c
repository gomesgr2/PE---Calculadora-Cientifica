#include<stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX_TAMANHO_DA_PALAVRA 100
#define NUMERO_DE_OPERACOES 5
#define NUMERO_DE_FIGURAS_PLANAS 7
#define NUMERO_DE_FIGURAS_ESPACIAS 7
#define PI 3.14159265358979323846

//Definir variáveis globais
// [tipo operação] [operaçao] [Resultado]
float historico[21][3];
int cont = 0;


//função ler histórico de operações
void lerhistorico() {
    
    if (cont != 0) { 
        for (int i = 0; i < cont; i++) {
            
            if (historico[i][0] == 1) {
                printf("[%d] Operacoes basicas, ", i + 1);
                    if (historico[i][1] == 1) {
                        printf("soma, resultado = %.4f\n", historico[i][2]);
                    } else if (historico[i][1] == 2) {
                        printf("subtracao, resultado = %.4f\n", historico[i][2]);
                    } else if (historico[i][1] == 3) {
                        printf("multiplicacao, resultado = %.4f\n", historico[i][2]);
                    } else if (historico[i][1] == 4) {
                        printf("divisao, resultado = %.4f\n", historico[i][2]);
                    } else {
                        printf("potenciacao, resultado = %.4f\n", historico[i][2]);
                    }

            } else if (historico[i][0] == 2) {
                printf("[%d] Funcoes matematicas, ", i + 1);

            } else {
                printf("[%d] Areas de figuras geometricas, ", i + 1);
            }
        }
    } else {
        printf("Nenhuma operacao realizada anteriormente\n");
    }
}

//função criar linha para menus
void criarlinha(int n) {
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
}



void imprimeListaDePalavras( char arr[][MAX_TAMANHO_DA_PALAVRA], int tam){
    
    printf("\nEscolha o tipo de operacao desejada:\n");
    criarlinha(34);

    for(int i =0; i < tam; i++  ){
        printf("|(%d)             |%s\n",i, arr[i]);
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
        switch(operacao) {
            case 1 :
                resultado = calculoQuadrado();
                break;
            case 2 :
                resultado = calculoTrianguloOuRetangulo(0);
                break;
            case 3 :
                resultado = calculoTrianguloOuRetangulo(1);
                break;
            
            case 4:
                resultado = calculoTrapezio();
                break;
               
            case 5 :
                resultado = calculoCirculo();
                break;

            case 6 :
                resultado = calculoLosango();
                break;
            default :
                printf("Operação inválida !");
                break;
        } 
        imprimeValorDaArea(listaDeFigurasPlanas, resultado, operacao);
        imprimeListaDePalavras(listaDeFigurasPlanas, NUMERO_DE_FIGURAS_PLANAS );
        // itoa(resultadoString, resultado, MAX_TAMANHO_DA_PALAVRA);
        
        scanf("%d",&operacao);
        
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
            // 
            break;
        
        default :
            break;

    }

    return;
}
void operacoesbasicas() {
    float a, b, esc = 0;
    char op;

    while (esc == 0) {
        printf("Digite o primeiro numero:\n");
            scanf("%f", &a);
        printf("Digite a operacao (+, -, *, /, ^): \n");
            scanf(" %c", &op);
        printf("Digite o segundo numero:\n");
            scanf("%f", &b);

        switch (op) {

            case '+':
                printf("%.2f %c %.2f = %.4f\n", a, op, b, (a + b));
                historico[cont][1] = 1;
                historico[cont][2] = (a + b);
                esc = 1;
                break;
            case '-':
                printf("%.2f %c %.2f = %.4f\n", a, op, b, (a - b));
                esc = 1;
                historico[cont][1] = 2;
                historico[cont][2] = (a - b);
                break;
            case '*':
                printf("%.2f %c %.2f = %.4f\n", a, op, b, (a*b));
                esc = 1;
                historico[cont][1] = 3;
                historico[cont][2] = (a*b);
                break;
            case '/':
                printf("%.2f %c %.2f = %.4f\n", a, op, b, (a/b));
                esc = 1;
                historico[cont][1] = 4;
                historico[cont][2] = (a/b);
                break;
            case '^':
                printf("%.2f %c %.2f = %.4f\n", a, op, b, potencia(a,b));
                esc = 1;
                historico[cont][1] = 5;
                historico[cont][2] = potencia(a,b);
                break;
            default:
                printf("Operacao invalida! Digite novamente\n");
                break;

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


    while(escolha != 5){
        if (cont >= 20) {
            printf("Mais de 20 operacoes realizadas! O historico foi apagado.\n");
            cont = 0;
        }
        switch(escolha) {
            case 0:
                historico[cont][0] = 1;
                operacoesbasicas();
                cont++;
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


    

    return 0;
}
