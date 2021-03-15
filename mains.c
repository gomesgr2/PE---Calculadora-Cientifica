//Importar bibliotecas necessárias
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
                printf("%.2f %c %.2f = %.4f\n", a, op, b, pow(a,b));
                esc = 1;
                historico[cont][1] = 5;
                historico[cont][2] = pow(a,b);
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

void areasgeometricas() {
    printf("3");
}

//main
void main(){
    //Definição de variáveis
    //escolha de operações
    int escolha = 0;
    //auxiliar do historico
    int aux = 0; 

    printf("Bem vindo ao UFABCalc!\n");

    while (escolha != 5) {
        if (cont >= 20) {
            printf("Mais de 20 operacoes realizadas! O historico foi apagado.\n");
            cont = 0;
        }

        printf("\nEscolha o tipo de operacao desejada:\n");
        criarlinha(34);
        printf("|(1) Operacoes basicas           |\n");
        criarlinha(34);
        printf("|(2) Funcoes matematicas         |\n");
        criarlinha(34);
        printf("|(3) Area de figuras geomatricas |\n");
        criarlinha(34);
        printf("|(4) Historico de operacoes      |\n");
        criarlinha(34);
        printf("|(5) Sair                        |\n");
        criarlinha(34);

        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                historico[cont][0] = 1;
                operacoesbasicas();
                cont++;
                break;
            case 2:
                historico[cont][0] = 2;
                funcoesmatematicas();
                cont++;
                break;
            case 3:
                historico[cont][0] = 3;
                areasgeometricas();
                cont++;
                break;
            case 4:
                printf("[1] Apagar historico de operacoes\n[2] Ler historico\n");
                scanf("%d", &aux);
                if (aux == 1) {
                    cont = 0;
                } else {
                    lerhistorico(cont);
                }
                break;
            case 5:
                break;
            default:
                printf("Opcao invalida! Por favor, digite novamente.\n");

        }

    }

    printf("Obrigado por usar UFABCalc!\nAte a proxima!");


}
