// programa que implementa uma pilha

#include<stdio.h>
#include<stdlib.h>

// declaracao da estrutura do no
struct no{
    int numero;
    struct no *proximo;
};

// funcao que insere um no na pilha
struct no *push(struct no *cabeca, int numero){
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = cabeca;
    return novoNo;
};

// funcao que remove um no da pilha
struct no *pop(struct no *cabeca){
    if(cabeca==NULL){
        return NULL;
    }

    struct no *excluir = cabeca;
    printf("%d\n", cabeca -> numero);
     cabeca = cabeca -> proximo;
     free(excluir);
     return cabeca;
};

// funcao principal de execucao do programa
int main(){
    struct no *pilha = NULL;
    int i = 0;

    for(i = 0; i < 1000; i++){
        pilha = push(pilha, i);
    }

    for(i = 0; i < 10; i++){
        pilha = pop(pilha);
    }


}
