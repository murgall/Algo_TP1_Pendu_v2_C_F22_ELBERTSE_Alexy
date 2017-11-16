#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 100

/*ALGORITHME : PENDU

BUT: Ce programme simule le jeu du pendu
ENTREE : Le caract�re demand� � l'utilisateur
SORTIE : Le mot cach�
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

    POUR i ALLANT de 1 � LongueurMot
    DEBUT
        MotAfficher[i]<- "_"
    FINPOUR

    ECRIRE("Bienvenue dans le jeu du pendu!")
    i<-1
    TANTQUE ((NbCoupRestant>0) OU (NbLettreRestant>0))
    DEBUT
        ECRIRE("Le mot cach� est :",MotAfficher)
        ECRIRE("Il vous reste",NbCoupRestant," coup � jouer")
        LIRE(LettreEntree)
        POUR J ALLANT de 1 � LongueurMot
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
    char lettreEntree = ' ';  //garde la lettre entr�e par l'utilisateur
    char motaTrouver[TAILLE] = "COCASSE"; //Mot � trouver
    int NbCoupRestant = 10; //tout est dit
    int i = 0; int j = 0; //index de boucles
    int LongueurMot = strlen(motaTrouver);  //longueur du mot
    char MotAfficher[TAILLE] = ""; //Mot actuellement affich� par le programme
    int NbLettreRestante = LongueurMot; //lorsqu'il est � 0, la partie est gagn�



        for (i = 0; i <LongueurMot; i++)    //Affiche l'avanc� actuelle du mot � d�couvrir
        {
            MotAfficher[i] = taille_mot(i); //fonction qui masque le mot � deviner
        }
    printf("Bienvenue dans le jeu du pendu!\n");

    i= 0;                                   //R�initialise L'index
    while ((NbCoupRestant>0) && (NbLettreRestante>0))
        {
        text_debut(MotAfficher, NbCoupRestant); //procedure permettant d'afficher l'avanc� actuelle du jeu
        lettreEntree = saisie_caractere(&lettreEntree); //fonction permettant d'entrer une lettre

        for (j = 0;j <LongueurMot; j++){
            if (lettreEntree == motaTrouver[j]){    //v�rifie que la lettre entr�e correspond � une(ou plusieurs) lettres du mot cach�
                MotAfficher[j]= lettreEntree;       //affiche la bonne lettre
                motaTrouver[j] = ' ';               //Remplace la lettre trouv� dans le mot d'origine afin d'�viter la tricherie
                NbLettreRestante = NbLettreRestante - 1;
            }
        }
        if (NbLettreRestante == 0 ){
            printf("Felicitation, Vous avez gagne\n");
        } else{
        NbCoupRestant = NbCoupRestant -1;   //d�cr�mente de 1 le nombre de coup
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
            fflush(stdin);      //vide le tampon m�moire de la derniere lettre entr�e
            scanf("%c",lettre);  //entre un caractere
            return *lettre;
}
