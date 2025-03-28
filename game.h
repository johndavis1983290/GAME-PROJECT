#ifndef GAME_H
#define GAME_H
#include <string>

#define INITIAL_SPEED 3
#include "def.h"


struct Mouse{
    int x, y;
    int dx = 0;
    int dy = 0;
    int speed = INITIAL_SPEED;
    void move(){
      x += dx;
      y += dy;
    }
    void turnNorth(){
     dy = -speed;
     dx = 0;
    }
    void turnSouth(){
    dy = speed;
    dx = 0;
    }
    void turnWest(){
    dy = 0;
    dx = -speed;
    }
    void turnEast(){
    dy = 0;
    dx = speed;
    }
    void movementRestriction(){
     if(x < 0){
        x = 0;
     }
     else if(x > WINDOW_WIDTH - 150){
        x = WINDOW_WIDTH - 150;
     }
     if(y < 0){
        y = 0;
     }
     else if(y > WINDOW_HEIGHT - 120){
        y = WINDOW_HEIGHT - 120;
     }
    }

};

struct otherfish_movement{
   int x,y;
   int dx;
   int width, height;
   std::string currentDirection;
   void move(){
     x += dx;
     if(x + width < 0 || x > WINDOW_WIDTH){
       resetFishPosition((rand() % 2 == 0) ? "left" : "right");
       currentDirection = (dx > 0) ? "left" : "right";
     }
   }
    void resetFishPosition(std::string direction){
     if(direction == "left"){
        x = -width;
        y = rand() % (WINDOW_HEIGHT - height);
        dx = rand() % 3 + 1;
        currentDirection = "left";
     }
     else if(direction == "right"){
        x = WINDOW_WIDTH;
        y = rand() % (WINDOW_HEIGHT - height);
        dx = -(rand() % 3 + 1);
        currentDirection = "right";
     }
   }

};
void render(const Mouse& mouse, const Graphics& graphics, SDL_Texture* texture){
    SDL_Rect main_character;
    main_character.x = mouse.x;
    main_character.y = mouse.y;
    main_character.w = 100;
    main_character.h = 90;
    SDL_RenderCopy(graphics.renderer, texture, NULL, &main_character);

}

bool checkCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2, KeyPressSurfaces lastHorizontalSurfaces){
      const int MOUTH_WIDTH = 35;
      const int MOUTH_HEIGHT = 15;

      int mouthX, mouthY;
      switch(lastHorizontalSurfaces){
     case RIGHT:
     case RIGHT_UP:
     case RIGHT_DOWN:
        mouthX = x1 + w1 - MOUTH_WIDTH;
        mouthY = y1 + h1 - h1 / 3;
        break;
     case LEFT:
     case LEFT_UP:
     case LEFT_DOWN:
        mouthX = x1;
        mouthY = y1 + h1 - h1 / 3;
        break;
     default:
        mouthX = x1 + w1 - MOUTH_WIDTH;
        mouthY = y1 + h1 - h1 / 3;
        break;
}
     if(mouthX + MOUTH_WIDTH > x2 && x2 + w2 > mouthX && mouthY + MOUTH_HEIGHT > y2 && y2 + h2 > mouthY){
        return true;
     }
     return false;
}
#endif // GAME_H
