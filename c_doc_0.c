//#ANNEE 2016/2017 
//EXERCICE I (8pts)

#include <stdio.h>
#include <stdlib.h>

//1.Creer une liste chainee qui contient N entiers.

typedef struct liste{
	int number;
	struct liste *next;
}liste;

liste *creerListe(){
	liste *head = NULL, *tmp, *p;
	int i, n;
	printf("Entrez la taille de la liste: ");
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		tmp = (liste*)malloc(sizeof(liste));
		printf("Entrez l'entier %d\t", i);
		scanf("%d", &tmp->number);
		if(i==1){
			head = tmp;
			p = head;
		}
		else {
			p->next = tmp;
			p =p->next;
		}

	}
	printf("\n");
	p->next = NULL;
	return head;
}

//2.Calculer la moyenne de la liste.

int calculerMoyenne(liste *head){
	liste *p = head;
	int sum = 0;
	while(p != NULL) {
		sum += p->number;
		p = p->next;
	}
	return sum;
}

//3.Ecrire une fonction qui renvoie la position de l'element X s'il existe dans une liste.

int entierPosition(liste *head,int X){
	liste *p = head;
	int pos = 0, i=0;
	while(p!=NULL){
		i++;
		if (X==p->number){
			pos = i;
			break;
		}
		p=p->next;
	}
	return pos;
}

//4.Ecrire une fonction qui renvoie la valeur du dernier element de la liste.

int valeurDernierElement(liste *head){
		liste *p = head;
		while(p->next!=NULL){
			p=p->next;
		}
		return p->number;
}

//5.Retirer le premier element d'une liste.

liste *retirerPremierElement(liste *head){
	liste *p = head;
	head = p->next;
	free(p);
	return head;
}

//6.Retirer le dernier element d'une liste.

liste *retirerDernierElement(liste *head){
	liste *p = head;
	while(p->next->next != NULL) {
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	return head;
}

//7.Ecrire une fonction qui concatene deux listes.

liste *concateneDeuxListes(liste *liste_one, liste *liste_two) {
	liste *p = liste_one;
	while(p->next != NULL) {
		p=p->next;
	}
	p->next = liste_two;
	return liste_one;
}

int main(){
	/*
	 	Demo snippets
	*/
	liste *myListe = creerListe();
	printf("La moyenne est \t %d \n\n", calculerMoyenne(myListe));
	const myNumber = 99;	 //Chercher la position de myNumber s'il existe
	int pos = entierPosition(myListe, myNumber);
	if(pos == 0) {   // entierPosition renvoie 0 si myNumber il n'existe pas sinon la position
		printf("%d il n'existe pas! essayez un autre nombre.\n\n",myNumber);
	}
	else {
		printf("La position de %d est l'index \t %d \n\n", myNumber, pos);
	}
	printf("la valeur du dernier element de la liste\t%d", valeurDernierElement(myListe));
	return 0;
}
