#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int i = 0;
    int j = 0;
    int PosX = 0;
    int PosY = 0;
    int Carte[10][10] = {
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



    printf("Bienvenue a la Bataille Navale :)\n\n");

    system("Pause");

    printf("Voici l'aide du jeu:");
    printf("\n\nLe jeu possede 5 navires: "
           "\n1 portes avion (5 cases),"
           " \n1 croiseur (4 cases), "
           "\n2 contre-torpilleurs (3 cases),"
           " \n1 torpilleur (2 cases)."
           "\nLe but du jeu est de rentrer des coordonnee (par example B4) "
           "\net d'essayer de toucher les bateaux adverses. En tirant le moins de coup possible.\n\n");

     system("Pause");

    //montre la grille de jeu sans les bateaux
        printf("\n     1    2    3    4    5    6    7    8    9    10");
    for (int i = 1; i <= 10; ++i) {
        printf("\n   ---------------------------------------------------");
        printf("\n%d  |    |    |    |    |    |    |    |    |    |    |", i);
    }
    printf("\n    ---------------------------------------------------");

    //ajouter les bateau dans la grille
    for (int k = 2; k < 6; k++) {
        Carte[3][k] == 1;
    }

    do{
        printf("\n\nEntrer la position de tir");
        printf("\nPosition Horizontal:");
        scanf("\n%d", &PosX);
        printf("\nPosition Vertical:");
        scanf("%d", &PosY);
    }while((PosX <= 0) || (PosX >= 10) || (PosY <= 0 ) || (PosY >= 10));

    if (Carte [PosY] [PosX] == 0){
        printf("Raté");
    }
    else{
        if (Carte [PosY] [PosX] == 1){
            printf("Touché");
            Carte [PosY] [PosX] == 0;
        }
    }

    system("Pause");

    return 0;
}