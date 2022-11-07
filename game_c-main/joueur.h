
 #ifndef JOUEUR_H
 #define JOUEUR_H

#include <SDL2/SDL.h>
 #include <stdio.h>
  #include <stdlib.h>
  #include "sdl2-ttf-light.h"

#define SCREEN_WIDTH 700
  #define SCREEN_HEIGHT 400

typedef struct joueur_s{
  int x;
  int y;
  int w;
  int h;
}joueur_t;


typedef struct game_s{
  joueur_t* joueur;
  int score ;
  bool gameover;
  char*  tmp;
  int  temps;
  int temps_init;
}game_t;


typedef struct textures_s{
    TTF_Font* font; /*textures liée a l'image représentant l'affichage du texte*/
}textures_t;

void print_affichage(SDL_Renderer *ecran, game_t *game,textures_t *textures);
void print_temps(SDL_Renderer *ecran, game_t *game,textures_t* textures);
int is_game_over(game_t * game);
int score(game_t * game);
void jump( joueur_t * joueur);
void handle_event(SDL_Event* evenements, game_t* game , char ** tab);
void joueur_print(SDL_Event* evenements, game_t* game);
void collision_fenetre(joueur_t * joueur);
void collision_sprite(joueur_t * joueur);
void collision_sprites();
void collision_brick_haut(game_t* game,char** map);
void collision_brick_dt(game_t* game,char** map);
void collision_brick_bas(game_t* game,char** map);
void collision_brick_gch(game_t* game,char** map);

#endif
