#include "game.h"

Game::Game() : m_GameStarted(false), m_LeftScore(0), m_RightScore(0), m_WinnerNote("Draw")
{
    InitWindow(WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
    SetTargetFPS(FPS);

    std::cout << "Construction successful\n";
}

Game::~Game()
{
    CloseWindow();
    std::cout << "Deconstruction successful\n";
}

void Game::Start()
{
    while(!WindowShouldClose())
    {
        BeginDrawing();

        Update();
        Render();

        EndDrawing();
    }
}

void Game::Render()
{
    ClearBackground(W_COLOUR);
    ball.DrawBall();
    DrawFPS(10, 10);

}

void Game::Update()
{
    if (m_GameStarted == false)
    {
        int textWidth = MeasureText("Press SPACE to Start", 60);
        DrawText("Press SPACE to Start", WIN_WIDTH / 2 - textWidth / 2, WIN_HEIGHT / 2 - 50, 60, B_COLOUR);

        if (IsKeyPressed(KEY_SPACE))
        {
            DrawText(std::to_string(m_LeftScore).c_str(), (WIN_WIDTH/2)-120, (WIN_HEIGHT)-50, 30, B_COLOUR);
            DrawText(std::to_string(m_RightScore).c_str(), (WIN_WIDTH/2)+100, (WIN_HEIGHT)-50, 30, B_COLOUR);
            DrawLine(WIN_WIDTH/2, 0, WIN_WIDTH/2, WIN_HEIGHT, B_COLOUR);
            m_GameStarted = true;
        }
    }

}
