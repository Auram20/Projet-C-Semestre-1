#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "structures.h"
#include <stdio.h>

void initialiserMonde(Monde *monde);
void initialiserPlateau(Unite *plateau[LONG][LARG]);
int creerUnite(char genre, UListe *uliste);
int placerAuMonde(Unite *unite, Monde *monde, size_t posX, size_t posY);
void affichePlateau(Monde monde);
void ligne();
Unite *dernier(UListe uliste);

#endif /* FUNCTIONS_H_INCLUDED */
