#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <ctime>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "def.h"
#include "Graphic.h"
#include "game.h"
#include "loadMedia.h"

using namespace std;

int score = 0;
int timer = 60;
SDL_Texture* timerTexture = nullptr;
SDL_Texture* scoreTexture = nullptr;

void waitUntilClicktoStart(SDL_Rect buttonRect){
    SDL_Event e;
    bool quit  = false;

    while(!quit){
        SDL_PollEvent(&e);
        switch(e.type){
    case SDL_QUIT:
        quit = true;
        break;
    case SDL_MOUSEBUTTONDOWN:
        int x,y;
        SDL_GetMouseState(&x, &y);
         if(x >=buttonRect.x && x <=buttonRect.x + buttonRect.w && y >=buttonRect.y && y <= buttonRect.y + buttonRect.h){
            quit = true;
            break;
         }
        }
        SDL_Delay(10);
    }
}

void waitUntilClicktoClose(){
  bool quit = false;
  SDL_Event e;
  while(!quit){
    SDL_PollEvent(&e);
    if(e.type == SDL_QUIT){
        quit = true;
    }
}
}

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Graphics graphics;
    graphics.init();

    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
        SDL_Log("SDL_mixer could not initialize! SDL_mixer Error: %s", Mix_GetError());
        return 1;
    }
    Mix_Music* backgroundMusic = Mix_LoadMUS("music/background_sound.mp3");
      if(backgroundMusic == nullptr){
        SDL_Log("Failed to load background music! SDL_mixer Error: %s", Mix_GetError());
        return 1;
      }
      Mix_VolumeMusic(64);
      if(Mix_PlayMusic(backgroundMusic, -1)== -1){
        SDL_Log("Failed to play background music! SDL_mixer Error: %s", Mix_GetError());
        return 1;
      }


    if(TTF_Init() == -1){
        cout << "TTF_Init Error: " << TTF_GetError() << endl;
        return 1;
    }
    TTF_Font* font = TTF_OpenFont("WordFont/MJ-Megants.ttf",24);
    if(font == nullptr){
        cout << "Failed to load font: " << TTF_GetError() << endl;
        return 1;
    }
    initTimer(graphics.renderer, font);
    initScore(graphics.renderer, font);

    SDL_Texture* background[3];
    background[0] = graphics.loadTexture("Background/menu.jpg");
    background[1] = graphics.loadTexture("Background/background_2.png");
    background[2] = graphics.loadTexture("Background/SEE YOU NEXT TIME!.png");
    graphics.prepareScene(background[0]);
    graphics.presentScene();

    SDL_Rect buttonRect = {390,310, 230, 180};
    waitUntilClicktoStart(buttonRect);

    graphics.prepareScene(background[1]);
    graphics.presentScene();

    Mouse mouse;
        SDL_Texture* main_character = graphics.loadTexture("main_fish/Main_character(2).png");
        mouse.x = WINDOW_WIDTH / 2;
        mouse.y = WINDOW_HEIGHT / 2;
        render(mouse, graphics, main_character);

        graphics.presentScene();
    main_fish movement;
        movement.currentTexture = main_character;
        movement.rightTexture[0] = graphics.loadTexture("main_fish/fish_right(1).png");
        movement.rightTexture[1] = graphics.loadTexture("main_fish/fish_right(2).png");
        movement.rightTexture[2] = graphics.loadTexture("main_fish/fish_right(3).png");
        movement.rightTexture[3] = graphics.loadTexture("main_fish/fish_right(4).png");
        movement.rightTexture[4] = graphics.loadTexture("main_fish/fish_right(5).png");
        movement.rightTexture[5] = graphics.loadTexture("main_fish/fish_right(6).png");
        movement.rightTexture[6] = graphics.loadTexture("main_fish/fish_right(7).png");
        movement.leftTexture[0] = graphics.loadTexture("main_fish/fish_left(1).png");
        movement.leftTexture[1] = graphics.loadTexture("main_fish/fish_left(2).png");
        movement.leftTexture[2] = graphics.loadTexture("main_fish/fish_left(3).png");
        movement.leftTexture[3] = graphics.loadTexture("main_fish/fish_left(4).png");
        movement.leftTexture[4] = graphics.loadTexture("main_fish/fish_left(5).png");
        movement.leftTexture[5] = graphics.loadTexture("main_fish/fish_left(6).png");
        movement.leftTexture[6] = graphics.loadTexture("main_fish/fish_left(7).png");
        movement.upTexture[0] = graphics.loadTexture("main_fish/fish_right(1).png");
        movement.upTexture[1] = graphics.loadTexture("main_fish/fish_right(2).png");
        movement.upTexture[2] = graphics.loadTexture("main_fish/fish_right(3).png");
        movement.upTexture[3] = graphics.loadTexture("main_fish/fish_right(4).png");
        movement.upTexture[4] = graphics.loadTexture("main_fish/fish_right(5).png");
        movement.upTexture[5] = graphics.loadTexture("main_fish/fish_right(6).png");
        movement.upTexture[6] = graphics.loadTexture("main_fish/fish_right(7).png");
        movement.downTexture[0] = graphics.loadTexture("main_fish/fish_left(1).png");
        movement.downTexture[1] = graphics.loadTexture("main_fish/fish_left(2).png");
        movement.downTexture[2] = graphics.loadTexture("main_fish/fish_left(3).png");
        movement.downTexture[3] = graphics.loadTexture("main_fish/fish_left(4).png");
        movement.downTexture[4] = graphics.loadTexture("main_fish/fish_left(5).png");
        movement.downTexture[5] = graphics.loadTexture("main_fish/fish_left(6).png");
        movement.downTexture[6] = graphics.loadTexture("main_fish/fish_left(7).png");
        movement.right_downTexture[0] = graphics.loadTexture("main_fish/fish_right(1).png");
        movement.right_downTexture[1] = graphics.loadTexture("main_fish/fish_right(2).png");
        movement.right_downTexture[2] = graphics.loadTexture("main_fish/fish_right(3).png");
        movement.right_downTexture[3] = graphics.loadTexture("main_fish/fish_right(4).png");
        movement.right_downTexture[4] = graphics.loadTexture("main_fish/fish_right(5).png");
        movement.right_downTexture[5] = graphics.loadTexture("main_fish/fish_right(6).png");
        movement.right_downTexture[6] = graphics.loadTexture("main_fish/fish_right(7).png");
        movement.left_upTexture[0] = graphics.loadTexture("main_fish/fish_left(1).png");
        movement.left_upTexture[1] = graphics.loadTexture("main_fish/fish_left(2).png");
        movement.left_upTexture[2] = graphics.loadTexture("main_fish/fish_left(3).png");
        movement.left_upTexture[3] = graphics.loadTexture("main_fish/fish_left(4).png");
        movement.left_upTexture[4] = graphics.loadTexture("main_fish/fish_left(5).png");
        movement.left_upTexture[5] = graphics.loadTexture("main_fish/fish_left(6).png");
        movement.left_upTexture[6] = graphics.loadTexture("main_fish/fish_left(7).png");

    const int NUM_FISH1 = 5;
    otherfish_movement movement1[NUM_FISH1];
    otherfish fish1[NUM_FISH1];
      for(int i=0; i< NUM_FISH1; i++){
       movement1[i].width = 45;
       movement1[i].height = 45;
       movement1[i].resetFishPosition((rand() % 2 == 0) ? "left" : "right");

       fish1[i].currentTexture = graphics.loadTexture("other_fish/otherfish_right(1).png");
       fish1[i].leftTexture[0] = graphics.loadTexture("other_fish/otherfish_left(1).png");
       fish1[i].leftTexture[1] = graphics.loadTexture("other_fish/otherfish_left(2).png");
       fish1[i].leftTexture[2] = graphics.loadTexture("other_fish/otherfish_left(3).png");
       fish1[i].leftTexture[3] = graphics.loadTexture("other_fish/otherfish_left(4).png");
       fish1[i].leftTexture[4] = graphics.loadTexture("other_fish/otherfish_left(5).png");
       fish1[i].leftTexture[5] = graphics.loadTexture("other_fish/otherfish_left(6).png");
       fish1[i].rightTexture[0] = graphics.loadTexture("other_fish/otherfish_right(1).png");
       fish1[i].rightTexture[1] = graphics.loadTexture("other_fish/otherfish_right(2).png");
       fish1[i].rightTexture[2] = graphics.loadTexture("other_fish/otherfish_right(3).png");
       fish1[i].rightTexture[3] = graphics.loadTexture("other_fish/otherfish_right(4).png");
       fish1[i].rightTexture[4] = graphics.loadTexture("other_fish/otherfish_right(5).png");
       fish1[i].rightTexture[5] = graphics.loadTexture("other_fish/otherfish_right(6).png");
      }
    const int NUM_FISH2 = 5;
    otherfish_movement movement2[NUM_FISH2];
    otherfish fish2[NUM_FISH2];
      for(int i=0; i < NUM_FISH2; i++){
       movement2[i].width = 160;
       movement2[i].height = 120;
       movement2[i].resetFishPosition((rand() % 2 == 0) ? "left" : "right");

       fish2[i].currentTexture = graphics.loadTexture("other_fish/otherfish(2)_right(1).png");
       fish2[i].leftTexture[0] = graphics.loadTexture("other_fish/otherfish(2)_left(1).png");
       fish2[i].leftTexture[1] = graphics.loadTexture("other_fish/otherfish(2)_left(2).png");
       fish2[i].leftTexture[2] = graphics.loadTexture("other_fish/otherfish(2)_left(3).png");
       fish2[i].leftTexture[3] = graphics.loadTexture("other_fish/otherfish(2)_left(4).png");
       fish2[i].leftTexture[4] = graphics.loadTexture("other_fish/otherfish(2)_left(5).png");
       fish2[i].leftTexture[5] = graphics.loadTexture("other_fish/otherfish(2)_left(6).png");
       fish2[i].rightTexture[0] = graphics.loadTexture("other_fish/otherfish(2)_right(1).png");
       fish2[i].rightTexture[1] = graphics.loadTexture("other_fish/otherfish(2)_right(2).png");
       fish2[i].rightTexture[2] = graphics.loadTexture("other_fish/otherfish(2)_right(3).png");
       fish2[i].rightTexture[3] = graphics.loadTexture("other_fish/otherfish(2)_right(4).png");
       fish2[i].rightTexture[4] = graphics.loadTexture("other_fish/otherfish(2)_right(5).png");
       fish2[i].rightTexture[5] = graphics.loadTexture("other_fish/otherfish(2)_right(6).png");
      }
    bool quit = false;
    bool gameOver = false;
    SDL_Event event;
    KeyPressSurfaces lastHorizontalSurfaces = RIGHT;
    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
            }
        }
    if(!gameOver){
    KeyPressSurfaces direction = lastHorizontalSurfaces;
    updateTimer(graphics.renderer, font);
    updateScore(graphics.renderer, font);
    if(timer <=0){
        timer = 0;
        gameOver = true;
    }
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if(currentKeyStates[SDL_SCANCODE_UP]){
        if(currentKeyStates[SDL_SCANCODE_RIGHT]){
            direction = RIGHT_UP;
             mouse.turnEast();
            movement.updateTexture(direction);
        }
        else if(currentKeyStates[SDL_SCANCODE_LEFT]){
            direction = LEFT_UP;
            mouse.turnWest();
            movement.updateTexture(direction);
        }
        else{
            direction = UP;
            mouse.turnNorth();
            movement.updateTexture(direction);
        }
    }
    if(currentKeyStates[SDL_SCANCODE_DOWN]){
        if(currentKeyStates[SDL_SCANCODE_RIGHT]){
            direction = RIGHT_DOWN;
            mouse.turnEast();
            movement.updateTexture(direction);
        }
        else if(currentKeyStates[SDL_SCANCODE_LEFT]){
            direction = LEFT_DOWN;
            mouse.turnWest();
            movement.updateTexture(direction);
        }
        else{
            direction = DOWN;
            mouse.turnSouth();
            movement.updateTexture(direction);
        }
    }
    if(currentKeyStates[SDL_SCANCODE_LEFT] && direction != LEFT_UP && direction != LEFT_DOWN){
        mouse.turnWest();
        direction = LEFT;
        movement.updateTexture(direction);
    }
    if(currentKeyStates[SDL_SCANCODE_RIGHT] && direction != RIGHT_UP && direction != RIGHT_DOWN){
        mouse.turnEast();
        direction = RIGHT;
        movement.updateTexture(direction);
    }

    mouse.movementRestriction();
    mouse.move();

    for(int i=0; i< NUM_FISH1; i++){
    movement1[i].move();
    fish1[i].updateTexture(movement1[i].currentDirection);
    movement2[i].move();
    fish2[i].updateTexture(movement2[i].currentDirection);
    }
    graphics.prepareScene(background[1]);
    render(mouse, graphics, movement.currentTexture);
    for(int i=0; i< NUM_FISH1; i++){
    graphics.renderTexture(fish1[i].currentTexture, movement1[i].x, movement1[i].y, movement1[i].width, movement1[i].height, graphics.renderer);
    graphics.renderTexture(fish2[i].currentTexture, movement2[i].x, movement2[i].y, movement2[i].width, movement2[i].height, graphics.renderer);
      if (checkCollision(mouse.x, mouse.y, 100, 90, movement1[i].x, movement1[i].y, movement1[i].width, movement1[i].height, direction)) {
                movement1[i].resetFishPosition((rand() % 2 == 0) ? "left" : "right");
                timer += 2;
                score += 10;
                Mix_Chunk* biteMusic = Mix_LoadWAV("music/bite_sound.mp3");
                Mix_VolumeChunk(biteMusic, 50);
                if(biteMusic == nullptr){
                   SDL_Log("Failed to load background music! SDL_mixer Error: %s", Mix_GetError());
                }
                else{
                   if(Mix_PlayChannel(-1, biteMusic, 0) == -1) {
                   SDL_Log("Failed to play bite sound! SDL_mixer Error: %s", Mix_GetError());
        }
}
    }
       if (checkCollision(mouse.x, mouse.y, 100, 90, movement2[i].x, movement2[i].y, movement2[i].width, movement2[i].height, direction)) {
                score = 0;
                Mix_Music* loseMusic = Mix_LoadMUS("music/lost_sound.wav");
                Mix_VolumeMusic(50);
                if(loseMusic == nullptr){
                    SDL_Log("Failed to load background music! SDL_mixer Error: %s", Mix_GetError());
                }
                if(Mix_PlayMusic(loseMusic, 0)== -1){
                    SDL_Log("Failed to play background music! SDL_mixer Error: %s", Mix_GetError());
                    return 1;
      }
                gameOver = true;
            }
    }
    }
    else{
        graphics.prepareScene(background[2]);
        graphics.presentScene();
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }
    }
    RenderTime(graphics.renderer);
    RenderScore(graphics.renderer);
    graphics.presentScene();

    SDL_Delay(15);
}
    TTF_CloseFont(font);
    TTF_Quit();
    Mix_FreeMusic(backgroundMusic);
    Mix_CloseAudio();
    graphics.quitSDL();
    return 0;
}
