#ifndef __SOKOBAN__
#define __SOKOBAN__

#include <unistd.h>

#define ajaxvitre system("clear");
#define dodo(x) sleep(x);

#define LARGEUR 24
#define HAUTEUR 12
#define MAXCH 40

enum Boolean { false = 0, true =1};
enum Symbole { MUR = '#', CAISSE = 'O', CIBLE = 'o', SOKOBAN = 'S', VIDE = '.'};
enum Commande { HAUT = 'h', BAS = 'b', GAUCHE = 'g', DROITE = 'd', AIDE = 'a', QUITTER = 'q'};
enum CodeError {NO_SOKOBAN = 1, INCORRECT_GRID = 2, BAD_ENTRY =3, INVALID_COMMANDE = 4, IMPOSSIBLE_DEPLACEMENT = 5};

typedef enum Boolean Boolean;
typedef enum Symbole Symbole;
typedef enum Commande Commande;
typedef enum CodeError CodeError;

typedef char Ligne[LARGEUR+1];
typedef Ligne Grille[HAUTEUR];
typedef struct {
	int ligne;
	int colonne;
} Position;

void afficheGrille(Grille grille);
Position getSokoban(Grille grille);
void error(CodeError code);
void nouveauJeu(Grille init, Grille g);
Boolean verifGrille(Grille g);
int compteGrille(Grille g, char c);
void aide();
Position newPosition(Position pos_depart,Commande cmd);
Boolean possible(Grille g,Position pos);
void deplace(Grille jeu,Position pos_a,Position pos_b, Grille init);
Position joue(Grille jeu, Commande dir, Position depart, Grille init);
Boolean verifCommande(Commande cmd);
Boolean gagne(Grille jeu, Position soko, Grille init, int compteur);

#endif
