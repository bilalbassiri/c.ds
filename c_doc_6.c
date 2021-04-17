//RATTRAPAGE 2018-2019 .EXERCISE I
#include <stdio.h>
#include <stdlib.h>
typedef struct liste{
	int num;
	float note;
	struct liste * next;
}liste;

int existe(liste *t, int X);
liste * creer(liste *head, int N);
void display_liste(liste *T);
int longueur_l(liste * t);
float noteMax(liste * f);
void suppMin(liste *t);
int nombrS(liste * t);
liste * addMiddle(liste * t, int pos);
float mynL(liste * t);
liste * rechL(liste *t);
liste * debutSup(liste * t);
liste * lastSup(liste * t);
liste * concL(liste * t,liste * c);
liste * dMiddle(liste * t, int pos);
liste * inverse(liste *t);

int main(){
	liste * head, *q, *l, *w;
	q=NULL;
	int N,pos;
	printf("Input N : ");
	scanf("%d", &N);
	q = creer(head, N);
	//printf("Input N : ");
	//scanf("%d", &N);
	//l = creer(head, N);
	//pos = existe(q,4);
	//printf("%d", pos);
	display_liste(q);
	//scanf("%d", &pos);
	//l = creer(head, N);
	w = inverse(q);
	//l = rechL(q);
	//m = 3;
	//suppMin(q);
    //l = inverse(q);
    display_liste(w);
	//printf("\n-----POS de num 3 ---\n      %d", rechL(q,m));
	//w = dMiddle(q,pos);
	//display_liste(w);
	//q = NULL;
	//int lon = longueur_l(q);
	//printf("%d", lon);
	//printf("\n-----LONG---\n     %.2d", longueur_l(q));
	//printf("\n-----MAX----\n     %.2f", noteMax(q));
	//printf("\n----->=10----\n     %.2d", nombrS(q));
}

//1
liste * creer(liste *head, int N){
	liste *new_e, *tmp, *p;
	int i;
	for(i=0; i<N; i++){
	new_e = (liste*)malloc(sizeof(liste));
	printf("Input Student's ID:\t");
	scanf("%d", &(new_e->num));
	printf("Input the note:\t");
	scanf("%f", &(new_e->note));
	if (i == 0) {
		head = new_e;
		tmp = head;
	}else {
	tmp ->next= new_e;
	tmp = tmp->next;}
	}
	tmp->next = NULL;
	return head;
}

void display_liste(liste *t){
	if(t==NULL){
		printf("la liste est vide: ");
	}
	else{
		printf("NUM:--------------NOTE:\n");
		while(t!=NULL){
		printf(" %d  ````````````` %.2f\n", t->num, t->note);
		t = t->next;}
		}
}
//2
int longueur_l(liste * t){
	int lng=0;
	if(t == NULL){
		return lng;
	}
	else{
	while(t!=NULL){
		lng +=1;
		t = t->next;
		}
		return lng;
	}
}
//4
float noteMax(liste * f){
	float Max = f->note;
	liste *s;
	s = f->next;
	while(s != NULL){
		if(Max <= (s->note)){
			Max = s->note;
		}
		s = s->next;
	}
	return Max;
}
//3
void suppMin(liste *t){
	liste *Mptr, *p, *q;
	float Min = t->note;
	p= t->next;
	while(p!=NULL){
		if((p->note <= Min)){
			Min = p->note;
			Mptr = p;
		}

		p = p->next;
	}
	q = t;
	while(q->next != Mptr) q = q->next;
	if (Mptr->next != NULL) q->next = Mptr->next;
	else q->next = NULL;
	free(Mptr);

}
//5
int nombrS(liste * t){
	int sm = 0;
	liste *p = t;
	while(p != NULL){
		if((p->note) >= 10) sm +=1;
		p = p->next;
	}
	return sm;
}
// 6
liste * addMiddle(liste * t, int pos){
	liste *new_st, *p, *q;
	p = t; int i=1;
	new_st = (liste*)malloc(sizeof(liste));
	printf("Input the num of the student:\t");
	scanf("%d", &(new_st->num));
	printf("Input the note:\t");
	scanf("%f", &(new_st->note));
	while(p != NULL){
		p = p->next;
		i++;
		if(i==pos) break;
	}
	q = p->next;
	p->next = new_st;
	new_st->next = q;
	return t;
}
liste * dMiddle(liste * t, int pos){
	liste *p,*q;
	int i;

	if (pos == 1){
		p=t;
		t = p->next;
		free(p);
	}else {
		i=2;
		p = t->next;
		while((i+1) != pos){
			p = p->next;
			i++;
		}
		q=p->next;
		if(q->next == NULL){
			p->next= NULL;
			free(q);
		}else{
		p->next=q->next;
		free(q);
		}
	}
	return t;
}
float mynL(liste * t){
	liste *p = t;
	float sm=0, total=0;
	while(p != NULL){
		sm++;
		total = total + p->note;
		p = p->next;
	}
	return total/sm;
}

liste * rechL(liste *t){
	liste *p, *q;
	p = t->next;
	q = t;
	while(p != NULL){
		p = p->next;
		q = q->next;
	}
	return q;
}
liste * debutSup(liste * t){
	liste *p;
	p = t;
	t = p->next ;
	free(p);
	return t;
}
 liste * lastSup(liste * t){
	liste *p, *q;
	p = t->next;
	q = t;
	while(p->next != NULL){
		p = p->next;
		q = q->next;
	}
	q->next = NULL;
	free(p);
	return t;
 }

 liste * concL(liste * t,liste * c){
	liste *p = t;
	while (p->next != NULL){
		p = p->next;
	}
	p ->next = c;
	return t;
 }
liste * inverse(liste *t){
	liste *p, *q = NULL;
	while ( t != NULL){
		p = t;
		t = t->next;
		p->next = q;
		q = p;
	}
	return q;
}
int existe(liste *t, int X){
	int E = 0;
	liste *p;
	p=t;
	while(p!=NULL){
		if(p->num==X){
			E = 1;
		}
		p = p->next;
	}
	return E;
}
