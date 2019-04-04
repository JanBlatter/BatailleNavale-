#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>
#include "fonctions.h"

#pragma execution_character_set("utf-8") // pour accents
/* Auteur : Jan blatter
 * Date : 08.03.2019
 * Nom du fichier : Bataille navale
 * Version : 1.0
 */



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
        case 1: Jeu();
            break;

        case 2: // Score des anciennes parties
            AfficherScore();
            break;

        case 3:
            AfficherAide();
            main();
            break;


        case 4:
            return 0;

        default:
            break;
    }

    return 0;
}