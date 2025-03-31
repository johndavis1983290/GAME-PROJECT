#ifndef GAME_H
#define GAME_H
#include <string>
#include <SDL_ttf.h>

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
     else if(x > WINDOW_WIDTH - 70){
        x = WINDOW_WIDTH - 70;
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

void initTimer(SDL_Renderer* renderer, TTF_Font* font){
    timer = 60;
    SDL_Color textColor = {255, 255, 255};
    std::string timerText = "Time: " + std::to_string(timer);

    SDL_Surface* TimeSurface = TTF_RenderText_Solid(font, timerText.c_str(), textColor);
    timerTexture = SDL_CreateTextureFromSurface(renderer, TimeSurface);
    SDL_FreeSurface(TimeSurface);
}

void updateTimer(SDL_Renderer* renderer, TTF_Font* font){
    static Uint32 start_time = SDL_GetTicks();
    Uint32 elapsed_time = SDL_GetTicks() - start_time;
    if(elapsed_time >= 1000){
        timer--;
        start_time = SDL_GetTicks();

        SDL_Color textColor = {255, 255, 255};
        std::string timerText = "Time: " + std::to_string(timer);

        SDL_Surface* TimeSurface = TTF_RenderText_Solid(font, timerText.c_str(), textColor);
        SDL_DestroyTexture(timerTexture);
        timerTexture = SDL_CreateTextureFromSurface(renderer, TimeSurface);
        SDL_FreeSurface(TimeSurface);
        if(timer <=0){
        std::cout << "Game Over! Your time to be a fish has been over!!!" << std::endl;
    }
    }
}

void RenderTime(SDL_Renderer* renderer){
   SDL_Rect timerRect = {10, 10, 150, 50};
   SDL_RenderCopy(renderer, timerTexture, NULL, &timerRect);
}

void initScore(SDL_Renderer* renderer, TTF_Font* font){
    score = 0;
    SDL_Color textColor = {255 , 255 , 255};
    std::string scoreText = "Score: " + std::to_string(score);

    SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText.c_str(), textColor);
    scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    SDL_FreeSurface(scoreSurface);
}

void updateScore(SDL_Renderer* renderer, TTF_Font* font){
     SDL_Color textColor = {255, 255, 255};
     std::string scoreText = "Score: " + std::to_string(score);
        SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText.c_str(), textColor);
        SDL_DestroyTexture(scoreTexture);
      scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
        SDL_FreeSurface(scoreSurface);
}

void RenderScore(SDL_Renderer* renderer){
    SDL_Rect scoreRect = {10 + WINDOW_WIDTH - 300, 10, 150, 50};
    SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);
}

#endif // GAME_H
