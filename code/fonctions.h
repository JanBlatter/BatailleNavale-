//
// Created by Jan.BLATTER on 04.04.2019.
//

#ifndef CODE_FONCTIONS_H
#define CODE_FONCTIONS_H
#include <stdlib.h>
#include <stdio.h>











void AfficherAide(){
    system("cls");
    printf(" le jeu consiste a faire couler tous les bateaux de l'ennemi en touchant leurs parties.\n");                // l'aide
    printf(" Tout d'abord , il faudra deviner où sont les bâteaux sur la grille. \n");
    printf(" Apres cela, écriver les coordonées afin d'essayer de toucher une partie des bâteaux.\n");
    printf(" Si toutes les parties d'un bâteau sont touchées. Le bâteau est coulé. Couler tous les bâteaux et la victoire sera votre.\n");
    printf(" Vivre ou mourir , à vous de choisir.\n");
    system("pause");
}
#endif //CODE_FONCTIONS_H
