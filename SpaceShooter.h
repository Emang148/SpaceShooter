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
	enum motion {
		MOVE_RIGHT = 0,
		MOVE_LEFT = 1,
		SHOOT = 2
	};

	bool motion_detect[3] = { false,false,false };
	bool is_running = false;
	bool mouse_click = false;
	bool start_game = false;//game start variable
	bool shoot_laser = false;
	int speed = 5, laser_speed = 10, laser_count = 0;
	int mouse_x, mouse_y;
	int limit = 10;
	int alien_speed = 3;
	int alien_count = 0;
	bool clicked = false;
	bool aliens_coordinate[3][14] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	}; //0 means there's no alien there, 1 means there is

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* spaceship, * space, * white_stars, * planet1, * planet2, * planet3, * planet4, * planet5, * planet6;
	SDL_Rect ship_des, space_des, star_des, planet1_des, planet2_des, planet3_des, planet4_des, planet5_des, planet6_des;
	SDL_Texture* laser1, * laser2, * laser3; // Only allow 3 users per screen
	SDL_Rect laser_des1, laser_des2, laser_des3;
	SDL_Texture* sButton, * sButtonHover, * sButtonClick;
	SDL_Rect sb_des;
	SDL_Texture* alien;
	SDL_Rect alien_des;
	SDL_Texture* sMenuBG; //Start Menu Background
	SDL_Rect sMenuBG_des;

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


