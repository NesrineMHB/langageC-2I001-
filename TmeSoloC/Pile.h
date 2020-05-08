//
//  Pile.h
//  

#ifndef Pile_h
#define Pile_h

#include "Principal.h"

typedef struct objet{
    int val;
    struct objet *suiv;
} cellule;

int InitialisePile(cellule ** pt_pile);
int EmpilePile(int x,cellule **pt_pile);
int DepilePile(int  *pt_x,cellule **pt_pile);

#endif /* Pile_h */
