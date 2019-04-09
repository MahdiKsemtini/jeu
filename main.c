#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "fichier.h"

int main() {
	SDL_Surface *screen;
	background menu;
	background level;
	background parametre;
	bouton play;
	bouton play2;
	bouton settings;
	bouton settings2;
	bouton exit;
	bouton exit2;
	SDL_Event event;
	IMG_INIT_PNG;
	int bool_menu=1;
	int done = 1;
	Mix_Music *music;

	if(SDL_Init(SDL_INIT_VIDEO) !=0) {
		printf("unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}

	screen=SDL_SetVideoMode(640,360,0,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(screen==NULL) {
		printf("Unable to set video mode:%s\n",SDL_GetError());
		return 1;
	}

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
		printf("%s",Mix_GetError());
	}

	music=Mix_LoadMUS("music.mp3");
	Mix_PlayMusic(music,-1);

	initialiser_background_menu(&menu);
	initialiser_background_level(&level);
	initialiser_background_parametre(&parametre);
	initialiser_bouton_play(&play);
	initialiser_bouton_play2(&play2);
	initialiser_bouton_settings(&settings);
	initialiser_bouton_settings2(&settings2);
	initialiser_bouton_exit(&exit);
	initialiser_bouton_exit2(&exit2);
	affichage_background_menu(screen,&menu);
	affichage_bouton_play(screen,&play);
	affichage_bouton_settings(screen,&settings);
	affichage_bouton_exit(screen,&exit);
	
	while (done) {
		SDL_Flip(screen);
		SDL_PollEvent(&event);
		switch(event.type) {
			case SDL_QUIT:
				done=0;
				break;
			case SDL_KEYDOWN: {
				if(event.key.keysym.sym == SDLK_ESCAPE)
					done=0; }
				break;
			case SDL_MOUSEMOTION: {
				if (bool_menu==1) {
					if((event.motion.x>225)&&(event.motion.x<395)&&(event.motion.y>70)&&(event.motion.y<130)){
						affichage_background_menu(screen,&menu);
						affichage_bouton_play2(screen,&play2);
						affichage_bouton_settings(screen,&settings);
						affichage_bouton_exit(screen,&exit);
					}
					else if((event.motion.x>225)&&(event.motion.x<395)&&(event.motion.y>165)&&(event.motion.y<225)){
						affichage_background_menu(screen,&menu);
						affichage_bouton_play(screen,&play);
						affichage_bouton_settings2(screen,&settings2);
						affichage_bouton_exit(screen,&exit);
					}
					else if((event.motion.x>225)&&(event.motion.x<395)&&(event.motion.y>240)&&(event.motion.y<300)){
						affichage_background_menu(screen,&menu);
						affichage_bouton_play(screen,&play);
						affichage_bouton_settings(screen,&settings);
						affichage_bouton_exit2(screen,&exit2);
					}
					else {
						affichage_background_menu(screen,&menu);
						affichage_bouton_play(screen,&play);
						affichage_bouton_settings(screen,&settings);
						affichage_bouton_exit(screen,&exit);
					}
				}
				break;
			}
			case SDL_MOUSEBUTTONUP: {
				if (bool_menu==1) {
					if((event.motion.x>225)&&(event.motion.x<395)&&(event.motion.y>90)&&(event.motion.y<150)){
						affichage_background_level(screen,&level); 
						bool_menu=0;
					}
					else if((event.motion.x>225)&&(event.motion.x<395)&&(event.motion.y>240)&&(event.motion.y<300)){
						done=0;
					}
					else if ((event.motion.x>225)&&(event.motion.x<395)&&(event.motion.y>165)&&(event.motion.y<225)){
						affichage_background_parametre(screen,&parametre);
						bool_menu=0;
					}
				}
				break;
			}
		}
	}
}
