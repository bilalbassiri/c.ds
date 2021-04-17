#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct entier{
	int data;
	struct entier *next;
}Entier;

typedef struct mots{
	char mot[25];
	struct mots *next;
}Mots;


Entier *creer(){
	Entier *node, *p, *head;
	node = NULL;
	int N, i;
	printf("Entrez N: \n");
	scanf("%d", &N);
	if(N >= 20){
		printf("Err !!!");
		exit(0);
	}
	else {
		for(i=0 ; i<N; i++){
			node = (Entier*)malloc(sizeof(Entier*));
			printf("Entrez l'entier %d\t", i+1);
			scanf("%d", &node->data);
			if(i==0){
				head = node;
				p = head;
			}
			else {
				(*p).next = node;
				p = p->next;
			}
		}
	}
		p->next = NULL;
		return head;
}


float Moyenne(Entier *head){
		int l=0, sum=0;
		float M ;
		Entier *p = head;
		while (p != NULL){
			sum = sum + p->data;
			l++;
			p = p->next;
		}
		M = (float)sum/(float)l;
		return M;
}

Entier * car(Entier *head){
	Entier *p;
	p = head;
	while (p != NULL){
		p->data = (p->data) * (p->data);
		p = p->next;
	}
	return head;
}

Mots * CreerMots(){
	int N, i;
	Mots *head = NULL, *p, *m;
	printf("Entrez N: \n");
	scanf("%d", &N);
	for(i=0; i < N; i++){
		m = (Mots*)malloc(sizeof(Mots*));
		printf("Entrez le mot %d\t", i+1);
		scanf("%s", &m->mot);
		if(i==0){
			head = m;
			p = head;
		}
		else {
			p->next = m;
			p = p->next;
		}

	}
	p->next= NULL;
	return head;
}
void AjouterMot(Mots *head){
	Mots *p = head, *newm;
	newm = (Mots*)malloc(sizeof(Mots*));
	scanf("%s", &newm->mot);
	while(p->next != NULL){
		p= p->next;
	}
	p ->next = newm;
	newm ->next = NULL;
}


void Pretirer(Mots *head){
	Mots *p;
	p = head;
	head = p->next;
	free(p);
}

Mots *r_p_e(Mots **tete){
    Mots *p;
    if(*tete!=NULL)
    {
    p=*tete;
    *tete=(*tete)->next;
    free(p);
    }
    return tete;
}

void afiicher(Mots *head){
	Mots *p = head;
	while(p != NULL){
		printf("%s\n", p->mot);
		p= p->next;
	}

}
void main (){
}
