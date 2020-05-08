#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orcid.h"

/* vérification d'un ORCID sous forme de chaîne de 16 caractères sans tirets, renvoyant 1 s'il est valide, 0 sinon */
int verifier_ORCID(char* orcid) {
char *s =malloc (sizeof (int)*15);
s[0]=orcid[0]*2;
int i;
	for(i=0;i<14;i++)
	s[i+1]=(s[i]+orcid[i+1])*2;
	double ch= (12-(s[14]%11))%11;
	return ch==9;/// c posssible???.?
}

/* écriture d'un ORCID bien formaté avec tirets dans un flux ouvert */
void ecrire_ORCID(FILE* f, char* orcid) {
	int i,j;
	for (i=0; i<LEN_ORCID; i=i+4) {
		for (j=0; j<4; j++) {
			fprintf(f, "%c", orcid[i+j]);
		}
		if (i+4<LEN_ORCID)
			fprintf(f, "-");
	}
	fprintf(f, "\n");
}

/* affichage d'un ORCID bien formaté avec tirets */
void afficher_ORCID(char* orcid) {
	ecrire_ORCID(stdout, orcid);
}
