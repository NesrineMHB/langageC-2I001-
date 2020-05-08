#ifndef LISTE_ORCID_H
#define LISTE_ORCID_H

typedef struct _elt {
	char orcid[LEN_ORCID+1];/* ORCID d'un auteur */
	struct _elt *suiv;	/* pointeur vers l'auteur suivant */
} elt;

/* ajout dans une liste chaînée d'ORCID d'un nouvel élément */
void inserer_listeORCID(elt** liste, elt* nouveau);

/* création d'un élement de liste contenant un ORCID passé en argument */
elt* creer_eltORCID(char* orcid);

/* affichage d'une liste chaînée d'ORCID */
void affichage_listeORCID(elt* liste);

/* vérification de chaque ORCID d'une liste et destruction de ceux ne contenant pas des ORCID valides */
elt* verifier_listeORCID(elt* liste);

/* destruction d'une liste d'éléments contenant des ORCID */
void detruire_listeORCID(elt* liste);

/* lecture d'un fichier d'ORCID et ajout des ORCID valides dans une liste chaînée */
elt* lire_fichierORCID(char* nom_fichier);

/* écriture d'un fichier d'ORCID (avec tirets) depuis une liste chaînée */
void ecrire_fichierORCID(char* nom_fichier, elt* liste);

#endif