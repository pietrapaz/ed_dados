// programa que implementa uma matriz esparsa
#include<stdio.h>
#include<stdlib.h>

// declaracao de constantes 
#define MODULO 16

// declaracao de estruturas 
struct no {
    int numero;
    struct no *proximoNo;
};

struct diretor {
    int resto;
    struct no *proximoNo;
    struct diretor *proximoDiretor;
};

// funcao que cria um novo diretor
struct diretor *criarDiretor(struct diretor *cabeca, int resto){
    struct diretor *novoDiretor = (struct diretor *) malloc(sizeof(struct diretor));
    novoDiretor -> resto = resto;
    novoDiretor -> proximoNo = NULL;
    novoDiretor -> proximoDiretor = cabeca;
    return novoDiretor;
} 

// funcao que procura um diretor 
struct diretor *procurarDiretor(struct diretor *cabeca, int resto){
    struct diretor *ponteiroDiretor = cabeca;

    while((ponteiroDiretor != NULL) && (ponteiroDiretor -> resto != resto)){
        ponteiroDiretor = ponteiroDiretor -> proximoDiretor;
    }
    return ponteiroDiretor;
}

// funcao que insere um no na matriz esparsa
struct diretor *inserir(struct diretor *cabeca, int numero){
    // primeira tarefa é encontrar o diretor correto 
    struct diretor *ponteiroDiretor = procurarDiretor(cabeca, (numero % MODULO));

    // se o diretor correto nao for encontrado, criar um novo
    if(ponteiroDiretor == NULL){
        cabeca = criarDiretor(cabeca, (numero % MODULO));
        ponteiroDiretor = cabeca;
    }

    // insercao propriamente dita
    struct no *novoNo = (struct no *) malloc(sizeof(struct no));
    novoNo -> numero = numero;
    novoNo -> proximoNo = ponteiroDiretor -> proximoNo;
    ponteiroDiretor -> proximoNo = novoNo;

    return cabeca;
} 

// funcao que imprime a matriz esparsa na tela
void imprimir(struct diretor *cabeca){
    struct diretor *ponteiroDiretor = cabeca;
    struct no *ponteiroNo = NULL;

    while (ponteiroDiretor != NULL){
        printf("%d\t", ponteiroDiretor -> resto);
        ponteiroNo = ponteiroDiretor -> proximoNo;
        while(ponteiroNo != NULL){
            printf("%d", ponteiroNo -> numero);
            ponteiroNo = ponteiroNo -> proximoNo;
        }
        printf("\n");
        ponteiroDiretor = ponteiroDiretor -> proximoDiretor;
    }
}

// funcao que remove um no da matriz esparsa
void remover(struct diretor *cabeca, int numero){
    // cenario muito facil: matriz vazia
    if(cabeca == NULL){
        return;
    }

    // cenario medio facil: procurar o diretor correto, porem nao encontrar
    struct diretor *ponteiroDiretor = procurarDiretor(cabeca, (numero % MODULO));
    if(ponteiroDiretor == NULL){
        return;
    }

    // cenario facil: excluir o primeiro no
    if(ponteiroDiretor -> proximoNo -> numero == numero){
        struct no *excluir = ponteiroDiretor -> proximoNo;
        ponteiroDiretor -> proximoNo = ponteiroDiretor -> proximoNo -> proximoNo;
        free(excluir);
        return;
    }

    // procurar o no a ser excluido parando no anterior
    struct no *anterior = ponteiroDiretor -> proximoNo;
    while((anterior -> proximoNo != NULL) && (anterior -> proximoNo -> numero != numero)){
        anterior = anterior -> proximoNo;
    }

    // cenario dificil: varri a lista toda e nao encontrei
    if(anterior -> proximoNo == NULL){
        return;
    }

    // cenario muito dificil: varri a lista toda, encontrei, e parei na anterior
    struct no *excluir = anterior -> proximoNo;
    anterior -> proximoNo = anterior -> proximoNo -> proximoNo;
    free(excluir);
}

// funcao principal de execucao do programa
int main(){
    struct diretor *matrizEsparsa = NULL;
    int i = 0;

    for(i = 0; i < 500; i++){
        matrizEsparsa = inserir(matrizEsparsa, i);
    }

    imprimir(matrizEsparsa);
    printf("==============================================\n");

    for(i = 0; i < 100; i++){
        remover(matrizEsparsa, i);
    }

    for(i = 400; i < 500; i++){
        remover(matrizEsparsa, i);
    }

    imprimir(matrizEsparsa);
}