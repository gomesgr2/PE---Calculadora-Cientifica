#include<stdio.h>
#define MAX_TAMANHO_DA_PALAVRA 40
#define NUMERO_DE_OPERACOES 3

int main(){

    // Exemplos da lista de operações

    char arr[NUMERO_DE_OPERACOES][MAX_TAMANHO_DA_PALAVRA] = { "Soma", "Subtracao", "Fatorial"};

    // Exemplo da impressão inicial

    printf("Bem vindo a UFABCalc\nDigite o numero para realizar as operacoes\n");


    for(int i =0; i < NUMERO_DE_OPERACOES; i++  ){
        printf("%d : %s\n",i, arr[i]);
    }

    // Input 


    

    return 0;
}