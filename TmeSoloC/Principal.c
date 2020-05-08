//
//  Principal.c
//  

#include "Principal.h"
#include "Pile.h"
#include "Postfixe.h"
#include "Tests.h"


/**************************************************************/
int main(int argc, char *argv[])
{
    char chaine[TAILLE];
    int valeur;
    FILE *f,*g;

  

    /*Test de Pile.c*/
    printf("Test de Pile.c  %d \n",TestPile());
    /*Test de Postfixe.c*/
    printf("Test de Postfixe.c  %d \n",TestPostfixe());
    
    
     f = stdin;
     g = stdout;
     while(fgets(chaine,TAILLE,f)){
          if(ExpPostValid(chaine)){
               if(DechiffrePostfixe(chaine,&valeur))
                    fprintf(g,"%d\n",valeur);
               else
                    fprintf(g,"\n");
          }
          else
               fprintf(g,"erreur\n");
     }
    
    /*************************************/
     
     //  ZONE  REPONSE
     
     /************************************/
    
     return(1);
}


