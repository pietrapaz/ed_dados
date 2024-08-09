///////////////////////////////////////////////////////////////
// Programa que implementa uma lista de encadeamento simples //
///////////////////////////////////////////////////////////////

// ponteiro eh um endereco de memoria 

#include <stdio.h>
#include <stdlib.h>

// declaracao da estrutura do no
struct no {
	int numero;
	struct no *proximo;
};

// funcao que insere um no na lista
struct no *inserir(struct no *cabeca, int numero){
	// criacao do novo no
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = NULL;
	
	// cenario facil lista vazia
	if(cabeca == NULL){
		return novoNo;
	}
	
	// cenario dificil: lista nao vazia
	novoNo -> proximo = cabeca;
	return novoNo;
}

// funcao que imprime a lista
void imprimir (struct no *cabeca){
	struct no *ponteiro = cabeca;
	
	while(ponteiro != NULL){
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

// funcao que remove um no da lista
struct no *remover(struct no *cabeca, int numero){
	//cenario facil: lista vazia
	if(cabeca==NULL){
		return NULL;;
	}
	
	// cenario medio facil: remover o primeiro no
	if(cabeca -> numero == numero){
		struct no *ponteiroExcluir = cabeca;
		cabeca = cabeca -> proximo;
		free(ponteiroExcluir);
		return cabeca;
	}
	
	// cenario dificil: remover no meio ou no fim
	struct no *ponteiro = cabeca;
	
	while((ponteiro -> proximo != NULL) && (ponteiro -> proximo -> numero != numero)){
		ponteiro = ponteiro -> proximo;
	}
	
	if(ponteiro -> proximo != NULL){
		struct no *ponteiroExcluir = ponteiro -> proximo;
		ponteiro -> proximo = ponteiro -> proximo -> proximo;
		free(ponteiroExcluir);
	}
	
	return cabeca;
	
}


int main(){
	// declaracao de variavel
	struct no *cabeca = NULL;
	int i;
	
	// processamento
	for (i = 0; i < 5; i++){
		cabeca = inserir(cabeca, i);
	}
	
	cabeca = remover(cabeca, 0);
	cabeca = remover(cabeca, 2);
	cabeca = remover(cabeca, 4);
	cabeca = remover(cabeca, 100);
	
	imprimir(cabeca);
	
	
}
