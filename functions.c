#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "functions.h"

int initialiserMonde(Monde *monde){
    monde->tour = 0;
    initialiserPlateau(monde->plateau);
    (monde->rouge) = calloc(1, sizeof(*(monde->rouge)));
    if((monde->rouge) == NULL) {
      return 0;
    }
    (monde->rouge)->couleur = ROUGE;
    (monde->rouge)->unites = NULL;
    (monde->bleu) = calloc(1, sizeof(*(monde->bleu)));
    if((monde->bleu) == NULL) {
      return 0;
    }
    (monde->bleu)->couleur = BLEU;
    (monde->bleu)->unites = NULL;
    return 1;
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
  if(temp == NULL) {
    return 0;
  } else {
    temp->genre = genre;
    temp->couleur = uliste->couleur;
    temp->suiv = NULL;
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


void deplacerUnite(Unite *unite, Monde *monde, int destX, int destY){
    if(monde->plateau[destX][destY] == NULL && destX <= LONG && destY <= LARG && abs(destX-(unite->posX))<=1 && abs(destY-(unite->posY))<=1 ) /* On verifie que la destination existe et est vide et que c'est un déplacement adjascent */
    {
                    monde->plateau[unite->posX][unite->posY]=NULL;
                    unite->posX = destX;
                    unite->posY = destY;
                    monde->plateau[destX][destY] = unite;

        }

}

void enleverUnite(Unite *unite, Monde *monde) {
  Unite *unitePrec = getUnitePrec(unite, getUListe(unite->couleur, monde));
  if(unitePrec == unite) {
    unitePrec = unite->suiv;
  } else if(unitePrec != NULL) {
    unitePrec->suiv = unite->suiv;
  }

  monde->plateau[unite->posX][unite->posY] = NULL;
}





UListe *getUListe(char couleur, Monde *monde) {
  if(couleur == (monde->rouge)->couleur) {
    return (monde->rouge);
  }
  else if(couleur == (monde->bleu)->couleur) {
    return (monde->bleu);
  }
  else {
    return NULL;
  }

}

Unite *getUnitePrec(Unite *unite, UListe *uliste) {
  Unite *search;
  search = uliste->unites;
  while(search != NULL && search->suiv != unite && search != unite) {
    search = search->suiv;
  }
  return search;
}



int attaquer(Unite *unite, Monde *monde, int destX, int destY){
    if(monde->plateau[destX][destY] !=NULL){
                if (unite->genre==GUERRIER || unite->genre==monde->plateau[destX][destY]->genre){
                    enleverUnite(monde->plateau[destX][destY],monde);
                    deplacerUnite(unite,monde,destX,destY);
                    return 1;
    }
         enleverUnite(unite,monde);
        return 0;
    }
        
   return 0;     
    
}


