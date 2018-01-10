#include "functions.h"
#include "structures.h"

#include <stdio.h>
#include <stdlib.h>


int main(void) {
  Monde monmonde;
  if(!initialiserMonde(&monmonde)) {
    printf("Erreur Mémoire\n");
    return EXIT_FAILURE;
  }

  affichePlateau(monmonde);
  if(!placerAuMonde(creerUnite(SERF, monmonde.rouge), &monmonde, 10, 6)) {
    printf("Erreur Placement Unite\n");
  }
  if(!placerAuMonde(creerUnite(GUERRIER, monmonde.bleu), &monmonde, 10, 5)) {
    printf("Erreur Placement Unite\n");
  }

  affichePlateau(monmonde);


 attaquer(monmonde.plateau[10][6],&monmonde,10,5);
  affichePlateau(monmonde);
  enleverUnite((monmonde.rouge)->unites, &monmonde);
  affichePlateau(monmonde);

  return EXIT_SUCCESS;
}
