#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
                                 Snake::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake, bool areControlsModified) const {

  auto up = areControlsModified ? Snake::Direction::kDown : Snake::Direction::kUp;
  auto down = areControlsModified ? Snake::Direction::kUp : Snake::Direction::kDown;
  auto left = areControlsModified ? Snake::Direction::kRight : Snake::Direction::kLeft;
  auto right = areControlsModified ? Snake::Direction::kLeft : Snake::Direction::kRight;


  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, up, down);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, down, up);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, left, right);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, right, left);
          break;
      }
    }
  }
}