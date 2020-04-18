//header file
#include <iostream>
#include <SDL.h> //SDL library
#include <SDL_image.h> //SDL library for image
#include <SDL_ttf.h> //True type font 
#include <windows.h> //Sleep
#include <time.h> // time
#include <stdlib.h>  //rand and srand function
#include <string> //to_string and c_str()
using namespace std;
//header file
#ifndef SPACESHOOTER
#define SPACESHOOTER

class Game {
private:
	//----- Start Game Variables ----- //
	enum motion {
		MOVE_RIGHT = 0,
		MOVE_LEFT = 1,
		SHOOT = 2
	};
	
	bool clicked = false;
	bool motion_detect[3] = { false,false,false };
	bool is_running = false;
	bool mouse_click = false;
	bool start_game = false;//game start variable
	
	//----- Laser Variables ------//
	int laser_speed = 3; 
	clock_t laser_time = clock(); //the controller of laser shoot rate
								  //use clock instead of time because we 
								  //need to keep track of decimal seconds
	
	int current_x[5] = { 0,
						 0,
						 0,
						 0,
						 0  }; //the location of each laser at the start
	
	int velocity[5] = {  0,
						 0,
						 0,
						 0,
						 0  }; // the velocity of each laser at the start
						 
	bool laser_coordinate[5] = { 0,
								 0,
								 0,
								 0,
								 0 }; //keep track of how many laser have been shot
	//---------------//
	int ship_speed = 5;
	int mouse_x, mouse_y; //keep track of current mouse x and y location
	//---------------//
	
	//----- Alien Variables -----//
	int alien_limit = 10, alien_speed = 3,  alien_count = 0;
	
	bool aliens_coordinate[3][14] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	}; //0 means there's no alien there, 1 means there is

	//----- SDL Variables -----//
	//----- General section -----//
	SDL_Window* window;
	SDL_Renderer* renderer;
	//---- Picture and coordinate for planets spaceship and space ----//
	SDL_Texture* spaceship, * space, * white_stars, * planet1, * planet2, * planet3, * planet4, * planet5, * planet6;
	SDL_Rect ship_des, space_des, star_des, planet1_des, planet2_des, planet3_des, planet4_des, planet5_des, planet6_des;
	//---- Picture and coordinate for laser ----//
	SDL_Texture* laser; 
	SDL_Rect laser_des;
	//---- Picture and coordinate for button ----//
	SDL_Texture* sMenuBG, * sButton, * sButtonHover, * sButtonClick;
	SDL_Rect sBG_des;
	SDL_Rect sMenuBG_des;
	//---- Picture and coordinate for alien ----//
	SDL_Texture* alien;
	SDL_Rect alien_des;
	
	//---- Score Variables ----//
	int current_score = 0;
	SDL_Rect score_rect;
	TTF_Font* my_font; //load our text
	SDL_Color my_color;//set the color of font to white
	SDL_Texture* score_text;
	string text = "Score is " + to_string(current_score);
	int increment_value = 0;
	int time_now = time(NULL);
	

public:
	Game();
	void loadImages_setInfos();
	void setDes(SDL_Rect& rect, int hori, int vert, int width, int height);
	void handle_event();
	void update();
	void renderMenu();
	void render();
	void spawn_alien();
	bool is_it_running();
	void clean();

	~Game();
};

#endif



