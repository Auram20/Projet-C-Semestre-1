#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

/* dimension du monde en nombre de cases */
#define LONG 12
#define LARG 18
/* l'origine est en haut a gauche */
#define ROUGE 'R' /* identifiant du premier joueur */
#define BLEU 'B' /* identifiant du deuxième joueur */
/* les genres d'unites */
#define SERF 's'
#define GUERRIER 'g'

#define MAXCHAR 12

typedef struct Unite {
    int posX,posY;
    char couleur;
    char genre;
    struct Unite *suiv;

} Unite;

/*J'ai changé le Uliste, car chaque liste a une couleur. Lorsqu'une unité rentre dans une liste, il prend immédiatement la couleur de cette liste*/
typedef struct UListe{
  Unite *unites;
  char couleur;
} UListe;


typedef struct Monde{
  Unite *plateau[LONG][LARG];
  int tour;   /* Numero du tour */
  UListe *rouge, *bleu; /*Listes des deux joueurs*/
} Monde;

#endif /* STRUCTURES_H_INCLUDED */
