#include<stdio.h>
#include<stdlib.h>

// estrutura de dados a ser declarada para o tipo Lista, definida por ponteiros
typedef struct Lista{
	int info;
	struct Lista* prox;
}Lista, TipoLista;

// iniciar lista vazia
Lista* iniciaLista(void){
	return NULL;
}

// funcao que percorre os elementos da lista
void imprime(Lista *l){
	Lista *p;
	for (p=l;p!=NULL;p=p->prox)
	printf("info=%d\n", p->info);
}

// funcao que verifica se a lista esta vazia
/*
int vazia (){
	if (l==NULL)
		return 1;
	else
		return 0;		
}
*/

// forma mais compacta
int vazia(Lista *l){
	return (l==NULL);
}

// funcao de buscar um elemento na lista
Lista* busca (Lista* l, int v){
	Lista* p;
	for (p=l; p!=NULL; p=p->prox)
		if (p->info==v)
			return p;
	return NULL;
}

// funcao que retira um elemento da lista
Lista* retira (Lista* l, int v){
	Lista* ant = NULL;
	Lista* p = l;
	
	// procura elemento na lista, guardando anterior
	while(p!=NULL && p->info != v){
		ant = p;
		p = p->prox;
	}
	
	// verifica se achou elemento
	if(p==NULL){
		return l;
	}
	
	// retira elemento
	if(ant==NULL){
		l=p->prox;
	} else {
		ant->prox=p->prox;
	}
	free(p);
	return l;
}

// PAROU AI
// funcao para liberar a lista
//void libera(Lista* l){
//	Lista* p=l;
//	while(p!=NULL){
		
//	}
//}

// funcao de insercao
Lista* insere (Lista* l, int i){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo -> info = i;
	novo -> prox = l;
	return novo;
}

int main(void){
	Lista* l;
	l = iniciaLista();
	l = insere(l, 23);
	l = insere(l, 45);
	imprime(l);
	printf("tamanho da lista: ", malloc(sizeof(l)));
	return 0;
}
