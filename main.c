/**
 *Projet: Jeu Bataille Navale
 *Créateur: Stojilovic Ivan
 *Date:08.04.2020
 *Version: 1.0
 */
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>



int main() {
    SetConsoleOutputCP(CP_UTF8);



    //initialiser les valeurs au début
    int carteAleatoire = 0;
    int choix = 0;
    int i =0;
    int j =0;
    int PosV =0;
    int PosH =0;
    int retourMenu= 0;
    int fichierScore = 0;
    char nomJoueur[20] = {0};
    FILE*fichier = NULL;

    //créer les tableaux pour notre grille de jeu

    //différant tableau avec les bateaux vu par le programme
    int carte1[10][10] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 6, 6, 6, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 2, 2, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 4, 0, 0},
            {0, 0, 5, 0, 0, 0, 0, 4, 0, 0},
            {0, 0, 5, 0, 3, 0, 0, 4, 0, 0},
            {0, 0, 5, 0, 3, 0, 0, 4, 0, 0},
            {0, 0, 5, 0, 3, 0, 0, 0, 0, 0},
            {0, 0, 5, 0, 0, 0, 0, 0, 0, 0},
    };

    int carte2[10][10] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 5, 5, 5, 5, 5, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 6, 6, 6, 0, 0, 4, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 4, 0, 2, 0},
            {3, 0, 0, 0, 0, 0, 4, 0, 2, 0},
            {3, 0, 0, 0, 0, 0, 4, 0, 0, 0},
            {3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    int carte3[10][10] = {
            {4, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {4, 0, 0, 2, 2, 0, 0, 0, 0, 0},
            {4, 0, 0, 0, 0, 0, 0, 6, 0, 0},
            {4, 0, 0, 0, 0, 0, 0, 6, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 6, 0, 0},
            {0, 3, 3, 3, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 5, 5, 5, 5, 5},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    //tableau vu par le joueur
    int carteJoueur[10][10] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    //tableau vu par le progmramme
    int carteProgramme[10][10] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };


    //phrase d'entrée du jeu ainsi qu'une pause pour lire
    printf("\nBienvenue a la Bataille Navale :)\n"
           "=================================\n\n");
    system("Pause");

    //demander un nom de joueur a l'utilisateur
    printf("\nVotre nom:(maximum 12 caractéres)");
    scanf("%12s", &nomJoueur);

    do {
        //affiche le menu et demande le choix de l'utilisateur
        do {
            printf("\n\nMenu");
            printf("\n\n1.Jouer"
                   "\n2.Scores"
                   "\n3.Aide"
                   "\n4.Quitter");
            printf("\n\nQuel est votre choix:");
            scanf("%d", &choix);
            printf("\n");
        } while ((choix < 1) || (choix > 4));

        switch (choix) {
            case 1:

                carteAleatoire = rand() % 3 + 1;
                switch (carteAleatoire) {
                    case 1:
                        for (i = 0; i < 10; i++) {
                            for (j = 0; j < 10; j++) {
                                carteProgramme[i][j] = carte1[i][j];
                            }
                        }
                    case 2:
                        for (i = 0; i < 10; i++) {
                            for (j = 0; j < 10; j++) {
                                carteProgramme[i][j] = carte2[i][j];
                            }
                        }
                    case 3:
                        for (i = 0; i < 10; i++) {
                            for (j = 0; j < 10; j++) {
                                carteProgramme[i][j] = carte3[i][j];
                            }
                        }
                }
                int carteJoueur[10][10] = {0};
                int Scores =0;
                int nbTouche =0;
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
                    do {
                        //demande d'entré les position choisit
                        printf("\n\nEntrer la position de tir");
                        printf("\n\nPosition Horizontal:");
                        scanf("%d", &PosH);
                        printf("\nPosition Vertical:");
                        scanf("%d", &PosV);
                        PosH -= 1;
                        PosV -= 1;
                        if (carteJoueur[PosV][PosH] > 0) {
                            printf("\nDéja choisit");
                        }
                    } while ((PosH < 0) || (PosH > 9) || (PosV < 0) || (PosV > 9) || (carteJoueur[PosV][PosH] > 0));

                    Scores += 1;

                    //affiche raté ou coulé si la position contient un bateau ou pas et le score
                    if (carteProgramme[PosV][PosH] == 0) {
                        printf("\nRaté !"
                               "\n------\n");
                        carteJoueur[PosV][PosH] = 1;
                    } else if (carteProgramme[PosV][PosH] = !0) {
                        printf("\nTouché !"
                               "\n--------\n");
                        carteJoueur[PosV][PosH] = 2;
                        nbTouche += 1;
                    }
                    printf("\nVotre scores en jeu: %d",Scores);
                } while (nbTouche < 17);

                //texte de fin
                printf("\n\nGagner !!!"
                       "\n----------\n\n");
                printf("\n\nJoueur: %s  Scores: %d\n\n", nomJoueur, Scores );

                //enregistre le score avec le pseudo en fin de partie
                fichier = fopen("Scores.txt", "a");
                fprintf(fichier,"\n%s; %d", nomJoueur, Scores);
                fclose(fichier);
                printf("score enregistré\n"
                       "----------------\n");




                system("Pause");
                break;

                //affiche la liste de tout les scores enregistrer
            case 2:
                fichier = fopen("Scores.txt", "r");
                do {
                    fichierScore = fgetc(fichier);
                    printf("%c", fichierScore);
                }while (fichierScore !=EOF );
                fclose(fichier);
                system("Pause");
                break;

                //affiche les régles du jeu
            case 3:
                printf("\nVoici l'aide du jeu:");
                printf("\n\nLe jeu possede 5 navires: "
                       "\n1 portes avion (5 cases),"
                       "\n1 croiseur (4 cases), "
                       "\n2 contre-torpilleurs (3 cases),"
                       "\n1 torpilleur (2 cases)."
                       "\nLe but du jeu est de rentrer des coordonnee (par example 4 et 7) "
                       "\net d'essayer de toucher les bateaux adverses. En tirant le moins de coup possible."
                       "\nLe jeu affiche 1 si vous ratez ou un 2 si vous touchez un bateau.\n\n");
                system("Pause");
                break;

                //permet de quitter le programme depuis le menu
            case 4:
                exit(EXIT_SUCCESS);
        }
    }while(retourMenu == 0);

}