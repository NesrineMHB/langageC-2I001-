#include<stdio.h>
#include<stdlib.h>
#include"Listes.h"
# define TAILLE 255


tyElListe *LireListe (char * nomF,int *pN){
	*pN=0;
	char buffer [TAILLE];
	FILE*f=fopen(nomF,"r");
	if(!f) return NULL;
	tyElListe *ls ;//=malloc (sizeof(tyElListe));
	tyElListe *temp; //=malloc (sizeof(tyElListe));
		//LM=ls;
	fgets(buffer,255,f);
	int val;
	sscanf(buffer,"%d",&val);
	ls = malloc (sizeof(tyElListe));
	ls->val = val;
	ls->pS=NULL;
	
	temp = ls;
	while(fgets(buffer,TAILLE,f)){// var local
		sscanf(buffer,"%d ",&val);// TU DONNE UNE @
		
		tyElListe *nv=malloc (sizeof(tyElListe));
		nv->val=val;
		nv->pS=NULL;
		
		temp->pS=nv;
		temp = nv;
		*pN+= val;
		}
	return ls;
	}
	
	
void AfficherListe (tyElListe *pL){
	while(pL){
		printf("%d",pL->val);
		pL=pL->pS;
	}}


