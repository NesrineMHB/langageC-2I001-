#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "orcid.h"
#include "listeOrcid.h"

/* ajout dans une liste chaînée d'ORCID d'un nouvel élément en tête */
void inserer_listeORCID(elt** liste, elt* nouveau) {
}

/* création d'un élement de liste contenant un ORCID passé en argument */
elt* creer_eltORCID(char* orcid) {
	return NULL;
}

/* affichage d'une liste chaînée d'ORCID */
void affichage_listeORCID(elt* liste) {
	// fonction non demandée, à écrire au besoin mais ne rapportant pas de points
}

/* vérification de chaque ORCID d'une liste et destruction de ceux ne contenant pas des ORCID valides */
elt* verifier_listeORCID(elt* liste) {
	elt* tmp;
	if (liste->suiv != NULL) {
		liste->suiv = verifier_listeORCID(liste->suiv);
	}
	if (verifier_ORCID(liste->orcid))
		return liste;
	else {
		tmp = liste->suiv;
		free(liste);
		return tmp;
	}
}

/* destruction d'une liste d'éléments contenant des ORCID */
void detruire_listeORCID(elt* liste) {
}

/* lecture d'un fichier d'ORCID et ajout des ORCID valides dans une liste chaînée */
elt* lire_fichierORCID(char* nom_fichier) {
	return NULL;
}

/* écriture d'un fichier d'ORCID (avec tirets) depuis une liste chaînée */
void ecrire_fichierORCID(char* nom_fichier, elt* liste) {
}