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
  creerUnite(GUERRIER, monmonde.rouge);
  placerAuMonde((monmonde.rouge)->unites, &monmonde, 10, 6);
  affichePlateau(monmonde);
  deplacerUnite((monmonde.rouge)->unites, &monmonde, 9, 5);
  affichePlateau(monmonde);
  enleverUnite((monmonde.rouge)->unites, &monmonde);
  affichePlateau(monmonde);

  return EXIT_SUCCESS;
}
