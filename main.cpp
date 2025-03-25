//#include <iostream>
//#include <SDL.h>
//#include <SDL_image.h>
//#include "def.h"
//#include "Graphic.h"
//#include "game.h"
//#include "loadMedia.h"
//using namespace std;
//
//void waitUntilClicktoStart(SDL_Rect buttonRect){
//    SDL_Event e;
//    bool quit  = false;
//
//    while(!quit){
//        SDL_PollEvent(&e);
//        switch(e.type){
//    case SDL_QUIT:
//        quit = true;
//        break;
//    case SDL_MOUSEBUTTONDOWN:
//        int x,y;
//        SDL_GetMouseState(&x, &y);
//         if(x >=buttonRect.x && x <=buttonRect.x + buttonRect.w && y >=buttonRect.y && y <= buttonRect.y + buttonRect.h){
//            quit = true;
//            break;
//         }
//        }
//        SDL_Delay(10);
//    }
//}
//
//void waitUntilClicktoClose(){
//  bool quit = false;
//  SDL_Event e;
//  while(!quit){
//    SDL_PollEvent(&e);
//    if(e.type == SDL_QUIT){
//        quit = true;
//    }
//}
//}
//
//int main(int argc, char *argv[])
//{
//    Graphics graphics;
//    graphics.init();
//
//    SDL_Texture* background[2];
//    background[0] = graphics.loadTexture("menu.jpg");
//    background[1] = graphics.loadTexture("Background.png");
//    graphics.prepareScene(background[0]);
//    graphics.presentScene();
//
//    SDL_Rect buttonRect = {390,310, 230, 180};
//    waitUntilClicktoStart(buttonRect);
//
//    graphics.prepareScene(background[1]);
//    graphics.presentScene();
//
//    Mouse mouse;
//        SDL_Texture* main_character = graphics.loadTexture("Main_character(2).png");
//        mouse.x = WINDOW_WIDTH / 2;
//        mouse.y = WINDOW_HEIGHT / 2;
//        render(mouse, graphics, main_character);
//
//        graphics.presentScene();
//    fish movement;
//        movement.currentTexture = main_character;
//        movement.rightTexture[0] = graphics.loadTexture("fish_right(1).png");
//        movement.rightTexture[1] = graphics.loadTexture("fish_right(2).png");
//        movement.rightTexture[2] = graphics.loadTexture("fish_right(3).png");
//        movement.rightTexture[3] = graphics.loadTexture("fish_right(4).png");
//        movement.rightTexture[4] = graphics.loadTexture("fish_right(5).png");
//        movement.rightTexture[5] = graphics.loadTexture("fish_right(6).png");
//        movement.rightTexture[6] = graphics.loadTexture("fish_right(7).png");
//        movement.leftTexture[0] = graphics.loadTexture("fish_left(1).png");
//        movement.leftTexture[1] = graphics.loadTexture("fish_left(2).png");
//        movement.leftTexture[2] = graphics.loadTexture("fish_left(3).png");
//        movement.leftTexture[3] = graphics.loadTexture("fish_left(4).png");
//        movement.leftTexture[4] = graphics.loadTexture("fish_left(5).png");
//        movement.leftTexture[5] = graphics.loadTexture("fish_left(6).png");
//        movement.leftTexture[6] = graphics.loadTexture("fish_left(7).png");
//        movement.upTexture[0] = graphics.loadTexture("fish_right(1).png");
//        movement.upTexture[1] = graphics.loadTexture("fish_right(2).png");
//        movement.upTexture[2] = graphics.loadTexture("fish_right(3).png");
//        movement.upTexture[3] = graphics.loadTexture("fish_right(4).png");
//        movement.upTexture[4] = graphics.loadTexture("fish_right(5).png");
//        movement.upTexture[5] = graphics.loadTexture("fish_right(6).png");
//        movement.upTexture[6] = graphics.loadTexture("fish_right(7).png");
//        movement.downTexture[0] = graphics.loadTexture("fish_left(1).png");
//        movement.downTexture[1] = graphics.loadTexture("fish_left(2).png");
//        movement.downTexture[2] = graphics.loadTexture("fish_left(3).png");
//        movement.downTexture[3] = graphics.loadTexture("fish_left(4).png");
//        movement.downTexture[4] = graphics.loadTexture("fish_left(5).png");
//        movement.downTexture[5] = graphics.loadTexture("fish_left(6).png");
//        movement.downTexture[6] = graphics.loadTexture("fish_left(7).png");
//
//    bool quit = false;
//    SDL_Event event;
//    while(!quit){
//        while(SDL_PollEvent(&event)){
//            if(event.type == SDL_QUIT){
//                quit = true;
//            }
//        }
//    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
//
//    if(currentKeyStates[SDL_SCANCODE_UP]){
//        mouse.turnNorth();
//        movement.updateTexture(UP);
//    }
//    if(currentKeyStates[SDL_SCANCODE_DOWN]){
//        mouse.turnSouth();
//        movement.updateTexture(DOWN);
//    }
//    if(currentKeyStates[SDL_SCANCODE_LEFT]){
//        mouse.turnWest();
//        movement.updateTexture(LEFT);
//    }
//    if(currentKeyStates[SDL_SCANCODE_RIGHT]){
//        mouse.turnEast();
//        movement.updateTexture(RIGHT);
//    }
//
//    mouse.move();
//    graphics.prepareScene(background[1]);
//    render(mouse, graphics, movement.currentTexture);
//
//    graphics.presentScene();
//
//    SDL_Delay(15);
//}
//
//    graphics.quitSDL();
//    return 0;
//}
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "def.h"
#include "Graphic.h"
#include "game.h"
#include "loadMedia.h"
using namespace std;

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
    Graphics graphics;
    graphics.init();

    SDL_Texture* background[2];
    background[0] = graphics.loadTexture("menu.jpg");
    background[1] = graphics.loadTexture("Background.png");
    graphics.prepareScene(background[0]);
    graphics.presentScene();

    SDL_Rect buttonRect = {390,310, 230, 180};
    waitUntilClicktoStart(buttonRect);

    graphics.prepareScene(background[1]);
    graphics.presentScene();

    Mouse mouse;
        SDL_Texture* main_character = graphics.loadTexture("Main_character(2).png");
        mouse.x = WINDOW_WIDTH / 2;
        mouse.y = WINDOW_HEIGHT / 2;
        render(mouse, graphics, main_character);

        graphics.presentScene();
    fish movement;
        movement.currentTexture = main_character;
        movement.rightTexture[0] = graphics.loadTexture("fish_right(1).png");
        movement.rightTexture[1] = graphics.loadTexture("fish_right(2).png");
        movement.rightTexture[2] = graphics.loadTexture("fish_right(3).png");
        movement.rightTexture[3] = graphics.loadTexture("fish_right(4).png");
        movement.rightTexture[4] = graphics.loadTexture("fish_right(5).png");
        movement.rightTexture[5] = graphics.loadTexture("fish_right(6).png");
        movement.rightTexture[6] = graphics.loadTexture("fish_right(7).png");
        movement.leftTexture[0] = graphics.loadTexture("fish_left(1).png");
        movement.leftTexture[1] = graphics.loadTexture("fish_left(2).png");
        movement.leftTexture[2] = graphics.loadTexture("fish_left(3).png");
        movement.leftTexture[3] = graphics.loadTexture("fish_left(4).png");
        movement.leftTexture[4] = graphics.loadTexture("fish_left(5).png");
        movement.leftTexture[5] = graphics.loadTexture("fish_left(6).png");
        movement.leftTexture[6] = graphics.loadTexture("fish_left(7).png");
        movement.upTexture[0] = graphics.loadTexture("fish_right(1).png");
        movement.upTexture[1] = graphics.loadTexture("fish_right(2).png");
        movement.upTexture[2] = graphics.loadTexture("fish_right(3).png");
        movement.upTexture[3] = graphics.loadTexture("fish_right(4).png");
        movement.upTexture[4] = graphics.loadTexture("fish_right(5).png");
        movement.upTexture[5] = graphics.loadTexture("fish_right(6).png");
        movement.upTexture[6] = graphics.loadTexture("fish_right(7).png");
        movement.downTexture[0] = graphics.loadTexture("fish_left(1).png");
        movement.downTexture[1] = graphics.loadTexture("fish_left(2).png");
        movement.downTexture[2] = graphics.loadTexture("fish_left(3).png");
        movement.downTexture[3] = graphics.loadTexture("fish_left(4).png");
        movement.downTexture[4] = graphics.loadTexture("fish_left(5).png");
        movement.downTexture[5] = graphics.loadTexture("fish_left(6).png");
        movement.downTexture[6] = graphics.loadTexture("fish_left(7).png");
        movement.right_downTexture[0] = graphics.loadTexture("fish_right(1).png");
        movement.right_downTexture[1] = graphics.loadTexture("fish_right(2).png");
        movement.right_downTexture[2] = graphics.loadTexture("fish_right(3).png");
        movement.right_downTexture[3] = graphics.loadTexture("fish_right(4).png");
        movement.right_downTexture[4] = graphics.loadTexture("fish_right(5).png");
        movement.right_downTexture[5] = graphics.loadTexture("fish_right(6).png");
        movement.right_downTexture[6] = graphics.loadTexture("fish_right(7).png");
        movement.left_upTexture[0] = graphics.loadTexture("fish_left(1).png");
        movement.left_upTexture[1] = graphics.loadTexture("fish_left(2).png");
        movement.left_upTexture[2] = graphics.loadTexture("fish_left(3).png");
        movement.left_upTexture[3] = graphics.loadTexture("fish_left(4).png");
        movement.left_upTexture[4] = graphics.loadTexture("fish_left(5).png");
        movement.left_upTexture[5] = graphics.loadTexture("fish_left(6).png");
        movement.left_upTexture[6] = graphics.loadTexture("fish_left(7).png");


    bool quit = false;
    SDL_Event event;
    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                quit = true;
            }
        }
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    KeyPressSurfaces direction = RIGHT;

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

//    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
//    KeyPressSurfaces direction = RIGHT;
//
//    if(currentKeyStates[SDL_SCANCODE_RIGHT]){
//        mouse.turnEast();
//        movement.updateTexture(RIGHT);
//        if(currentKeyStates[SDL_SCANCODE_UP] && direction == RIGHT){
//            mouse.turnNorth();
//            movement.updateTexture(RIGHT);
//            if(currentKeyStates[SDL_SCANCODE_DOWN]){
//                direction = DOWN;
//            }
//        }
//        if(currentKeyStates[SDL_SCANCODE_DOWN] && direction == DOWN){
//            mouse.turnSouth();
//            movement.updateTexture(RIGHT);
//            if(currentKeyStates[SDL_SCANCODE_UP]){
//                direction = UP;
//            }
//        }
//    }
//    if(currentKeyStates[SDL_SCANCODE_LEFT]){
//        mouse.turnWest();
//        movement.updateTexture(LEFT);
//        if(currentKeyStates[SDL_SCANCODE_UP] && direction == RIGHT){
//            mouse.turnNorth();
//            movement.updateTexture(LEFT);
//            if(currentKeyStates[SDL_SCANCODE_DOWN]){
//                direction = DOWN;
//            }
//        }
//        if(currentKeyStates[SDL_SCANCODE_DOWN] && direction == DOWN){
//            mouse.turnSouth();
//            movement.updateTexture(LEFT);
//            if(currentKeyStates[SDL_SCANCODE_UP]){
//                direction = UP;
//            }
//        }
//    }


    mouse.movementRestriction();
    mouse.move();
    graphics.prepareScene(background[1]);
    render(mouse, graphics, movement.currentTexture);

    graphics.presentScene();

    SDL_Delay(15);
}

    graphics.quitSDL();
    return 0;
}
