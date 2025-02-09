#ifndef PONG_SETTINGS_H
#define PONG_SETTINGS_H

#include <iostream>
#include "raylib.h"
#include <string_view> // does not allocate memory in order to pass a string val

constexpr uint16_t WIN_HEIGHT = 600;
constexpr uint16_t WIN_WIDTH = 800;
constexpr uint16_t WIN_H_HALF = 300;
constexpr uint16_t WIN_W_HALF = 400;
constexpr uint16_t TXT_S_MAIN = 60;
constexpr uint16_t TXT_S_SIDE = 30;
constexpr uint16_t TXT_W_START = 350; // cca 700
constexpr uint16_t TXT_W_VICTORY = 270; // cca 550/2
constexpr uint16_t FPS = 60;
constexpr float BALL_RADIUS = 15.0f;
constexpr std::string_view WIN_NAME = "PONG";
constexpr Color W_COLOUR = RAYWHITE;
constexpr Color B_COLOUR = BLACK;

enum class GameState{Intro, Playing, GameOver};



#endif //PONG_SETTINGS_H
