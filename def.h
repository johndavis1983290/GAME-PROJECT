
#ifndef _DEF__H
#define _DEF__H

const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 900;
const char* WINDOW_TITLE = "Big Fish - Small Fish";
extern int score;
extern int timer;
extern SDL_Texture* timerTexture;
extern SDL_Texture* scoreTexture;

enum KeyPressSurfaces{
     UP,
     DOWN,
     LEFT,
     RIGHT,
     RIGHT_DOWN,
     RIGHT_UP,
     LEFT_DOWN,
     LEFT_UP
};
#endif
