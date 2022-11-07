
 #ifndef FONCTIONS_FICHIERS_H
 #define FONCTIONS_FICHIERS_H

#include <SDL2/SDL.h>
 #include <stdio.h>
  #include <stdlib.h>
  #include "joueur.h"
#include "joueur.h"

char ** allouer_tab_2D(int n , int m);

void desallouer_tab_2D( char ** tab , int n) ;

void afficher_tab_2D(char** tab , int n ,int m) ;

void taille_fichier( const char* nomFichier , int* nbLing , int* nbCol);

char** lire_fichier(const char* nomFichier);

void affichage_rect(  SDL_Renderer* ecran ,SDL_Texture* sprite, int largeur , int hauteur, int x , int y ,int k , int j);
void affichage_etoile(SDL_Renderer* ecran ,SDL_Texture* etoile, int l, int h, int largeur , int hauteur, int k , int j);


void affichage ( SDL_Renderer* ecran ,SDL_Texture* sprite,SDL_Texture* etoile, SDL_Texture* personnage , game_t * game , int lpers , int hpers ,int largeur , int hauteur , int l , int h);

void affichage_pers(SDL_Renderer* ecran ,SDL_Texture* sprite, game_t * game,int largeur , int hauteur, int x , int y );

#endif
