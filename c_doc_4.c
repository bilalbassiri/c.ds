#include <stdio.h>
#include <stdlib.h>

typedef struct etudiant{
	int num;
	float note;
	struct etudiant *suivant;
}etudiant;
int longu(etudiant *tete);
etudiant * creer(etudiant *head, int N);
void supmin(etudiant *e);
void maxi(etudiant *t);
int nombre(etudiant *tete);
void ajouter(etudiant *tete, int M);
void ajouterFin(etudiant *l);
void afficher(etudiant *tete);

int main(){
	etudiant *l, *e=NULL;
	l = creer(e, 4);
	ajouterFin(l);
	afficher(l);

}


/*void creer(){
	etudiant *p, *tmp, *tete=NULL;
	int i, nm;
	float nt;
	for(i=0; i<=4; i++){
		tmp = (etudiant*)malloc(sizeof(etudiant*));
		printf("Entez le num\n");
		scanf("%d", &tmp->num);
		printf("Entez la note\n");
		scanf("%f", &tmp->note);
		if (i==0){
			tete = tmp;
			p=tete;
		}
		else{
			p->suivant = tmp;
		}
		p = p->suivant;

	}
	p->suivant = NULL;
}


*/

int longu(etudiant *tete){
	etudiant *p;
	p = tete;
	int l=0;
	while(p!=NULL){
		l++;
		p = p->suivant;
	}
	return l;
}
etudiant * creer(etudiant *head, int N){
	etudiant *new_e, *tmp, *p;
	int i;
	for(i=0; i<N; i++){
	new_e = (etudiant*)malloc(sizeof(etudiant));
	printf("Input Student's ID:\t");
	scanf("%d", &(new_e->num));
	printf("Input the note:\t");
	scanf("%f", &(new_e->note));
	if (i == 0) {
		head = new_e;
		tmp = head;
	}else {
	tmp ->suivant= new_e;
	tmp = tmp->suivant;}
	}
	tmp->suivant = NULL;
	return head;
}

void supmin(etudiant *e){
	float min= e->note;
	etudiant *p, *q;
	p = e->suivant;
	while(p!=NULL){
		if (min >= p->note){
			min = p->note;
			q=p;	}
				p= p->suivant;
	}
	if(q==e){
		e = q->suivant;
		free(q);
	}
	else{
	p=e;
	while(p->suivant != q){
		p= p->suivant;
	}
	p->suivant = q->suivant;
	free(q);}
}
void maxi(etudiant *t){
	float max = t->note;
	etudiant *p=t;
	int pos=0;
	int i=0;
	while(p!=NULL){
		i++;
		if(max <= p->note){
			max = p->note;
			pos = i;
		}
		p = p->suivant;
	}
	printf("%.2f\n", max);
	printf("%d", pos);
}

int nombre(etudiant *tete){
	etudiant *p = tete;
	int nbr=0;
	while(p!=NULL){
		if(p->note >= 10) nbr++;
		p = p ->suivant;
	}
	return nbr;
}

void ajouter(etudiant *tete, int M){
	etudiant *p=tete, *q, *new_e;
	int i=0;
	new_e = (etudiant*)malloc(sizeof(etudiant*));
	printf("Entrez le num d'etudiant: ");
	scanf("%d", &new_e->num);
	printf("Entrez la note");
	scanf("%.2f", &new_e->note);
	if (M>=longu(tete)){
		exit(0);
	}else{
	while(p!=NULL){
	i++;
	if (i = (M-1)){
		q = p->suivant;
		p->suivant = new_e;
		new_e->suivant = q;
		break;
	}
	p = p->suivant;
	}
	}
}
void ajouterFin(etudiant *l){
	etudiant *new_e, *p;
	new_e = (etudiant*)malloc(sizeof(etudiant*));
	printf("Entrez le num d'etudiant: ");
	scanf("%d", &new_e->num);
	printf("Entrez la note");
	scanf("%f", &new_e->note);
	while(p->suivant!=NULL){
		p = p->suivant;
	}
	p->suivant = new_e;
	new_e->suivant = NULL;
}
void afficher(etudiant *tete){
	etudiant *p = tete;
	while(p != NULL){
		printf("%d\t", p->num);
		printf("%.2f\n", p->note);
		p = p->suivant;
	}
}

