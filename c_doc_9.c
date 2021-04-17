#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void saisirP(int C[], int n);
void aficher(int C[], int n);

int main(){
	int n, C[10];
	printf("Entrez le degree de polynome : ");
	scanf("%d", &n);
	saisirP(C, n);
	aficher(C, n);
}

void saisirP(int C[], int n){
	int i;
	for ( i = 0; i <= n; i++){

		printf("Entrez la coefficient num %d :\n", i);
		scanf("%d", &C[i]);
	}
}
void aficher(int C[], int n){
	int i;
	for (i =0; i <= n ; i++){
		printf("%dX^%d", C[i], i);
		if(i==n) break;
		printf(" + ");
	}
}
