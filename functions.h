#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "structures.h"
#include <stdio.h>

int initialiserMonde(Monde *monde);
void initialiserPlateau(Unite *plateau[LONG][LARG]);
Unite* creerUnite(char genre, UListe *uliste);
int placerAuMonde(Unite *unite, Monde *monde, size_t posX, size_t posY);
void affichePlateau(Monde monde);
void ligne();
Unite *dernier(UListe uliste);
void enleverUnite(Unite *unite, Monde* monde);
Unite *getUnitePrec(Unite *unite, UListe *uliste);
UListe *getUListe(char couleur, Monde *monde);
void deplacerUnite(Unite *unite, Monde *monde, int destX, int destY);
void gererTourJoueur(char couleur, Monde *monde);
int attaquer(Unite *unite, Monde *monde, int destX, int destY);
int deplacerouattaquer(Unite *unite, Monde *monde, int destX, int destY);

#endif /* FUNCTIONS_H_INCLUDED */
