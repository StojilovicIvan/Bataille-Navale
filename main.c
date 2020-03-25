/**
 *Projet: Jeu Bataille Navale
 *Créateur: Stojilovic Ivan
 *Date:18.03.2020
 *Version: 0.1
 */
#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);


    //initialiser les valeurs au début
    int choix = 0;
    int i = 0;
    int j = 0;
    int PosH = 0;
    int PosV = 0;
    int bateauCoule = 0;

    //créer les tableaux pour notre grille de jeu

    //tableau avec les bateaux vu par le programme
    int carteBateau[10][10] = {
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

    //tableau vu par le joueur
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
    printf("Bienvenue a la Bataille Navale :)\n"
           "=================================\n\n");
    printf("Etes-vour prêt ?\n"
           "================\n");
    system("Pause");

    //boucle pour pouvoir jouer avec entant de coup que l'on a besoin avant de toucher tout les bateaux
    do {
        //montre la grille au joueur pour s'orienter
        printf("\n      1   2   3   4   5   6   7   8   9   10 \n"
               "    -----------------------------------------\n");
        for (i = 0; i < 10; i++) {
            printf("%3d | ", i + 1);
            for (j = 0; j < 10; j++) {
                printf("%d | ", carteJoueur[i][j]);
            }
            printf("\n");
            printf("    -----------------------------------------\n");
        }


        //demande les positions ou affiche l'aide ou arrête le programme selon la volontée de l'utilisateur
        do {
            //affiche le nombre de bateau coulé au total
            printf("\nbateau coulé :%d",bateauCoule);
            //demande d'entré des position
            printf("\n\nEntrer la position de tir");
            printf("\n(Pour quitter taper 11. Ou pour de l'aide taper 12.)");
            printf("\n\nPosition Horizontal:");
            scanf("\n%d", &PosH);
            printf("\nPosition Vertical:");
            scanf("%d", &PosV);
            PosH -= 1;
            PosV -= 1;
            if ((PosV == 10) || (PosH == 10)) {
                exit(EXIT_SUCCESS);
            } else if ((PosV == 11) || (PosH == 11)) {
                printf("Voici l'aide du jeu:");
                printf("\n\nLe jeu possede 5 navires: "
                       "\n1 portes avion (5 cases),"
                       "\n1 croiseur (4 cases), "
                       "\n2 contre-torpilleurs (3 cases),"
                       "\n1 torpilleur (2 cases)."
                       "\nLe but du jeu est de rentrer des coordonnee (par example 4 et 7) "
                       "\net d'essayer de toucher les bateaux adverses. En tirant le moins de coup possible."
                       "\nLe jeu affiche 1 si vous ratez, un 2 si vous touchez et 3 si vous faites touché-coulé.\n");
            }
            //affiche un texte si la position à déjà était rentrée
            if(carteJoueur[PosV][PosH] > 0){
            printf("\nDéja choisit");
            }
        } while ((PosH < 0) || (PosH > 9) || (PosV < 0) || (PosV > 9) || (carteJoueur[PosV][PosH] > 0));

        //affiche raté ou coulé si la position contient un bateau ou pas
        if (carteBateau[PosV][PosH] == 0) {
            printf("\n------"
                   "\nRaté !"
                   "\n------\n");
            carteJoueur[PosV][PosH] = 1;
        } else if (carteBateau[PosV][PosH] =! 0) {
            printf("\n--------"
                   "\nTouché !"
                   "\n--------\n");
            carteJoueur[PosV][PosH] = 2;
        }

        //affiche coulé si le bateau a été entièrement touché
        //bateau 1
        if((carteJoueur[3][3] == 2) && (carteJoueur[3][4] == 2)){
            printf("Coulé"
                   "\n-----");
            carteJoueur[3][3]  = 3;
            carteJoueur[3][4]  = 3;
            bateauCoule += 1;
        }
        //bateau 2
        if((carteJoueur[1][1] == 2) && (carteJoueur[1][2] == 2) && (carteJoueur[1][3] == 2)){
            printf("Coulé"
                   "\n-----");
            carteJoueur[1][1]  = 3;
            carteJoueur[1][2]  = 3;
            carteJoueur[1][3]  = 3;
            bateauCoule += 1;
        }
        //bateau 3
        if((carteJoueur[6][4] == 2) && (carteJoueur[7][4] == 2) && (carteJoueur[8][4] == 2)){
            printf("Coulé"
                   "\n-----");
            carteJoueur[6][4]  = 3;
            carteJoueur[7][4]  = 3;
            carteJoueur[8][4]  = 3;
            bateauCoule += 1;
        }
        //bateau 4
        if((carteJoueur[4][7] == 2) && (carteJoueur[5][7] == 2) && (carteJoueur[6][7] == 2) && (carteJoueur[7][7] ==2)){
            printf("Coulé"
                   "\n-----");
            carteJoueur[4][7]  = 3;
            carteJoueur[5][7]  = 3;
            carteJoueur[6][7]  = 3;
            carteJoueur[7][7]  = 3;
            bateauCoule += 1;
        }
        //bateau 5
        if((carteJoueur[5][2] == 2) && (carteJoueur[6][2] == 2) && (carteJoueur[7][2] == 2) && (carteJoueur[8][2] ==2)
        && (carteJoueur[9][2] ==2)){
            printf("Coulé"
                   "\n-----");
            carteJoueur[5][2]  = 3;
            carteJoueur[6][2]  = 3;
            carteJoueur[7][2]  = 3;
            carteJoueur[8][2]  = 3;
            carteJoueur[9][2]  = 3;
            bateauCoule += 1;
        }
    //termine la boucle si tout les bateaux ont été coulé
    }while(bateauCoule < 5);

    //petit texte de victoire à la fin
    printf("\n----------"
           "\nGagner !!!"
           "\n----------"
           "\nBien joué."
           "\n----------\n\n");

    system("Pause");

    return 0;
}