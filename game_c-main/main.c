#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SDL2/SDL.h"

#include "sdl2-ttf-light.h"

#include "fonctions_fichiers.h"
#include "joueur.h"
#include "Fonction_SDL.h"
#include "sdl2-ttf-light.h"


#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 400

int main ( int argc , char* args[] ){

    textures_t* textures= malloc(sizeof(textures_t));
  	int nbCol=0,nbLing=0;
  	char** map=lire_fichier("mape.txt");
    taille_fichier( "mape.txt" , &nbLing , &nbCol);
    SDL_Window* fenetre; // Déclaration de la fenêtre
    SDL_Event evenements; // Événements liés à la fenêtre

    if(SDL_Init(SDL_INIT_VIDEO) < 0) // Initialisation de la SDL
    {
        printf("Erreur d’initialisation de la SDL: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }


    // Créer la fenêtre
    fenetre = SDL_CreateWindow("Fenetre SDL", SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED, 700, 400, SDL_WINDOW_RESIZABLE);
    if(fenetre == NULL) // En cas d’erreur
    {
        printf("Erreur de la creation d’une fenetre: %s",SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    // Mettre en place un contexte de rendu de l’écran
    SDL_Renderer* ecran;
  //  textures_t *textures =malloc(sizeof(textures_t));
    ecran = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    // Charger l’image
    SDL_Texture* fond = charger_image( "layer.bmp", ecran );
    SDL_Texture* sprite= charger_image( "pavage.bmp", ecran );
    SDL_Texture* personnage = charger_image( "personnage1.bmp", ecran );
    SDL_Texture* etoile = charger_image( "v.bmp", ecran );
    textures->font = load_font("arial.ttf",50);
     int largeur , lpers ,l, hauteur,hpers,h;
     Uint32 format,f ,formatpers;
     int access , accesspers, a;

     SDL_QueryTexture(sprite, &format, &access , &largeur ,&hauteur);//recuperation d info sur l image
     largeur = largeur/16 ;
     hauteur = hauteur/10;


      SDL_QueryTexture(personnage, &formatpers, &accesspers , &lpers,&hpers);//recuperation d info sur l image
     lpers = lpers/5 ;
     hpers = hpers/4;


     SDL_QueryTexture(etoile, &f, &a , &l ,&h);//recuperation d info sur l image

      //joueur_t * player;
			game_t* game= malloc(sizeof(game_t));
      game->joueur=malloc(sizeof(joueur_t));
			game->joueur->x=0;
			game->joueur->y=hpers*8;


      TTF_Init();




    // Boucle principale
    while( ! is_game_over(game)){

        SDL_RenderClear(ecran);
        SDL_RenderCopy(ecran, fond, NULL, NULL);
  	    affichage (  ecran , sprite, etoile, personnage , game , lpers , hpers , largeur ,  hauteur ,l , h );
       affichage_pers( ecran ,personnage,game , lpers ,  hpers, 0 , 2*hpers  );
        handle_event( &evenements,game,map);
        collision_fenetre(game->joueur);
        SDL_RenderPresent(ecran);
        //print_affichage(ecran , game , textures);
        //print_temps(ecran, game, textures);


    }
   TTF_Quit();

   // Libérer de la mémoire
    SDL_DestroyTexture(fond);
    SDL_DestroyRenderer(ecran);

    // Quitter SDL
    SDL_DestroyWindow(fenetre);
    SDL_Quit();
    return 0;


}
