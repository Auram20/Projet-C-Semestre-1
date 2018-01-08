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
  creerUnite(SERF, monmonde.rouge);
  creerUnite(GUERRIER, monmonde.bleu);
  placerAuMonde((monmonde.rouge)->unites, &monmonde, 10, 6);
  placerAuMonde((monmonde.bleu)->unites, &monmonde, 10, 5);
  affichePlateau(monmonde);


 attaquer(monmonde.plateau[10][6],&monmonde,10,5);
  affichePlateau(monmonde);
  enleverUnite((monmonde.rouge)->unites, &monmonde);
  affichePlateau(monmonde);

  return EXIT_SUCCESS;
}
