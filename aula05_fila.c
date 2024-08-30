// FIFO (first in first out)
// saida na cabeca e entrada no final OU entrada na cabeca e saida no final

// programa que implementa uma fila

#include<stdio.h>
#include<stdlib.h>

// decalracao da estrutura do no
struct no {
    int numero;
    struct no *proximo;

};

// funcao que insere um no na fila
struct no *entrar (struct no *cabeca, int numero){
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = cabeca;
    return novoNo;
};

// funcao que remove um no da fila
struct no *sair (struct no *cabeca){
    // cenario muito facil: lista vazia
    if (cabeca==NULL){
        return NULL;
    }

    // cenario medio facil: lista so tem um unico no
    if (cabeca -> proximo == NULL){
        printf("%d\n", cabeca -> numero);
        free(cabeca);
        return NULL;
    }

    // cenario dificil: lista tem muitos nos, procurar penultimo
    struct no *penultimo = cabeca;
    while(penultimo -> proximo -> proximo != NULL){
        penultimo = penultimo -> proximo;
    }

    printf("%d\n", penultimo -> proximo -> numero);
    free(penultimo -> proximo);
    penultimo -> proximo = NULL;
    return cabeca;

};

// funcao principal de execucao do programa
int main(){
    struct no *fila = NULL;
    int i = 0;

    for(i = 0; i < 10; i++){
        fila = entrar(fila, i);
    }

    for(i = 0; i < 10; i++){
        fila = sair(fila);
    }
}
