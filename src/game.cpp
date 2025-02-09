#include "game.h"

float Game::m_FadeAlpha = 1.0f;  // fully visible at start
float Game::m_FadeDuration = 1.5f;  // fade duration in seconds
float Game::m_ElapsedTime = 0.0f;  // timer

Game::Game() :
    m_GameState(GameState::Intro),
    m_LeftScore(0),
    m_RightScore(0),
    m_WinnerNote("Draw"),
    ball(WIN_WIDTH, WIN_HEIGHT),
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
        ball.ResetBall(WIN_WIDTH, WIN_HEIGHT, 400, 400);
    }
    else if(ball.GetX() > WIN_WIDTH)
    {
        m_LeftScore++;
        ball.ResetBall(WIN_WIDTH,WIN_HEIGHT, -400, 400);
    }
}

void Game::ResetGame()
{
    m_LeftScore = 0;
    m_RightScore = 0;
    m_GameState = GameState::Intro;
    ball.ResetBall(WIN_WIDTH, WIN_HEIGHT, 400, 400);
}

void Game::Render()
{
    ClearBackground(W_COLOUR);
    DrawFPS(10, 10);
    if(m_GameState == GameState::Intro)
    {

    }
}

void Game::StartMessage()
{
    DrawText("Press SPACE to Start", WIN_W_HALF - TXT_W_START, WIN_H_HALF - 50, TXT_S_MAIN, Fade(B_COLOUR, m_FadeAlpha));
    if(IsKeyPressed(KEY_SPACE))
    {
        m_GameState = GameState::Playing;
        m_ElapsedTime = 0.0f;
    }
}

void Game::Update()
{
    float deltaTime = GetFrameTime();

    if(m_GameState == GameState::Intro)
    {
        StartMessage();
    } else
    {
        if (m_FadeAlpha > 0.0f)
        {
            m_ElapsedTime += deltaTime;
            m_FadeAlpha = 1.0f - (m_ElapsedTime/m_FadeDuration);

            if (m_FadeAlpha < 0.0f) m_FadeAlpha = 0.0f;

//            fade effect of the rectangle
            DrawRectangle(0, 0, WIN_WIDTH, WIN_HEIGHT, Fade(B_COLOUR, m_FadeAlpha));
        }
        else
        {
//            TODO: dokoncit ball movement a racket movement logic

//            draws the text
            DrawText(std::to_string(m_LeftScore).c_str(), WIN_W_HALF - 120, WIN_HEIGHT - 50, TXT_S_SIDE, B_COLOUR);
            DrawText(std::to_string(m_RightScore).c_str(), WIN_W_HALF + 100, WIN_HEIGHT - 50, TXT_S_SIDE, B_COLOUR);
            DrawLine(WIN_W_HALF, 0, WIN_W_HALF, WIN_HEIGHT, B_COLOUR);

//            draws the necessary tools for the game
            ball.DrawBall(B_COLOUR);
            rightRacket.DrawRacket(B_COLOUR);
            leftRacket.DrawRacket(B_COLOUR);


//            TODO: randomizing the ball spawn direction
//            sets the direction of the ball
            ball.SetX(ball.GetX() + ball.GetSpeedX() * deltaTime);
//            ball.SetY(ball.GetY() + ball.GetSpeedY() * deltaTime);


//            ball top and bottom collision detection
            if(ball.GetY() < 0 || ball.GetY() > WIN_HEIGHT)
            {
                if(ball.GetY() < 0)
                {
                    ball.SetY(0);
                    ball.SetSpeedY(ball.GetSpeedY() * -1); // reversing vertical speed
                } else
                {
                    ball.SetY(WIN_HEIGHT);
                    ball.SetSpeedY(ball.GetSpeedY() * -1); // reversing vertical speed
                }
            }


//            check for collision between the ball and the left and right racket
            if (ball.GetX() < 60 || ball.GetX() > WIN_WIDTH - 60)
            {
                if (CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, ball.GetRadius(), leftRacket.GetRect()))
                {
                    ball.UpdateSpeed(550, 550);
                }
                else if (CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, ball.GetRadius(), rightRacket.GetRect()))
                {
                    ball.UpdateSpeed(-550, -550);
                }
                else UpdateScore();
            }


            if(m_LeftScore == 10 || m_RightScore == 10)
            {
                if(m_LeftScore == 10)
                {
                    DrawText("Left player has won", WIN_W_HALF - TXT_W_VICTORY, WIN_H_HALF - 50, TXT_S_MAIN, B_COLOUR);
//                    m_GameStarted = false;
                }
                else
                {
                    DrawText("Right player has won", WIN_W_HALF - TXT_W_VICTORY, WIN_H_HALF - 50, TXT_S_MAIN, B_COLOUR);
//                    m_GameStarted = false;
                }
            }

        }

    }

}

//           TODO: vytvorit funkciu na ovladanie hry, W,S a sipky
