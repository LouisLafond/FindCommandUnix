#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Pile.h"

Pile* initialisation (Pile * tas){
  tas = calloc(1,sizeof(Pile));
  return tas;
  
}

/* empiler (ajouter) un élément dans la pile */
int empiler(Pile * tas, char *donnee){
  Element *nouveau_element;
  
  nouveau_element = calloc(1,sizeof(Element));
  nouveau_element->donnee = strdup(donnee);
  nouveau_element->suivant = tas->debut;
  tas->debut = nouveau_element;
  tas->taille++;
  return 0;
  
  
}

/* depiler (supprimer les éléments de la pile */
int depiler (Pile * tas){
  if ((tas->debut != NULL)&&(tas->debut->donnee)) {
    Element *courant = tas->debut;
    while (courant != NULL) {
      free(courant->donnee);
      tas->taille -= 1;
      courant = courant->suivant;
    }
    free(tas);

  }
  
  return 0;
  
}

/* affichage de la pile */
void affiche (Pile * tas){
  Element *courant;
  
  courant = tas->debut;

  while(courant != NULL) {

    printf("%s\n", courant->donnee);
    courant = courant->suivant;
  }

}