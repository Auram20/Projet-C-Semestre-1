#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "functions.h"

void initialiserMonde(Monde *monde){
    monde->tour = 0;
    initialiserPlateau(monde->plateau);
    (monde->rouge) = calloc(1, sizeof(*(monde->rouge)));
    (monde->rouge)->couleur = ROUGE;
    (monde->rouge)->unites = NULL;
    (monde->bleu) = calloc(1, sizeof(*(monde->bleu)));
    (monde->bleu)->couleur = BLEU;
    (monde->bleu)->unites = NULL;
}

/*Je suis obligé de mettre les tailles du tableau pour une raison que j'ignore*/
void initialiserPlateau(Unite *plateau[LONG][LARG]) {
  size_t i, j;
  for(i = 0; i < LONG; ++i) {
    for(j = 0; j < LARG; ++j) {
      plateau[i][j] = NULL;
    }
  }
}

int creerUnite(char genre, UListe *uliste) {
  Unite *temp;
  temp = calloc(1, sizeof(*(uliste->unites)));
  temp->genre = genre;
  temp->couleur = uliste->couleur;
  temp->suiv = NULL;
  if(temp == NULL) {
    return 0;
  } else {
    if(uliste->unites == NULL) {
      uliste->unites = temp;
    } else {
      dernier(*uliste)->suiv = temp;
    }
    return 1;
  }

}

Unite *dernier(UListe uliste) {
  Unite *unite;
  unite = uliste.unites;
  while(unite != NULL) {
    unite = (unite->suiv);
  }
  return unite;
}

int placerAuMonde(Unite *unite, Monde *monde, size_t posX, size_t posY) {
  if(monde->plateau[posX][posY] != NULL || posX >= LONG || posY >= LARG) {
    return 0;
  } else {
    unite->posX = posX;
    unite->posY = posY;
    monde->plateau[posX][posY] = unite;
    return 1;
  }
}

void affichePlateau(Monde monde) {
  size_t i, j;
  for(i = 0; i < LONG; ++i) {
    ligne();
    printf("|");
    for(j = 0; j < LARG; ++j) {
      if(monde.plateau[i][j] == NULL) {
        printf("    ");
      } else {
        switch((monde.plateau[i][j])->genre) {
          case(SERF):
            printf(" 00 ");
            break;
          case(GUERRIER):
          printf(" () ");
            break;
        }
      }
      printf("|");
    }
    printf("\n");
  }
  ligne();
}

void ligne() {
  int i;
  for(i = 0; i < LARG * 5 + 1; ++i) {
    printf("-");
  }
  printf("\n");
}
