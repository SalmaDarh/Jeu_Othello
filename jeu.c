#include<stdio.h>
#include<stdlib.h>
extern char grille[9][9];//la grille qui represente la table de jeu
extern int mouvposs[100][2];// un tableau pour stocker les positions qu'on trouve pour chaque pion adversee
extern int mouvement[100][2];// tableau comprenant toutes les positions possibles lors d un coup
extern int Jeu;//variable qui prends 1 ou 0 (condition d arret) afin de verifier si on peut toujours jouer ou la partie est terminee
extern int coup;//on verifie sa parite pour savoir le tour est de quel des deux joueurs
extern int Nombre;//le nombre des positions lors un coup
extern char Couleur;//N pour noir ou B pour blanc
extern int Ligne,Colonne;//deux variables globales pour stocker les valeurs entrees par le joueur determinant la position qu il a choisit
extern int TYPEDEJEU;// 1 si contre autre joueur 2 si contre machine
extern char Niveau;//facile aleatoire ou moyen ou difficile
extern char Choixjoueur;
char Joueur1[20];
char Joueur2[20];
void bienvenue_et_regles(void)
{
    int a;
    printf("\t\t\t#######  #######  ##   ##  #######  ##       ##       #######\n");
    printf("\t\t\t##   ##    ##     ##   ##  ##       ##       ##       ##   ##\n");
    printf("\t\t\t##   ##    ##     #######  #######  ##       ##       ##   ##\n");
    printf("\t\t\t##   ##    ##     ##   ##  ##       ##       ##       ##   ##\n");
    printf("\t\t\t#######    ##     ##   ##  #######  #######  #######  #######\n\n\n\n\n\n");
    printf("\t\t\t\t\tBienvenue au jeu othello : \n\n\n\n");
    printf("voici un petit rappel des regles du jeu othello:\nChaque joueur a son tour doit placer une piece a sa couleur sur la grille.\nLes pions sont toujours places dans une case adjacente a un pion adverse et il faut que ce pion encadre un ou plusieurs pions adverses qui seront donc captures.\nLes pions ne sont pas retires de la grille, mais on les retourne pour changer leur couleur.\n\n\n\n");
    printf("C'est compris?\nTapez O pour oui et N pour non\n\n");
    char x;
    scanf("%c",&x);
    while((x!='N')&&(x!='n')&&(x!='O')&&(x!='o'))
    {
        printf("Veuillez entrer un choix correcte.Tapez O pour oui et N pour non\n\n ");
        fflush(stdin);
        scanf("%c",&x);

    }
    while (x=='N' | x=='n')
    {
        printf("voici un petit rappel des regles du jeu othello:\n\n\nChaque joueur a son tour doit placer une piece a sa couleur sur la grille.\nLes pions sont toujours places dans une case adjacente a un pion adverse et il faut que ce pion encadre un ou plusieurs pions adverses qui seront donc captures.\nLes pions ne sont pas retires de la grille, mais on les retourne pour changer leur couleur.\n\n\n\n");
        printf("C'est compris?\nTapez O pour oui et N pour non\n\n");
        fflush(stdin);
        scanf("%c",&x);

    }
    printf("Veuillez choisir le mode de jeu : taper 1 pour jouer contre un autre joueur ou tapez 2 pour jouer contre la machine . \n");
    fflush(stdin);
    scanf("%d",&a);
    if (a==1)
    {
        printf("\tVous avez choisi de jouer contre un autre joueur\n\n\n");
        printf("Joueur 1 veuillez entrer votre prenom\n");
        scanf("%s",Joueur1);
        printf("Joueur 2 veuillez entrer votre prenom\n");
        scanf("%s",Joueur2);
        fflush(stdin);
        printf("voulez-vous jouer en niveau facile ou difficile? Tapez F pour facile ou D pour difficile\n");
        scanf("%c",&Choixjoueur);
        fflush(stdin);
        while((Choixjoueur!='D')&&(Choixjoueur!='d')&&(Choixjoueur!='F')&&(Choixjoueur!='f'))
        {
            printf("veuillez entrer un choix valide. Tapez F pour facile ou D pour difficile\n");
            scanf("%c",&Choixjoueur);
        }
        grilleinitiale();
        affichergrille();
        printf("\n\n\n");
        printf(" %s aura des pions noirs et %s aura des pions blancs\n\nC'est parti!\n\n\n\n",Joueur1,Joueur2);


        TYPEDEJEU=1;
    }
    else if (a==2)
    {
        printf("Vous avez choisi de jouer contre la machine\n\nVoulez vous le niveau facile,moyen ou difficile?  Tapez F pour facile ou M pour moyen ou D pour difficile\n\n");
        fflush(stdin);
        scanf ("%c",&Niveau);
        while((Niveau!='f')&&(Niveau!='F')&&(Niveau!='M')&&(Niveau!='m')&&(Niveau!='d')&&(Niveau!='D'))
        {
            printf("Veuillez choisir un niveau correcte ! Tapez F pour facile ou M pour moyen ou D pour Difficile\n");
            scanf("%c",&Niveau);
        }
        printf("Super ! maintenant veuillez entrer votre prenom\n");
        scanf("%s",Joueur1);
        grilleinitiale();
        affichergrille();
        printf("\n\n\n");
        printf("%s tu auras des pions noirs et la machine aura des pions blancs\n\nC'est parti!\n\n\n",Joueur1);

        TYPEDEJEU=2;
    }

}
/*fonction qui initialise la grille*/
void grilleinitiale(void)
{
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if (((i==4) && (j==4))| ((i==5)&&(j==5)))//ce sont les positions definies par les regles
                grille[i][j]='B';
            else if ((i==4 && j==5)|(i==5 && j==4))//ce sont les positions definies par les regles
                grille[i][j]='N';
            else
                grille[i][j]='X';//les positions seront a priori vides , designes par X
        }
    }

}
/*fonction qui affiche la grille*/
void affichergrille(void)
{
    for (int i=0; i<=8;i++)
    {
        if (i==0) printf("\t\t\t\t   1 2 3 4 5 6 7 8\n"); //pour numeroter les colonnes
        else
        {
            for(int j=0; j<=8;j++)
            {
                if (j==0)
                    printf("\t\t\t\t%d ",i);//pour numeroter les lignes
                else
                {
                    printf("|%c", grille[i][j]);
                    if (j==8) printf("|");
                }
            }
            printf("\n");//retour a la ligne apres chaque ligne
        }
    }
}
int verifier_voisinage(int ligne, int colonne,char couleur)
{
    int N=0;

    if ((ligne!=1) && (ligne!=8) &&(colonne!=1 )&& (colonne!=8))//on se place d'abord au milieu de la grille pour supprimer les cas particulers
    {
        /*on cherche les pions couleur adjacents
        on va etudier cas par cas c'est a dire a droite , a droite diagonale haut, a droite diagonale bas, haut, bas a gauche diagonale bas,
        a gauche diagonale bas,et  a gauche  */
        if (grille[ligne-1][colonne-1]==couleur)//diagonale droite en haut
        {
            for(int r=1;((r+ligne<=8)&&(r+colonne<=8));r++)//cherche dans la diagonale droite vers le bas
            {
                if ((grille[ligne+r][colonne+r]=='X'))//si la position est vide alors elle est possible
                {
                    mouvposs[N][0]=ligne+r;
                    mouvposs[N][1]=colonne+r;
                    N++;
                    break;
                }
                else if (grille[ligne+r][colonne+r]==couleur)//si elle est de meme couleur la position n'est pas possible on sort de la boucle
                {
                    break;
                }
                /*si la position n'est ni vide ni de meme couleur alors elle sera toujours en couleur adverse
                il faut ainsi continuer la boucle car toute la ligne peut etre capturee , jusqu a trouver une position valide ou une condition d arret :
                dans notre cas un pion de la meme couleur que le joueur */

            }

        }
        if (grille[ligne-1][colonne]==couleur)//en haut
        {
            for(int r=1;(r+ligne<=8);r++)
            {
                if (grille[ligne+r][colonne]=='X')//en bas
                {
                    mouvposs[N][0]=ligne+r;
                    mouvposs[N][1]=colonne;
                    N++;
                    break;
                }
                else if (grille[ligne+r][colonne]==couleur)
                {
                    break;
                }


            }

        //meme principe de recherche dans tout les cas.
       }
       if (grille[ligne-1][colonne+1]==couleur)// recherche dans la diagonale droite en haut
       {
            for(int r=1;((r+ligne<=8)&&(colonne-r>=1));r++)
            {
                if (grille[ligne+r][colonne-r]=='X')//recherche des positions dans la diagonale gauche en bas
                {
                    mouvposs[N][0]=ligne+r;
                    mouvposs[N][1]=colonne-r;
                    N++;
                    break;
                }
                else if (grille[ligne+r][colonne-r]==couleur)
                {
                    break;
                }
            }
       }
       if (grille[ligne][colonne-1]==couleur)//a gauche
       {
           for(int r=1;(colonne+r<=8);r++)
            {
                if (grille[ligne][colonne+r]=='X')//a droite
                {
                    mouvposs[N][0]=ligne;
                    mouvposs[N][1]=colonne+r;
                    N++;
                    break;
                }
                else if (grille[ligne][colonne+r]==couleur)
                {
                    break;
                }
            }
       }
       if (grille[ligne][colonne+1]==couleur)// a droite
       {
            for(int r=1;(colonne-r>=1);r++)
            {
                if (grille[ligne][colonne-r]=='X')// a gauche
                {
                    mouvposs[N][0]=ligne;
                    mouvposs[N][1]=colonne-r;
                    N++;
                    break;
                }
                else if (grille[ligne][colonne-r]==couleur)
                {
                    break;
                }
            }
       }
       if(grille[ligne+1][colonne-1]==couleur)//diagonale gauche en bas
       {
            for(int r=1;((ligne-r>=1)&&(colonne+r<=8));r++)
            {
                if (grille[ligne-r][colonne+r]=='X')// diagonale droite en haut
                {
                    mouvposs[N][0]=ligne-r;
                    mouvposs[N][1]=colonne+r;
                    N++;
                    break;
                }
                else if (grille[ligne-r][colonne+r]==couleur)
                {
                    break;
                }
            }
       }
       if (grille[ligne+1][colonne]==couleur)//en bas
       {
            for(int r=1;(ligne-r>=1);r++)
            {
                if (grille[ligne-r][colonne]=='X')//en haut
                {
                    mouvposs[N][0]=ligne-r;
                    mouvposs[N][1]=colonne;
                    N++;
                    break;
                }
                else if (grille[ligne-r][colonne]==couleur)
                {
                    break;
                }
            }
       }
       if (grille[ligne+1][colonne+1]==couleur)//diagonale droite en bas
       {
            for(int r=1;((ligne-r>=1)&&(colonne-r>=1));r++)
            {
                if (grille[ligne-r][colonne-r]=='X')//diagonale gauche en haut
                {
                    mouvposs[N][0]=ligne-r;
                    mouvposs[N][1]=colonne-r;
                    N++;
                    break;
                }
                else if (grille[ligne-r][colonne-r]==couleur)
                {
                    break;
                }
            }
       }

   }
   /*passons aux cas particulers c'est a dire les extrimites en eliminant les quatres coins de la table
 pour eviter de sortir de la grille vu qu on ne peut avoir positions 0 ou 9 dans aucun sens !*/
   else if (((ligne==1)|(ligne==8))&&(colonne!=1)&&(colonne!=8))// les deux lignes premiere et derniere
   {
       if (grille[1][colonne-1]==couleur)
       {
           for(int r=1;(colonne+r<=8);r++)
            {
                if (grille[1][colonne+r]=='X')
                {
                    mouvposs[N][0]=1;
                    mouvposs[N][1]=colonne+r;
                    N++;
                    break;
                }
                else if (grille[1][colonne+r]==couleur)
                {
                    break;
                }
            }
       }
       if (grille[1][colonne+1]==couleur)
       {
           for(int r=1;(colonne-r>=1);r++)
            {
                if (grille[1][colonne-r]=='X')
                {
                    mouvposs[N][0]=1;
                    mouvposs[N][1]=colonne-r;
                    N++;
                    break;
                }
                else if (grille[1][colonne-r]==couleur)
                {
                    break;
                }
            }
       }

   }
    else if ((ligne!=1)&&((colonne==1)|(colonne==8))&&(ligne!=8))//les deux colonnes 1 et 8
    {
        if (grille[ligne-1][1]==couleur)
        {
            for(int r=1;(ligne+r<=8);r++)
            {
                if (grille[ligne+r][1]=='X')
                {
                    mouvposs[N][0]=ligne+r;
                    mouvposs[N][1]=1;
                    N++;
                    break;
                }
                else if (grille[ligne+r][1]==couleur)
                {
                    break;
                }
            }
        }
        if (grille[ligne+1][1]==couleur)
        {
           for(int r=1;(ligne-r>=1);r++)
            {
                if (grille[ligne-r][1]=='X')
                {
                    mouvposs[N][0]=ligne-r;
                    mouvposs[N][1]=1;
                    N++;
                    break;
                }
                else if (grille[ligne-r][1]==couleur)
                {
                    break;
                }
            }
        }
    }
    /*les quatres coins ne proposent aucune positions possibles */
    /*cette condition ci dessous verifie s il existe au moins une position possible et l'ajoute au tableau mouvement */
    if (N!=0)

    {
        for(int k=0,j=Nombre ;k<N,j<(Nombre+N) ;k++,j++)
        {
                int m=0;
                for (int i=0;i<Nombre;i++)
                {
                    if ((mouvement[i][0]==mouvposs[k][0])&&(mouvement[i][1]==mouvposs[k][1]))
                        m++;
                }
                if(m==0)
                {
                    mouvement[j][0]=mouvposs[k][0];
                    mouvement[j][1]=mouvposs[k][1];
                    if ((Choixjoueur=='F')|(Choixjoueur=='f')|(Niveau=='F')|(Niveau=='f'))
                    {
                        if ((TYPEDEJEU==1)|((TYPEDEJEU==2)&&(coup%2==1)))
                            printf("(%d;%d)\n",mouvposs[k][0],mouvposs[k][1]);
                    }
                }


        }



        return N;
    }

    return N;


}
void jouer_encore(int N)
{

    if ( N==0)// le nombre de positions possibles nul donc la partie est terminee pour ce joueur
    {
        int l= (Couleur=='N')? 1 : 2;
        if (TYPEDEJEU==1)
        {
          if (l==1)
         printf("Aucune position possible pour toi %s! \n",Joueur1);
         else if (l==2)
         printf("Aucune position possible pour toi %s! \n",Joueur2);
        }
        else if (TYPEDEJEU==2)
        {
            if (l==1)
         printf("Aucune position possible pour toi %s! \n",Joueur1);
        else if (l==2)
         printf("Aucune position possible pour la machine \n");
        }
        printf("Partie terminee\n");

        Jeu=1;

    }

}

void mouvement_possible(char couleur)
{
    char anticouleur=(couleur=='B')? 'N' : 'B';
    int numjoueur=(couleur=='N')? 1 : 2;
    Nombre=0;

    if (Jeu==0)//tant que la partie n est pas encore terminee c est a dire qu il existe au moins une position possible
    {

        for (int i=1; i<=8;i++)
        {
            for(int j=1; j<=8 ;j++)
            {
                if ( grille[i][j]==anticouleur)//on cherche les pions adverses
                {

                    Nombre+= verifier_voisinage(i,j,couleur);//on cherche si ces pions adverses sont adjacents a des pions couleur pour pouvoir les capturer


                }
            }

        }




    }
    jouer_encore(Nombre);





}
void gagnant(void)// calcule le nombre de pions noir et blanc dans la grille pour determiner le gagnant
{
    int nombreblanc=0;
    int nombrenoir=0;
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if (grille[i][j]=='B')
                nombreblanc++;
            else if (grille[i][j]=='N')
                nombrenoir++;
        }
    }
    if (TYPEDEJEU==1)
    {
        printf("%s a %d points, et %s a %d points :\n",Joueur1,nombrenoir,Joueur2,nombreblanc);
    if(nombrenoir>nombreblanc)
        printf ("%s est gagnant ! FELICITATION\n",Joueur1);
    else if (nombrenoir<nombreblanc)
        printf ("%s est gagnant ! FELICITATION\n",Joueur2);
    else
        printf ("EGALITE, FELICITATION AUX DEUX JOUEURS %s et %s\n",Joueur1,Joueur2);
    }
    else if (TYPEDEJEU==2)
    {
        printf("%s a %d points, et la machine a %d points :\n",Joueur1,nombrenoir,nombreblanc);
        if(nombrenoir>nombreblanc)
        printf ("%s est gagnant ! FELICITATION\n",Joueur1);
        else if (nombrenoir<nombreblanc)
        printf ("la machine est gagnante ! NOUS SOMMES DESOLES\n");
        else
        printf ("EGALITE, FELICITATIONS \n");
    }



}
int verifierentree(int k, int j)
{
    for(int i=0;i<Nombre;i++)
    {
        if ((mouvement[i][0]==k)&&(mouvement[i][1]==j))
        return 1;

    }
    return 0;
}

void jeu(char couleur)
{
    mouvement_possible(couleur);
    if (Jeu!=1)
    {
        int joueur=(couleur=='N') ? 1 : 2;
        if (joueur==1)
        {
            printf("%s entrez la ligne et la colonne souhaitee\n",Joueur1);
            scanf("%d %d",&Ligne,&Colonne);
        }
        else if (joueur==2)
        {
            printf("%s entrez la ligne et la colonne souhaitee\n",Joueur2);
            scanf("%d %d",&Ligne,&Colonne);
        }


        int vrai;
        vrai = verifierentree(Ligne,Colonne);
        while (vrai==0)
        {
            printf("\aAttention ! vous avez entre une position non valide ! Veuillez reessayer \n");
            fflush(stdin);
            scanf("%d %d",&Ligne,&Colonne);
            vrai=verifierentree(Ligne,Colonne);

        }
        changement_possible(couleur);
        affichergrille();
    }
}
void changement(int x, int y,char couleur,char anticouleur)
{

   if ((x!=1) && (y!=8) &&(y!=1 )&& (y!=8))
   {
       if (grille[x-1][y-1]==couleur)
       {
           for(int r=1;((r+x<=8)&&(r+y<=8));r++)
           {
               if ((grille[x+r][y+r]=='X')&&(x+r==Ligne)&&(y+r==Colonne))
               {
                    for(int a=0;a<=r;a++)
                    {
                        grille[x+a][y+a]=couleur;
                    }
                    break;
               }
           }

       }
       if (grille[x-1][y]==couleur)
       {
            for(int r=1;(r+x<=8);r++)
            {
                if ((grille[x+r][y]=='X')&&(x+r==Ligne)&&(y==Colonne))
                {
                    for(int a=0;a<=r;a++)
                    {
                        grille[x+a][y]=couleur;
                    }
                    break;

                }
            }
        }
       if (grille[x-1][y+1]==couleur)
       {
            for(int r=1;((r+x<=8)&&(y-r>=1));r++)
            {
                if ((grille[x+r][y-r]=='X')&&(x+r==Ligne)&&(y-r==Colonne))
                {
                    for(int a=0;a<=r;a++)
                    {
                        grille[x+a][y-a]=couleur;
                    }
                    break;
                }
            }
       }
       if (grille[x][y-1]==couleur)
       {
           for(int r=1;(y+r<=8);r++)
            {
                if ((grille[x][y+r]=='X')&&(x==Ligne)&&(y+r==Colonne))
                {
                   for(int a=0;a<=r;a++)
                    {
                        grille[x][y+a]=couleur;
                    }
                    break;
                }
            }
       }
       if (grille[x][y+1]==couleur)
       {
            for(int r=1;(y-r>=1);r++)
            {
                if ((grille[x][y-r]=='X')&&(x==Ligne)&&(y-r==Colonne))
                {
                    for(int a=0;a<=r;a++)
                    {
                        grille[x][y-a]=couleur;
                    }
                    break;
                }
            }
       }
       if(grille[x+1][y-1]==couleur)
       {
            for(int r=1;((x-r>=1)&&(y+r<=8));r++)
            {
                if ((grille[x-r][y+r]=='X')&&(x-r==Ligne)&&(y+r==Colonne))
                {
                   for(int a=0;a<=r;a++)
                    {
                        grille[x-a][y+a]=couleur;
                    }
                   break;
                }
            }
       }
       if (grille[x+1][y]==couleur)
       {
            for(int r=1;(x-r>=1);r++)
            {
                if ((grille[x-r][y]=='X')&&(x-r==Ligne)&&(y==Colonne))
                {
                    for(int a=0;a<=r;a++)
                    {
                        grille[x-a][y]=couleur;
                    }
                   break;
                }
            }
       }
       if (grille[x+1][y+1]==couleur)
       {
            for(int r=1;((x-r>=1)&&(y-r>=1));r++)
            {
                if ((grille[x-r][y-r]=='X')&&(x-r==Ligne)&&(y-r==Colonne))
                {
                    for(int a=0;a<=r;a++)
                    {
                        grille[x-a][y-a]=couleur;
                    }
                    break;
                }
            }
       }

   }
   else if (((x==1)|(x==8))&&(y!=1)&&(y!=8))
   {
       if (grille[1][y-1]==couleur)
       {
           for(int r=1;(y+r<=8);r++)
            {
                if ((grille[1][y+r]=='X')&&(Ligne==1)&&(y+r==Colonne))
                {
                    for(int a=0;a<=r;a++)
                    {
                        grille[1][y+a]=couleur;
                    }
                  break;
                }
            }
       }
       if (grille[1][y+1]==couleur)
       {
           for(int r=1;(y-r>=1);r++)
            {
                if ((grille[1][y-r]=='X')&&(Ligne==1)&&(y-r==Colonne))
                {
                    for(int a=0;a<=r;a++)
                    {
                        grille[1][y-a]=couleur;
                    }
                   break;
                }
            }
       }

   }
    else if ((x!=1)&&((y==1)|(y==8))&&(x!=8))
    {
        if (grille[x-1][1]==couleur)
        {
            for(int r=1;(x+r<=8);r++)
            {
                if ((grille[x+r][1]=='X')&&(x+r==Ligne)&&(Colonne==1))
                {
                    for(int a=0;a<=r;a++)
                    {
                        grille[x+a][1]=couleur;
                    }
                    break;
                }
            }
        }
        if (grille[x+1][1]==couleur)
        {
           for(int r=1;(x-r>=1);r++)
            {
                if ((grille[x-r][1]=='X')&&(x-r==Ligne)&&(Colonne==1))
                {
                   for(int a=0;a<=r;a++)
                    {
                        grille[x-a][1]=couleur;
                    }
                    break;
                }
            }
        }
    }


}
void changement_possible(char couleur)
{
    char anticouleur=(couleur=='B')? 'N' : 'B';
    for (int i=1; i<=8;i++)
    {
        for(int j=1; j<=8 ;j++)
        {
            if ( grille[i][j]==anticouleur)
            {
                changement(i,j,couleur,anticouleur);
            }
        }
    }
}

void mouvement_possible_machine(void)
{
    int couleur='B';
    int anticouleur='N';
    Nombre=0;
    if (Jeu==0)
    {

        for (int i=1; i<=8;i++)
        {
            for(int j=1; j<=8 ;j++)
            {
                if ( grille[i][j]==anticouleur)
                {

                    Nombre+= verifier_voisinage(i,j,couleur);



                }
            }
        }


    }
    jouer_encore(Nombre);



}
void jeu_machine(char couleur)
{

    if (Jeu!=1)
    {
        int joueur=(couleur=='N') ? 1 : 2;
        if (joueur==1)
        {
            mouvement_possible(couleur);
            printf("%s  veuillez entrez la ligne et la colonne souhaitee\n",Joueur1);
            scanf("%d %d",&Ligne,&Colonne);
            int vrai;
            vrai = verifierentree(Ligne,Colonne);
            while (vrai==0)
            {
                printf("\aAttention ! vous avez entre une position non valide reessayez \n");
                scanf("%d %d",&Ligne,&Colonne);
                vrai=verifierentree(Ligne,Colonne);

            }
            changement_possible(couleur);

        }
        else
        {
            printf("\n\n\tC'est au tour de la machine!\n");
            mouvement_possible_machine();
            if ((Niveau=='f')|(Niveau=='F'))
            {
                srand(time(NULL));
                int positionchoisie = rand() %(Nombre-1);
                Ligne=mouvement[positionchoisie][0];
                Colonne=mouvement[positionchoisie][1];
            }
            else if ((Niveau=='m')|(Niveau=='M'))
            {
                Ligne = mouvement[0][0];
                Colonne = mouvement[0][1];


            }
            else if((Niveau=='d')|(Niveau=='D'))
            {
                strategie();


            }
            changement_possible(couleur);
            printf("\n\n\n\n");
        }
        affichergrille();

    }
}
void strategie(void)
{
    int minligne= mouvement[0][0];
    int maxligne = mouvement[Nombre-1][0];
    int positionmin,positionmax;
    for(int i=0;i<Nombre;i++)
    {
        if (mouvement[i][0]<=minligne)
        {
            minligne=mouvement[i][0];
            positionmin=i;
        }
        if (mouvement[i][0]>=maxligne)
        {
            maxligne=mouvement[i][0];
            positionmax=i;
        }



    }
    Ligne = ((8-maxligne)<= minligne)? maxligne : minligne;
    int position;
    position = ((8-maxligne)<= minligne)? positionmax : positionmin;
    int mincolonne = mouvement[position][1];
    int maxcolonne = mouvement[position][1];

    for(int j=0;j<Nombre;j++)
    {
        if (mouvement[j][0]==Ligne)
        {

            if (mouvement[j][1]<=mincolonne)
            {
                mincolonne=mouvement[j][1];
            }
            if (mouvement[1][1]>=maxcolonne)
            {
                maxcolonne=mouvement[j][1];
            }
            Colonne = ((8-maxcolonne)<= mincolonne) ? maxcolonne : mincolonne;
        }
    }


}
/*  else if ((N!=0)&&(coup%2==0)&&(TYPEDEJEU==2))
    {
        for(int k=0,j=Nombre ;k<N,j<(Nombre+N) ;k++,j++)
        {

            mouvement[j][0]=mouvposs[k][0];
            mouvement[j][1]=mouvposs[k][1];
        }
        return N;
    }*/










