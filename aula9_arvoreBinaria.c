// programa que implementa uma arvore binaria

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// declaracao da estrutura do no

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
};

// funcao que insere um no na arvore
struct no *inserir(struct no *raiz, int numero){
	// caso facil: arvore vazia
	if (raiz == NULL){
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
		return raiz;
	}
	
	// caso dificil: arvore nao vazia
	int sorteio = (rand() % 2);
	if (sorteio){
		raiz -> esquerda = inserir(raiz -> esquerda, numero);
	} else {
		raiz -> direita = inserir(raiz -> direita, numero);
	}
	return raiz;
}

// funcao que navega a arvore em PRE-ORDEM
void navegarPreOrdem(struct no *raiz){
	if (raiz == NULL){
		return;
	}
	printf("%d, ", raiz -> numero);
	navegarPreOrdem(raiz -> esquerda);
	navegarPreOrdem(raiz -> direita);
}

// funcao que navega a arvore em EM-ORDEM
void navegarEmOrdem(struct no *raiz){
	if (raiz == NULL){
		return;
	}
	navegarEmOrdem(raiz -> esquerda);
	printf("%d, ", raiz -> numero);
	navegarEmOrdem(raiz -> direita);
}

// funcao que navega a arvore em POS-ORDEM
void navegarPosOrdem(struct no *raiz){
	if (raiz == NULL){
		return;
	}
	navegarPosOrdem(raiz -> esquerda);
	navegarPosOrdem(raiz -> direita);
	printf("%d, ", raiz -> numero);
}

// funcao principal de execucao do codigo
int main(){
	struct no *arvore = NULL;
	int i = 0;

	// inicializacao da aleatoriedade
	time_t t;
	srand(time(&t));

	// construcao da arvore
	for (i = 0; i < 10; i++){
		arvore = inserir(arvore, i);
	}	
	
	// navegacoes
	printf("Pre-Ordem: ");
	navegarPreOrdem(arvore);
	printf("\nEm-Ordem:  ");
	navegarEmOrdem(arvore);
	printf("\nPos-Ordem: ");
	navegarPosOrdem(arvore);
}

