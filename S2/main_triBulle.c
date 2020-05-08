#include "utilitaires_tableaux.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tri_bulle.h"
#define TAILLE 10000

int main(){
	int t[TAILLE];
	srand(time(NULL));
	init_tab_alea(t, TAILLE);
//afficher_tab(t,TAILLE);
	printf("Tri Bulle\n");
	triBulle(t, TAILLE);
	if(tab_trie(t, TAILLE))
		printf("Trie reussi\n");
	else    printf("Trie echoué\n");
//afficher_tab(t,TAILLE);
return 0;
}
/* 1)la fonction triBulleAmeliore est plus rapide que la fonction triBulle. En effet, TriBulleAmeliore effectue n-1 passages alors que  la fonction triBulle en effectue n*(n-1)/2.
Le temps mis après l'éxecution de  la fonction triBulleAmelioré est:
real	0m9,136s
user	0m9,132s
sys	0m0,000s

Le temps mis après l'éxecution de  la fonction triBulle est:
real	0m18,336s
user	0m18,332s
sys	0m0,000s

2)La fonction Tribulle est plus rapide.*/
