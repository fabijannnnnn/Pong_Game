#ifndef PONG_GAME_H
#define PONG_GAME_H

#include "ball.h"
#include "racket.h"
#include "settings.h"

class Game {

private:
    GameState m_GameState;
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
    void ResetGame();
};

#endif //PONG_GAME_H