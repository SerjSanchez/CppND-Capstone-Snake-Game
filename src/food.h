#ifndef FOOD_H
#define FOOD_H

#include "SDL.h"
#include "snake.h"

class Food {

public: 

    enum class FoodType { defaultFood, faster, slower, drunk, shrink, death};

    Food(FoodType type, Snake& snake, int x, int y);
    bool isEaten();

    int getX() const;
    int getY() const;
    FoodType getType();

    bool operator==(const Food& other) const;

private:
    SDL_Point foodPoint;
    FoodType type;
    Snake* snake;
};

#endif