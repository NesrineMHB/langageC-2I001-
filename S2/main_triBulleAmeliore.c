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
	printf("Tri Bulle Ameliore\n");
        triBulleAmeliore(t, TAILLE);
	if(tab_trie(t, TAILLE))
		printf("Trie reussi\n");
	else    printf("Trie echoué\n");


//afficher_tab(t,TAILLE);
return 0;
}
