//
// Created by Jan.BLATTER on 04.04.2019.
//

#ifndef CODE_FONCTIONS_H
#define CODE_FONCTIONS_H
#include <stdlib.h>
#include <stdio.h>

int choix;//variable pour le choix du menu
int choix2;   //Variable pour le choix des grilles
int choix3;
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
int caractereActuel = 0;



// Les Grilles

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
int grilleVierge[8][8] = {  // Grille 1 (pour la grille aléatoire

        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,

};

int grilleAleatoire[8][8] = {  // Grille 2 (pour la grille aléatoire)

        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0,
        4, 0, 0, 0, 0, 0, 0, 0,
        4, 0, 0, 0, 0, 0, 0, 0,
        4, 0, 0, 0, 0, 0, 0, 1,
        4, 0, 0, 0, 0, 0, 0, 1,
        4, 0, 0, 0, 0, 0, 0, 1,
        3, 3, 2, 2, 2, 2, 0, 0,

};

int grilleAleatoire2[8][8] = {  // Grille 3 (pour la grille aléatoire)

        0, 2, 2, 2, 2, 3, 3, 4,
        0, 0, 0, 0, 0, 0, 0, 4,
        0, 0, 0, 0, 0, 0, 0, 4,
        0, 0, 0, 0, 0, 0, 0, 4,
        0, 0, 0, 0, 0, 0, 0, 4,
        0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 1,

};

int grilleAleatoire3[8][8] = {  // Grille 3 (pour la grille aléatoire)

        0, 0, 0, 4, 4, 4, 4, 4,
        0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 1, 1, 2, 0,
        0, 0, 0, 0, 0, 0, 2, 0,
        0, 0, 0, 0, 0, 0, 2, 0,
        0, 0, 0, 0, 0, 0, 2, 0,
        3, 0, 0, 0, 0, 0, 0, 0,
        3, 0, 0, 0, 0, 0, 0, 0,

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










void Jeu(){
    printf("Quel est votre nom ?\n");  // Demande le nom
    scanf("%s", nom);


    if (fpscore == NULL) {                   // met les données sur le fichiet TXT le nom

        fpscore = fopen("Score.txt", "a+");
        fprintf(fpscore, "%s \n", nom);
    }
    printf("Veuillez-choisir votre grille\n");
    printf(" Taper 1 pour choisir la grille de base\n");
    printf(" Taper 2 pour choisir une grille aléatoire parmis 3 grilles \n");

    scanf("%d", &choix2);

    switch (choix2) {
        case 1:
            for (ligne = 0; ligne < 8; ligne++) {
                for (colonne = 0; colonne < 8; colonne++) {
                    grilleVierge[ligne][colonne] = grille2[ligne][colonne];
                }
            }
            break;
        case 2 :
            srand((unsigned)time( NULL ));
            choix3 = rand() % 3;
            switch (choix3) {
                case 1:
                    for (ligne = 0; ligne < 8; ligne++) {
                        for (colonne = 0; colonne < 8; colonne++) {
                            grilleVierge[ligne][colonne] = grilleAleatoire[ligne][colonne];
                        }
                    };
                    break;

                case 2:
                    for (ligne = 0; ligne < 8; ligne++) {
                        for (colonne = 0; colonne < 8; colonne++) {
                            grilleVierge[ligne][colonne] = grilleAleatoire2[ligne][colonne];
                        }
                    };
                    break;
                case 3:
                    for (ligne = 0; ligne < 8; ligne++) {
                        for (colonne = 0; colonne < 8; colonne++) {
                            grilleVierge[ligne][colonne] = grilleAleatoire3[ligne][colonne];
                        }
                    };
                    break;

            }
            break;


    }

    system("cls");

    printf("voici la grille\n\n");
    printf("Veuillez écrire les coordonées pour tenter de toucher un bâteau\n\n");
    printf(" O = Eau //////  X = Touché ////// R = Raté\n\n");


    ;                                         // Affichage des coordonées honrizontals


    for (ConditionImpossible = 0;
         ConditionImpossible < 1000; ConditionImpossible++)   // Boucle pour afficher la grille
    {

        printf("   ");
        for (Condition = 0; Condition < 8; Condition++) {
            printf("%2d", Condition);
        }
        printf("\n");

        //Affiche la grille
        for (ligne = 0; ligne < 8; ligne++) {
            printf("%d |", ligne);                                        //Affichage des coordonées verticals
            for (colonne = 0; colonne < 8; colonne++) {
                printf("%2c", grille[ligne][colonne]);
            }
            printf("\n");
        }


        // Toucher
        printf("\n\nveuillez-choisir une coordonnée de 0 à 7 (Honrizontal)\n");
        scanf("%d", &LigneChoisi);
        printf("veuillez-choisir une coordonnée de 0 à 7 (Vertical)\n");
        scanf("%d", &ColonneChoisi);

        if (grille2[LigneChoisi][ColonneChoisi] != 1 && grille2[LigneChoisi][ColonneChoisi] != 2 &&
            grille2[LigneChoisi][ColonneChoisi] != 3 && grille2[LigneChoisi][ColonneChoisi] != 4) {
            printf("Vous avez raté\n");
            grille[LigneChoisi][ColonneChoisi] = 'R';
            Score++;
        } else {
            if (grille2[LigneChoisi][ColonneChoisi] == 1 || grille2[LigneChoisi][ColonneChoisi] == 2 ||
                // condition qui marque un X si c'est touché  //Le x remplace le 0 si il y a un bateau
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
                    fprintf(fpscore, "\n%d", Score);

                }


            }
        }
    }
    fclose(fpscore);
}



void AfficherScore(){

    if (fpscore != NULL) {
        //boucle de lecture des caractères un à un
        do {
            caractereActuel = fgetc(fpscore); // on lit le caractère
            printf("%c", caractereActuel); // on l'affiche

        } while (caractereActuel != EOF); // on continue tant que fgetc n'a pas retourné EOF (fin de fichier)


        fclose(fpscore);
    }
}


void AfficherAide(){
    system("cls");
    printf(" le jeu consiste a faire couler tous les bateaux de l'ennemi en touchant leurs parties.\n");                // l'aide
    printf(" Tout d'abord , il faudra deviner où sont les bâteaux sur la grille. \n");
    printf(" Apres cela, écriver les coordonées afin d'essayer de toucher une partie des bâteaux.\n");
    printf(" Si toutes les parties d'un bâteau sont touchées. Le bâteau est coulé. Couler tous les bâteaux et la victoire sera votre.\n");
    printf(" Vivre ou mourir , à vous de choisir.\n\n");
    system("pause");
}





#endif //CODE_FONCTIONS_H
