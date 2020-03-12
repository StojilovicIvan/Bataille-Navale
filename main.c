/**
 *Projet: Jeu Bataille Navale
 *Créateur: Stojilovic Ivan
 *Date:
 *Version: 0.1
 *
 */
#include <stdio.h>
#include <windows.h>

int main() {
    //console pour reconnaître les accents
    SetConsoleOutputCP(CP_UTF8);

    //initialiser les valeurs au début
    int i = 0;
    int j = 0;
    int PosX = 0;
    int PosY = 0;

    //créer le tableau pour notre grille de jeu
    int carteSystem[10][10] = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,5,0,0,0,0,0,0,0},
            {0,0,5,0,0,0,0,0,0,0},
            {0,0,5,0,0,0,0,0,0,0},
            {0,0,5,0,0,0,0,0,0,0},
            {0,0,5,0,0,0,0,0,0,0},
            };

    int carteJoueur[10][10] = {
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            };

    //phrase d'entrée du jeu ainsi qu'une pause pour lire
    printf("Bienvenue a la Bataille Navale :)\n\n");
    system("Pause");

    //l'aide du jeu au début  pour comprendre le jeu et une pause
    printf("Voici l'aide du jeu:");
    printf("\n\nLe jeu possede 5 navires: "
           "\n1 portes avion (5 cases),"
           " \n1 croiseur (4 cases), "
           "\n2 contre-torpilleurs (3 cases),"
           " \n1 torpilleur (2 cases)."
           "\nLe but du jeu est de rentrer des coordonnee (par example B4) "
           "\net d'essayer de toucher les bateaux adverses. En tirant le moins de coup possible.\n\n");
     system("Pause");

    //montre la grille de jeu visible par l'utilisateur sans les bateaux
    printf("\n      1     2     3     4     5     6     7     8     9    10   "
           "\n   -------------------------------------------------------------"
           "\n1  |     |     |     |     |     |     |     |     |     |     |"
           "\n   -------------------------------------------------------------"
           "\n2  |     |     |     |     |     |     |     |     |     |     |"
           "\n   -------------------------------------------------------------"
           "\n3  |     |     |     |     |     |     |     |     |     |     |"
           "\n   -------------------------------------------------------------"
           "\n4  |     |     |     |     |     |     |     |     |     |     |"
           "\n   -------------------------------------------------------------"
           "\n5  |     |     |     |     |     |     |     |     |     |     |"
           "\n   -------------------------------------------------------------"
           "\n6  |     |     |     |     |     |     |     |     |     |     |"
           "\n   -------------------------------------------------------------"
           "\n7  |     |     |     |     |     |     |     |     |     |     |"
           "\n   -------------------------------------------------------------"
           "\n8  |     |     |     |     |     |     |     |     |     |     |"
           "\n   -------------------------------------------------------------"
           "\n9  |     |     |     |     |     |     |     |     |     |     |"
           "\n   -------------------------------------------------------------"
           "\n10 |     |     |     |     |     |     |     |     |     |     |"
           "\n   -------------------------------------------------------------");


    do {
        do {
            printf("\n\nEntrer la position de tir");
            printf("\nPosition Horizontal:");
            scanf("\n%d", &PosX);
            printf("\nPosition Vertical:");
            scanf("%d", &PosY);
        } while ((PosX <= 0) || (PosX >= 10) || (PosY <= 0) || (PosY >= 10));

        if (carteSystem[PosY][PosX] == 0) {
            printf("Raté");
            carteJoueur[PosY][PosX] == 1;
        } else {
            if (carteSystem[PosY][PosX] == 1) {
                printf("Touché");
                carteSystem[PosY][PosX] == 0;
            }
        }

    printf()
        system("Pause");
    }while();
    return 0;
}