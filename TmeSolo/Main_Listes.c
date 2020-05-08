#include <stdio.h>
#include <stdlib.h>
#include "Listes.h"

int main(int argc, char **argv)
{int i=0;
	tyElListe *doc=malloc (sizeof(tyElListe));
	doc=LireListe ( "TMESOLO.txt",&i);
	
	AfficherListe (doc);
	
	return 0;
	}

