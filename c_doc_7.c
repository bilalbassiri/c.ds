#include <stdlib.h>
#include <stdio.h>

int CalculV(int n);
int CalculU(int n);


int CalculU(int n){
	if(n==0) return 1;
	else return 2*CalculU(n-1) + CalculV(n-1);
}
int CalculV(int n){
	if(n==0) return 2;
	else return CalculU(n-1) - CalculV(n-1);
}
int main() {
	int n;
	printf("Entrez n: ");
	scanf("%d", &n);
	int i;
	int U[n+1], V[n+1];
	*V = (int*)calloc(n+1, sizeof(int));
	*U = (int*)calloc(n+1, sizeof(int));
	for(i=0; i<n+1; i++){
		U[i] = CalculU(i);
		V[i] = CalculV(i);
	}

	for(i=0; i<n+1; i++){
		printf("U(%d) = %d\t", i, CalculU(i));
	}
	printf("\n");
	for(i=0; i<n+1; i++){
		printf("V(%d) = %d\t", i, CalculV(i));
	}
	free(U);
	free(V);
	return 0;
}
