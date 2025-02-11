#ifndef PONG_GAME_H
#define PONG_GAME_H

#include "racket.h"

class Game {

private:
    GameState m_GameState;
    std::string m_WinnerNote;
    uint16_t m_RightScore, m_LeftScore;

    static float m_FadeAlpha, m_FadeDuration, m_ElapsedTime;

    Ball ball;
    Racket leftRacket, rightRacket;

public:
    Game();
    ~Game();

    void Start();
    void Render();
    void Update(float deltaTime);
    void HandleInput(float deltaTime);

    void ResetGame();
    void StartMessage();
    void CheckGameOver();

    void UpdateScore();
    void CheckRacketCollision();

    static void UpdateFadeEffect(float deltaTime);
};

#endif //PONG_GAME_H