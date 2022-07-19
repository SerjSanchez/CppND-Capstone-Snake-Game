#include "food.h"
#include "SDL.h"
#include "snake.h"

Food::Food(FoodType type, Snake& snake, int x, int y) : snake{&snake}, type{type} {
    foodPoint.x = x;
    foodPoint.y = y;
}

bool Food::isEaten() {
    int new_x = static_cast<int>(snake->head_x);
    int new_y = static_cast<int>(snake->head_y);

    // Check if there's food on the snake's head
    if (foodPoint.x == new_x && foodPoint.y == new_y) {
        return true;
    } else {
        return false;
    }
}

int Food::getX() const {
    return foodPoint.x;
}

int Food::getY() const {
    return foodPoint.y;
}

Food::FoodType Food::getType() {
    return type;
}

bool Food::operator==(const Food& other) const
{
    return (foodPoint.x == other.getX()) && (foodPoint.y == other.getY());
}