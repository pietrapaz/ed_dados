// programa que implementa a procura de um percurso em um grafico

#include <stdio.h>

// declaracao de constantes
 #define TAMANHO 4
 
 // funcao que constroi o grafo
 
 void construir (int grafo[TAMANHO][TAMANHO]){
 	// declaracao de variaveis
 	int i, j, adjacencia;
 	
 	// inicializacao da estrutura
 	for(i = 0; i < TAMANHO; i++){
 		for(j=0;j<TAMANHO;j++){
 			grafo[i][j]=0;
		 }
	 }
	 
	 // construcao propriamente dita
	 for(i = 0; i < TAMANHO - 1; i++){
	 	for(j = (i + 1); j < TAMANHO; j++){
	 		printf("Digite <1> se %d for adjacente a %d: ", i, j);
	 		scanf("%d", &adjacencia);
	 		grafo[i][j] = adjacencia;
	 		grafo[j][i] = adjacencia;
		 }
	 }
	 
 }
 
 // funcao recursiva que procura um percurso em um grafo
 int procurarPercursoRecursivo(int grafo[TAMANHO][TAMANHO], int visitado[TAMANHO], int inicio, int fim){
 	int vizinho = 0;
 	int retorno = 0;
 	if(inicio == fim){
 		return 1;
	 }
	 
	 visitado[inicio] = 1;
	 for(vizinho = 0; vizinho < TAMANHO; vizinho++){
	 	if((grafo[inicio][vizinho]) && (! visitado[vizinho])){
	 		if(procurarPercursoRecursivo(grafo, visitado, vizinho, fim)){
	 			retorno = 1;
	 			printf("%d <- ", vizinho);
	 			break;
			 }
		 }
	 }
	return retorno;	 
 }
  
// funcao que procura um percurso em um grafo
int procurarPercurso(int grafo[TAMANHO][TAMANHO], int inicio, int fim){
	int i = 0;
	int visitado[TAMANHO];
	
	for(i = 0; i < TAMANHO; i++){
		visitado[i] = 0;
	}
	
	if(procurarPercursoRecursivo(grafo, visitado, inicio, fim)){
		printf("%d\n", inicio);
	} else {
		printf("NAO ha percurso entre essas vertices !\n");
	}
}  

// funcao principal de execucao do programa
int main(){
	int grafo[TAMANHO][TAMANHO];
	int inicio, fim;
	
	construir(grafo);
	
	while(1){
		printf("Digite o vertice inicial: ");
		scanf("%d", &inicio);
		
		printf("Digite o vertice final: ");
		scanf("%d", &fim);
		
		procurarPercurso(grafo, inicio, fim);
	}
}
