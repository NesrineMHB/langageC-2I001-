#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "image.h"
#include "noyau.h"

int i,j,val;
image_t *negatif(image_t *src)
	{
	if(src==NULL)
	{
		printf("errreur");
		return NULL;
	}
	image_t *dst=copier_image(src);
		
	for(i=0;i<dst->h;i++)
		for(j=0;j<dst->w;j++)
			{
			dst->buff[i+j]=255-dst->buff[(i)*(dst->w)+(j)];

			}
	return dst;
	}



image_t *rotation(image_t *src, int angle)
	{ 
	if(src==NULL)
	{
		printf("errreur");
		return NULL;
	}
	image_t *dst=copier_image(src);
	switch (angle)
	{
		case 90:
			for(i=0;i<dst->h;i++)
			for(j=0;j<dst->w;j++)
				{
				VAL(dst,i,j)=VAL(src,j,(dst->h-i-1));
				}
		break;
		case 180:
			for(i=0;i<dst->h;i++)
			for(j=0;j<dst->w;j++)
				{
				VAL(dst,i,j)=VAL(src,(dst->h-i-1),(dst->w-1-j));
				}
		break;
		case 270:
		for(i=0;i<dst->h;i++)
			for(j=0;j<dst->w;j++)
				{
				VAL(dst,i,j)=VAL(src,(dst->w-1-j),i);
				}
		default: printf ("erreur");	
	}	
	return dst;
	
	
	}



image_t *modifier_lumin(image_t *src, int pourcent)
	{ 
	if(src==NULL)
		{
		printf("errreur");
		return NULL;
		}
	image_t *dst=copier_image(src);
		
	for(i=0;i<dst->h;i++)
		for(j=0;j<dst->w;j++)
			{
			unsigned char*case=dst->buff[(i)*(img)->w+(j)];
			*case=(*case*pourcent)/100;
			if(*case>255)
				*case=255;
			}
	return dst;
	}



image_t *bruiter_image(image_t *src, int pourcent)
	{
	
	
	if(src==NULL)
		{
		printf("errreur");
		return NULL;
		}
	image_t *dst=copier_image();
	for(i=0;i<dst->h * dst->w;i++)
		{
	        val=rand()%100;
		if(val<pourcent)
			dst->buff[i]=rand()%256;	
				
		}
	}





image_t *filtrer_median(image_t *src)
	{
	return NULL;
	}




image_t *convoluer(image_t *src, noyau_t *pn)
	{
	image_t *dst;
	int coef_norm=0,k=0,nvp=0;
	unsigned int dim,somd,jbrd,ibrd,mj,mi,i,j;
	
	if (!pn) return NULL;
	if(!src) return NULL;	

	dim= pn->dim;
	for(int i=0;i<dim*dim;i++)
		coef_norm=coef_norm+pn->coeffs[i];

	dst=copier_image(src);
	for( i=0;i<src->h;i++)
		for( j=0;j<src->w;j++)
			{
			for( mi=i-(dim/2);mi<=i+(dim/2);mi++){
				if(mi<0) mi=0;
				if(mi>dst->h) mi=dst->h-1
				for( mj=j-(dim/2);mj<=j+(dim/2);mj++)
					 { 
					ibrd=i+mi-(dim/2);
						if (ibrd<0)
							ibrd=0;
						if (ibrd>src->h)
								ibrd=src->h-1;
						jbrd=j+mj+dim/2;
						if(jbrd<0)
							jbrd=0;	
						if(jbrd>src->w)
							jbrd=src->w-1;
						somd=somd+pn->coeffs[mi*pn->dim+mj]+VAL(src,ibrd,jbrd);
					  }		
				 if(coef_norm==0)// avoir
				 	VAL(dst,i,j)=(unsigned int)somd/coef_norm;
				 else
					VAL(dst,i,j)=(unsigned int)abs(somd/coef_norm);
			}
	return dst;
	}

