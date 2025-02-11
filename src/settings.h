#ifndef PONG_SETTINGS_H
#define PONG_SETTINGS_H

#include <iostream>
#include "raylib.h"

// ---window dimensions---
constexpr uint16_t WIN_HEIGHT = 600;
constexpr uint16_t WIN_WIDTH = 800;
constexpr float WIN_H_HALF = 300.0f;
constexpr float WIN_W_HALF = 400.0f;
// ---framerate setting---
constexpr uint16_t FPS = 60;
// ---max score---
constexpr uint16_t SCORE_MAX = 10;
// ---text sizing---
constexpr uint16_t TXT_S_MAIN = 60;
constexpr uint16_t TXT_S_SIDE = 30;
constexpr uint16_t TXT_W_START = 350; // cca 700
constexpr uint16_t TXT_W_VICTORY = 310;
constexpr uint16_t TXT_SCORE_L = WIN_W_HALF - 120;
constexpr uint16_t TXT_SCORE_R = WIN_W_HALF + 100;
// ---ball settings---
constexpr float SPEED_SLOW = 450.0f;
constexpr float SPEED_FAST = 550.0f;
constexpr float BALL_RADIUS = 13.0f;
// ---racket settings---
constexpr float RAC_WIDTH = 15.0f;
constexpr float RAC_HEIGHT = 120.0f;
constexpr float RAC_POS_L = 40.0f;
constexpr float RAC_POS_R = WIN_WIDTH - 40.0f;
constexpr float RAC_BOT = WIN_HEIGHT - RAC_HEIGHT/2;
constexpr float RAC_TOP = RAC_HEIGHT/2;
// ---colours---
constexpr Color COLOUR_W = RAYWHITE;
constexpr Color COLOUR_B = BLACK;
// ---game status---
enum class GameState{Intro, Playing, GameOver};


#endif //PONG_SETTINGS_H
