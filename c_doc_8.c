#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1
typedef struct indiv {
	int num;
	char nom[25];
	struct indiv * next;
}indiv;
//2
indiv *creer(){
	int n = 4;
	indiv *head = NULL, *tmp, *p;
	int i;
	for(i=1; i<=n; i++){
		tmp = (indiv*)malloc(sizeof(indiv));
		printf("\n Entrez le num: \t", i);
		scanf("%d", &tmp->num);
		printf("Entrez le nom: \t");
		scanf("%s", &tmp->nom);
		if(i==1){
			head = tmp;
			p = head;
		}
		else{
			p->next = tmp;
			p = p->next;
		}


	}
	p->next = NULL;
	return head;
}

//3
void existe(indiv *head, indiv e){
		indiv *p = head;
		int existe = 0;
		while(p!=NULL){
			if((e.num == p->num)&&(e.nom == p->nom)){
				existe = 1;
			}
			p = p->next;
		}
		if(existe=0){
			printf("n'existe pas !!");
		}else printf("l'individu %d est existe ", e.num);

}

//4

indiv *ajouter(indiv *head, indiv e){
	indiv *ind, *p;
	ind = (indiv*)malloc(sizeof(indiv));
	ind->num = e.num;
	strcpy(ind->nom, e.nom);
	ind->next = head;
	head = ind;
	return head;
}

//5
int nombre(indiv *head){
	int l = 0;
	indiv *p = head;
	while(p!=NULL){
		l ++;
		p=p->next;
	}
	return l;
}

//6

float moyenne(indiv *head){
	indiv *p = head;
	int sum= 0, n = 0;
	float M;
	while(p!=NULL){
		sum = sum + p->num;
		n++;
		p=p->next;
	}
	M = (float)sum/(float)n;
	return M;
}

//***

void afficher(indiv *head){
		indiv *p= head;
		printf("NUM-------------NOM");
		while(p!=NULL){
			printf(" %d------------- %s \n", p->num, p->nom);
			p=p->next;
		}
}

int main(){

}

