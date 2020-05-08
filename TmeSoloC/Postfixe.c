//
//  Postfixe.c
//  

#include "Pile.h"
#include "Postfixe.h"

/**************************************************************/
void SautBlancs(char *expression,int *pt_rang)
{//saute les espaces et la valeur du groupe
    int i=*pt_rang;
    
    while(expression[i] != '\0' && ((expression[i] == ' ') || (expression[i] == '\n'))){i++;} //si expression commence par les espaces
    *pt_rang = i;

}

/**************************************************************/
int EstOperateur(char *expression, int i)
{
    int validity = 0;
 
    
    /*************************************/
    
    //  ZONE  REPONSE
    
    /************************************/

    return(validity);
}


/**************************************************************/
int EstNombre(char *expression, int i)
{ int validity =0;
    
    /*************************************/
    
    //  ZONE  REPONSE
    
    /************************************/

    return(validity);
}

/**************************************************************/
void SautNombre(char *expression,int *pt_rang)
{//saute les nombres
    int i=*pt_rang;
    i= i + EstNombre(expression,i);
    *pt_rang = i;
}



/**************************************************************/
int ExpPostValid(char * expression)
{
    int validity=1,last=0;// dernier term doit être un operateur sauf si expression réduite à un nombre
    
    /*************************************/
    
    //  ZONE  REPONSE
    
    /************************************/

    return(last*validity);
}
/**************************************************************/


int DechiffrePostfixe(char *expression,int	*total)
{
    int i=0;
    int x,y,z;
    cellule *pile;
    int validity=0;
    
    
    /*************************************/
    
    //  ZONE  REPONSE
    
    /************************************/

  
      return(validity);
}
