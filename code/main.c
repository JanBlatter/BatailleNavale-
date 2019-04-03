#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma execution_character_set("utf-8") // pour accents
/* Auteur : Jan blatter
 * Date : 08.03.2019
 * Nom du fichier : Bataille navale
 * Version : 1.0
 */

int choix;      //variable pour le choix du menu
char nom[50];       // nom du joueur
int ligne=0;            // variable pour la création des lignes
int colonne=0;            // variable pour la création des colonnes
int LigneChoisi=0;                              // les coordonées de la ligne choisies par l'utilisateur
int ColonneChoisi=0;                            // les coordonées de la colonne choisies par l'utilisateur
int ConditionImpossible=0;   // Compteur pour la boucle
int Bateau1=0;  // Vie du bâteau
int Bateau2=0;  // Vie du bâteau
int Bateau3=0;  // Vie du bâteau
int Bateau4=0;  // Vie du bâteau
int Condition=0;        //compteur pour l'affichage des coordonnées
int Score=100;
FILE *fpscore;


int menu()
{
    printf("Bonjour et bienvenue dans la bataille navale. ");
    printf("Menu : Que voulez-vous faire ?\n");

    printf("Taper 1 pour Jouer\n");               // Affiche le menu
    printf("Taper 2 pour voir les scores\n");
    printf("Taper 3 pour afficher l'aide\n");
    printf("Taper 4 pour quitter\n");


    scanf("%d", &choix);
    return choix;
}


int main() {

    SetConsoleOutputCP(65001);

    printf("Bienvenue à la bataille navale.\n\n");

    printf("Menu : Que voulez-vous faire ?\n\n");

    printf("Taper 1 pour Jouer\n");      // Affiche le menu
    printf("Taper 2 pour voir les scores\n");
    printf("Taper 3 pour afficher l'aide\n");
    printf("Taper 4 pour quitter\n");


    scanf("%d", &choix);              //le choix du joueur
    system("cls");


    switch (choix) {
        case 1:

            printf("Quel est votre nom ?\n");  // Demande le nom
            scanf("%s", nom);


            fpscore = fopen("Score.txt", "a+");
            fprintf(fpscore, "%s", nom);

            system("cls");

            printf("voici la grille\n\n");
            printf("Veuillez écrire les coordonées pour tenter de toucher un bâteau\n\n");


            char grille[8][8] = { // La Grille que le joueur peut voir
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',

            };
            int grille2[8][8] = {  // la grille invisible au yeux du joueur

                    0, 0, 0, 0, 0, 0, 0, 0,
                    0, 3, 3, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 1, 0, 0,
                    0, 0, 0, 0, 0, 1, 0, 0,
                    0, 0, 0, 0, 0, 1, 0, 0,
                    0, 2, 2, 2, 2, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 4, 4, 4, 4, 4, 0,

            };

            ;                                         // Affichage des coordonées honrizontals


            for (ConditionImpossible = 0;
                 ConditionImpossible < 1000; ConditionImpossible++)   // Boucle pour afficher la grille
            {

                printf("   ");
                for (Condition = 0; Condition < 8; Condition++) {
                    printf("%5d", Condition);
                }
                printf("\n");

                //Affiche la grille
                for (ligne = 0; ligne < 8; ligne++) {
                    printf("%d |", ligne);                                        //Affichage des coordonées verticals
                    for (colonne = 0; colonne < 8; colonne++) {
                        printf("%5c", grille[ligne][colonne]);
                    }
                    printf("\n");
                }


                // Toucher
                printf("\n\nveuillez-choisir une coordonnée de 0 à 7 (Honrizontal)\n");
                scanf("%d", &LigneChoisi);
                printf("veuillez-choisir une coordonnée de 0 à 7 (Vertical)\n");
                scanf("%d", &ColonneChoisi);

                if (grille2[LigneChoisi][ColonneChoisi] != 1 && grille2[LigneChoisi][ColonneChoisi] != 2 &&
                    grille2[LigneChoisi][ColonneChoisi] != 3 && grille2[LigneChoisi][ColonneChoisi] != 4){
                    printf("Vous avez raté\n");
                    grille[LigneChoisi][ColonneChoisi] = 'R';
                    Score++;
                }
                else
                {
                    if (grille2[LigneChoisi][ColonneChoisi] == 1 || grille2[LigneChoisi][ColonneChoisi] == 2 || // condition qui marque un X si c'est touché  //Le x remplace le 0 si il y a un bateau
                        grille2[LigneChoisi][ColonneChoisi] == 3 || grille2[LigneChoisi][ColonneChoisi] == 4) {

                        if (grille[LigneChoisi][ColonneChoisi] == 'X')
                            printf("Un bâteau a déjà été touché\n");
                        else {
                            printf("un bâteau a été touché\n"); //
                            grille[LigneChoisi][ColonneChoisi] = 'X';
                            Score--;
                        }



                        if (grille2[LigneChoisi][ColonneChoisi] == 3) {                   // Coulé du bâteau 3
                            Bateau3 = Bateau3 + 1;
                            if (Bateau3 == 2) {
                                printf("Le torpilleur a été éliminé.\n");
                            }

                        }
                        if (grille2[LigneChoisi][ColonneChoisi] == 4) {               // coulé du bâteau 4
                            Bateau4 = Bateau4 + 1;
                            if (Bateau4 == 5) {
                                printf("Le porte-avions a été éliminé. \n");
                            }

                        }
                        if (grille2[LigneChoisi][ColonneChoisi] == 2) {                   //Coulé du bâteau 2
                            Bateau2 = Bateau2 + 1;
                            if (Bateau2 == 4) {
                                printf(" Le croiseur a été éliminé.\n");
                            }

                        }

                        if (grille2[LigneChoisi][ColonneChoisi] == 1) {                //Coulé du bâteau 1
                            Bateau1 = Bateau1 + 1;
                            if (Bateau1 == 3) {
                                printf(" Le sous-marin a été éliminé.\n");
                            }
                        }


                        if (Bateau1 >= 3 && Bateau2 >= 4 && Bateau3 >= 2 && Bateau4 >= 5) { //Victoire
                            printf("Victoire, vous avez touché tous les bâteaux. La partie est terminée. \n\n");
                            printf("Voici le score : %d  \n", Score);
                            ConditionImpossible = ConditionImpossible + 1000;

                            fprintf(fpscore, "%s","\n");
                            fprintf(fpscore, "%d", Score);
                            fprintf(fpscore, "%s","\n");

                        }


                    }
                }
            }
            break;


        case 2: // Score des anciennes parties
            fscanf(fpscore, "%s",&nom);
            fscanf(fpscore, "%d",&Score);
            printf("%s   %d", nom,Score);


            break;

        case 3:
            printf(" le jeu consiste a faire couler tous les bateaux de l'ennemi en touchant leurs parties.\n");                // l'aide
            printf(" Tout d'abord , il faudra deviner où sont les bâteaux sur la grille. \n");
            printf(" Apres cela, écriver les coordonées afin d'essayer de toucher une partie des bâteaux.\n");
            printf(" Si toutes les parties d'un bâteau sont touchées. Le bâteau est coulé. Couler tous les bâteaux et la victoire sera votre.\n");
            printf(" Vivre ou mourir , à vous de choisir.\n");


            menu();
            return 0;


        case 4:
            return 0;

        default:
            break;
    }


    fclose(fpscore);
    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma execution_character_set("utf-8") // pour accents
/* Auteur : Jan blatter
 * Date : 08.03.2019
 * Nom du fichier : Bataille navale
 * Version : 1.0
 */

int choix;      //variable pour le choix du menu
char nom[50];       // nom du joueur
int ligne=0;            // variable pour la création des lignes
int colonne=0;            // variable pour la création des colonnes
int LigneChoisi=0;                              // les coordonées de la ligne choisies par l'utilisateur
int ColonneChoisi=0;                            // les coordonées de la colonne choisies par l'utilisateur
int ConditionImpossible=0;   // Compteur pour la boucle
int Bateau1=0;  // Vie du bâteau
int Bateau2=0;  // Vie du bâteau
int Bateau3=0;  // Vie du bâteau
int Bateau4=0;  // Vie du bâteau
int Condition=0;        //compteur pour l'affichage des coordonnées
int Score=100;
FILE *fpscore;


int menu()
{
    printf("Bonjour et bienvenue dans la bataille navale. ");
    printf("Menu : Que voulez-vous faire ?\n");

    printf("Taper 1 pour Jouer\n");               // Affiche le menu
    printf("Taper 2 pour voir les scores\n");
    printf("Taper 3 pour afficher l'aide\n");
    printf("Taper 4 pour quitter\n");


    scanf("%d", &choix);
    return choix;
}


int main() {

    SetConsoleOutputCP(65001);

    printf("Bienvenue à la bataille navale.\n\n");

    printf("Menu : Que voulez-vous faire ?\n\n");

    printf("Taper 1 pour Jouer\n");      // Affiche le menu
    printf("Taper 2 pour voir les scores\n");
    printf("Taper 3 pour afficher l'aide\n");
    printf("Taper 4 pour quitter\n");


    scanf("%d", &choix);              //le choix du joueur
    system("cls");


    switch (choix) {
        case 1:

            printf("Quel est votre nom ?\n");  // Demande le nom
            scanf("%s", nom);


            fpscore = fopen("Score.txt", "a+");
            fprintf(fpscore, "%s", nom);

            system("cls");

            printf("voici la grille\n\n");
            printf("Veuillez écrire les coordonées pour tenter de toucher un bâteau\n\n");


            char grille[8][8] = { // La Grille que le joueur peut voir
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',
                    'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O',

            };
            int grille2[8][8] = {  // la grille invisible au yeux du joueur

                    0, 0, 0, 0, 0, 0, 0, 0,
                    0, 3, 3, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 1, 0, 0,
                    0, 0, 0, 0, 0, 1, 0, 0,
                    0, 0, 0, 0, 0, 1, 0, 0,
                    0, 2, 2, 2, 2, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0, 0,
                    0, 0, 4, 4, 4, 4, 4, 0,

            };

            ;                                         // Affichage des coordonées honrizontals


            for (ConditionImpossible = 0;
                 ConditionImpossible < 1000; ConditionImpossible++)   // Boucle pour afficher la grille
            {

                printf("   ");
                for (Condition = 0; Condition < 8; Condition++) {
                    printf("%5d", Condition);
                }
                printf("\n");

                //Affiche la grille
                for (ligne = 0; ligne < 8; ligne++) {
                    printf("%d |", ligne);                                        //Affichage des coordonées verticals
                    for (colonne = 0; colonne < 8; colonne++) {
                        printf("%5c", grille[ligne][colonne]);
                    }
                    printf("\n");
                }


                // Toucher
                printf("\n\nveuillez-choisir une coordonnée de 0 à 7 (Honrizontal)\n");
                scanf("%d", &LigneChoisi);
                printf("veuillez-choisir une coordonnée de 0 à 7 (Vertical)\n");
                scanf("%d", &ColonneChoisi);

                if (grille2[LigneChoisi][ColonneChoisi] != 1 && grille2[LigneChoisi][ColonneChoisi] != 2 &&
                    grille2[LigneChoisi][ColonneChoisi] != 3 && grille2[LigneChoisi][ColonneChoisi] != 4){
                    printf("Vous avez raté\n");
                    grille[LigneChoisi][ColonneChoisi] = 'R';
                    Score++;
                }
                else
                {
                    if (grille2[LigneChoisi][ColonneChoisi] == 1 || grille2[LigneChoisi][ColonneChoisi] == 2 || // condition qui marque un X si c'est touché  //Le x remplace le 0 si il y a un bateau
                        grille2[LigneChoisi][ColonneChoisi] == 3 || grille2[LigneChoisi][ColonneChoisi] == 4) {

                        if (grille[LigneChoisi][ColonneChoisi] == 'X')
                            printf("Un bâteau a déjà été touché\n");
                        else {
                            printf("un bâteau a été touché\n"); //
                            grille[LigneChoisi][ColonneChoisi] = 'X';
                            Score--;
                        }



                        if (grille2[LigneChoisi][ColonneChoisi] == 3) {                   // Coulé du bâteau 3
                            Bateau3 = Bateau3 + 1;
                            if (Bateau3 == 2) {
                                printf("Le torpilleur a été éliminé.\n");
                            }

                        }
                        if (grille2[LigneChoisi][ColonneChoisi] == 4) {               // coulé du bâteau 4
                            Bateau4 = Bateau4 + 1;
                            if (Bateau4 == 5) {
                                printf("Le porte-avions a été éliminé. \n");
                            }

                        }
                        if (grille2[LigneChoisi][ColonneChoisi] == 2) {                   //Coulé du bâteau 2
                            Bateau2 = Bateau2 + 1;
                            if (Bateau2 == 4) {
                                printf(" Le croiseur a été éliminé.\n");
                            }

                        }

                        if (grille2[LigneChoisi][ColonneChoisi] == 1) {                //Coulé du bâteau 1
                            Bateau1 = Bateau1 + 1;
                            if (Bateau1 == 3) {
                                printf(" Le sous-marin a été éliminé.\n");
                            }
                        }


                        if (Bateau1 >= 3 && Bateau2 >= 4 && Bateau3 >= 2 && Bateau4 >= 5) { //Victoire
                            printf("Victoire, vous avez touché tous les bâteaux. La partie est terminée. \n\n");
                            printf("Voici le score : %d  \n", Score);
                            ConditionImpossible = ConditionImpossible + 1000;

                            fprintf(fpscore, "%s","\n");
                            fprintf(fpscore, "%d", Score);
                            fprintf(fpscore, "%s","\n");

                        }


                    }
                }
            }
            break;


        case 2: // Score des anciennes parties
            fscanf(fpscore, "%s",&nom);
            fscanf(fpscore, "%d",&Score);
            printf("%s   %d", nom,Score);


            break;

        case 3:
            printf(" le jeu consiste a faire couler tous les bateaux de l'ennemi en touchant leurs parties.\n");                // l'aide
            printf(" Tout d'abord , il faudra deviner où sont les bâteaux sur la grille. \n");
            printf(" Apres cela, écriver les coordonées afin d'essayer de toucher une partie des bâteaux.\n");
            printf(" Si toutes les parties d'un bâteau sont touchées. Le bâteau est coulé. Couler tous les bâteaux et la victoire sera votre.\n");
            printf(" Vivre ou mourir , à vous de choisir.\n");


            menu();
            return 0;


        case 4:
            return 0;

        default:
            break;
    }


    fclose(fpscore);
    return 0;
}