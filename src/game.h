#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <string>
#include "raylib.h"
#include "ball.h"

constexpr int WIN_HEIGHT = 600;
constexpr int WIN_WIDTH = 800;
constexpr const char* WIN_NAME = "PONG";
constexpr int FPS = 60;
constexpr Color W_COLOUR = RAYWHITE;
constexpr Color B_COLOUR = BLACK;

class Game {
private:
    bool m_GameOver;
    int m_RightScore, m_LeftScore, m_Score;
    const char* m_WinnerNote;
//    Ball ball;
//    Racket racket;

public:
    Game();
    ~Game();

    void Start();

    void Render();

    void Update();

    void Terminate();



};


#endif //PONG_GAME_H
