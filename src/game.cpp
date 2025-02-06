#include "game.h"

Game::Game() :
    m_GameStarted(false),
    m_LeftScore(0),
    m_RightScore(0),
    m_WinnerNote("Draw"),
    ball(WIN_WIDTH, WIN_HEIGHT),
    rightRacket(),
    leftRacket()
{
    InitWindow(WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
    SetTargetFPS(FPS);

    leftRacket.Position(40, float(WIN_HEIGHT) / 2);
    rightRacket.Position(WIN_WIDTH - 40, float(WIN_HEIGHT) / 2);

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

void Game::Render()
{
    ClearBackground(W_COLOUR);



    DrawFPS(10, 10);
}

void Game::Update()
{
    static float fadeAlpha = 1.0f;  // Fully visible at start
    static float fadeDuration = 1.5f;  // Fade duration in seconds
    static float elapsedTime = 0.0f;  // Timer


    if(!m_GameStarted)
    {
        int textWidth = MeasureText("Press SPACE to Start", 60);
//        DrawText("Press SPACE to Start", WIN_WIDTH / 2 - textWidth / 2, WIN_HEIGHT / 2 - 50, 60, B_COLOUR);
        DrawText("Press SPACE to Start", WIN_WIDTH / 2 - textWidth / 2, WIN_HEIGHT / 2 - 50, 60, Fade(B_COLOUR, fadeAlpha));

        if(IsKeyPressed(KEY_SPACE))
        {
            m_GameStarted = true;
            elapsedTime = 0.0f;
        }
    } else
    {
        if (fadeAlpha > 0.0f)
        {
            elapsedTime += GetFrameTime();
            fadeAlpha = 1.0f - (elapsedTime / fadeDuration);

            if (fadeAlpha < 0.0f) fadeAlpha = 0.0f;

//            fade overlay
            DrawRectangle(0, 0, WIN_WIDTH, WIN_HEIGHT, Fade(B_COLOUR, fadeAlpha));
        }
        else
        {
            DrawText(std::to_string(m_LeftScore).c_str(), (WIN_WIDTH / 2) - 120, (WIN_HEIGHT) - 50, 30, B_COLOUR);
            DrawText(std::to_string(m_RightScore).c_str(), (WIN_WIDTH / 2) + 100, (WIN_HEIGHT) - 50, 30, B_COLOUR);
            DrawLine(WIN_WIDTH / 2, 0, WIN_WIDTH / 2, WIN_HEIGHT, B_COLOUR);

            ball.DrawBall(B_COLOUR);
            rightRacket.DrawRacket(B_COLOUR);
            leftRacket.DrawRacket(B_COLOUR);

            ball.SetX(ball.GetX() + ball.GetSpeedX() * GetFrameTime());
            ball.SetY(ball.GetY() + ball.GetSpeedY() * GetFrameTime());

//           TODO: dokoncit ball movement a racket movement logic

//           TODO2: vytvorit funkciu na ovladanie hry, WS a sipky

        }
    }



























//    static float fadeAlpha = 1.0f; // fade variable for the transition
//
//    if(!m_GameStarted)
//    {
//        int textWidth = MeasureText("Press SPACE to Start", 60);
////        DrawText("Press SPACE to Start", WIN_WIDTH / 2 - textWidth / 2, WIN_HEIGHT / 2 - 50, 60, B_COLOUR);
//        DrawText("Press SPACE to Start", WIN_WIDTH / 2 - textWidth / 2, WIN_HEIGHT / 2 - 50, 60, Fade(B_COLOUR, fadeAlpha));
//
//        if(IsKeyPressed(KEY_SPACE))
//        {
//            m_GameStarted = true;
//        }
//    } else
//    {
//        if(fadeAlpha > 0.0f)
//        {
//            fadeAlpha -= 0.01f;
//        } else {
//
//            DrawText(std::to_string(m_LeftScore).c_str(), (WIN_WIDTH / 2) - 120, (WIN_HEIGHT) - 50, 30, B_COLOUR);
//            DrawText(std::to_string(m_RightScore).c_str(), (WIN_WIDTH / 2) + 100, (WIN_HEIGHT) - 50, 30, B_COLOUR);
//            DrawLine(WIN_WIDTH / 2, 0, WIN_WIDTH / 2, WIN_HEIGHT, B_COLOUR);
//
//            ball.DrawBall(B_COLOUR);
//            rightRacket.DrawRacket(B_COLOUR);
//            leftRacket.DrawRacket(B_COLOUR);
//        }
//    }
}
