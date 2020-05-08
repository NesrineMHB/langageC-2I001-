# Makefile gameScores

GCC_FLAGS = -Wall
all: main1 main2

orcid.o	: orcid.c # les point .h
	gcc $(GCC_FLAGS) -c orcid.c

tabOrcid.o	: tabOrcid.c
	gcc $(GCC_FLAGS) -c tabOrcid.c

main1.o	: main1.c
	gcc $(GCC_FLAGS) -c main1.c

main1 : orcid.o tabOrcid.o main1.o
	gcc $(GCC_FLAGS) orcid.o tabOrcid.o main1.o -o main1

listeOrcid.o :# .c et .h 
	#la commande pour compiler separement une seul fichier.c
main2 :# tout le fichiers dont depend main2 que les .o car c un executable

clean	:
	rm -f orcid.o tabOrcid.o main1.o main1
