#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fichier.h"

void initialiser_background_menu(background *menu) {
	menu->positionbackground.x=0;
	menu->positionbackground.y=0;
	menu->image_background = IMG_Load("background.png");
}

void affichage_background_menu(SDL_Surface *screen,background *menu){
	SDL_BlitSurface(menu->image_background,NULL,screen,&menu->positionbackground);
}

void initialiser_background_level(background *level) {
	level->positionbackground.x=0;
	level->positionbackground.y=0;
	level->image_background = IMG_Load("map.png");
}

void affichage_background_level(SDL_Surface *screen,background *level){
	SDL_BlitSurface(level->image_background,NULL,screen,&level->positionbackground);
}

void initialiser_background_parametre(background *parametre) {
	parametre->positionbackground.x=0;
	parametre->positionbackground.y=0;
	parametre->image_background = IMG_Load("parametre.png");
}

void affichage_background_parametre(SDL_Surface *screen,background *parametre){
	SDL_BlitSurface(parametre->image_background,NULL,screen,&parametre->positionbackground);
}

void initialiser_bouton_play(bouton *play) {
	play->positionbouton.x=225;
	play->positionbouton.y=70;
	play->image_bouton = IMG_Load("play.png");
}

void initialiser_bouton_play2(bouton *play2) {
	play2->positionbouton.x=225;
	play2->positionbouton.y=70;
	play2->image_bouton = IMG_Load("play2.png");
}

void affichage_bouton_play(SDL_Surface *screen,bouton *play){
	SDL_BlitSurface(play->image_bouton,NULL,screen,&play->positionbouton);
}

void affichage_bouton_play2(SDL_Surface *screen,bouton *play2){
	SDL_BlitSurface(play2->image_bouton,NULL,screen,&play2->positionbouton);
}

void initialiser_bouton_settings(bouton *settings) {
	settings->positionbouton.x=225;
	settings->positionbouton.y=145;
	settings->image_bouton = IMG_Load("settings.png");
}

void initialiser_bouton_settings2(bouton *settings2) {
	settings2->positionbouton.x=225;
	settings2->positionbouton.y=145;
	settings2->image_bouton = IMG_Load("settings2.png");
}

void affichage_bouton_settings(SDL_Surface *screen,bouton *settings){
	SDL_BlitSurface(settings->image_bouton,NULL,screen,&settings->positionbouton);
}

void affichage_bouton_settings2(SDL_Surface *screen,bouton *settings2){
	SDL_BlitSurface(settings2->image_bouton,NULL,screen,&settings2->positionbouton);
}

void initialiser_bouton_exit(bouton *exit) {
	exit->positionbouton.x=225;
	exit->positionbouton.y=220;
	exit->image_bouton = IMG_Load("exit.png");
}

void initialiser_bouton_exit2(bouton *exit2) {
	exit2->positionbouton.x=225;
	exit2->positionbouton.y=220;
	exit2->image_bouton = IMG_Load("exit2.png");
}

void affichage_bouton_exit(SDL_Surface *screen,bouton *exit){
	SDL_BlitSurface(exit->image_bouton,NULL,screen,&exit->positionbouton);
}

void affichage_bouton_exit2(SDL_Surface *screen,bouton *exit2){
	SDL_BlitSurface(exit2->image_bouton,NULL,screen,&exit2->positionbouton);
}

