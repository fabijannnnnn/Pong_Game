#ifndef PONG_GAME_H
#define PONG_GAME_H

#include "racket.h"

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
    void Update(float deltaTime);
    void HandleInput(float deltaTime);
    void UpdateScore();
    void StartMessage();
    void ResetGame();

    void CheckPaddleCollision();
    void CheckGameOver();
    void CheckWallCollision();
    void MoveBall(float deltaTime);
    static void UpdateFadeEffect(float deltaTime);
};

#endif //PONG_GAME_H