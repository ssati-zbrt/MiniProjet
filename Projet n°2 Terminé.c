#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Projet 2 - Devine le nombre



int main(){

// phase 1 - Jeu fixe
/*
    int nombre_fixe;
    nombre_fixe =7;
    int a;

    while (a != nombre_fixe){
        printf("Saississez un nombre:\n");
        scanf("%d",&a);
        if(a < nombre_fixe ){
            printf("Trop petit\n");
        }
        if(a > nombre_fixe){
            printf("Trop grand\n");
            }
        if( a == nombre_fixe){
            printf("Bravo\n");
        }
    }
    return 0;
}
*/

// Phase 2- Jeu aléatoire
/*
    srand(time(NULL));
    int NombreMystere = rand()% 100+1;
    int essai;
    int Compteur=0;
    while (essai != NombreMystere){
        printf("Devine un nombre entre 1 et 100:\n");
        scanf("%d",&essai);
        if(essai < NombreMystere ){
            printf("Trop petit\n");
        }
        if(essai > NombreMystere){
            printf("Trop grand\n");
            }
        if( essai == NombreMystere){
            printf("Bravo\n");
        }
        Compteur = Compteur+1;

    }
    printf("Trouver apres %d essais \n,", Compteur);
    return 0;
*/


// Phase 3 - Boucle de rejouablité

/*
    srand(time(NULL));
    int choix_a;
    int choix_b;
    int NombreMystere;
    int essai;
    int Compteur=0;

    while (choix_b != 5){



        printf("Menu\n");
        printf("Niveau 1: facile(1-50)\n");
        printf("Niveau 2: moyen(1-100)\n");
        printf("Niveau 3: difficile(1-150\n");
        printf("Coississez le niveau:\n");
        scanf("%d",&choix_a);


        switch(choix_a){
            case 1 :
                NombreMystere = rand() %50+1;
                printf("Coississer un nombre entre 1 et 50\n");
                break;
            case 2 :
                NombreMystere = rand() %100+1;
                printf("Coississer un nombre entre 1 et 100\n");
                break;

            case 3 :
                NombreMystere = rand() %150+1;
                printf("Coississer un nombre entre 1 et 150\n");
                break;
        }

        do{
            scanf("%d",&essai);
            if(essai < NombreMystere ){
                printf("Trop petit\n");
            }
            if (essai > NombreMystere){
                printf("Trop grand\n");
            }
            if (essai == NombreMystere){
                printf("Bravo\n");
            }
        }
        while ( essai != NombreMystere);


    printf("Option...\n");
    printf("4.Rejouer\n");
    printf("5.Quitter\n");
    printf("Choisisser une option:\n");
    scanf("%d",&choix_b);

    }

*/

}



