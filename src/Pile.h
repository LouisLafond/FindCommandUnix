#ifndef PILE_H
#define PILE_H

typedef struct ElementListe {
  char *donnee;
  struct ElementListe *suivant;
} Element;

typedef struct ListeRepere{
  Element *debut;
  int taille;
} Pile;




/* initialisation */
Pile * initialisation(Pile *tas);

/* EMPILER*/
int empiler(Pile *tas, char *donnee);

/* DEPILER*/
int depiler(Pile *tas);


/* Affiche la pile */
void affiche (Pile *tas);
/*vérifie si la pile est dans le tas*/
int contain(Pile * tas, char *donnee);

#endif