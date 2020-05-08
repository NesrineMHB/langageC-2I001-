//
//  Postfixe.h
//  

#ifndef Postfixe_h
#define Postfixe_h

#include <math.h>
#include "Principal.h"

void SautBlancs(char *expression,int *pt_rang);
void SautNombre(char *expression,int *pt_rang);
int EstOperateur(char *expression, int i);
int EstNombre(char *expression, int i);
int ExpPostValid(char * expression);
int DechiffrePostfixe(char *expression,int	*total);

#endif /* Postfixe_h */
