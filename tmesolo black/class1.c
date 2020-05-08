#include<stdio.h>
#include"liste.h"
#include<stdlib.h>

Element *ajouter_carte(Element *lcarte,Carte c){
	
		Element * nv=malloc (sizeof(Element));
		nv->carte=c;
		nv->suivant=NULL;
		if(lcarte==NULL) return nv;
		
	Element *tmp;
	tmp=lcarte;
	while(tmp->suivant) tmp=tmp->suivant;
	tmp->suivant=nv;
	return lcarte;
	}

unsigned int nb_carte(Element *lcarte){
	int nb=0;
	while(lcarte){// lcarte et pas lcarte-<suivant
		nb++;// le nombre de carte
		lcarte=lcarte->suivant;
		}return nb;
	}
void ecrire_lcarte(Element *lcarte, const char *nom_fichier){
	if (lcarte==NULL) return ; //erreur
	FILE*f=fopen(nom_fichier,"w");
	if(f==NULL) return ;
	
	while(lcarte){
		fprintf(f,"%s de %s /n",Couleur_texte[(lcarte->carte).couleur],Valeur_texte[(lcarte->carte).valeur]);// le sparenthese
		lcarte=lcarte->suivant;
		}
		fclose(f);// noublie pas les fclose
	}
	
Carte trier (Element **plcarte){
	Carte c;
	if(*plcarte==NULL){
		c.couleur=4;// attention 4 et pas 5
		c.valeur=13;
		return c;
		}
	Element *tmp;
	tmp=*plcarte;
	*plcarte=*plcarte->suivant;
	c.couleur=tmp->carte.couleur;
    c.valeur=tmp->carte.valeur;
	return c;
}
	
void liberer_element(Element *lcarte){// a revoir*******************************
	if(lcarte==NULL) return ;
	liberer_element(lcarte->suivant);
	free(lcarte);
	}

unsigned int best_score(Element*tas){// cas de las
	unsigned int *tscore;
	int i=0,nb; // declarer iont n et affecter &n pareil pour tscor
	score_rec(tas,&tscore,&nb );
	int tmp=0;
	for (i=0;i<nb;i++){
		if(tscore[i]>tmp && tscore[i]<=21)
		tmp=tscore[i];
		}return tmp;
	}
	
	
	
Element *tour_joueur(Element *cartes_joueur,Element **plcartee,const char *nom_joueur){
	Carte tirer ;
	tirer=trier (plcartee);
	Element *ajout;
	ajout=ajouter_carte(cartes_joueur,tirer);
    Element *tscore;
    printf("")
	// affichage
	}
