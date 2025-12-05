#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

//Phase 1
    char taille=20;
    char max_article=20;
    char courses[max_article][taille];

    printf("Entrez le nom \n");
    fgets(courses[0],taille,stdin);
    printf("l'article a ete ajoute avec succes.\n");
    printf("%s",courses[0]);

*/

// Phase 2
/*
    int i,j;
    for (i=0;i<=9;i++){
        int taille=20;
        int max_article=20;
        char courses[max_article][taille];
        printf("Entrez le nom de l'article!\n");
        fgets(courses[i],taille,stdin);
        printf("l'article a ete ajoute avec succes.\n\n");
        for(j=0;j<=i;j++){
            printf("%d -%s",j,courses[j]);
        }
    }
*/


// Phase 3 Supprimer un article

int main(){
// nombre_max_article  et taille_article
// Déclaration des variables
    int taille=20;
    int max_article=20;
    char courses[20][20];
    //courses[max_article][taille];
    int choix;
    int element_supp;
    int nb_articles=0;

    do{
        printf("===Menu===\n");
        printf("1 : Ajouter un article \n");
        printf("2 : Afficher les articles \n");
        printf("3 : Supprimer un article \n");
        printf("4 : Quittez! \n");
        printf("Votre choix ?\n");
        scanf("%d",&choix);
        getchar();

        switch(choix){
            case 1:
                if (nb_articles >= 20) {
                    printf("La liste est pleine !\n");
                    break;
                }
                printf("Entrez le nom de l'article:\n\n");
                fgets(courses[nb_articles],taille,stdin);
                courses[nb_articles][strcspn(courses[nb_articles],"\n")]='\0';
                nb_articles++;
                printf("l'article a ete ajoute avec succes.\n");

                break;
            case 2:
                    printf("Liste de course:\n");
                    for(int i=0;i<nb_articles;i++){
                        printf("%d -%s\n",i+1,courses[i]);
                    }
                break;
            case 3:
                if (nb_articles == 0) {
                    printf("La liste est vide !\n");
                    break;
                }
                printf("Liste de course:\n");
                for(int i=0;i<nb_articles;i++){
                    printf("%d -%s\n",i+1,courses[i]);
                }
                printf("Entrez le numéro de l'element a supprimer:\n");
                scanf("%d",&element_supp);
                getchar();

                if (element_supp < 1 || element_supp > nb_articles){
                    printf("Numéro invalide !\n");
                    break;
                }
                // mettre une for pour réorganiser
                else{
                    for(int i=element_supp-1;i<nb_articles-1;i++){
                        strcpy(courses[i], courses[i+1]);
                    }
                    nb_articles--;
                }
            break;
        }

    } while(choix !=4);


}
