///////////////////////////////////
// programa que inverte um vetor //
///////////////////////////////////

#include <stdio.h>

int main(){
	// declaracao de variaveis
	int vetorOriginal[5];
	int vetorInvertido[5];
	int i;
	
	// entrada de dados
	for (i = 0; i < 5; i++){
		printf("vetorOriginal[%d] = ", i);
		scanf("%d", &vetorOriginal[i]);
	}
	
	// processsamento
	for(i = 0; i < 5; i++){
		vetorInvertido[4-i] = vetorOriginal[i];
	}
	
	// saida de dados
	for(i = 0; i < 5; i++){
		printf("vetorInvertido[%d] = %d \n", i, vetorInvertido[i]);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
