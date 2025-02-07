#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <string>
#include "raylib.h"
#include "ball.h"
#include "racket.h"

constexpr uint16_t WIN_HEIGHT = 600;
constexpr uint16_t WIN_WIDTH = 800;
constexpr uint16_t WIN_H_HALF = 300;
constexpr uint16_t WIN_W_HALF = 400;
constexpr uint16_t TXT_S_MAIN = 60;
constexpr uint16_t TXT_S_SIDE = 30;
constexpr uint16_t TXT_W_START = 350; // cca 700
constexpr uint16_t TXT_W_VICTORY = 270; // cca 550/2
constexpr uint16_t FPS = 60;
constexpr const char* WIN_NAME = "PONG";
constexpr Color W_COLOUR = RAYWHITE;
constexpr Color B_COLOUR = BLACK;

class Game {

private:
    bool m_GameStarted;
    static float m_FadeAlpha, m_FadeDuration, m_ElapsedTime;
    uint16_t m_RightScore, m_LeftScore;
    std::string m_WinnerNote;
    Ball ball;
    Racket leftRacket, rightRacket;

public:
    Game();
    ~Game();

    void Start();
    void Render();
    void Update();
    void UpdateScore();
    void StartMessage();
};

#endif //PONG_GAME_H