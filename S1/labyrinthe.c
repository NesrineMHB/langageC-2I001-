#include<stdio.h>
#include<stdlib.h>
#define DIM 8


void afficher_lab(int lab[DIM][DIM], char palette[])

	{int i,j;
     	printf("+");
	for(i=0;i<DIM;i++){
		printf("-");         }
	printf("+\n");
		for(i=0;i<DIM;i++){
		printf("|");
			for(j=0;j<DIM;j++){
				// printf("%d",lab[i][j]);
				if(lab[i][j]==2) printf("%c",palette[0]);
				else printf("%c",palette[1]);
			}printf("| \n");}
	printf("+");
	for(i=0;i<DIM;i++){
		printf("-");         }
	printf("+\n");
	}


int cheminRec(int lab[DIM][DIM],int lc,int cc)
{
	// TESTER SI ON EST PAS A L'EXTERIEUR DU TAB
	if(lc<0||cc<0||lc>=DIM||cc>=DIM) 
		return 0;
	
	// TESTER le contenu de la case en cour
	if(lab[lc][cc]!=0)  
		return 0;

	// affecter le 2 dans le cas echean
	lab[lc][cc]=2;

	// TESTER SI ON EST a la derniere case
	if(lc==DIM-1 && cc==DIM-1)	
		return 1;
	 
	// appel recurssive pour parcourir toute la table
	if(cheminRec( lab, lc+1,cc))
		return 1;
	if(cheminRec( lab, lc-1,cc))
		return 1;
	if(cheminRec( lab, lc,cc+1))
		return 1;
	if(cheminRec( lab, lc,cc-1))
		return 1;
                                   	
	// affecter le 2 si il n'y a pas de chemain
	lab[lc][cc]=3; return 0;
}


void monChemin(int lab[DIM][DIM]){
	int x=0,y=0;
	if(cheminRec( lab, x,y)) printf("bravo\n");
	else printf("ERREUR\n");}






int main (){	
   int tab[8][8]={{0,0,1,0,0,0,1,1},{1,0,0,1,1,0,1,0},{1,0,1,1,1,0,0,0},{1,0,0,1,0,0,1,1},{0,1,0,0,0,1,0,1},{0,0,0,1,0,1,0,1},{1,1,1,1,0,0,0,0,},{1,0,1,1,0,0,0,0,}};
		
	//int tab[3][3]={{0,0,1},{0,0,1},{1,1,1}}; c'est pour voir le cas ou il n'y'a pas de 					chemain, mais il faut changer le define a 3 au lieu de 8

   char palette[]={' ','*'};
	afficher_lab(tab, palette);
	monChemin(tab);
	afficher_lab(tab, palette);
		return 0;
	}
