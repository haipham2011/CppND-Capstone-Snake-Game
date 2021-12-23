//
// Created by Hai Pham on 23.12.2021.
//

#include <food/food.h>
#include "obstacle.h"

std::vector<std::vector<int>> Obstacle::shapeToVector(Shape &shape){
    if (shape == STAIR) {
        return { { 2, 2 }, { 3, 3 }, { 4, 4 }, { 5, 5 } };
    } else if (shape == CROSS) {
        return { { 2, 2 }, { 3, 2 }, { 4, 2 }, { 3, 1 }, { 3, 3 } };
    } else if (shape == SQUARE) {
        return { { 2, 2 }, { 3, 2 }, { 3, 3 }, { 2, 3 } };
    }
}

Obstacle::Obstacle(Shape &shape, Food &food) {
    _shape = shape;
    _food = food;
}

void Obstacle::updateObstaclePoints(std::vector<SDL_Point> &obstacles){
    std::vector<std::vector<int>> obs_pos = shapeToVector(_shape);
    for(int&& i = 0; i < obs_pos.size(); i++){
        SDL_Point obstacle;
        obstacle.x = _food.getX() + obs_pos[i][0];
        obstacle.y = _food.getY() + obs_pos[i][1];
        obstacles.push_back(obstacle);
    }
}