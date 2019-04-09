#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct {
	SDL_Surface *image_background;
	SDL_Rect positionbackground;
}background;

typedef struct {
	SDL_Surface *image_bouton;
	SDL_Rect positionbouton;
}bouton;


void initialiser_background_menu(background *menu);
void affichage_background_menu(SDL_Surface *screen,background *menu);
void initialiser_background_level(background *level);
void affichage_background_level(SDL_Surface *screen,background *level);
void initialiser_background_parametre(background *parametre);
void affichage_background_parametre(SDL_Surface *screen,background *parametre);
void initialiser_bouton_play(bouton *play);
void initialiser_bouton_play2(bouton *play2);
void affichage_bouton_play(SDL_Surface *screen,bouton *play);
void affichage_bouton_play2(SDL_Surface *screen,bouton *play2);
void initialiser_bouton_settings(bouton *settings);
void initialiser_bouton_settings2(bouton *settings2);
void affichage_bouton_settings(SDL_Surface *screen,bouton *settings);
void affichage_bouton_settings2(SDL_Surface *screen,bouton *settings2);
void initialiser_bouton_exit(bouton *exit);
void initialiser_bouton_exit2(bouton *exit2);
void affichage_bouton_exit(SDL_Surface *screen,bouton *exit);
void affichage_bouton_exit2(SDL_Surface *screen,bouton *exit2);

#endif
