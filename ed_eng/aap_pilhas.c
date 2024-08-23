#include <stdio.h>
#include <stdlib.h>

// estrutura de dados a ser declarada para o tipo Pilha, definida por ponteiros
typedef struct No {
	int valor;
	struct No *prox; 
}No, TipoNo;

typedef struct Pilha {
	TipoNo *topo;
	int tamanho; 
}Pilha, TipoPilha;

// a funcao define uma pilha vazia, o campo topo é associado ao ponteiro nulo, tamanho é 0
void IniciaPilha(TipoPilha *pilha){
	pilha->topo = NULL;
	pilha->tamanho = 0;
}

// funcao recebe o parametro (ponteiro) pilha que da acesso a mesma e retorna
// verdadeiro caso nao haja elementos na pilha. o topo da pilha é o ponteiro nulo.
int Vazia(TipoPilha *pilha){
	return (pilha->topo == NULL);
}

// funcao recebe como parametros o valor a ser empilhado e um ponteiro para a pilha.
// uma nova estrutura TipoNo deve ser alocada para que o novo valor seja armazenado e encadeado.
void Empilha(int x, TipoPilha *pilha){
	TipoNo *aux;
	aux = (TipoNo *) malloc(sizeof(TipoNo));
	aux -> valor = x;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->tamanho++;
}

//a funcao recebe como parametro um ponteiro para a pilha e remove o valor que estava
// no topo da pilha. este valor eh retornado a unidade chamadora.
int Desempilha(TipoPilha *pilha){
	TipoNo *q; int v;
		if (Vazia(pilha)) {
		printf("Lista vazia\n"); return 0;
		}
	q = pilha->topo;
	pilha->topo = q->prox;
	v = q->valor;
	free(q);
	pilha->tamanho--;
	return v;
}

// definicao da funcao Main
int main() {
	int i, numero, max=5;
	TipoPilha *pilha;
	
	pilha = (TipoPilha *) malloc (sizeof(TipoPilha));
	IniciaPilha(pilha);
	
	for (i=0;i<max;i++) {
		printf("Leitura do valor (%d) :",i); 
		scanf("%d",&numero);
		Empilha(numero, pilha);
		printf("Empilhou: %d \n", numero);
	}
	
	for(i=0;i<max;i++) {
		numero = Desempilha (pilha);
		printf ("Desempilhou: %d \n", numero);
	}
}
