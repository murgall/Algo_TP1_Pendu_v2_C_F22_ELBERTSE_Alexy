#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 100

/*ALGORITHME : PENDU

BUT: Ce programme simule le jeu du pendu
ENTREE : Le caractère demandé à l'utilisateur
SORTIE : Le mot caché
CONST
    TAILLE <- 100


VAR
    LettreEntree -> CARACTERE
    MotaTrouver ->CHAINE
    MotAfficher -> CHAINE
    NbCoupRestant,i,j,LongueurMot,NbLettreRestante -> ENTIER

DEBUT
    MotaTrouver -> "COCASSE"
    NbCoupRestant <-10
    LongueurMot <- LONGUEUR(MotaTrouver)
    NbLettreRestante <- LongueurMot

    POUR i ALLANT de 1 à LongueurMot
    DEBUT
        MotAfficher[i]<- "_"
    FINPOUR

    ECRIRE("Bienvenue dans le jeu du pendu!")
    i<-1
    TANTQUE ((NbCoupRestant>0) OU (NbLettreRestant>0))
    DEBUT
        ECRIRE("Le mot caché est :",MotAfficher)
        ECRIRE("Il vous reste",NbCoupRestant," coup à jouer")
        LIRE(LettreEntree)
        POUR J ALLANT de 1 à LongueurMot
        DEBUT
            SI (lettreEntree == MotaTrouver[j]) ALORS
            DEBUT
                MotAfficher[j]<- lettreEntree;
                NbLettreRestante <- NbLettreRestante - 1;
            FINSI
        FINPOUR

        SI (NbLettreRestante = 0 ) ALORS
        DEBUT
            ECRIRE("Felicitation, Vous avez gagne")
         SINON
        NbCoupRestant <- NbCoupRestant -1
        FINSI

    FINTANTQUE

FIN





*/

char saisie_caractere(char *lettre);
char taille_mot(char mot1);
void text_debut(char mot2[TAILLE], int nb1);


int main()
{
    char lettreEntree = ' ';  //garde la lettre entrée par l'utilisateur
    char motaTrouver[TAILLE] = "COCASSE"; //Mot à trouver
    int NbCoupRestant = 10; //tout est dit
    int i = 0; int j = 0; //index de boucles
    int LongueurMot = strlen(motaTrouver);  //longueur du mot
    char MotAfficher[TAILLE] = ""; //Mot actuellement affiché par le programme
    int NbLettreRestante = LongueurMot; //lorsqu'il est à 0, la partie est gagné



        for (i = 0; i <LongueurMot; i++)    //Affiche l'avancé actuelle du mot à découvrir
        {
            MotAfficher[i] = taille_mot(i); //fonction qui masque le mot à deviner
        }
    printf("Bienvenue dans le jeu du pendu!\n");

    i= 0;                                   //Réinitialise L'index
    while ((NbCoupRestant>0) && (NbLettreRestante>0))
        {
        text_debut(MotAfficher, NbCoupRestant); //procedure permettant d'afficher l'avancé actuelle du jeu
        lettreEntree = saisie_caractere(&lettreEntree); //fonction permettant d'entrer une lettre

        for (j = 0;j <LongueurMot; j++){
            if (lettreEntree == motaTrouver[j]){    //vérifie que la lettre entrée correspond à une(ou plusieurs) lettres du mot caché
                MotAfficher[j]= lettreEntree;       //affiche la bonne lettre
                motaTrouver[j] = ' ';               //Remplace la lettre trouvé dans le mot d'origine afin d'éviter la tricherie
                NbLettreRestante = NbLettreRestante - 1;
            }
        }
        if (NbLettreRestante == 0 ){
            printf("Felicitation, Vous avez gagne\n");
        } else{
        NbCoupRestant = NbCoupRestant -1;   //décrémente de 1 le nombre de coup
        }
    i++;
    }
    return 0;
}



char taille_mot(char mot1)
{
    mot1='_';
    return mot1;
}




void text_debut(char mot2[TAILLE], int nb1)
{
        printf("Le mot cache est : %s \n", mot2);
        printf("il vous reste %d a jouer\n", nb1);    //montre le nbde coup restant

}

char saisie_caractere(char *lettre)
{

            printf("Veuillez entrer un caractere(En MAJUSCULE)\n");
            fflush(stdin);      //vide le tampon mémoire de la derniere lettre entrée
            scanf("%c",lettre);  //entre un caractere
            return *lettre;
}
