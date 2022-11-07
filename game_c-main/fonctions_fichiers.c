#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fonctions_fichiers.h"
#include "joueur.h"
#include <SDL2/SDL.h>


char ** allouer_tab_2D(int n , int m){

			char ** tab2D = malloc (n *sizeof(char*)) ;
			for(int i = 0 ; i< n ; i++){
				tab2D[i] =  malloc (m *sizeof(char)) ;
			}

			for(int j = 0 ; j< n ; j++){
					for(int k = 0 ; k < m ; k++){
						tab2D[j][k] = ' ';
					}
			}
			return tab2D;
}


void desallouer_tab_2D( char ** tab , int n){
			for(int i = 0 ; i< n ; i++){
				free(tab[i]) ;
			}
			 free(tab);
}


void afficher_tab_2D(char** tab , int n ,int m) {

			for(int j = 0 ; j< n ; j++){
					for(int k = 0 ; k < m; k++){

						printf("%c", tab[j][k]);
				 	}
			 	  printf("\n");
      }
}

void taille_fichier( const char* nomFichier , int* nbLing , int* nbCol){
  FILE* file =fopen(nomFichier,"r");
  char caractereLu = 0 ;
  int col =0;
  int ling = 0 ;
  int tmp=0;
    if (file != NULL){
     	while ( ( caractereLu= (char) fgetc(file) ) != EOF ){
		   if (caractereLu=='\n'){
		   	if (ling == 0 ){
		   		tmp =col;
		   	}
		    else {
		   		if (tmp < col ) {
		   		   tmp = col ;
		   		 }
		    }
		    ling ++;
		    col= 0;
      }
			else{
				col++;
		  }
		//	printf("%d  %d %d %c \n",ling , col , tmp , caractereLu );
    }
		fclose(file);
		*nbLing = ling;
    *nbCol =tmp;
	//	 printf(" col : %d lign : %d" , *nbCol , *nbLing );
	  }
  else {
  // On affiche un message d'erreur si on veut
   printf("Impossible d'ouvrir le fichier .txt");
  }
 }


char** lire_fichier(const char* nomFichier){
	int nbLing=0,nbCol=0;
	char ret;
	FILE* file=NULL;
	taille_fichier(nomFichier ,&nbLing ,&nbCol);
	char **tab= allouer_tab_2D(nbLing,nbCol);
  file =fopen(nomFichier ,"r");
    if (file != NULL){// On peut lire le fichier
			for(int i=0;i<nbLing ;i++){
				for (int j = 0; j< nbCol ;j++){
			  	fscanf(file,"%c",&tab[i][j]);
				}
				fscanf(file , "%c" , &ret);
			}
	  }

	  else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier .txt");
    }
 fclose(file);
 return tab;
}
char** modifier_caracteres(char** tab,int n,int m,char ancien,char nouveau){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
          if(tab[i][j]==ancien){
						tab[i][j]=nouveau;
					}
			}
	  }
	return tab;
}

void ecrire_fichier(const char* nomFichier,char** tab,int n,int m){
	FILE* file =fopen(nomFichier,"w");
  if (file != NULL){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				fputc(tab[i][j],file);
      }
			fprintf(file,"\n");
	  }
		fclose(file);
	}else{
		printf("Impossible d'ouvrir le fichier .txt");

	}
}


void affichage_rect(  SDL_Renderer* ecran ,SDL_Texture* sprite, int largeur , int hauteur, int x , int y ,int k , int j){
SDL_Rect dest , src ;
dest.x=x;
dest.y=y;
dest.w=largeur;
dest.h=hauteur;
src.x=largeur*k;
src.y=hauteur*j;
src.w=largeur;
src.h=hauteur;
 SDL_RenderCopy(ecran , sprite  ,&dest, &src);
}

void affichage_etoile(SDL_Renderer* ecran ,SDL_Texture* etoile, int l, int h, int largeur , int hauteur, int k , int j){
					SDL_Rect dest , src ;
				  dest.x = 0;
			   	dest.y = 0;
					dest.w = l; // Largeur du sprite
					dest.h = h; // Hauteur du sprite
					src.x = largeur*k ;
					src.y = hauteur*j ;
					src.w = largeur;
					src.h = hauteur ;
					SDL_RenderCopy(ecran , etoile  ,&dest , &src );
}

void affichage_pers(SDL_Renderer* ecran ,SDL_Texture* sprite,game_t * game , int lpers , int hpers, int x , int y ){
	SDL_Rect dest ,src ;
	dest.x = x;
	dest.y = y;
	dest.w = lpers; // Largeur du sprite
	dest.h = hpers; // Hauteur du sprite
	src.x =game->joueur->x ;
	src.y =game->joueur->y -5;
	src.w = lpers+10;
	src.h = hpers +10;
	SDL_RenderCopy(ecran , sprite  ,&dest, &src);

}


void affichage ( SDL_Renderer* ecran ,SDL_Texture* sprite,SDL_Texture* etoile, SDL_Texture* personnage, game_t * game , int lpers,int  hpers  ,int largeur , int hauteur, int l , int h){

		int nbCol=0,nbLing=0;
		char** map=lire_fichier("mape.txt");
	  taille_fichier( "mape.txt" , &nbLing , &nbCol);

	for(int j = 0 ; j< nbLing; j++){
		for(int k = 0 ; k< nbCol ; k++){
			if( map [j][k] == '4'){

				affichage_etoile(ecran ,etoile , l, h, largeur ,  hauteur,  k ,  j);



			} else if( map [j][k] == '1'){
			//	 affichage_pers( ecran ,personnage,game , lpers ,  hpers, 0 , 2*hpers  );
				// affichage_rect(  ecran , personnage, lpers ,  hpers,  0 , 2*hpers , k , j);



			} else if( map [j][k] == ' '){
				affichage_rect( ecran , sprite,  largeur , hauteur,  15*largeur , 7*largeur , k , j);

			} else 	if( map [j][k] == '5'){

					 affichage_rect( ecran , sprite,  largeur , hauteur,  0, 4*largeur , k , j);


			}
		}
	}

}
