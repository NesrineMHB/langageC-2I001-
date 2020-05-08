#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "image.h"
#define TMP_STR_SIZE 256



	
	
image_t *charger_image_pgm(char *nom_fichier){
	FILE *f;
	image_t *img;
	unsigned int nb_niveaux_gris;
	char ligne_lue[TMP_STR_SIZE];
	// enum format {BIN, ASCII} pgm_form;
	
	if (!(f=fopen(nom_fichier,"r")))
	{
		printf("Erreur\n");
		exit(1);	
    }
	do {
		fgets(ligne_lue,TMP_STR_SIZE,f);
		
	} while (*ligne_lue=='#');
	if(strcmp(ligne_lue,"P2\n")!=0)
	{
		printf("Le fichier n'est pas structuré\n");
		return NULL;
	}
	// pour voir si il nya pas de commentzire entre P2 et le code quon veut avoir
		do
		fgets(ligne_lue,TMP_STR_SIZE,f);
		while (*ligne_lue=='#');

	img= creer_image();
	img->path=strdup(nom_fichier);

	if (sscanf(ligne_lue,"%lu %lu \n",&(img->w),&(img->h))!=2)
	{
		printf("Mauvais format\n");
		detruire_image(img);/// a revoir (fuite de mémoire)
		return NULL ;
	}
	
	// pour voir si il nya pas de commentzire entre h et w et le code quon veut avoir
	do
	{
		fgets(ligne_lue,TMP_STR_SIZE,f);
	} while (*ligne_lue=='#');
		
	if(sscanf(ligne_lue,"%d",&nb_niveaux_gris)!=1)
	{
		printf("Fichier mal structuré\n");
		detruire_image(img);
	    return NULL;
	}	
	img->buff=(unsigned char*)malloc(img->w*img->h*sizeof(unsigned char));
	
	
	if((img->buff)==NULL){
		printf("Fichier mal structuré\n");
		detruire_image(img);
		return NULL;
	}
	unsigned int i,j;
	unsigned char *p=img->buff;
	for(i=0;i<img->h;i++)
	{
		for(j=0;j<img->w;j++)
		fscanf(f,"%hhu ",p++);
	}
	fclose(f);
	return img;
	}

    int sauver_image_pgm(char *nom_fichier, image_t *img)	
		{
	    FILE *f;
		//image_t *img;
		unsigned int nb_niveaux_gris = 0;
		//char ligne_lue[TMP_STR_SIZE];
	// enum format {BIN, ASCII} pgm_form;
	    
		if (!(f=fopen(nom_fichier,"w+")))
		{
		printf("Erreur\n");
		exit(1);
	    }
	    //tester l'existance	
	   
		// tester le bon format
		fprintf(f,"P2\n");
		fprintf(f," %ld %ld \n",img->w ,img->h);
		
		fprintf(f,"%d\n",nb_niveaux_gris);
		int j,i;
		unsigned char *p=img->buff;
		for(i=0;i<img->h;i++)
	    {
			for(j=0;j<img->w;j++)
				fprintf(f," %s\n",p++);
		
		}fclose(f);
		return 1;
	    
	}


