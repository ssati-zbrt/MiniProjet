#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Projet n°8 -Mini tableaur
int main(){
/*
// Phase 1 : Remplir un tableau 2D

    int Tab[4][4]={{0,1,2,3,4},{5,6,7,8,9},{10,11,12,13,14},{15,16,17,18,19},{20,21,22,23,24}};
    int i,j;
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            printf("Element : Tab[%d][%d]= %d\n ",i,j,Tab[i][j]);
        }
    }

//Phase 2 - Calculs
// on veut proposer un menu qui 1 somme des elements d'une ligne 2 moyenne d'une colonne 3 somme des elements des tableau et 4 pour quitter
// On definit un tableau de taille 5*5 manuellement
    int Tab[5][5]={{0,1,2,3,4},
                    {5,6,7,8,9},
                    {1,1,2,3,4},
                    {1,4,7,8,9},
                    {2,1,2,3,2}};
    int a;
    int choix;
    int somme_c=0;
    int somme_l=0;
    int somme;
    float moy;
// On affiche les elements du tableau
        for (int i=0;i<5;i++){
            for (int j=0;j<5;j++){
                printf("%d ",Tab[i][j]);
                if (j==4){
                    printf("\n");
                }
            }
        }
// On affiche le menu + choix de l'operation
        printf("--Menu--\n");
        printf("1 : Somme d'une ligne \n");
        printf("2 : Moyenne d'une colonne \n");
        printf("3 : Somme du tableau entier \n");
        printf("4 : Quitter\n");

        printf("Que voulez vous faire ?\n");
        scanf("%d",&a);

        switch (a){
            case 1 :
                int choix_ligne;
                printf("On a un tableau de taille 4*4.\n");
                printf("Quel ligne voulez vous effectuer l'operation somme d'une ligne ?\n");
                scanf("%d",&choix_ligne);
                for (int i=0 ;i<5;i++){
                    for (int j=0;j<5;j++){
                        if(i == choix_ligne){
                        somme_l+= Tab[i][j];
                        }
                    }
                }
                printf("La somme de la ligne %d est %d \n",choix_ligne,somme_l);
            break;

            case 2:
                int choix_colonne;
                printf("Sur quelle colonne voulez vous effectuer l'operation :moyenne de la colonne\n");
                scanf("%d",&choix_colonne);
                for (int i=0; i<5; i++){
                    for (int j =0;j<5;j++){
                        if (j==choix_colonne){
                            somme_c+= Tab[i][j];
                        }
                    }
                }
                printf("La somme de la colonne est %d \n",somme_c);
                moy = somme_c/5;
                printf("La moyenne de la colonne est %f \n",moy);
                break;
            case 3:
                printf("On a un tableau de taille 4*4.");
                printf("Vous demander la somme des elements du tableau.\n");
                for (int i=0;i<5;i++){
                    for (int j=0;j<5;j++){
                        somme+= Tab[i][j];
                    }
                }
                printf("La somme totale du tableau est : %d \n",somme);

                break;


        }

*/


    }



