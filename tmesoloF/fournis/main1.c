#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orcid.h"
#include "tabOrcid.h"
#define TAILLE_TEST 6

int main() {
	char orcidTab[TAILLE_TEST][LEN_ORCID+1] = {"0000000314159269", "0000000218250097", "000000029079593X", 
						"0000000301662484", "0000000194361251", "0000000350002103"};  // 3 ORCID valides suivis de 3 ORCID invalides
	int taille = TAILLE_TEST;
	int i;
	// verification du tableau de test
	for (i=0; i<taille; i++) {
		afficher_ORCID(orcidTab[i]);
		printf("--- %s\n", verifier_ORCID(orcidTab[i]) ? "valide" : "invalide");
	}

char ** tab;
int n;
tab= verifier_tabORCID(orcidTab,&n)
	
	// allocation dynamique d'un nouveau tableau, copie du premier
	// supression????
	// affichage de ce tableau, avant et apres verification des ORCID contenus
	return 0;
}
