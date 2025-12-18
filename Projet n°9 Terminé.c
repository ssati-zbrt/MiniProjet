#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Projet 9 - Simulateur de gestion de stock
/*
// Phase 1 : Ajouter un produit

typedef struct {
    char nom[50];
    float prix;
    int stock;
}SProduit;

void AfficheProduit(SProduit x){
    printf("\n Le nom est %s",x.nom);
    printf("\n Le prix est %f",x.prix);
    printf("\n Le stock est %d",x.stock);
}

int main(){
    SProduit p;
    strcpy(p.nom,"Orange");
    p.prix=3.10;
    p.stock=50;

    AfficheProduit(p);
}
*/
/*
// Phase 2 Liste de produit

//#define MAX_POIDS 10000
typedef struct SProduit{
    char nom[50];
    float prix;
    int stock;
}SProduit;

void AfficheProduit(SProduit x){
    printf("\n Le nom est %s",x.nom);
    printf("\n Le prix est %f",x.prix);
    printf("\n Le stock est %d",x.stock);
}
void AfficheTousLesProduit(SProduit *Liste,int taille){
    for (int i=0;i<taille;i++){
        AfficheProduit(Liste[i]);
    }
}
void AjouterProduit(SProduit *Liste,int t){
    SProduit p;
    scanf("%s",&p.nom);
    scanf("%f",&p.prix);
    scanf("%d",&p.stock);
    Liste[t]=p;
}
int main(){
    int n=2;
    SProduit Liste[n];
    int t=0;
    for (int i=0;i<n;i++){
        AjouterProduit(Liste,t);
        t++;
    }
    AfficheTousLesProduit(Liste,n);
}

*/

// Phase 3 Recherche et tri à bulles
/*
void echanger(float *a,float *b){
    float tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void tri_bulles(float t[],int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n-1;j++){
            if(t[j]>t[j+1]){
                echanger(&t[j],&t[j+1]);
            }
        }
    }
}
typedef struct SProduit{
    char nom[50];
    float prix;
    int stock;
}SProduit;

void AfficheProduit(SProduit x){
    printf("\n Le nom est %s",x.nom);
    printf("\n Le prix est %.2f",x.prix);
    printf("\n Le stock est %d",x.stock);
}
void AfficheTousLesProduit(SProduit *Liste,int taille){
    for (int i=0;i<taille;i++){
        AfficheProduit(Liste[i]);
    }
}
void AjouterProduit(SProduit *Liste,int t){
    printf("Entrez le nom,le prix et le nombre en stock du produit.\n");
    scanf("%49s",Liste[t].nom);
    scanf("%f",&Liste[t].prix);
    scanf("%d",&Liste[t].stock);
    }
SProduit* RechercheProduit(const char *nom,SProduit *Liste,int t){
    //SProduit p;
    //strcpy(p.nom," ");
    for(int i=0;i<t;i++){
        if(strcmp(nom,Liste[i].nom)==0){
            return &Liste[i];
        }
    }
    return NULL;
}
int main(){
    int n=2;
    SProduit Liste[n];
    for (int i=0;i<n;i++){
        AjouterProduit(Liste,i);
    }
    AfficheTousLesProduit(Liste,n);
    SProduit *p=RechercheProduit("Banane",Liste,n);
    if(p !=NULL){
        AfficheProduit(*p);
    }
    else{
        printf("\nProduit non trouvee\n");
    }
}
*/
// Phase 4 Gestion de mémoire + fichiers
#define nom_max 50
// On définit la structure
typedef struct SProduit{
    char nom[50];
    float prix;
    int stock;
}SProduit;
//Fonction afficher un element de la structure
void AfficheProduit(SProduit x){
    printf("\n Le nom est %s",x.nom);
    printf("\n Le prix est %.2f",x.prix);
    printf("\n Le stock est %d",x.stock);
}
// Appel à la fonction précedentes pour tous les afficher
void AfficheTousLesProduit(SProduit *Liste,int taille){
    for (int i=0;i<taille;i++){
        AfficheProduit(Liste[i]);
    }
}
void AjouterProduit(SProduit *Liste,int t){
    printf("Entrez le nom,le prix et le nombre en stock du produit.\n");
    scanf("%49s",Liste[t].nom);
    scanf("%f",&Liste[t].prix);
    scanf("%d",&Liste[t].stock);
}
// Sauvegarde
void SauvegardeProduit(SProduit Liste[],int taille,const char *nomFichier){
    FILE*f=fopen(nomFichier,"w");
    if (f==NULL){
        printf("Erreur d'ouverture du fichier\n");
        return;
    }
    else{
        for(int i=0;i<taille;i++){
            fprintf(f,"%s;%f;%d \n",Liste[i].nom,Liste[i].prix,Liste[i].stock);
        }
    }
    fclose(f);
}
// Chargement
void ChargerProduit(SProduit **Liste,int *taille,const char *nomFichier){
    FILE*f;
    f=fopen(nomFichier,"r");
    if(f==NULL){
        return;
    }
    char ligne[100];
    while(fgets(ligne,sizeof(ligne),f)){
        SProduit p={"",0.0f,0};
        char*token=strtok(ligne,";");
        if(token){
            strncpy(p.nom,token,nom_max-1);
            p.nom[nom_max-1]='\0';
        }
        token=strtok(NULL,";");
        if (token)p.prix=atof(token);
        token=strtok(NULL,";");
        if (token)p.stock=atoi(token);

        SProduit *tmp=realloc(*Liste,(*taille+1)*sizeof(SProduit));
        if (tmp==NULL){
            printf("Erreur de realloc \n");
            fclose(f);
            return;
        }
        *Liste =tmp;

        (*Liste)[*taille]=p;
        (*taille)++;
    }
    fclose(f);
}

int main(){
    SProduit *Liste=NULL;
    int n=0;
    ChargerProduit(&Liste,&n,"liste_courses.txt");
    int j;
    printf("nombre d'articles a ajouter?\n");
    scanf("%d",&j);
    for (int i=0;i<j;i++){
        SProduit*tmp=realloc(Liste,(n+1)*sizeof(SProduit));
        if(tmp==NULL){
            printf("Erreur realloc\n");
            free(Liste);
            return 1;
        }
        Liste=tmp;
        AjouterProduit(Liste,n);
        n++;
    }
    SauvegardeProduit(Liste,n,"liste_courses.txt");

    printf("\n Liste complete \n");
    AfficheTousLesProduit(Liste,n);
    fclose(f);
    free(Liste);
    return 0;

}




