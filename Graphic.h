
#ifndef _GRAPHIC__H
#define _GRAPHIC__H

#include <SDL.h>
#include <SDL_image.h>
#include "def.h"

struct Graphics{
    SDL_Renderer *renderer;
    SDL_Window *window;

    void logErrorAndExist(const char* msg, const char* error){
       SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "%s: %s", msg, error);
       SDL_Quit();
    }
    void init() {
      if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
       logErrorAndExist("SDL_Init", SDL_GetError());
      }
       window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
       if(window == nullptr){
        logErrorAndExist("SDL_CreateWindow", SDL_GetError());
       }

       if(!IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG)){
        logErrorAndExist("IMG_Init", IMG_GetError());
       }

       renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
       if(renderer==nullptr){
        logErrorAndExist("SDL_CreateRenderer", SDL_GetError());
       }
       SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"linear");
       SDL_SetHint(SDL_HINT_VIDEO_MINIMIZE_ON_FOCUS_LOSS, "0");
       SDL_SetHint(SDL_HINT_GRAB_KEYBOARD, "0");
       SDL_SetHint(SDL_HINT_IDLE_TIMER_DISABLED, "0");
       SDL_SetHint(SDL_HINT_ALLOW_TOPMOST,"0");
       SDL_RenderSetLogicalSize(renderer, WINDOW_WIDTH, WINDOW_HEIGHT);
    }
    void prepareScene(SDL_Texture* background){
       SDL_RenderClear(renderer);
       SDL_RenderCopy(renderer, background, NULL, NULL);
    }
    void presentScene(){
        SDL_RenderPresent(renderer);
    }

    SDL_Texture *loadTexture(const char* filename){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);
        SDL_Texture* texture = IMG_LoadTexture(renderer, filename);
        if(texture==nullptr){
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Loading texture %s", IMG_GetError());
        }
        return texture;
    }
       void renderTexture(SDL_Texture* texture, int x, int y, int width, int height, SDL_Renderer* renderer){
       SDL_Rect animator;
       animator.x = x;
       animator.y = y;
       animator.w = width;
       animator.h = height;
       SDL_RenderCopy(renderer, texture, NULL, &animator);
    }
    void drawRect(int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b) {
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;

        SDL_SetRenderDrawColor(renderer, r, g, b, 255);  // Màu của khung (RGB)
        SDL_RenderDrawRect(renderer, &rect);
    }
        void quitSDL(){
       IMG_Quit();
       SDL_DestroyRenderer(renderer);
       SDL_DestroyWindow(window);
       SDL_Quit();
    }
};
#endif
