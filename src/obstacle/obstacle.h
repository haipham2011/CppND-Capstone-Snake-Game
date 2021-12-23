//
// Created by Hai Pham on 23.12.2021.
//

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL_rect.h>
#include <vector>

enum Shape
{
    STAIR,
    CROSS,
    SQUARE
};

class Obstacle {
private:
    Shape _shape;
    Food _food;
    std::vector<std::vector<int>> shapeToVector(Shape &shape);

public:
    Obstacle(Shape &shape, Food &food);
    void updateObstaclePoints(std::vector<SDL_Point> &obstacles);
};


#endif //OBSTACLE_H
