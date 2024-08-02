/////////////////////////////////////////////////////
// programa que realiza a transposicao de matrizes //
/////////////////////////////////////////////////////

#include <stdio.h>

int main(){
	// declaracao de variaveis
	int matrizOriginal[2][3];
	int matrizTransposta[3][2];
	int i;
	int j;
	
	// entrada de dados
	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++){
			printf("matrizOriginal[%d][%d] = ", i, j);
			scanf("%d", &matrizOriginal[i][j]);
			
			
			
		}
	}
	
	//processamento
	for (i = 0; i < 2; i++){
		for (j = 0; j < 3; j++){
			matrizTransposta[j][i] = matrizOriginal[i][j];
		}
	}
	
	// \t = tab \n = quebra de linha
	
	// saida de dados
	printf("\n===== Matriz Original =====\n");
	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++){
			printf("%d \t", matrizOriginal[i][j]);
		}
		printf("\n");
	}
	
	printf("\n===== Matriz Transposta =====\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 2; j++){
			printf("%d \t", matrizTransposta[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	
	
}
