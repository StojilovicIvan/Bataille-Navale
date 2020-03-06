#include <stdio.h>


int main() {
    int i=0;

    printf("\nBienvenue a la Bataille Navale");
    printf("\n\nVoici l'aide du jeu:");
    printf("\n\nLe jeu possde 5 navires: \n1 portes avion (5 cases),"
           " \n1 croiseur (4 cases), \n2 contre-torpilleurs (3 cases),"
           " \n1 torpilleur (2 cases)."
           "\nLe but du jeu est de rentrer des coordonnee (par example B4) \net d'essayer de toucher"
           " les bateaux adverses. En tirant le moins de coup possible.");

    for (int i = 0; i < 10; ++i) {
        printf("\n---------------------------------------------------");
        printf("\n|    |    |    |    |    |    |    |    |    |    |");
    }

  printf("\n\nExemple de ligne suplementaire");

    return 0;
}