#include "utilitaires_tableaux.h"
#include <stdlib.h>
#include <stdio.h>


void triRapide(int tab[], int n) {
int i;
	if(n>1){
		int*tab1=nouveau_tableau(n-1); 
		int*tab2=nouveau_tableau(n-1); 
		int it1=0,it2=0;
	 	for( i=1;i<n;i++)
			if(tab[i]<=tab[0]){
				tab1[it1]=tab[i]; it1++;}
			else{
				tab1[it2]=tab[i]; it2++;}
			triRapide(tab1, it1);
			triRapide(tab2, it2);

			tab[it1]=tab[0];
			for(i=0;i<it1;i++)
				tab[i]=tab1[i];
			for(i=0;i<it2;i++)
				tab[i+it1+1]=tab2[i];
			detruire_tableau(tab1);
			detruire_tableau(tab2);}

}
int partitionner(int tab[], int s, int n)
	{
    int compt=s;
    int pivot=tab[s];
    int i;

    for(i=s+1;i<=n;i++)
        {
        if(tab[i]<pivot)
            {
            compt++;
            echanger_elem_tab(tab,compt,i);
            }
        }
    echanger_elem_tab(tab,compt,s);
    return(compt);
    }


void triRapideAmeliore(int tab[], int s, int n)
	{
	 {
    if(s<n)
        {
        int pivot=partitionner(tab,s,n);
        triRapideAmeliore(tab,s,pivot-1);
        triRapideAmeliore(tab,pivot+1,n);
        }
    }

	}
