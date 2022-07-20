#include "game.h"

#include <iostream>

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      random_type(1, 5),
      food_prob(0, 100) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake, areControlsModified);
    Update();
    renderer.Render(snake, foodList);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  PlaceFood(Food::FoodType::defaultFood);
}

void Game::PlaceFood(Food::FoodType type) {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      foodList.push_back(Food(type, snake, x, y));
      return;
    }
  }
}

void Game::CreateRandomNonDefaultFood() {
  Food::FoodType type = static_cast<Food::FoodType>(random_type(engine));

  if (snake.size < 6 || FoodListContainsType(type)) {
    // Avoid repeated foods at the same time and also add a minimum snake size
    return;
  }

  if (food_prob(engine) < foodCreationThr) {
    // If the generated number is lower than the threshold, create a food item 
    PlaceFood(type);
  }
}

bool Game::FoodListContainsType(Food::FoodType type) {
  for (Food item : foodList) {
    if (item.getType() == type) {
      return true;
    }
  }
  return false;
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int foodIndex = 0;
  bool isFoodEaten = false;

  for (foodIndex = 0; foodIndex < foodList.size(); foodIndex++) {
    Food foodItem = foodList[foodIndex];
    if (foodItem.isEaten()) {
      ApplyFoodEffects(foodItem);
      isFoodEaten = true;
      break;
    }
  }

  //If some food has been eaten, remove it from the list
  // Cannot be removed during the loop to avoid indexing problems
  if (isFoodEaten) {
    foodList.erase(foodList.begin() + foodIndex);
    CreateRandomNonDefaultFood();
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }

void Game::ApplyFoodEffects(Food food) {
  switch (food.getType())
  {
  case Food::FoodType::faster:
    // Increase snake speed
    snake.speed += 0.06;
    score += 5;
    break;
  case Food::FoodType::slower:
    // Decrease snake speed
    snake.speed -= 0.02;
    break;
  case Food::FoodType::drunk:
    // Toggle modifying the controls
    areControlsModified = !areControlsModified;
    score += 5;
    break;
  case Food::FoodType::shrink:
    // Make snake smaller
      snake.ShrinkBody();
    break;
    case Food::FoodType::death:
      // Game over
      score -= 5;
      snake.alive = false;
    break;
  default:
      // Default food, grow snake and increase speed.
      score++;
      // Always place default food when eating one
      PlaceFood();
      // Grow snake and increase speed.
      snake.GrowBody();
      snake.speed += 0.002;
    break;
  }
}