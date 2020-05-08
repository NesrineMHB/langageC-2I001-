#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include "image.h"



image_t *creer_image()
	{
	image_t *p;
	p=(image_t*)malloc(sizeof(image_t));
	if(p==NULL)
	{
		printf("probleme d'allocation");
		return NULL;
	}

	p->w=0; 
	p->h=0;
	p->path=NULL;
	p->buff=NULL;	
	return p;

	}

image_t *copier_image(image_t *src)
	{
	
	image_t *cp;
	cp=creer_image();
	cp->h=src->h;
	cp->w=src->w;
	cp->path=strdup(src->path);
	cp->buff=(unsigned char *)malloc(sizeof(unsigned char)*(cp->h)*(cp->w));
	if(cp->buff==NULL)
	{
		exit(1);
		return NULL;
	}
	memcpy(cp->buff,src->buff,sizeof(unsigned char)*(cp->h)*(cp->w));
	return cp;
	
	}

void detruire_image(image_t *p)
	{
	if(p==NULL)

		printf("structure vide");

	free(p->path);
	free(p->buff);
	free(p);
	}
