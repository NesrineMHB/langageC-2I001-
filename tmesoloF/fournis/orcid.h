#ifndef ORCID_H
#define ORCID_H

#define MIN_ORCID "0000000150000007"	/* ORCID minimum pouvant être généré aléatoirement */
#define MAX_ORCID "0000000350000001" 	/* ORCID maximum pouvant être généré aléatoirement */
#define LEN_ORCID 16

/* vérification d'un ORCID sous forme de chaîne de 16 caractères sans tirets, renvoyant 1 s'il est valide, 0 sinon */
int verifier_ORCID(char* orcid);
void afficher_ORCID(char* orcid);
void ecrire_ORCID(FILE* f, char* orcid) ;

#endif
