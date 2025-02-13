#include "game.h"

float Game::m_FadeAlpha = 1.0f;  // fully visible at start
float Game::m_FadeDuration = 2.0f;  // fade duration in seconds
float Game::m_ElapsedTime = 0.0f;  // timer

Game::Game() :
    m_GameState(GameState::Intro),
    m_LeftScore(0),
    m_RightScore(0),
    m_WinnerNote("Draw"),
    ball(WIN_W_HALF, WIN_H_HALF, SPEED_SLOW, SPEED_SLOW),
    rightRacket(RAC_POS_R, SPEED_FAST),
    leftRacket(RAC_POS_L, SPEED_FAST),
    m_DeltaTime(0.0f)
{
    InitWindow(WIN_WIDTH, WIN_HEIGHT, "PONG");
    SetTargetFPS(FPS);
}

Game::~Game()
{
    CloseWindow();
}

//Main Game Loop (Start(), Update())
void Game::Start()
{
    while(!WindowShouldClose())
    {
        m_DeltaTime = GetFrameTime();
        BeginDrawing();
        Render();
        HandleInput();
        Update();
        EndDrawing();
    }
}

void Game::Update()
{
    switch (m_GameState)
    {
        case GameState::Intro:
            StartMessage();
            break;

        case GameState::Playing:
            if (m_FadeAlpha > 0.0f)
            {
                UpdateFadeEffect();
                return;
            }

            ball.MoveBall(m_DeltaTime);
            ball.CheckWallCollision();
            CheckRacketCollision();
            CheckGameOver();
            break;

        case GameState::GameOver:
            if (IsKeyPressed(KEY_SPACE))
            {
                ResetGame();
                m_GameState = GameState::Playing;
            }
            break;
    }
}

//  Render Function (Render())
void Game::Render()
{
    ClearBackground(COLOUR_W);
    DrawFPS(10, 10);

    if(m_GameState == GameState::Intro)
    {
        DrawText("Press SPACE to Start", WIN_W_HALF - TXT_W_START, WIN_H_HALF - 50, TXT_S_MAIN, Fade(COLOUR_B, m_FadeAlpha));
    }
    else if(m_GameState == GameState::Playing)
    {
        if (m_FadeAlpha > 0.0f)
        {
//            rectangle for the fade effect
            DrawRectangle(0, 0, WIN_WIDTH, WIN_HEIGHT, Fade(COLOUR_B, m_FadeAlpha));
        }
        else
        {
        DrawText(std::to_string(m_LeftScore).data(), TXT_SCORE_L, WIN_HEIGHT - 50, TXT_S_SIDE, COLOUR_B);
        DrawText(std::to_string(m_RightScore).data(), TXT_SCORE_R, WIN_HEIGHT - 50, TXT_S_SIDE, COLOUR_B);
        DrawLine(WIN_W_HALF, 0, WIN_W_HALF, WIN_HEIGHT, COLOUR_B);

        ball.DrawBall(COLOUR_B, BALL_RADIUS);
        rightRacket.DrawRacket(COLOUR_B);
        leftRacket.DrawRacket(COLOUR_B);
        }
    }
    else if(m_GameState == GameState::GameOver)
    {
        DrawText(m_WinnerNote.data(), WIN_W_HALF - TXT_W_VICTORY, WIN_H_HALF - 40, TXT_S_MAIN, COLOUR_B);
        DrawText("Press SPACE to restart", WIN_W_HALF - 200, WIN_H_HALF + 60, TXT_S_SIDE, COLOUR_B);
    }
}

//Input Handling (HandleInput())
void Game::HandleInput()
{
    if(IsKeyDown(KEY_W))
    {
        if(leftRacket.GetY() > RAC_TOP)
        {
            leftRacket.SetY(leftRacket.GetY() - leftRacket.GetSpeedY() * m_DeltaTime);
        }

    } else if(IsKeyDown(KEY_S))
    {
        if(leftRacket.GetY() < RAC_BOT)
        {
            leftRacket.SetY(leftRacket.GetY() + leftRacket.GetSpeedY() * m_DeltaTime);
        }
    }

    if(IsKeyDown(KEY_UP))
    {
        if(rightRacket.GetY() > RAC_TOP)
        {
            rightRacket.SetY(rightRacket.GetY() - rightRacket.GetSpeedY() * m_DeltaTime);
        }
    } else if(IsKeyDown(KEY_DOWN))
    {
        if(rightRacket.GetY() < RAC_BOT)
        {
            rightRacket.SetY(rightRacket.GetY() + rightRacket.GetSpeedY() * m_DeltaTime);
        }
    }
}

//Game Logic and State Update (UpdateScore(), CheckGameOver())
void Game::UpdateScore()
{
    if(ball.GetX() < 0)
    {
        m_RightScore++;
        ball.ResetBall(SPEED_SLOW, SPEED_SLOW);
    }
    else if(ball.GetX() > WIN_WIDTH)
    {
        m_LeftScore++;
        ball.ResetBall(-SPEED_SLOW, SPEED_SLOW);
    }
}

void Game::CheckGameOver()
{
    if (m_LeftScore == SCORE_MAX || m_RightScore == SCORE_MAX)
    {
        m_GameState = GameState::GameOver;
        m_WinnerNote = (m_LeftScore == SCORE_MAX) ? "Left player has won!" : "Right player has won!";
    }
}

//Collision Logic (CheckRacketCollision()
void Game::CheckRacketCollision()
{
    if(ball.GetX() < RAC_ZONE && ball.GetX() > WIN_WIDTH - RAC_ZONE)
        return;

    if(CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, BALL_RADIUS, leftRacket.GetRect()))
    {
        if(ball.GetSpeedX() < 0)
        {
            ball.SetSpeedX(-ball.GetSpeedX());
            ball.UpdateSpeed();
        }
    }
    else if(CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, BALL_RADIUS, rightRacket.GetRect()))
    {
        if(ball.GetSpeedX() > 0)
        {
            ball.SetSpeedX(-ball.GetSpeedX());
            ball.UpdateSpeed();
        }
    }
    else
    {
        UpdateScore();
    }
}

//Helper Function for fading effect (UpdateFadeEffect())
void Game::UpdateFadeEffect() const // const because it modifies only static attributes
{
    m_ElapsedTime += m_DeltaTime;
    m_FadeAlpha = 1.0f - (m_ElapsedTime / m_FadeDuration);
    if (m_FadeAlpha == 0.0f)
        return;
}

//Reset and Start Message (ResetGame(), StartMessage())
void Game::ResetGame()
{
    m_LeftScore = 0;
    m_RightScore = 0;
    m_FadeAlpha = 1.0f;
    m_ElapsedTime = 0.0f;
    m_GameState = GameState::Intro;
    ball.ResetBall(SPEED_SLOW, SPEED_SLOW);
    rightRacket.ResetRacket(WIN_H_HALF);
    leftRacket.ResetRacket(WIN_H_HALF);
}

void Game::StartMessage()
{
    if(IsKeyPressed(KEY_SPACE))
    {
        m_GameState = GameState::Playing;
        m_ElapsedTime = 0.0f;
    }
}
