#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Supprimer le dernier caractère d'une chaîne de caractères

void deleteLastChar(char *s){
	s[strlen(s)-1] = '\0';
}

// Supprimer le caractère avec la position X

void deletePositionChar(char *s, int pos){
	int i=0;
	if ((pos==0) || (pos>=strlen(s))){
		printf("Error de position !");
		exit(0);
		}
	while(i!=pos){
		i++;
	}
	for(int j=i; j<strlen(s); j++){
		s[j] = s[j+1];
	}
}

// Trouver la position d'un caractère X dans une chaîne de caractères

int charPosition(char *s, char c){
	int r = -1;
	for(int i=0; i<strlen(s); i++){
		if (s[i] == c){
			r =i;
			break;
		}
	}
	return r;
}

//Supprimer le caractère X

void deleteChar(char *s, char c){
	int p = charPosition(s, c);
	while(p != -1){
		deletePositionChar(s, p);
		p = charPosition(s, c);
	}
}

int main(){
	return 0;
}
