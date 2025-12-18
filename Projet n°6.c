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








