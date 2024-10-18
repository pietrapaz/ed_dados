// programa que implementa uma arvore rubro negra

#include<stdio.h>
#include<stdlib.h>

// declaracao da estrutura do no
struct no {
	int numero;
	int cor; // 0: preto 1: vermelho
	struct no *esquerda;
	struct no *direita;
};

// funcao que recupera a cor do no
int vermelho(struct no *raiz){
	if(raiz == NULL){
		return 0;
	}
	return raiz -> cor;
}

// funcao que rotaciona arvore a esquerda
struct no *rotacionarEsquerda(struct no *pai){
	// correcao dos ponteiros
	struct no *filho = pai -> direita;
	pai -> direita = filho -> esquerda;
	filho -> esquerda = pai;
	// correcao das cores
	filho -> cor = pai -> cor;
	pai -> cor = 1;
	// retorno
	return filho;
}

// funcao que rotaciona arvore a direita
struct no *rotacionarDireita(struct no *pai){
	// correcao dos ponteiros
	struct no *filho = pai -> esquerda;
	pai -> esquerda = filho -> direita;
	filho -> direita = pai;
	// correcao das cores
	filho -> cor = pai -> cor;
	pai -> cor = 1;
	// retorno
	return filho;
}

// funcao que sobe o vermelho
void subirVermelho(struct no *raiz){
	raiz -> cor = 1;
	raiz -> esquerda -> cor = 0;
	raiz -> direita -> cor = 0;
}

// funcao que insere um no na arvore
struct no *inserir(struct no *raiz, int numero){
	// caso facil: arvore vazia
	if (raiz == NULL){
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> cor = 1;
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
	
	// correcoes de balanceamento
	if((! vermelho(raiz -> esquerda)) && (vermelho(raiz -> direita))){
		raiz = rotacionarEsquerda(raiz);
	}
	
	// esquerda vermelho, neto esquerda vermelho
	if((vermelho(raiz -> esquerda)) && (vermelho(raiz -> esquerda -> esquerda))) {
		raiz = rotacionarDireita(raiz);
	}
	
	// vermelho na esquerda e na direita
	if((vermelho(raiz -> esquerda)) && (vermelho(raiz -> direita))){
		subirVermelho(raiz);
	}
	return raiz;
}

// funcao que imprime a arvore
void imprimir(struct no *raiz, int indentacao){
	if(raiz == NULL){
		return;
	}
	
	int i=0;
	
	for(i = 0; i < indentacao; i++){
		printf("-");
	}
	printf("%d", raiz -> numero);
	// antes do : VERDADEIRO, depois do : FALSO (operador ternario)
	printf((raiz -> cor) ? " (V)\n" : " (P)\n");
	
	indentacao += 3;
	imprimir(raiz -> esquerda, indentacao);
	imprimir(raiz -> direita, indentacao);
}

// funcao principal de execucao do programa
int main(){
	
	struct no *arvore = NULL;
	int i = 0;
	
	for (i = 0; i < 100000; i++){
		arvore = inserir(arvore, i);
	}
	
	imprimir(arvore, 0);
}

