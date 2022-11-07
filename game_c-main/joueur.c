#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include "sdl2-ttf-light.h"
#include "joueur.h"


int is_game_over(game_t * game){
return game->gameover;

}

int score(game_t * game){
  return 0;
}

void handle_event(SDL_Event * evenements, game_t *game , char ** tab ){
void handle_event(SDL_Event * evenements, game_t *game , char ** tab,SDL_Renderer* ecran ,SDL_Texture* personnage,int lpers , int hpers ){

    game->gameover = false;

  SDL_PollEvent( evenements );
  switch(evenements->type)
  {
  case SDL_QUIT:
game->gameover = true;

  break;

  case SDL_KEYDOWN:
  switch(evenements->key.keysym.sym)
  {
   case SDLK_DOWN:

   //collision_brick_bas(game,tab);

     game->joueur->y += 1;

       break;
   case SDLK_UP:


  //  collision_brick_haut(game,tab);
    game->joueur->y-=1;


       break;
   case SDLK_RIGHT:
//collision_brick_dt(game,tab);

     game->joueur->x += 1;

       break;
   case SDLK_UP:


    //collision_brick_haut(game,tab);
    game->joueur->y-=1;



       break;
   case SDLK_RIGHT:

//collision_brick_dt(game,tab);

     game->joueur->x += 1;

        break;

   case SDLK_LEFT:
   //collision_brick_gch(game,tab);

     game->joueur->x -= 1;

          break;
  case SDLK_q:
        game->gameover = true;

          break;
  case SDLK_ESCAPE:

       game->joueur->x += 1;
        game->joueur->y -= 1;


        break;
  }
  }
}

void collision_fenetre(joueur_t * joueur){
  if(joueur->x <= 0){
    joueur->x +=1;
  }else if(joueur->x >= 659 ){
    joueur->x -= 1;
  }

  if(joueur->y <= 0){
    joueur->y +=1;
  }else if(joueur->y >= 359 ){
    joueur->y -= 1;
  }

}

void collision_sprite(joueur_t * joueur){
  if(joueur->x <= 0){
    joueur->x +=1;
  }else if(joueur->x >= 64 ){
    joueur->x -= 1;
  }

  if(joueur->y <= 0){
    joueur->y +=1;
  }else if(joueur->y >= 32 ){
    joueur->y -= 1;
  }



}


void collision_brick_haut(game_t* game,char** map){
  //if(game->joueur->y > 0){
printf("x = %d\n",game->joueur->x );
printf("y = %d\n",game->joueur->y);
  if(map[4][5]=='5'){
    game->joueur->y+=0;
      if(map[game->joueur->x][game->joueur->y-1]=='5'){
     game->joueur->y +=0;
  }
}
}

void collision_brick_bas(game_t* game,char** map){

  if(map[game->joueur->x][game->joueur->y+1]=='5'){
   game->joueur->y +=0;
}
}

void collision_brick_gch(game_t* game,char** map){
//  if(game->joueur->x >0){
  if(map[game->joueur->x-1][game->joueur->y]=='5'){
    game->joueur->x +=0;
}
}
/*
pos de joueur est en pixel 32 pour largeur et 32 pou Hauteur
pour cela on arrive pas a detecter la pos exact sur la map
//////////////////////////////////////////////////////////
solution proposee : diviser sur 32 pour la pos de jour
MAIS ca Maaaaaaaaaaaaaaaaaaaaaaaaaaaaaarche pas!!!!!!!!
*/

void collision_brick_haut(game_t* game,char** map){
  if(game->joueur->y > 0){
  if(map[game->joueur->x/32][game->joueur->y/32-1]=='5'){
     game->joueur->y +=0;
  }
}
}
void collision_brick_bas(game_t* game,char** map){
  if(map[game->joueur->x/32][(game->joueur->y)/32+1]=='5'){
   game->joueur->y +=0;
}
}

void collision_brick_gch(game_t* game,char** map){
    if(game->joueur->y > 0){
      if(map[game->joueur->x/32-1][game->joueur->y/32]=='5'){
        game->joueur->x +=0;
      }
    }
}
void collision_brick_dt(game_t* game,char** map){
  if(map[game->joueur->x/32][game->joueur->y/32+1]=='5'){
    game->joueur->x +=0;
}
}

void print_affichage(SDL_Renderer *ecran, game_t *game,textures_t *textures){
  apply_text(ecran,10,10,10,40,"WELCOME TO YOUR GAME!",textures->font);

}

void print_temps(SDL_Renderer *ecran, game_t *game,textures_t* textures){
      sprintf(game->tmp,"TEMPS : %d S", (game->temps - game->temps_init));

      apply_text(ecran,0,0,100,50,game->tmp,textures->font);//on applique le temps en haut à gauche

}
