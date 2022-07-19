#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>

#include "SDL.h"
#include "controller.h"
#include "food.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  std::vector<Food> foodList;
  int foodCreationThr = 99; // Threshold to control randomness of created non-default food items
  bool areControlsModified{false};

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  std::uniform_int_distribution<int> random_type;
  std::uniform_int_distribution<int> food_prob;


  int score{0};

  void PlaceFood(Food::FoodType type);
  void Update();
  void ApplyFoodEffects(Food food);
  void CreateRandomNonDefaultFood();
  bool FoodListContainsType(Food::FoodType type);
};

#endif