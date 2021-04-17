#include <stdlib.h>
#include <stdio.h>


typedef struct Heure{
	int hh;
	int mm;
	int ss;
}Heure;

Heure *Add(Heure *h1, Heure *h2);
Heure *ConvSH(int s);
int ConvertHS(Heure *h);

int main(){
	Heure *d, *f, *x;
	d->hh = 3;
	d->mm = 34;
	d->ss = 59;
	f->hh = 4;
	f->mm = 43;
	f->ss = 30;
	int i = 1800;
	x = ConvSH(i);
	printf("%d ... %d ... %d ", x->hh, x->mm, x->ss);


}
int ConvertHS(Heure *h){

	return h->hh*3600 + h->mm*60 + h->ss;
}

Heure *ConvSH(int s){
	Heure *p;
	int r;
	p->hh = s/3600;
	r = s%3600;
	p->mm = r/60;
	p->ss = r%60;

	return p;
}

Heure *Add(Heure *h1, Heure *h2){
	int s1, s2;
	Heure *q;
	s1 = ConvertHS(h1);
	s2 = ConvertHS(h2);
	q = ConvSH(s1+s1);
	if(q->hh >= 24){
		q->hh = q->hh - 24;
	}
	return q;
}




