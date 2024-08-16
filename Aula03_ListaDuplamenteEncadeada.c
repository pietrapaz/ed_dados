// programa que implementa uma lista duplamente encadeada

#include<stdio.h>
#include<stdlib.h>

// declaracao da estrutura do no

struct no {
	int numero;
	struct no *anterior;
	struct no *proximo;
};

// funcao que insere um no na lista
struct no *inserir(struct no *cabeca, int numero){
	// criacao do novo no
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> anterior = NULL;
	novoNo -> proximo = NULL;
	
	// cenario facil: lista vazia
	if(cabeca == NULL){
		return novoNo;
	}
	
	// cenario dificil: lista NAO vazia
	struct no *ultimo = cabeca;
	while(ultimo -> proximo != NULL){
		ultimo = ultimo -> proximo;
	}
	ultimo -> proximo = novoNo;
	novoNo -> anterior = ultimo;
	
	return cabeca;	
}

// funcao que remove um no da lista
struct no *remover(struct no *cabeca, int numero){
	// cenario muito facil: lista vazia
	if(cabeca == NULL){
		return NULL;
	}
	
	// cenario medio facil: excluir o primeiro no da lista
	if(cabeca -> numero == numero){
		struct no *excluir = cabeca;
		cabeca = cabeca -> proximo;
		if(cabeca != NULL){ // protecao para a exclusao do unico no da lista
			cabeca -> anterior = NULL;	
		}
		free(excluir); // remove da memoria 
		
		return cabeca;
	}
	
	// cenario dificil: excluir um no no meio ou no final da lista
	struct no *ponteiro = cabeca;
	while ((ponteiro != NULL) && (ponteiro -> numero != numero)){
		ponteiro = ponteiro -> proximo;
	}
	
	if(ponteiro != NULL){
		ponteiro -> anterior -> proximo = ponteiro -> proximo;
		if(ponteiro -> proximo != NULL){ // protecao da exclusao do ultimo no
			ponteiro -> proximo -> anterior = ponteiro -> anterior;
		}
		
	}
	
	return cabeca;	
}

void imprimir(struct no *cabeca){
	struct no *ponteiro = cabeca;
	while(ponteiro != NULL){
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
	}
}

int menu(){
	int opcao;
	
	printf("+================+\n");
	printf("| Menu de Opcoes |\n");
	printf("+================+\n");
	printf("| 1.  Inserir    |\n");
	printf("| 2.  Remover    |\n");
	printf("| 3.  Imprimir   |\n");
	printf("| 4.  Sair       |\n");
	printf("| 5.  Explodir   |\n");
	printf("+================+\n");
	printf("Digite a sua opcao: ");
	scanf("%d", &opcao);
	
	return opcao;
}

// funcao principal de execucao do programa
int main(){
	struct no *cabeca = NULL;
	int opcao = 0, numero = 0;
	
	while (opcao != 4){
		opcao = menu();
		
		switch(opcao){
			case 1:
				printf("Digite um numero: ");
				scanf("%d", &numero);
				cabeca = inserir(cabeca, numero);
				break;
			case 2:
				printf("Digite um numero: ");
				scanf("%d", &numero);
				cabeca = remover(cabeca, numero);
				break;
			case 3:
				imprimir(cabeca);
				break;
			case 5: 
			for (numero=0; numero < 100000; numero++){
				cabeca = inserir(cabeca, numero);
			}
			break;
		}
		
	}
	
}


