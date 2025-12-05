#include <stdlib.h>
#include <stdio.h>

// Projet 4 Statistiques sur des notes
/*
int main(){

// Phase 1 Moyenne de trois notes
    int a,b,c,moyenne;
    printf("Donnez les trois notes a,b,c \n");
    scanf("%d %d %d",&a,&b,&c);
    printf("La moyenne des trois nombres est: %d",moyenne=(a+b+c)/3);

*/


/*

// Phase 2
    int moyenne;
    int somme;
    int n;
    int t[n];
    int min, max;
    printf("Combien de notes voulez vous rentres ? \n");
    scanf("%d",&n);
    int n_max = 20;
    if (n>n_max){
        printf("Trop de nombres : Echec \n");
    }
    else{
        for (int i=0;i<n;i++){
            printf("Entrez les nombres %d:",i+1);
            scanf("%d",&t[i]);
            somme+= t[i];
        }
        moyenne = somme/n;
        printf("La moyenne des elements est: %d \n",moyenne);
        for (int i=0;i<n;i++){
            max=t[0];
            if (t[i]>max){
                max = t[i];
            }
        }
        printf("La valeur du maximun est: %d \n",max);
        for (int j=0;j<n;j++){
            min=t[0];
            if (t[j]<min){
                min = t[j];
            }
        }
        printf ("La valeur du minimum est:%d \n",min);

    }


}
*/
// Phase 3: Tri des notes

void echange(int*a,int*b){
    int tmp;
    tmp =*a;
    *a=*b;
    *b=tmp;
}


void tri_bulles(int t[],int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n-i-1;j++){
            if(t[j]>t[j+1]){
                echange(&t[j],&t[j+1]);
            }
        }
    }
}

void affiche(int t[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",t[i]);
    }
}

int main(){
    int n;
    printf("Combien de notes voulez vous rentres ? \n");
    scanf("%d",&n);
    int t[n];
    int n_max =20;
    if (n>n_max){
        printf("Trop de nombres : Echec \n");
        return 1;
    }
    for (int i=0;i<n;i++){
            printf("Entrez les nombres %d:",i+1);
            scanf("%d",&t[i]);
    }
    tri_bulles(t,n);

    printf("Tableau trie : \n");
    affiche(t,n);

    return 0;
}










