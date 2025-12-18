#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Projet n°6 Gestion d'étudiants

/*

// Phase 1 Saisie d'un étudiant

struct SEtudiant
    {
    char nom[100];
    int age;
    float note;
    } ;

int main(){

    struct SEtudiant e1;
    printf(" Quel est le nom de l'etudiant ?\n");
    scanf("%99s",e1.nom);
    printf("Quel age a t il ?\n");
    scanf("%d",&e1.age);
    printf("Quel note a t il obtenu ?\n");
    scanf("%f",&e1.note);

    printf("Information de l'etudiant:\n");
    printf("Nom : %s\n", e1.nom);
    printf("Age : %d\n", e1.age);
    printf("Note : %.3f\n", e1.note);

    return 0;

}

*/

/*
// Phase 2 Tableau d'étudiant

struct SEtudiant{
    char nom[30];
    char prenom[30];
};




int main(){


    int n;
    printf("Combien d'etudiants voulez vous rentrez ?\n ");
    scanf("%d",&n);

    int n_max = 20;
    if(n>n_max){
        printf("nombre trop eleves\n");
        return 0;
    }

    struct SEtudiant list[n];

    for (int i =0; i<n ;i++){
        printf("Entrez le nom :\n");
        scanf("%29s",list[i].nom);
        printf("Entrez le prenom :\n");
        scanf("%29s",list[i].prenom);
    }

    printf("\n\n");

    for (int i =0; i<n;i++){
        printf("Nom Prenom  : %s %s \n", list[i].nom ,list[i].prenom);
    }
    return 0;

}
*/

/*
//Phase 3 Sauvegarde dans un fichier

struct SEtudiant{
    char nom[30];
    char prenom[30];
};

int main(){
    FILE* fp;
    fp=fopen("etudiants.txt","w");
    if (fp == NULL)
        return -1;

    printf("--creation du fichier --\n");
    int n;
    int n_max = 20;
    printf("Nombres d'etudiant a saisir :\n");
    scanf("%d",&n);

    if(n>n_max){
        printf("nombre trop eleves\n");
        return 0;
    }

    struct SEtudiant list[n];
    for (int i =0;i<n;i++){
        printf("Entrez le nom :\n");
        scanf("%29s",list[i].nom);

        printf("Entrez le prenom :\n");
        scanf("%29s",list[i].prenom);

        fprintf(fp,"%s %s \n",list[i].nom,list[i].prenom);
    }

    fclose(fp);

    fp=fopen("etudiants.txt","r");

    if (fp == NULL){
        printf("Erreur d'ouverture.\n");
        return 1;
    }
    char nom[30];
    char prenom[30];
    while (fscanf(fp, "%29s %29s", nom, prenom) == 2) {
        printf("Nom Prenom :%s %s\n", nom, prenom);
    }

    fclose(fp);

    return 0;
}
*/


//Phase 4: Mémoire dynamique
// créer un tableau dynamique pour ajouter les noms d'étudiant sans taille fixe
#define ETU_MAX 50
typedef struct SEtudiant{
    char Nom[ETU_MAX];
    char Prenom[ETU_MAX];
}Etudiant;

int main(){

    int N=0;
    int choix=0;
    Etudiant *etudiants=NULL;

    while(choix!=5){
        printf("Menu\n");
        printf("1: Ajouter un etudiant dans la liste.\n");
        printf("2: Afficher la liste des etudiants.\n");
        printf("3: Sauvegarder les etudiants dans un fichier.\n");
        printf("4: Afficher(Charger) le contenu du ficher.\n");
        printf("5: Quittez.\n");
        scanf("%d",&choix);

        if (choix== 1){
            N++;
            etudiants =realloc(etudiants, N*sizeof(Etudiant));
            if(etudiants==NULL){
                printf("Erreur allocation memoire\n");
                return 1;
            }
            printf("Entrez le nom:\n");
            scanf("%49s",etudiants[N-1].Nom);

            printf("Entrez le prenom:\n");
            scanf("%49s",etudiants[N-1].Prenom);
        }
        if (choix ==2){
            printf("La liste des etudiants:\n");
            for (int i=0;i<N;i++){
                printf("%d-Nom: %s Prenom: %s \n",i+1,etudiants[i].Nom,etudiants[i].Prenom);
            }
        }
        if (choix ==3){
            FILE*fp=fopen("liste_etudiants.txt","a");
            if(fp==NULL){
                printf("Erreur d'ouverture du fichier\n");
                return 1;
            }
            printf("Sauvegarde des etudiants dans un fichier.\n");
            for(int i=0;i<N;i++){
                fprintf(fp,"Nom:%s~Prenom: %s\n",etudiants[i].Nom ,etudiants[i].Prenom);
            }
            fclose(fp);
            printf("Ecriture dans le fichier:liste_etudiant.txt terminee\n");
        }
// Charger les infos depuis le fichiers et les afficher
        if (choix == 4){
            FILE*fp=fopen("liste_etudiants.txt","r");
            if(fp==NULL){
                printf("Erreur d'ouverture du fichier\n");
                return 1;
            }
            char ligne[100];
            while(fgets(ligne,sizeof(ligne),fp)){
                Etudiant e;
                char*token=strtok(ligne,"~");
                if(token)strcpy(e.Nom,token);

                token=strtok(NULL,"\n");
                if(token)strcpy(e.Prenom,token);
                }
                fclose(fp);
            }
        }
        free(etudiants);
        return 0;

}








