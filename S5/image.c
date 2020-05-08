    #include<stdlib.h>
    #include<string.h>
    #include<stdio.h>
    #include "image.h"
    
    
    
    image_t *creer_image()
    {
    image_t *p; // CREATION D'UNE NOUVELLE IMAGE
    p=(image_t*)malloc(sizeof(image_t)); // ALLOCATION DE LA BONNE TAILLE DE L'IMAGE
    if(p==NULL)
    {
    printf("Problème d'allocation mémoire.\n");
    exit(1);
    }
    p->w=0; // INITIALISATION DE LA LARGEUR A 0.
    p->h=0; // iNITIALISATION DE LA HAUTEUR A 0.
    p->path=NULL; 
    p->buff=NULL;
    return p;
    }
    
    
    
    image_t *copier_image(image_t *src)
    {
    image_t *cp; 
    cp=creer_image(); // CREATION D'UN NOUVELLE IMAGE.
    cp->h=src->h; // COPIE DE LA LARGEUR DE L'IMAGE SOURCE EN PIXELS 
    cp->w=src->w; // COPIE DE LA HAUTEUR DE L'IMAGE SOURCE EN PIXELS
    cp->path=strdup(src->path); // DUPLICATION DE LA CHAINE DE CARACTÈRE PAS DE BESOIN D'ALLOCATION (DIRECTEMENT ALLOUE AVEC CETTE FONCTION) 
    cp->buff=(unsigned char *)malloc(sizeof(unsigned char)*(cp->h)*(cp->w)); // ALLOCATION D'UNE NOUVELLE ZONE MEMOIRE PERMETTANT DE RENSEIGNER LA TAILLE.
    if(cp->buff==NULL)
    {printf("Problème d'allocation mémoire.\n");
    exit(1);
    }
    memcpy(cp->buff,src->buff,sizeof(unsigned char)*(cp->h)*(cp->w)); //COPIE DE N OCTECTS A PARTIR DE L'ADRESSE CONTENUE DANS LE POINTEUR SRC VERS L'ADRESSE NOUVELLEMENT ALLOUE.
    return cp;
    }
    
    
    void detruire_image(image_t *p)
    {
    if(p==NULL){
    printf("La structure est vide");
    }else{
    free(p->path);
    free(p->buff);
    free(p);
    }
    }

