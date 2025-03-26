#ifndef LOADMEDIA_H
#define LOADMEDIA_H

#include "Graphic.h"
#include <string>

struct main_fish{
   SDL_Texture* rightTexture[7];
   SDL_Texture* leftTexture[7];
   SDL_Texture* upTexture[7];
   SDL_Texture* downTexture[7];
   SDL_Texture* right_downTexture[7];
   SDL_Texture* left_upTexture[7];

   SDL_Texture* currentTexture;
   KeyPressSurfaces direction = RIGHT;

   int textureIndex = 0; //Xac dinh texture nao hien thi

   void updateTexture(KeyPressSurfaces key){
       static int counter = 0;
     if(counter >=2){
        counter = 0;
        textureIndex++;
     }
     if(textureIndex >= 7){
        textureIndex = 0;
     }
     switch(key){
     case UP:
        currentTexture = upTexture[textureIndex];
        break;
     case DOWN:
        currentTexture = downTexture[textureIndex];
        break;
     case LEFT:
        currentTexture = leftTexture[textureIndex];
        break;
     case RIGHT:
        currentTexture = rightTexture[textureIndex];
        break;
     case RIGHT_DOWN:
        currentTexture = right_downTexture[textureIndex];
        break;
     case RIGHT_UP:
        currentTexture = rightTexture[textureIndex];
        break;
     case LEFT_DOWN:
        currentTexture = leftTexture[textureIndex];
        break;
     case LEFT_UP:
        currentTexture = left_upTexture[textureIndex];
        break;
   }
   counter++;
   }

};

struct otherfish{
   SDL_Texture* rightTexture[6];
   SDL_Texture* leftTexture[6];
   SDL_Texture* currentTexture;

   int textureIndex = 0;
   void updateTexture(std::string direction){
   if(textureIndex >= 6){
    textureIndex = 0;
   }
    if(direction == "left"){
      currentTexture = rightTexture[textureIndex];
      textureIndex++;
    }
    else if(direction == "right"){
      currentTexture = leftTexture[textureIndex];
      textureIndex++;
   }
   else{
    currentTexture = rightTexture[textureIndex];
    textureIndex++;
   }
   }
};
#endif // LOADMEDIA_h
