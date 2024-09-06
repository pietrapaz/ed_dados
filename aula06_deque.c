#include<stdio.h> 
#include<stdlib.h> 

// programa que implementa um deque
struct no {
	int numero;
	struct no *proximo;
};

struct deque {
	struct no *filaNormal;
	struct no *filaPreferencial;
}; 

// funcao que insere um no no deque
struct deque *entrar(struct deque *cabeca, int tipo, int numero){
	// alocacao de memoria do novo no
	struct no *novoNo = (struct no *) malloc(sizeof(struct no)); 
	novoNo -> numero = numero;
	novoNo -> proximo = NULL;
	
	// entrada propriamente dita
	if(tipo){ // fila normal
		novoNo -> proximo = cabeca -> filaNormal;
		cabeca -> filaNormal = novoNo;
	} else { // fila preferencial
		novoNo -> proximo = cabeca -> filaPreferencial;
		cabeca -> filaPreferencial = novoNo;
	}
	
	return cabeca;
}

// funcao que remove um no de uma das filas
struct no *sair(struct no *fila){
	// cenario muito facil 
	if(fila==NULL){
		return NULL;
	}
	
	// cenario medio facil: fila so tem um unico no
	if(fila -> proximo == NULL){
		printf("%d\n", fila -> numero);
		free(fila);
		return NULL;
	}
	
	// cenario dificil: fila tem mais de um no, procurar o penultimo
	struct no *penultimo = fila;
	while(penultimo -> proximo -> proximo != NULL){
		penultimo = penultimo -> proximo;
	}
	
	struct no *ultimo = penultimo -> proximo;
	printf("%d\n", ultimo -> numero);
	free(ultimo);
	penultimo -> proximo = NULL;
	return fila;
}

// funcao que simula o atendimento propriamente dito
void atender(struct deque *cabeca, int *contadorPreferencial){
	// cenario muito facil: ambas filas estao vazias
	if((cabeca -> filaNormal == NULL) && (cabeca -> filaPreferencial == NULL)){
		return; 
	}
	
	// cenario medio facil: so tem no na fila normal
	if(cabeca -> filaPreferencial == NULL){
		cabeca -> filaNormal = sair(cabeca -> filaNormal);
		return;
	}
	
	// cenario medio facil: so tem no na fila preferencial
	if(cabeca -> filaNormal == NULL){
		cabeca -> filaPreferencial = sair(cabeca -> filaPreferencial);
		return;
	}
	
	// cenario dificil: tem no em ambas filas
	if(*contadorPreferencial > 2){
		cabeca -> filaNormal = sair(cabeca -> filaNormal);
		*contadorPreferencial = 0;
	} else {
		cabeca -> filaPreferencial = sair(cabeca -> filaPreferencial);
		(*contadorPreferencial)++;
	}
}

// funcao principal de execucao do programa
int main(){
	// declaracao de variaveis
	int contadorPreferencial = 0, i = 0;
	struct deque *cabeca = (struct deque *) malloc(sizeof(struct deque)); 
	cabeca -> filaNormal = NULL;
	cabeca -> filaPreferencial = NULL;
	//int quantidade = 0;
	
// processamento com scan
	//printf("Digite a quantidade de pessoas na fila normal: ");
	//scanf("%d", &quantidade);
	//for(i = 0; i < quantidade; i++){
	//	cabeca = entrar(cabeca, 1, i);
	//}
	
	//printf("Digite a quantidade de pessoas na fila preferencial: ");
	//scanf("%d", &quantidade);
	//for(i = 0; i < quantidade; i++){
	//	cabeca = entrar(cabeca, 0 ,i);
	//}
	
// processamento
	for(i = 0; i < 10; i++){
		cabeca = entrar(cabeca, 1, i);
	}	
	
	for(i = 100; i < 110; i++){
		cabeca = entrar(cabeca, 0, i);
	}	
	
	for(i = 0; i < 20; i++){
		atender(cabeca, &contadorPreferencial);
	}	
	
	
}

