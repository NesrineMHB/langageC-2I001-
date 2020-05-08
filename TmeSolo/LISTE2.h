#ifndef LISTE2
#define LISTE2
#include "Listes.h"/////////////// khdemti bhaja fi listes tyElListe
#include "LISTE2.h"
typedef struct _tyCase {
	int barre;
	int eau;}tyCase;
	
	int sommeTab(tyCase tab[], int n);
	tyCase *liste2Tab(tyElListe *pL,int n,int *iMax);
	#endif
