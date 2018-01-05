#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

/* dimension du monde en nombre de cases */
#define LONG 12
#define LARG 18
/* l’origine est en haut a gauche */
#define ROUGE 'R' //identifiant du premier joueur
#define BLEU 'B' //identifiant du deuxi`eme joueur
/* les genres d’unites */
#define SERF 's'
#define GUERRIER 'g'

typedef struct unite{
    int posX,posY;
    char couleur;
    char genre;
    struct Unite *suiv;

} Unite;

typedef Unite* UListe;


typedef struct monde{
  Unite *plateau[LONG][LARG];
  int tour;   /* Numero du tour */
  UListe rouge, bleu; /*Listes des deux joueurs*/
} Monde;

#endif // STRUCTURES_H_INCLUDED
