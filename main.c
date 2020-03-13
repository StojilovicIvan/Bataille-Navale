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
            {0,3,3,3,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,2,2,0,0,0,0,0},
            {0,0,0,0,0,0,0,4,0,0},
            {0,0,5,0,0,0,0,4,0,0},
            {0,0,5,0,3,0,0,4,0,0},
            {0,0,5,0,3,0,0,4,0,0},
            {0,0,5,0,3,0,0,0,0,0},
            {0,0,5,0,0,0,0,0,0,0},
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




        do {
            printf("\n\nEntrer la position de tir");
            printf("\nPosition Horizontal:");
            scanf("\n%d", &PosX-1);
            printf("\nPosition Vertical:");
            scanf("%d", &PosY-1);
        } while ((PosX < 0) || (PosX >= 9) || (PosY < 0) || (PosY >= 9));

        if (carteSystem[PosX][PosY] == 5) {
            printf("Touché\n");
        } else if (carteSystem[PosX][PosY] == 0) {
                printf("Raté\n");
            }


        system("Pause");

    return 0;
}