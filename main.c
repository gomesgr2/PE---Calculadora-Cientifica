#include<stdio.h>
#define MAX_TAMANHO_DA_PALAVRA 40
#define NUMERO_DE_OPERACOES 4

int main(){

    int operacao;

    // Exemplos da lista de operações 
    char arr[NUMERO_DE_OPERACOES][MAX_TAMANHO_DA_PALAVRA] = { "Sair", "Soma", "Subtracao", "Fatorial"};

    // Exemplo da impressão inicial

    printf("Bem vindo a UFABCalc\nDigite o numero para realizar as operacoes\n");


    for(int i =0; i < NUMERO_DE_OPERACOES; i++  ){
        printf("%d : %s\n",i, arr[i]);
    }

    // Input 

    scanf("%d",&operacao);


    while(operacao != 0){
        switch(operacao) {
            case 1 :
                // soma()
                break;
            case 2 :
                // sub()
                break;
            case 3 :
                // fat()
                break;
            default :
                printf("Operação inválida !");
                break;
        }
        scanf("%d",&operacao);
        
    }

    printf("BYE BYE");


    

    return 0;
}