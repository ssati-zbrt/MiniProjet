#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Projet n°7 Dictionnaire de mots
/*
// Phase 1 Ajouter un mot
int main (){
    char Tab[20][20];
    for (int i=0;i<20;i++){
        printf("Entrez une chaine de caractère:\n");
        scanf("%s",&Tab[i]);
    }
    for (int i=0;i<20;i++){
        printf("Les mots saisis sont: %s \n ",Tab[i]);
    }

    return 0;
}


// Phase 2 Recherche un mot
// si mot present on retourne true sinon false ; recherche linéaire
int RecherchePositionMot(char texte[],char mot[]){
    for (int i=0;texte[i]!='\0';i++){
        int j=0;
        while(mot[j]!='\0' && texte[i+j]==mot[j]){
            j++;
        }
        if(mot[j]=='\0'){
            return i;
        }
    }
    return -1;

}

int main(){
    char texte[]="Bonjour tous le monde c'est ici que ça commence";
    char mot[]="ici";
    int pos=RecherchePositionMot(texte,mot);
    printf("L'indice du mot recherchee est a la position:%d\n",pos);

}

// Phase 3 Sauvegarde et chargement

int main(){
    int i;
    int nbMots=3;
    char mot[50][100];
    FILE*f;
    f=fopen("dictionnaire.txt","a");
    if (f==NULL){
        printf("Erreur d'ouverture du fichier");
        return 1;
    }
    printf("Entrez les %d mots:\n",nbMots);

    for (i=0;i<nbMots;i++){
        scanf("%49s",mot[i]);
        fprintf(f,"%s \n",mot[i]);
    }
    fclose(f);

    f=fopen("dictionnaire.txt","r");
    if(f==NULL){
        printf("Erreur d'ouverture du fichier");
        return 1;
    }
    i=0;
    while (fscanf(f,"%s",mot[i]) != EOF && i<50){
        i++;
    }
    fclose(f);

    printf("Mot lu depuis le fichier :\n");
    for (int j=0;j<i;j++){
        printf("%s \n",mot[j]);
    }
    return 0;

}
*/
// Phase 4 Allocation dynamique
int main(){
    int max_mots=50;
    int taille_mots=50;
    int i;
    int nbMots=0;
    int choix;
    char MotASupprimer[50];
    int trouvee;
    char **mots;
    mots=malloc(max_mots*sizeof(char*));
    if (mots== NULL){
        printf("Erreur allocation de la memoire.\n");
        return 1;
    }
    for(int i=0;i<max_mots;i++){
        mots[i]=malloc(taille_mots*sizeof(char));
        if(mots[i]==NULL){
            printf("Erreur allocation memoire\n");
            return 1;
        }
    }

    FILE*f;
    f=fopen("dictionnaire1.txt","a");
    if (f==NULL){
        printf("Erreur d'ouverture du fichier");
        return 1;
    }
    printf("Entrez les %d mots:\n",nbMots);

    for (i=0;i<nbMots;i++){
        scanf("%49s",mots[i]);
        fprintf(f,"%s \n",mots[i]);
    }
    fclose(f);

    f=fopen("dictionnaire1.txt","r");
    if(f==NULL){
        printf("Erreur d'ouverture du fichier");
        return 1;
    }
    i=0;
    while (fscanf(f,"%s",mots[i]) != EOF && i<max_mots){
        i++;
    }
    fclose(f);

    printf("Mot lu depuis le fichier :\n");
    for (int j=0;j<i;j++){
        printf("%s \n",mots[j]);
    }
    f=fopen("dictionnaire1.txt","r");
    if (f==NULL){
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }
    fclose(f);

    printf("Voulez vous supprimer un mot ?\n");
    printf("0 : non\n");
    printf("1 : oui\n");
    scanf("%d",&choix);

    if (choix==0){
        return -1;
    }

    else{
        printf("Mot a supprimer :\n");
        scanf("%49s",MotASupprimer);

        int trouvee=0;
        for (int i=0;i<nbMots;i++){
            if (strcmp(mots[i],MotASupprimer)==0){
                trouvee=1;
            }
            if (trouvee && i<nbMots-1){
                strcpy(mots[i],mots[i+1]);
            }
        }
        if (trouvee){
            nbMots--;
            printf("Mot supprimee\n");
        }
        else{
            printf("Mot non trouvee\n");
        }
    }
    f=fopen("dictionnaire1.txt","a");
    if(f==NULL){
        printf("Erreur d'ouvertre du fichier\n");
        return 1;
    }
    for (int i=0;i<nbMots;i++){
        fprintf(f,"%s \n",mots[i]);
    }
    printf("Liste mis a jour \n");
    for(int i=0;i<nbMots;i++){
        printf("%s\n",mots[i]);
    }
    fclose(f);

    for (int i=0;i<max_mots;i++){
        free(mots[i]);
    }
    free(mots);
    return 0;
}













