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
    rightRacket(RAC_POS_R, WIN_H_HALF, 0, SPEED_FAST),
    leftRacket(RAC_POS_L, WIN_H_HALF, 0, SPEED_FAST)
{
    InitWindow(WIN_WIDTH, WIN_HEIGHT, "PONG"); // possible use of .cstr(), also ends as null terminated
    SetTargetFPS(FPS);

    std::cout << "Game construction successful\n";
}

Game::~Game()
{
    CloseWindow();
    std::cout << "Game destruction successful\n";
}

void Game::Start()
{
    while(!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        BeginDrawing();
        Render();
        HandleInput(deltaTime);
        Update(deltaTime);
        EndDrawing();
    }
}

void Game::ResetGame()
{
    m_LeftScore = 0;
    m_RightScore = 0;
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
        DrawText("Press SPACE to restart", WIN_W_HALF - TXT_W_VICTORY, WIN_H_HALF - 100, TXT_S_SIDE, Fade(COLOUR_B, m_FadeAlpha));
    }
}

void Game::Update(float dT)
{
    float deltaTime = dT;

    switch (m_GameState)
    {
        case GameState::Intro:
            StartMessage();
            break;

        case GameState::Playing:
            UpdateFadeEffect(deltaTime);
            if (m_FadeAlpha > 0.0f) return;

            MoveBall(deltaTime);
            CheckWallCollision();
            CheckPaddleCollision();
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

void Game::UpdateFadeEffect(float deltaTime)
{
    if (m_FadeAlpha > 0.0f)
    {
        m_ElapsedTime += deltaTime;
        m_FadeAlpha = 1.0f - (m_ElapsedTime / m_FadeDuration);
        if (m_FadeAlpha < 0.0f) m_FadeAlpha = 0.0f;
    }
}

void Game::MoveBall(float deltaTime)
{
    ball.SetX(ball.GetX() + ball.GetSpeedX() * deltaTime);
    ball.SetY(ball.GetY() + ball.GetSpeedY() * deltaTime);
}

void Game::CheckWallCollision()
{
    if (ball.GetY() < 0 || ball.GetY() > WIN_HEIGHT)
    {
        ball.SetY(ball.GetY() < 0 ? 0 : WIN_HEIGHT);
        ball.SetSpeedY(-ball.GetSpeedY());
    }
}

//TODO: REPAIR THIS LOGIC SO IT COLLIDES WITH THE TOP AND THE BOTTOM AND CHANGES TRAJECTORY ACCORDINGLY
void Game::CheckPaddleCollision()
{
    if (ball.GetX() < 60 && ball.GetX() > WIN_WIDTH - 60) return;

    if (CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, BALL_RADIUS, leftRacket.GetRect()))
    {
        if(ball.GetSpeedX() < 0)
        {
            ball.SetSpeedX(-ball.GetSpeedX());
        }
    }
    else if (CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, BALL_RADIUS, rightRacket.GetRect()))
    {
        if(ball.GetSpeedX() > 0)
        {
            ball.SetSpeedX(-ball.GetSpeedX());
        }
    } else
    {
        UpdateScore(); // If no collision, update score
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

void Game::HandleInput(float dT)
{
    float deltaTime = dT;

    if(IsKeyDown(KEY_W))
    {
        if(leftRacket.GetY() > RAC_TOP)
        {
            leftRacket.SetY(leftRacket.GetY() - leftRacket.GetSpeedY() * deltaTime);
        }

    } else if(IsKeyDown(KEY_S))
    {
        if(leftRacket.GetY() < RAC_BOT)
        {
            leftRacket.SetY(leftRacket.GetY() + leftRacket.GetSpeedY() * deltaTime);
        }
    } else if(IsKeyDown(KEY_UP))
    {
        if(rightRacket.GetY() > RAC_TOP)
        {
            rightRacket.SetY(rightRacket.GetY() - rightRacket.GetSpeedY() * deltaTime);
        }
    } else if(IsKeyDown(KEY_DOWN))
    {
        if(rightRacket.GetY() < RAC_BOT)
        {
            rightRacket.SetY(rightRacket.GetY() + rightRacket.GetSpeedY() * deltaTime);
        }
    }

}

//void Game::Update(float dT)
//{
//    // delta time refers to the time passed between the current and previous frame
//    float deltaTime = dT;
//
//    if(m_GameState == GameState::Intro)
//    {
//        StartMessage();
//    }
//    else if(m_GameState == GameState::Playing)
//    {
////        fade alpha is the opacity of the fade
//        if (m_FadeAlpha > 0.0f)
//        {
//            m_ElapsedTime += deltaTime;
//            m_FadeAlpha = 1.0f - (m_ElapsedTime/m_FadeDuration);
//            return;
//        }
////        else
////        {
////        calculates the direction of the ball
//            ball.SetX(ball.GetX() + ball.GetSpeedX() * deltaTime);
//            ball.SetY(ball.GetY() + ball.GetSpeedY() * deltaTime);
//
//
////        ball top and bottom collision detection
//            if (ball.GetY() < 0 || ball.GetY() > WIN_HEIGHT) {
//                ball.SetY(ball.GetY() < 0 ? 0 : WIN_HEIGHT);
//                ball.SetSpeedY(-ball.GetSpeedY());
//            }
//
////        check for collision between the ball and the left and right racket
//            if (ball.GetX() < 60 || ball.GetX() > WIN_WIDTH - 60)
//            {
//                if (CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, BALL_RADIUS, leftRacket.GetRect()))
//                {
////                    ball.SetSpeedX((ball.GetSpeedX() > 0) ? -SPEED_FAST : SPEED_FAST);
////                    ball.SetSpeedY((ball.GetSpeedY() > 0) ? SPEED_FAST : -SPEED_FAST);
//////                    ball.SetX(rightRacket.GetX() - BALL_RADIUS - 1);
//                    if(ball.GetSpeedX() < 0)
//                    {
//                        ball.SetSpeedX(ball.GetSpeedX() * -1);
//                    }
//                }
//                else if (CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, BALL_RADIUS, rightRacket.GetRect()))
//                {
////                    ball.SetSpeedX((ball.GetSpeedX() > 0) ? -SPEED_FAST : SPEED_FAST);
////                    ball.SetSpeedY((ball.GetSpeedY() > 0) ? SPEED_FAST : -SPEED_FAST);
//////                    ball.SetX(rightRacket.GetX() - BALL_RADIUS - 1);
//                    if(ball.GetSpeedX() > 0)
//                    {
//                        ball.SetSpeedX(ball.GetSpeedX() * -1);
//                    }
//                }
//                else UpdateScore();
//            }
//
//            if (m_LeftScore == SCORE_MAX || m_RightScore == SCORE_MAX) {
//                m_GameState = GameState::GameOver;
//                m_WinnerNote = (m_LeftScore == 10) ? "Left player has won!" : "Right player has won!";
//            }
////        }
//    }
//    else if(m_GameState == GameState::GameOver)
//    {
//        if(IsKeyPressed(KEY_SPACE))
//        {
//            ResetGame();
//            m_GameState = GameState::Playing;
//        }
//    }
//
//}

