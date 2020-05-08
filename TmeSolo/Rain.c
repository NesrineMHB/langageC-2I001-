#include<stdio.h>
#include<stdlib.h>
#include "LISTE2.h"


tyCase *liste2Tab(tyElListe *pL,int n,int *iMax){
 tyCase *tab=malloc(sizeof(tyCase)*n);
 int i=0;
 int valMax=0;
 *iMax=0;
 while(pL){
	tab[i].eau=0;
	tab[i].barre = pL->val;
	if(pL->val>valMax){*iMax=i; valMax=pL->val;}
	pL = pL->pS;
	i++;
	}
	return tab;
}

int sommeTab(tyCase tab[], int n){// alhmara quantité deau
	int i, s=0;
	for(i=0; i<n;i++)// n c la longueur de tab
		s+=tab[i].eau;
		return s;
	
			}
void fillwater(int n,iMax,tyCase tab[]){}
		
void afficheRainWater(tyCase *tab , int n , int iMax){
	
	
	}	
