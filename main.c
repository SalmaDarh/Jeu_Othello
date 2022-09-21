#include <stdio.h>
#include <stdlib.h>
#include "header.h"
char grille[9][9];
int mouvposs[100][2];
int mouvement[100][2];
int Jeu;
int coup;
int Nombre;
char Couleur;
int Ligne,Colonne;
int TYPEDEJEU;
char Niveau;
char Choixjoueur;
int main(void)
{

    coup=1;
    Nombre=0;
    Jeu=0;
    bienvenue_et_regles();
    if (TYPEDEJEU==1)
    {
        while (Jeu==0)
        {
            if (coup%2==1)//C'est-a-dire c'est le noir qui joue
            {
                Couleur='N';
                jeu(Couleur);

            }

            coup++;
            if (coup%2==0)//le blanc qui joue
            {
                Couleur='B';
                jeu(Couleur);

            }
            coup++;
        }



    }
    else if (TYPEDEJEU==2)
    {
        while (Jeu==0)
        {
            if (coup%2==1)//C'est-a-dire c'est le noir qui joue
            {
                Couleur='N';
                jeu_machine(Couleur);

            }

            coup++;
            if (coup%2==0)//le blanc qui joue
            {
                Couleur='B';
                jeu_machine(Couleur);

            }
            coup++;
        }
    }
    if (Jeu==1)
        gagnant();

    return 0;
}

