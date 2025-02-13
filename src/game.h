#ifndef PONG_GAME_H
#define PONG_GAME_H

#include "racket.h"

class Game {

private:
    GameState m_GameState;
    std::string m_WinnerNote;
    uint16_t m_RightScore, m_LeftScore;
    float  m_DeltaTime;

    static float m_FadeAlpha, m_FadeDuration, m_ElapsedTime;

    Ball ball;
    Racket leftRacket, rightRacket;

public:
    Game();
    ~Game();

    void Start();
    void Render();
    void Update();
    void HandleInput();

    void ResetGame();
    void StartMessage();
    void CheckGameOver();

    void UpdateScore();
    void CheckRacketCollision();

    void UpdateFadeEffect() const;
};

#endif //PONG_GAME_H