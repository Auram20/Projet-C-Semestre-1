#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "structures.h"
#include <stdio.h>

int initialiserMonde(Monde *monde);
void initialiserPlateau(Unite *plateau[LONG][LARG]);
Unite* creerUnite(char genre, UListe *uliste);
int placerAuMonde(Unite *unite, Monde *monde, size_t posX, size_t posY);
void affichePlateau(Monde monde);
char *getSymbol(char genre);
void afficheNumH(int n);
void ligne();
Unite *dernier(UListe uliste);
void enleverUnite(Unite *unite, Monde* monde);
Unite *getUnitePrec(Unite *unite, UListe *uliste);
UListe *getUListe(char couleur, Monde *monde);
void deplacerUnite(Unite *unite, Monde *monde, int destX, int destY);
void gererTourJoueur(char couleur, Monde *monde);
int attaquer(Unite *unite, Monde *monde, int destX, int destY);
int deplacerouattaquer(Unite *unite, Monde *monde, int destX, int destY);
void gererTourJoueur(char couleur, Monde *monde);
Unite **creerSelection(UListe uliste);
int nombreUnite(UListe uliste);
int parcourirUniteSelect(Unite **tab, int length);
int enleverSelect(Unite **tab, size_t indice, size_t length);
void decaleSelect(Unite **tab, size_t debut, size_t length);
/*Unite *parcourirUnites(UListe uliste); BACKUP*/
void afficherUnite(Unite unite);
void actionUnite(Unite *unite, Monde *monde);
void viderMonde(Monde *monde);
void viderUListe(UListe *uliste);
void gererTour(Monde *monde);
void placerunite(Monde *monde, UListe *uliste, char genre);
void placementparjoueur(Monde *monde, char couleur);
void placementinitial(Monde *monde);
void gererPartie(void);
#endif /* FUNCTIONS_H_INCLUDED */
