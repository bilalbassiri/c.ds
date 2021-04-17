#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int *tri(int *T);
int main (){
	int f, re[8], ty[8] = {2,3,0,43,6,9,1,9};
	*re = tri(ty);
	for(f=0; f<8; f++){
		printf("%d\t", re[f]);
	}
	return 0;
}
int *tri(int *T){
	int i, j, min,p,tmp;
	int len;
	len = strlen(T);
	for(j=0; j < len-1; j++){
		min = T[j];
		for (i=j+1; i < len; i++){
		if (T[i] < min){
			min = T[i];
			p= i;}
		}
		tmp = T[j];
		T[j] = min;
		T[p] = tmp;
}
	return T;
}
