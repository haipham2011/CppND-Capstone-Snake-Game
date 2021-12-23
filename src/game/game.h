#ifndef GAME_H
#define GAME_H

#include <random>
#include <food/food.h>
#include "SDL.h"
#include "controller/controller.h"
#include "renderer/renderer.h"
#include "snake/snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  Food food = Food(0, 0);
  std::vector<SDL_Point> obstacles;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void PlaceObstacles();
  void Update();
};

#endif