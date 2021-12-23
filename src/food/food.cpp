//
// Created by Hai Pham on 22.12.2021.
//

#include "food.h"
Food::Food(){}

Food::Food(int x, int y) {
    this->x = x;
    this->y = y;
}

Color Food::getColor() const {
    return _color;
}

void Food::setColor(Color color) {
    _color = color;
}

int Food::getX() const {
    return this->x;
}

int Food::getY() const {
    return this->y;
}

void Food::setX(const int x) {
    this->x = x;
}

void Food::setY(const int y) {
    this->y = y;
}