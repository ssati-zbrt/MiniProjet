 #include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*

int main(){
// Projet n°5 : Manipulation de chaine



// Phase 1: Compter les caractères

    char str[100]; //Déclare une chaîne de caractères de taille 100
    int i, nbr;
    printf("Entrer une chaine de caracteres:");
    //Lire une chaîne de caractères à partir du clavier en utilisant fgets
    fgets(str, sizeof str, stdin);
    i = 0; // Initialiser l'itérateur
    nbr = 0;
    // Boucle pour compter les mots dans la chaîne
    while (str[i] != '\0') { // Boucle jusqu'à la fin de la chaîne
        //Vérifier si le caractère courant est un espace, une nouvelle ligne ou un caractère de tabulation.
        if (str [i]== '\0'){
            return 0;
        }
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            //Incrémenter le nombre de mots lorsqu'un espace, une nouvelle ligne ou une tabulation est trouvé.
            nbr++;
        }
        i++; // Passer au caractère suivant de la chaîne
    }
    printf("Le nombre total de mots dans la chaîne est: %d", nbr - 1);
    return 0;




*/


/*

//Phase 2: Compter les voyelles


    char str[100];
    int voy,len;

    voy=0;

    printf("Entrez une chaine de caractere: \n");
    fgets(str, sizeof str, stdin);
    len = strlen(str);

    for (int i=0;i<len;i++){
        if (str[i]=='a' || str[i]=='e' || str[i]=='i' ||str[i]=='o' || str[i]=='u' ||str[i]=='y' ||str[i]=='A' ||str[i]=='E' ||str[i]=='I'||str[i]=='O' ||str[i]=='U' ||str[i]=='Y'){
            voy++;
        }
    }
    printf("Le nombre de voyelle est: %d",voy);
    return 0;
}

*/



//Phase 3 :Verification de palindrome

int main(){
    char str_M[100];
    char str_R[100];
    int len,n;
    printf("Entrez une chaine de caractere :\n");

    fgets(str_M, sizeof str_M, stdin);
    // Ignorer \n à la fin de la chaine de caractere
    str_M[strcspn(str_M, "\n")] = '\0';

    len=strlen(str_M);
    for (int i= 0;i<len;i++){
        // inverser la chaine (plutot le mot)
        str_R[i] = str_M[len - 1 - i];
    }
    str_R[len] = '\0';
    printf("La chaine inversee est :%s\n",str_R);
    printf("\n");
    n=strcmp(str_M,str_R);
    if (n==0){
        printf("La chaine est un palindrome\n");
    }
    else{
        printf("La chaine n'est pas un palindrome\n");
    }
    return 0;



}





























