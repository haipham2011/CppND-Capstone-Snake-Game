#include "renderer.h"
#include <iostream>
#include <string>
#include <food/food.h>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Snake snake, Food &food, std::vector<SDL_Point> &obstacles) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  std::vector<SDL_Rect> block_obstacles;
  for(int&& i = 0; i < obstacles.size(); i++){
      SDL_Rect block_obstacle;
      block_obstacle.w = block.w;
      block_obstacle.h = block.h;
      block_obstacles.push_back(block_obstacle);
  }

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, food.getColor().Red(), food.getColor().Green(), food.getColor().Blue(), food.getColor().Alpha());
  block.x = food.getX() * block.w;
  block.y = food.getY() * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);

  for(int&& i = 0; i < obstacles.size(); i++){
    block_obstacles[i].x = obstacles[i].x * block.w;
    block_obstacles[i].y = obstacles[i].y * block.h;
    SDL_RenderFillRect(sdl_renderer, &block_obstacles[i]);
  }

    // Render snake's body
    Color body_color = Color(255, 255, 255, 0);
    SDL_SetRenderDrawColor(sdl_renderer, body_color.Red(), body_color.Green(), body_color.Blue(), body_color.Alpha());
    for (SDL_Point const &point : snake.body) {
        block.x = point.x * block.w;
        block.y = point.y * block.h;
        SDL_RenderFillRect(sdl_renderer, &block);
    }

    // Render snake's head
    block.x = static_cast<int>(snake.head_x) * block.w;
    block.y = static_cast<int>(snake.head_y) * block.h;

    Color head_color;
    if (snake.alive) {
        head_color = Color(102, 178, 255, 0);
    } else {
        head_color = Color(255, 102, 102, 0);
    }

    SDL_SetRenderDrawColor(sdl_renderer, head_color.Red(), head_color.Green(), head_color.Blue(), head_color.Alpha());

    SDL_RenderFillRect(sdl_renderer, &block);

    Color obstacle_color = Color(255, 178, 102, 0);
    for(int&& i = 0; i < obstacles.size(); i++){
        SDL_SetRenderDrawColor(sdl_renderer, obstacle_color.Red(), obstacle_color.Green(), obstacle_color.Blue(), obstacle_color.Alpha());
        SDL_RenderFillRect(sdl_renderer, &block_obstacles[i]);
    }

    // Update Screen
    SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
