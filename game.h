#ifndef GAME_H
#define GAME_H

#define INITIAL_SPEED 3
#include "def.h"
#include <string>
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
void render(const Mouse& mouse, const Graphics& graphics, SDL_Texture* texture){
    SDL_Rect main_character;
    main_character.x = mouse.x;
    main_character.y = mouse.y;
    main_character.w = 150;
    main_character.h = 120;
    SDL_RenderCopy(graphics.renderer, texture, NULL, &main_character);

}
struct Other_fish{
   int x,y;
   int dx, dy;
   int width, height;

   void move(){
     x += dx;
     y += dy;
     string direction = right;
     if(x < 0){
        direction = "left";
       resetFishPosition(direction);
     }
     else if(x > WINDOW_WIDTH){
         direction = right;
        resetFishPosition(direction);
     }
   }
    void resetFishPosition(string direction){
     if(direction == "left"){
        fish.x = -WINDOW_WIDTH;
        fish.y = rand() % WINDOW_HEIGHT;
        fish.dx = rand() % 3 + 1;
        fish.dy = rand() % 3 - 1;
     }
     else if(direction == "right"){
        fish.x = -WINDOW_WIDTH;
        fish.y = rand() % WINDOW_HEIGHT;
        fish.dx = -(rand() % 3 + 1);
        fish.dy = rand() % 3 - 1;
     }
   }
};
#endif // GAME_H
