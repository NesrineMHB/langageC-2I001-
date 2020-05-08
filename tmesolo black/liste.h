#ifndef LISTE
#define LISTE

#include "liste.h"
typedef enum {coeur, carreau,trefle,pique, couleur_invalide} Couleur;
typedef enum {as,deux,trois,quatre,cinq,six,sept,huit,neuf,dix,valet,dame,roi,valeur_invalide} Valeur;

typedef struct _carte{
Couleur couleur;
Valeur valeur;

}Carte;


typedef struct _element{
Carte carte;
struct _element *suivant;

}Element;



unsigned int nb_carte(Element *lcarte);
Element *ajouter_carte(Element *lcarte,Carte c);
Carte trier (Element **plcarte);
void ecrire_lcarte(Element *lcarte, const char *nom_fichier);
void liberer_element(Element *lcarte){
unsigned int best_score(Element *tas);
void score_rec(Element *tas, unsigned int **tscore,unsigned int *nb );


char *Couleur_texte []={"coeur", "carreau","trefle","pique", "couleur_invalide"};
char *Valeur_texte []={"as","deux","trois","quatre","cinq","six","sept","huit","neuf","dix","valet","dame","roi","valeur_invalide"} ;
 #endif
