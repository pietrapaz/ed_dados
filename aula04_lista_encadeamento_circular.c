// lista circular duplamente encadeada - pesquisar

// programa que implementa uma lista de encadeamento circular

#include<stdio.h>
#include<stdlib.h>

// declaracao da estrutura do no

struct no{
    int numero;
    struct no *proximo;
};

// funcao que insere um no na lista
struct no *inserir(struct no *cabeca, int numero){
    // alocacao de memoria do novo no
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximo = NULL;

    // caso facil: lista vazia
    if(cabeca==NULL){
        cabeca = novoNo;
        cabeca -> proximo = cabeca;
        return cabeca;
    }

    // caso dificil: lista NAO vazia
    struct no *proximo = cabeca;
    while (ultimo -> proximo != cabeca){
        ultimo = ultimo -> proximo;
    }

    ultimo -> proximo = novoNo;
    novoNo -> proximo = cabeca;
    return cabeca;
};

// funcao que remove um no da lista
struct no *remover(struct no *cabeca, int numero){
    // caso muito facil: lista vazia
    if (cabeca == NULL){
        return cabeca;
    }

    // caso medio facil excluir o unico
    if((cabeca -> numero == numero) && (cabeca -> proximo == cabeca)){
        free(cabeca);
        cabeca = NULL;
        return cabeca;
    }

    // caso dificil: excluir o primeiro
    if(cabeca -> numero == numero){
        struct no *ultimo = cabeca;
        while (ultimo -> proximo != cabeca){
            ultimo = ultimo -> proximo;
        }

        cabeca = cabeca -> proximo;
        free(ultimo -> proximo);
        ultimo -> proximo = cabeca;
        return cabeca;
    }

    // caso muito dificil: excluir no meio, no final, ou nao achei
    struct no *ponteiro = cabeca;
    while ((ponteiro -> proximo != cabeca) && (ponteiro -> proximo -> numero != numero)){
        ponteiro = ponteiro -> proximo;
    }

    if(ponteiro -> proximo == cabeca){ // nao achei
        return cabeca;
    }

    struct no *excluir = ponteiro -> proximo;
    ponteiro -> proximo = ponteiro -> proximo -> proximo;
    free(excluir);
    return cabeca;

};

// funcao que imprime a lista na tela
void imprimir(struct no *cabeca){
    if(cabeca==NULL){
        return;
    }

    struct no *ponteiro = cabeca;

    do{
        printf("%d\n", ponteiro -> numero);
        ponteiro = ponteiro -> proximo;
    } while (ponteiro != cabeca);
}

// funcao principal de execucao do programa
int main(){
    struct no *cabeca = NULL;
    int i;

    for(i=0;i<5;i++){
        cabeca = inserir(cabeca,i);
    }
    imprimir(cabeca);
    cabeca = remover(cabeca, 0);
    cabeca = remover(cabeca, 2);
    cabeca = remover(cabeca, 4);
    cabeca = remover(cabeca, 10);
    imprimir(cabeca);

}
