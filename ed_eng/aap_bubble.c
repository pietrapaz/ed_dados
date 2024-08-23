#include <stdio.h>

void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 0; k < n - 1; k++) {
        printf("\n[%d] ", k);

        for (j = 0; j < n - k - 1; j++) {
            printf("%d, ", j);

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main (void) {
	int k;
	int vetor[6] = {6,2,4,3,1,5};
	bubble_sort(vetor,6);
	printf("\n");
	printf("Lista ordenada: \n");
	for (k=0; k<6; k++){
		printf("%d ",vetor[k]);
	}
 return 0;
}

