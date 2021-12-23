//
// Created by Hai Pham on 22.12.2021.
//

#ifndef FOOD_H
#define FOOD_H


#include <SDL_rect.h>
#include <utils/color.h>

class Food : SDL_Point {
private:
    Color _color = Color(0, 0, 0, 0);

public:
    Food(int x, int y);
    Food();
    Color getColor() const;
    void setColor(Color color);
    int getX() const;
    int getY() const;
    void setX(const int x);
    void setY(const int y);
};


#endif //FOOD_H
