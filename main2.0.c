#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define MAX_TAMANHO_DA_PALAVRA 100
#define NUMERO_DE_OPERACOES 5
#define NUMERO_DE_FIGURAS_PLANAS 7
#define NUMERO_DE_FIGURAS_ESPACIAS 7
#define NUMERO_DE_FUNCOES_MATEMATICAS 3
#define NUMERO_DE_OPERACOES_BASICAS 6
#define PI 3.14159265358979323846
#define INDICE_RESULTADO 3

//Definir variáveis globais
// [tipo operação] [operaçao1] [operação2] [Resultado]
float historico[21][4];
int cont = -1;

//função criar linha para menus
void criarlinha(int n) {
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("\n");
}

//função ler histórico de operações
void lerhistorico() {
    
    if (cont != -1) { 
        for (int i = 0; i <= cont; i++) {
            criarlinha(90);
            if (historico[i][0] == 0) {
                printf("[%d] Operacoes basicas, ", i + 1);
                    if (historico[i][1] == 1) {
                        printf("soma, resultado = %.4f\n", historico[i][INDICE_RESULTADO]);
                    } else if (historico[i][1] == 2) {
                        printf("subtracao, resultado = %.4f\n", historico[i][INDICE_RESULTADO]);
                    } else if (historico[i][1] == 3) {
                        printf("multiplicacao, resultado = %.4f\n", historico[i][INDICE_RESULTADO]);
                    } else if (historico[i][1] == 4) {
                        printf("divisao, resultado = %.4f\n", historico[i][INDICE_RESULTADO]);
                    } else if (historico[i][1] == 5) {
                        printf("potenciacao, resultado = %.4f\n", historico[i][INDICE_RESULTADO]);
                    } else if (historico[i][1] == 6){
                        printf("raiz quadrada, resultado = %.4f\n", historico[i][INDICE_RESULTADO]);
                    }

            } else if (historico[i][0] == 1) {
                printf("[%d] Funcoes matematicas, ", i + 1);
                    if (historico[i][1] == 0) {
                        printf("MMC, resultado: %.4f\nf", historico[i][INDICE_RESULTADO]);
                    } else if (historico[i][1] == 1) {
                        printf("MDC, resultado: %.4f\n", historico[i][INDICE_RESULTADO]);
                    } else if (historico[i][1] == 2) {
                        printf("Fatorial, resultado: %.4f\n", historico[i][INDICE_RESULTADO]);
                    }

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
                            } else if (historico[i][2] == 6){
                                printf("area do losango, resultado: %.4f\n", historico[i][INDICE_RESULTADO]);
                            }
                    } else {
                        printf("figuras espaciais, ");
                            if(historico[i][2] == 1) {
                                printf("area do cubo, resultado: %.4f\n", historico[i][INDICE_RESULTADO]);
                            } else if (historico[i][2] == 2) {
                                printf("area do cone, resultado: %.4f\n", historico[i][INDICE_RESULTADO]);
                            } else if (historico[i][2] == 3) {
                                printf("area do prisma, resultado: %.4f\n", historico[i][INDICE_RESULTADO]); 
                            } else if (historico[i][2] == 4) {
                                printf("area da piramide, resultado: %.4f\n", historico[i][INDICE_RESULTADO]); 
                            } else if (historico[i][2] == 5) {
                                printf("area da esfera, resultado: %.4f\n", historico[i][INDICE_RESULTADO]); 
                            } else if (historico[i][2] == 6){
                                printf("area do cilindro, resultado: %.4f\n", historico[i][INDICE_RESULTADO]); 
                            }
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

void imprimeListaDePalavrasOPBasica(char arr[][MAX_TAMANHO_DA_PALAVRA], int tam){
    
    printf("\nEscolha o tipo de operacao desejada:\n");
    criarlinha(34);
    for (int i = 0; i < tam; i++) {
        switch(i) {
            case 0:
                printf("[+] ");
                break;
            case 1:
                printf("[-] ");
                break;
            case 2:
                printf("[*] ");
                break;
            case 3:
                printf("[/] ");
                break;
            case 4:
                printf("[^] ");
                break;
            case 5:
                printf("[r] ");
                break;
        }
        printf("%s\n", arr[i]);
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

    printf("Digite o valor do raio\n");
    scanf("%f", &raio);

    printf("Digite o valor do altura\n");
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
        switch(operacao) {
            case 1 :
                resultado = AreaCubo();
                cont++;
                historico[cont][0] = 2;
                historico[cont][1] = 1;
                historico[cont][2] = 1;
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
            case 2 :
                resultado = AreaCone(0);
                cont++;
                historico[cont][0] = 2;
                historico[cont][1] = 1;
                historico[cont][2] = 2;
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
            case 3 :
                resultado = AreaPrisma(1);
                    cont++;
                    historico[cont][0] = 2;
                    historico[cont][1] = 1;
                    historico[cont][2] = 3;
                    historico[cont][INDICE_RESULTADO] = resultado;
                break;

            case 4:
                resultado = AreaPiramide();
                cont++;
                historico[cont][0] = 2;
                historico[cont][1] = 1;
                historico[cont][2] = 4;
                historico[cont][INDICE_RESULTADO] = resultado;
                break;

            case 5 :
                resultado = AreaEsfera();
                cont++;
                historico[cont][0] = 2;
                historico[cont][1] = 1;
                historico[cont][2] = 5;
                historico[cont][INDICE_RESULTADO] = resultado;
                break;

            case 6 :
                resultado = AreaCilindro();
                cont++;
                historico[cont][0] = 2;
                historico[cont][1] = 1;
                historico[cont][2] = 6;
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
            default :
                printf("Operação inválida !");
                break;
        }
        imprimeValorDaArea(listaDeFigurasEspaciais, resultado, operacao);
        imprimeListaDePalavras(listaDeFigurasEspaciais, NUMERO_DE_FIGURAS_ESPACIAS );


        scanf("%d",&operacao);

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
        switch(operacao) {
            case 1 :
                resultado = calculoQuadrado();
                cont++;
                historico[cont][0] = 2;
                historico[cont][1] = 0;
                historico[cont][2] = 1;
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
            case 2 :
                resultado = calculoTrianguloOuRetangulo(0);
                cont++;
                historico[cont][0] = 2;
                historico[cont][1] = 0;
                historico[cont][2] = 3;
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
            case 3 :
                resultado = calculoTrianguloOuRetangulo(1);
                cont++;
                historico[cont][0] = 2;
                historico[cont][1] = 0;
                historico[cont][2] = 2;
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
            
            case 4:
                resultado = calculoTrapezio();
                cont++;
                historico[cont][0] = 2;
                historico[cont][1] = 0;
                historico[cont][2] = 4;
                historico[cont][INDICE_RESULTADO] = resultado;
                break;
               
            case 5 :
                resultado = calculoCirculo();
                cont++;
                historico[cont][0] = 2;
                historico[cont][1] = 0;
                historico[cont][2] = 5;
                historico[cont][INDICE_RESULTADO] = resultado;
                break;

            case 6 :
                resultado = calculoLosango();
                cont++;
                historico[cont][0] = 2;
                historico[cont][1] = 0;
                historico[cont][2] = 6;
                historico[cont][INDICE_RESULTADO] = resultado;
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
    char listadeoperacoesbasicas[NUMERO_DE_OPERACOES_BASICAS][MAX_TAMANHO_DA_PALAVRA] = {"Soma", "Subtracao", "Multiplicacao", "Divisao", "Potenciacao", "Raiz quadrada"};

    printf("Digite o primeiro numero:\n");
    scanf("%f", &a);
    imprimeListaDePalavrasOPBasica(listadeoperacoesbasicas, NUMERO_DE_OPERACOES_BASICAS);
    scanf(" %c", &op);
    
    while (1 == 1) {
              switch (op) {

                case '+':
                    printf("Digite o segundo numero:\n");
                    scanf("%f", &b);
                    criarlinha(34);
                    printf("%.2f %c %.2f = %.4f\n", a, op, b, (a + b));
                    criarlinha(34);
                    a = a + b;
                    cont++;
                    historico[cont][0] = 0;
                    historico[cont][1] = 1;
                    historico[cont][INDICE_RESULTADO] = a;

                    break;
                case '-':
                    printf("Digite o segundo numero:\n");
                    scanf("%f", &b);
                    criarlinha(34);
                    printf("%.2f %c %.2f = %.4f\n", a, op, b, (a - b));
                    criarlinha(34);
                    a = a - b;
                    cont++;
                    historico[cont][0] = 0;
                    historico[cont][1] = 2;
                    historico[cont][INDICE_RESULTADO] = a;

                    break;
                case '*':
                    printf("Digite o segundo numero:\n");
                    scanf("%f", &b);
                    criarlinha(34);
                    printf("%.2f %c %.2f = %.4f\n", a, op, b, (a*b));
                    criarlinha(34);
                    a = (a*b);
                    cont++;
                    historico[cont][0] = 0;
                    historico[cont][1] = 3;
                    historico[cont][INDICE_RESULTADO] = a;

                    break;
                case '/':
                    printf("Digite o segundo numero:\n");
                    scanf("%f", &b);
                    criarlinha(34);
                    printf("%.2f %c %.2f = %.4f\n", a, op, b, (a/b));
                    criarlinha(34);
                    a = (a/b);
                    cont++;
                    historico[cont][0] = 0;
                    historico[cont][1] = 4;
                    historico[cont][INDICE_RESULTADO] = a;

                    break;
                case '^':
                    printf("Digite o segundo numero:\n");
                    scanf("%f", &b);
                    criarlinha(34);
                    printf("%.2f %c %.2f = %.4f\n", a, op, b, potencia(a,b));
                    criarlinha(34);
                    a = potencia(a,b);
                    cont++;
                    historico[cont][0] = 0;
                    historico[cont][1] = 5;
                    historico[cont][INDICE_RESULTADO] = a;

                    break;
                case 'r':
                    criarlinha(34);
                    printf("Raiz quadrada de %.2f e: %.4f\n", a, sqrt(a));
                    criarlinha(34);
                    a = sqrt(a);
                    cont++;
                    historico[cont][0] = 0;
                    historico[cont][1] = 6;
                    historico[cont][INDICE_RESULTADO] = a;
            
                    break;
                default:
                    printf("Operacao invalida! Digite novamente\n");
                    break;

            }
            imprimeListaDePalavrasOPBasica(listadeoperacoesbasicas, NUMERO_DE_OPERACOES_BASICAS);
            printf("Para sair, digite 's'\n");
                scanf(" %c", &op);
                if ((op == 's') || (op == 'S')) {
                    break;
                } 
    }
}

void funcoesmatematicas ()
{
  int a, b, esc = 0;
  char op;
  char listadefuncoesmatematicas[NUMERO_DE_FUNCOES_MATEMATICAS][MAX_TAMANHO_DA_PALAVRA] = {"MMC", "MDC", "Fatorial"};  

  printf("Voce escolheu funcoes matematicas!\n");
    criarlinha(34);

  while (1 == 1)
    {
      switch (op)
	{
	case '0':
	  criarlinha (20);
        printf ("Digite o primeiro numero:\n");
        scanf ("%d", &a);
        printf ("Digite o segundo numero:\n");
        scanf ("%d", &b);

        int cont1, i, mmc;
        for (i = 2; i <= b; i++)
            {
            cont1 = a * i;
            if ((cont1 % b) == 0)
            {
            mmc = cont1;
            i = b + 1;
            }
            }
            cont++;
            historico[cont][0] = 1;
            historico[cont][1] = 0;
            historico[cont][INDICE_RESULTADO] = mmc;
            printf ("O mmc eh: %d\n", mmc);
        break;

	case '1':
        criarlinha (20);
        printf ("Digite o primeiro numero:\n");
        scanf ("%d", &a);
        printf ("Digite o segundo numero:\n");
        scanf ("%d", &b);

        while (a != b)
            {
            if (a > b)
            {
            a = a - b;
            }
            else
            b = b - a;
            }
            cont++;
            historico[cont][0] = 1;
            historico[cont][1] = 1;
            historico[cont][INDICE_RESULTADO] = a;
        printf ("O mC!ximo divisor comum eh: %d \n", a);
        break;

    case '2':
        criarlinha (20);
        int f, a;
        printf ("Digite o numero: ");
        scanf ("%d", &a);
        for (f = 1; a > 1; a--) {
            f = f * a;
        }
            cont++;
            historico[cont][0] = 1;
            historico[cont][1] = 2;
            historico[cont][INDICE_RESULTADO] = f;
        printf ("O fatorial eh: %d", f);
        break;
    

    }
    imprimeListaDePalavras(listadefuncoesmatematicas, NUMERO_DE_FUNCOES_MATEMATICAS);
    printf("Para sair, digite 's'\n");
    scanf (" %c", &op);
    if ((op == 's') || (op == 'S'))
    {
        break;
    }
    }

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
            cont = -1;
        }
        switch(escolha) {
            case 0:
                operacoesbasicas();
                break;
            case 1:
                funcoesmatematicas();
                break;
            case 2:
                defineCalculoDeFiguras();
                break;
            case 3:
                printf("[1] Apagar historico de operacoes\n[2] Ler historico\n");
                scanf("%d", &aux);
                if (aux == 1) {
                    cont = -1;
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
