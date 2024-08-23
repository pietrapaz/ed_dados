#include <stdio.h>

void insertion_sort (int vetor[], int n) {
    int k, j, aux;

   for (k = 1; k <= n - 1; k++){
      printf("\n[%d] ", k);

      aux = vetor[k];
      j = k - 1;
      while (j >= 0 && aux < vetor[j]) {
         printf("%d, ", j);

         vetor[j+1] = vetor[j];
         j--;
      }

      vetor[j+1] = aux;
   }
}

int main (void) {
	int k;
	int vetor[6] = {6,2,4,3,1,5};
	insertion_sort(vetor,6);
	printf("\n");
	printf("Lista ordenada: \n");
	for (k=0; k<6; k++){
		printf("%d ",vetor[k]);
	}
 return 0;
}

