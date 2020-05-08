#ifndef LISTE
#define LISTE

#include "Listes.h"////////////// dirihom ga3
typedef struct _tyElListe{
     int val;
     struct _tyElListe *pS;

} tyElListe;

tyElListe *LireListe (char * nomF,int *pN);
void AfficherListe (tyElListe *pL);
#endif
