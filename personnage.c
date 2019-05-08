#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "personnage.h"

void initialiser_personnage(personnage *perso) {
	perso->position_personnage.x=30;
	perso->position_personnage.y=235;
	perso->personnage = IMG_Load("idle1.png");
	perso->jump = IMG_Load("jump1.png");
	perso->jump2 = IMG_Load("jump2.png");
	perso->droite[0] = IMG_Load("droite1.png");
	perso->droite[1] = IMG_Load("droite2.png");
	perso->droite[2] = IMG_Load("droite3.png");
	perso->droite[3] = IMG_Load("droite4.png");
	perso->gauche[0] = IMG_Load("gauche1.png");
	perso->gauche[1] = IMG_Load("gauche2.png");
	perso->gauche[2] = IMG_Load("gauche3.png");
	perso->gauche[3] = IMG_Load("gauche4.png");
	perso->velocity=0;
	perso->acceleration=0;
}

void affichage_personnage(SDL_Surface *screen,personnage *perso){
	SDL_BlitSurface(perso->personnage,NULL,screen,&perso->position_personnage);
}

void initialiser_background_level(background *level) {
	level->positionbackground.x=0;
	level->positionbackground.y=0;
	level->image_background = IMG_Load("map.png");
}

void affichage_background_level(SDL_Surface *screen,background *level){
	SDL_BlitSurface(level->image_background,NULL,screen,&level->positionbackground);
}

void initialiser_background_gameover(background *gameover) {
	gameover->positionbackground.x=0;
	gameover->positionbackground.y=0;
	gameover->image_background = IMG_Load("gameover.png");
}

void affichage_background_gameover(SDL_Surface *screen,background *gameover){
	SDL_BlitSurface(gameover->image_background,NULL,screen,&gameover->positionbackground);
}


void initialiser_pause(image *pause) {
	pause->position_image.x=218;
	pause->position_image.y=56;
	pause->image = IMG_Load("pause.png");
}

void affichage_pause(SDL_Surface *screen,image *pause){
	SDL_BlitSurface(pause->image,NULL,screen,&pause->position_image);
}



void deplacer_personnage_droite (SDL_Surface *screen,personnage *perso,background *level, int *i, Uint32 dt){
	float dx;
	dx=(0.5*perso->acceleration*dt*dt)+(perso->velocity*dt);
	
	perso->position_personnage.x+=dx;

	SDL_BlitSurface(level->image_background,NULL,screen,&level->positionbackground);
	SDL_BlitSurface(perso->droite[*(i)],NULL,screen,&perso->position_personnage);
	SDL_Flip(screen);
	SDL_Delay(80);
	(*i)++;
	if ((*i)>=4) {(*i)=0; }
}


void deplacer_personnage_gauche (SDL_Surface *screen,personnage *perso,background *level, int *i){
	perso->position_personnage.x-=7; 
	SDL_BlitSurface(level->image_background,NULL,screen,&level->positionbackground);
	SDL_BlitSurface(perso->gauche[*(i)],NULL,screen,&perso->position_personnage);
	SDL_Flip(screen);
	SDL_Delay(80);
	(*i)++;
	if ((*i)>=4) {(*i)=0; }
}

void deplacer_personnage_haut (SDL_Surface *screen,personnage *perso,background *level){
	float i=0 ;
	while (i<=9) {
	i+=1;
	perso->position_personnage.y-=i*1.5;
	
	SDL_BlitSurface(level->image_background,NULL,screen,&level->positionbackground);
	SDL_BlitSurface(perso->jump,NULL,screen,&perso->position_personnage);
	SDL_Flip(screen);
	SDL_Delay(20);
	};
	i=0;
	while (i<=9) {
	i+=1;
	perso->position_personnage.y+=i*1.5;
	
	SDL_BlitSurface(level->image_background,NULL,screen,&level->positionbackground);
	SDL_BlitSurface(perso->jump,NULL,screen,&perso->position_personnage);
	SDL_Flip(screen);
	SDL_Delay(20);
	};
}

void deplacer_personnage_haut_droite (SDL_Surface *screen,personnage *perso,background *level){
	float i=0 ;
	while (i<=9) {
	i+=1;
	perso->position_personnage.y-=i*1.5;
	perso->position_personnage.x+=i;
	SDL_BlitSurface(level->image_background,NULL,screen,&level->positionbackground);
	SDL_BlitSurface(perso->jump,NULL,screen,&perso->position_personnage);
	SDL_Flip(screen);
	SDL_Delay(20);
	};
	i=0;
	while (i<=9) {
	i+=1;
	perso->position_personnage.y+=i*1.5;
	perso->position_personnage.x+=i;
	SDL_BlitSurface(level->image_background,NULL,screen,&level->positionbackground);
	SDL_BlitSurface(perso->jump,NULL,screen,&perso->position_personnage);
	SDL_Flip(screen);
	SDL_Delay(20);
	};
}

void deplacer_personnage_haut_gauche (SDL_Surface *screen,personnage *perso,background *level){
	float i=0 ;
	while (i<=9) {
	i+=1;
	perso->position_personnage.y-=i*1.5;
	perso->position_personnage.x-=i;
	SDL_BlitSurface(level->image_background,NULL,screen,&level->positionbackground);
	SDL_BlitSurface(perso->jump2,NULL,screen,&perso->position_personnage);
	SDL_Flip(screen);
	SDL_Delay(20);
	};
	i=0;
	while (i<=9) {
	i+=1;
	perso->position_personnage.y+=i*1.5;
	perso->position_personnage.x-=i;
	SDL_BlitSurface(level->image_background,NULL,screen,&level->positionbackground);
	SDL_BlitSurface(perso->jump2,NULL,screen,&perso->position_personnage);
	SDL_Flip(screen);
	SDL_Delay(20);
	};
}

