#include <stdlib.h>
#include "noyau.h"
#include <stdio.h>
#include <string.h>
#include "image.h"
#define TMP_STR_SIZE 128

noyau_t *creer_noyau(unsigned int dim)
	{
	noyau_t *pn;
	pn=(noyau_t*)malloc(sizeof(noyau_t));
	if(pn==NULL)
		return NULL;

	pn->dim=dim;
	pn->coeffs=(int *)malloc(dim*dim*sizeof(int));
	return pn;
	}

void detruire_noyau(noyau_t *pn)
	{
	if(pn!=NULL)
		{
		free(pn->coeffs);
		free(pn);
		}
	}

noyau_t *charger_noyau(char *nom_fichier)
	{
	unsigned int dim;
	char tmp_str[TMP_STR_SIZE];
	FILE *f;
	int i,j;
	noyau_t *pn;
	
	if (!(f=fopen(nom_fichier,"r")))
		{
		printf("Erreur\n");
		return NULL;	
   		 }
	
	fgets(tmp_str,TMP_STR_SIZE,f);

	if (sscanf(tmp_str,"%d \n",&dim)!=1)
		{
		printf("Mauvais format\n");
		return NULL;
		}
	if(!(pn=creer_noyau(dim)))
		{
		printf("Mauvais format\n");
		return NULL;		
		}
	int *pi=pn->coeffs;
	for(i=0;i<dim;i++)
		{
		char *cur=tmp_str;
		char *next;
		fgets(tmp_str,TMP_STR_SIZE,f);
		for(j=0;j<dim;j++)
			{
			strtol(cur,&next,0);
			pi++;
			}
		if(next==cur)
			{
			printf("ERREUR\n");
			detruire_noyau(pn);		
			}
		cur=next;
		}
	fclose(f);
	return pn;
	}
	
