//
//  Tests.c
//  

#include "Tests.h"
#include "Pile.h"
#include "Postfixe.h"
#include "Principal.h"


int TestPile()
{
    int tab[9]={2,4,0,2,+3,-4,0,3,100};
    int i,taux,resultat=0,val=0;
    int a;
    cellule *pile;
    
 
    InitialisePile(&pile);
    
    val=0;
    for(i=0;i<9;i++) val =  val + EmpilePile(tab[i],&pile);
    taux =  100*val/9;
    printf(" taux réussite EmpilePile = %d  \n", taux);
    resultat = resultat + taux*2;
    
    val =0;
    while(pile && DepilePile(&a,&pile))
        if(a == tab[--i]) val =  val + 1;
    taux =  100*val/9;
    printf(" taux réussite DepilePile = %d  \n", taux);
    resultat = resultat + taux*3;
    return(resultat);
}


int TestPostfixe()
{
    int  taux,resultat=0;
    int  coeff[4]={1,1,3,5};
    int  a, val;
    int i,j,taille=9;
    char *liste[9]={"3 2 *",
        "2 3 * 4 -  ",
        "-2 3 * 4 + ",
        "-22 5 * 7 - ",
        "     24  2 / 4 +  ",
        "+3 - 3",
        "    9 7 3 5 6 + + / * ",
        "2 3 4 5 6 *-/* ",
        "45 21 * 30 / 6 5 - *"
    };
    int tabliste[9]={6,2,-2,-117,16,0,0,0,31};
    int tabvalid[9]={1,1,1,1,1,0,1,0,1};
    char *tabop[9]={",","+","+","-","-2","a","/","*","-9"};
    char *tabnombre[9]={"/6","2","-2","-117","1.6","a","0","10000000","+"};
    int tabverifop[9]={0,1,1,1,0,0,1,1,0};
    int tabverifnb[9]={0,1,2,4,0,0,1,8,0};


    j=0;
    
    val=0;
    for(i=0;i < taille;i++) {val = val + (EstOperateur(tabop[i],0)==tabverifop[i]);}
    taux =  100*val/9;
    for(i=0,val=0;i < taille;i++){val = val + EstOperateur(tabop[i],0);}
    if (val == 0  || val == 9) taux = 0;
    printf(" taux réussite EstOperateur = %d  \n", taux);
    resultat = resultat + taux*coeff[j++];
    
    val=0;
    for(i=0;i < taille;i++) {val = val + (EstNombre(tabnombre[i],0)==tabverifnb[i]);}
    taux =  100*val/9;
    for(i=0,val=0;i < taille;i++){val = val + EstNombre(tabnombre[i],0);}
    if (val == 0  || val == 9) taux = 0;
    printf(" taux réussite EstNombre = %d  \n", taux);
    resultat = resultat + taux*coeff[j++];
    
    
    val=0;
    for(i=0;i < taille;i++) {val = val + (ExpPostValid(liste[i])==tabvalid[i]);}
    taux =  100*val/9;
    for(i=0,val=0;i < taille;i++){val = val + ExpPostValid(liste[i]);}
    if (val == 0  || val == 9) taux = 0;
    printf(" taux réussite ExpPostValid = %d  \n", taux);
    resultat = resultat + taux*coeff[j++];
    
    val=0;
    for(i=0;i < taille;i++)    {a=0;
        val = val + ( (DechiffrePostfixe(liste[i],&a)== tabvalid[i]) && (a == tabliste[i]) );
    }
    taux =  100*val/9;
    for(i=0,val=0;i < taille;i++){val = val + DechiffrePostfixe(liste[i],&a);}
    if (val == 0  || val == 9) taux = 0;
   printf(" taux réussite DechiffrePostfixe = %d  \n", taux);
    resultat = resultat + taux*coeff[j++];

    
    return(resultat);
}
