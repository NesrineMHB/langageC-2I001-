#include "utilitaires_tableaux.h"

void triBulle(int tab[], int n)
{
int i,j;
	for(i=n;i>1;i--)
		for(j=0;j<i-1;j++)
			if(tab[j]>tab[j+1])
				echanger_elem_tab(tab, j, j+1);		
}

void triBulleAmeliore(int tab[], int n)
{
int i,j,permute=1;
	for(i=n;(i>1) && permute;i--){
		permute=0;
		for(j=0;j<i-1;j++)
			if(tab[j]>tab[j+1]){
				echanger_elem_tab(tab, j, j+1);	
				permute=1;}}
}

