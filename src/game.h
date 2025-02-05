#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <string>
#include "raylib.h"
#include "ball.h"
#include "racket.h"

constexpr uint16_t WIN_HEIGHT = 600;
constexpr uint16_t WIN_WIDTH = 800;
constexpr uint16_t FPS = 60;
constexpr const char* WIN_NAME = "PONG";
constexpr Color W_COLOUR = RAYWHITE;
constexpr Color B_COLOUR = BLACK;

class Game {
private:
    bool m_GameStarted;
    int m_RightScore, m_LeftScore;
    std::string m_WinnerNote;
    Ball ball;
    Racket leftRacket, rightRacket;

public:
    Game();

    ~Game();

    void Start();

    void Render();

    void Update();

//    void Terminate();

};

#endif //PONG_GAME_H