// programa que implementa uma arvore binaria de busca

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// declaracao da estrutura do no
struct no{
	int numero;
	struct no *esquerda;
	struct no *direita;
};

// funcao que insere um no na arvore
struct no *inserir(struct no *raiz, int numero){
	// cenario facil: arvore vazia
	if(raiz == NULL){
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
		return raiz;
	}
	
	// caso dificil: arvore NAO vazia
	if(raiz -> numero > numero){
		raiz -> esquerda = inserir(raiz -> esquerda, numero);
	} else {
		raiz -> direita = inserir(raiz -> direita, numero);
	}
	return raiz;	
}

// funcao que procura um no na arvore
void procurar(struct no *raiz, int numero){
	// cenario muito facil: arvore vazia
	if(raiz==NULL){
		printf("Se fodeu! Nao achei!\n");
		return;
	}
	
	// cenario facil: dei sorte e achei na raiz
	if(raiz -> numero == numero){
		printf("Parabens !!!! Achei !!!!\n");
		return;
	}
	
	// cenario dificil: nao achei na raiz, continuar procurando
	if(raiz -> numero > numero){
		procurar(raiz -> esquerda, numero);
	} else {
		procurar(raiz -> direita, numero);
	}	
}

// funcao que navega a arvore EM-ORDEM
void navegarEmOrdem(struct no *raiz){
	if(raiz == NULL){
		return;
	}
	
	navegarEmOrdem(raiz -> esquerda);
	printf("%d, ", raiz -> numero);
	navegarEmOrdem(raiz -> direita);
}

// funcao principal de execucao do programa
int main(){
	// declaracao de variaveis
	int TAMANHO = 10;
	struct no *arvore = NULL;
	int i = 0;
	
	// inicializacao da aleatoriedade
	time_t t;
	srand(time(&t));
	
	// construcao da arvore
	for(i = 0; i < TAMANHO; i++){
		arvore = inserir(arvore, rand() % TAMANHO);
	}
	
	// impressao da arvore
	navegarEmOrdem(arvore);
	printf("\n");
	
	//pesquisas na arvore
	while(1){
		printf("Digite um numero: ");
		scanf("%d", &i);
		procurar(arvore, i);
	}
}


