
#include <stdio.h>
#include <stdlib.h>

#include "LISTE2.h"


int main(int argc, char **argv)
{int i=0;/// 3amri la liste pl

	tyElListe *doc=malloc (sizeof(tyElListe));
	doc=LireListe ( "TMESOLO.txt",&i);


 tyCase *tab;//=malloc(sizeof(tyCase));
 int n=0;
tab=liste2Tab(doc,i,&n);
int s=sommeTab(tab,i);
return 0;
	}

