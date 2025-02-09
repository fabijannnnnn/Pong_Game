#include "game.h"
#include <iostream>

float Game::m_FadeAlpha = 1.0f;  // fully visible at start
float Game::m_FadeDuration = 2.0f;  // fade duration in seconds
float Game::m_ElapsedTime = 0.0f;  // timer

Game::Game() :
    m_GameState(GameState::Intro),
    m_LeftScore(0),
    m_RightScore(0),
    m_WinnerNote("Draw"),
    ball(WIN_W_HALF, WIN_H_HALF),
    rightRacket(),
    leftRacket()
{
    InitWindow(WIN_WIDTH, WIN_HEIGHT, WIN_NAME.data()); // possible use of .cstr(), also ends as null terminated
    SetTargetFPS(FPS);

    leftRacket.Position(40, float(WIN_H_HALF));
    rightRacket.Position(WIN_WIDTH - 40, float(WIN_H_HALF));

    std::cout << "Construction successful\n";
}

Game::~Game()
{
    CloseWindow();
    std::cout << "Destruction successful\n";
}

void Game::Start()
{
    while(!WindowShouldClose())
    {
        BeginDrawing();
        Render();
        Update();
        EndDrawing();
    }
}

void Game::UpdateScore()
{
    if(ball.GetX() < 0)
    {
        m_RightScore++;
        ball.ResetBall(WIN_W_HALF, WIN_H_HALF);
    }
    else if(ball.GetX() > WIN_WIDTH)
    {
        m_LeftScore++;
        ball.ResetBall(WIN_W_HALF, WIN_H_HALF);
    }
}

void Game::ResetGame()
{
    m_LeftScore = 0;
    m_RightScore = 0;
    m_GameState = GameState::Intro;
    ball.ResetBall(WIN_W_HALF, WIN_H_HALF);
}

void Game::StartMessage()
{
    if(IsKeyPressed(KEY_SPACE))
    {
        m_GameState = GameState::Playing;
        m_ElapsedTime = 0.0f;
    }
}

void Game::Render()
{
    ClearBackground(W_COLOUR);
    DrawFPS(10, 10);

    if(m_GameState == GameState::Intro)
    {
        DrawText("Press SPACE to Start", WIN_W_HALF - TXT_W_START, WIN_H_HALF - 50, TXT_S_MAIN, Fade(B_COLOUR, m_FadeAlpha));
    }
    else if(m_GameState == GameState::Playing)
    {
        if (m_FadeAlpha > 0.0f)
        {
//            rectangle for the fade effect
            DrawRectangle(0, 0, WIN_WIDTH, WIN_HEIGHT, Fade(B_COLOUR, m_FadeAlpha));
        }
        else
        {
        DrawText(std::to_string(m_LeftScore).data(), WIN_W_HALF - 120, WIN_HEIGHT - 50, TXT_S_SIDE, B_COLOUR);
        DrawText(std::to_string(m_RightScore).data(), WIN_W_HALF + 100, WIN_HEIGHT - 50, TXT_S_SIDE, B_COLOUR);
        DrawLine(WIN_W_HALF, 0, WIN_W_HALF, WIN_HEIGHT, B_COLOUR);

        ball.DrawBall(B_COLOUR);
        rightRacket.DrawRacket(B_COLOUR);
        leftRacket.DrawRacket(B_COLOUR);
        }
    }
    else if(m_GameState == GameState::GameOver)
    {
        DrawText(m_WinnerNote.data(), WIN_W_HALF - TXT_W_VICTORY, WIN_H_HALF - 40, TXT_S_MAIN, B_COLOUR);
        DrawText("Press SPACE to restart", WIN_W_HALF - TXT_W_VICTORY, WIN_H_HALF - 100, TXT_S_SIDE, Fade(B_COLOUR, m_FadeAlpha));
    }
}

// UPDATE
void Game::Update()
{
    // delta time refers to the time passed between the current and previous frame
    float deltaTime = GetFrameTime();

    if(m_GameState == GameState::Intro)
    {
        StartMessage();
    }
    else if(m_GameState == GameState::Playing)
    {
//        fade alpha is the opacity of the fade
        if (m_FadeAlpha > 0.0f)
        {
            m_ElapsedTime += deltaTime;
            m_FadeAlpha = 1.0f - (m_ElapsedTime/m_FadeDuration);
            if (m_FadeAlpha < 0.0f) m_FadeAlpha = 0.0f;
        }
        else
        {

//        sets the direction of the ball
            ball.SetX(ball.GetX() + ball.GetSpeedX() * deltaTime);
//        ball.SetY(ball.GetY() + ball.GetSpeedY() * deltaTime);
            std::cout << ball.GetSpeedX() << "    " << ball.GetSpeedY() << std::endl;


//        ball top and bottom collision detection
            if (ball.GetY() < 0 || ball.GetY() > WIN_HEIGHT) {
                ball.SetY(ball.GetY() < 0 ? 0 : WIN_HEIGHT);
                ball.SetSpeedY(-ball.GetY());
            }

//        check for collision between the ball and the left and right racket
            if (ball.GetX() < 60 || ball.GetX() > WIN_WIDTH - 60) {
                if (CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, BALL_RADIUS, leftRacket.GetRect())) {
//                ball.SetSpeedX(-ball.GetSpeedX());
                    ball.UpdateSpeed(550, 550);
                } else if (CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, BALL_RADIUS,
                                                   rightRacket.GetRect())) {
                    ball.UpdateSpeed(-550, -550);
//                ball.SetSpeedX(-ball.GetSpeedX());
                } else UpdateScore();
            }

            if (m_LeftScore == 10 || m_RightScore == 10) {
                m_GameState = GameState::GameOver;
                m_WinnerNote = (m_LeftScore == 10) ? "Left player has won!" : "Right player has won!";
            }
        }
    }
    else if(m_GameState == GameState::GameOver)
    {
        if(IsKeyPressed(KEY_SPACE))
        {
            ResetGame();
            m_GameState = GameState::Playing;
        }
    }

}

//           TODO: vytvorit funkciu na ovladanie hry, W,S a sipky
