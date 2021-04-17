#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void accordeon(int m, int n, int t[m][n]){
	for(int i=0; i<m; i++){
		if(i%2==0){
			for(int j=0; j<n; j++){
				printf("%d\t", t[i][j]);
			}
		}
		else {
			for(int k=n-1; k>=0; k--){
				printf("%d\t", t[i][k]);
			}
		}
	}
}
int main(){
	int a=2, n=5, S=0;
	for(int i=0; i<=n; i++){
		S+= a*i*i +3;
	}
	printf("%d", S);
}
