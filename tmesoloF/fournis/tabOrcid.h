#ifndef TAB_ORCID_H
#define TAB_ORCID_H

/* vérification de chaque ORCID d'un tableau et création d'un nouveau tableau ne contenant que des ORCID valides */ 
char** verifier_tabORCID(char** tabOrcid, int* taille);

/* destruction d'un tableau d'ORCID alloué dynamiquement */
void detruire_tabORCID(char** tabOrcid, int taille);

/* affichage d'un tableau d'ORCID */
void afficher_tabORCID(char** tabOrcid, int taille);

#endif