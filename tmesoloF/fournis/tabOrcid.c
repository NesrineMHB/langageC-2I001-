#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orcid.h"
#include "tabOrcid.h"

/* vérification de chaque ORCID d'un tableau et création d'un nouveau tableau ne contenant que des ORCID valides */ 
char** verifier_tabORCID(char** tabOrcid, int* taille) {

	int i=0,j=0;
	for(i=0;i<length(*tabOrcid);i++){
		if(verifier_ORCID(tabOrcid[i])==1)
			tabOrcid[j++] = tabOrcid[i];
	tabOrcid = realloc(tabOrcid, j);// elle recopie le pointeur
	*taille = j;// la taille c n et pas n-1
	return tabOrcid;
}

/* destruction d'un tableau d'ORCID alloué dynamiquement */
void detruire_tabORCID(char** tabOrcid, int taille) {// quand il donne taille on lutilise car le tab leau ne contiendra pas null
int i;
	for(i=0;i<taille;i++){
	free(tabOrcid[i]);
free(tabOrcid);
}

/* affichage d'un tableau d'ORCID */
void afficher_tabORCID(char** tabOrcid, int taille) {
	int i;
	for (i=0; i<taille; i++) {
		afficher_ORCID(tabOrcid[i]);
	}	
}
