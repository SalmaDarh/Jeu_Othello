#ifndef HEADER_H
#define HEADER_H
extern void bienvenue_et_regles(void);//affiche un message d'accueil, les regles, et la grille initiale en demandant au joueur de choisir le mode de jeu qu'il souhaite.
extern void grilleinitiale(void);//affiche la grille initiale avec 2 pions noirs et deux blancs
extern void affichergrille(void);//affiche la grille
extern int verifier_voisinage(int ligne, int colonne,char couleur);//cherche les positions vides permettant d encadrer un pion de couleur opposee pour determiner les position possibles si elle n en trouve pas la partie est finie.
extern void jouer_encore(int N);//verifie si on peut encore jouer ou pas
extern void mouvement_possible(char couleur);//cherche les positions de tout les pions de couleur opposes et appelle la fonction verifier_voisinage pour afficher les mouvements possibles
extern void gagnant(void);//calcule le nombre de pions pour chaque couleur et determine le gagnant
extern int verifierentree(int ligne, int colonne);// verifie les positions entrees par le joueur si elle figure dans le tableau mouvement
extern void jeu(char couleur);//presente les positions possible et demande au joueur de jouer
extern void changement(int x, int y,char couleur,char anticouleur);//cherche la ligne a pour les changements selon la position choisie
extern void changement_possible(char couleur);//execute les changements selon la position choisie
extern void jeu_machine(char couleur);//demade au joueur de choisir la position et choisit quand c est au tour de la machine
extern void mouvement_possible_machine(void);
extern void strategie(void);

 #endif// header
