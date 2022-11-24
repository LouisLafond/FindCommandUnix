#ifndef PILE_H
#define PILE_H

typedef struct ElementListe{
  char *donnee;
  struct ElementListe *suivant;
} Element;

typedef struct ListeRepere{
  Element *debut;
  int taille;
} Pile;




/* initialisation */
void initialisation(Pile *tas);

/* EMPILER*/
int empiler(Pile *tas, char *donnee);

/* DEPILER*/
int depiler(Pile *tas);

/* Affichage de élément en haut de la pile (LastInFirstOut) */
#define pile_donnee(tas)  tas->debut->donnee

/* Affiche la pile */
void affiche (Pile *tas);

#endif