#include "game.h"

Game::Game() : m_GameOver(false), m_LeftScore(0), m_RightScore(0), m_Score(0), m_WinnerNote("Draw")
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
    while(!WindowShouldClose()) {
//        Update();
        Render();
    }
}

void Game::Render()
{
    BeginDrawing();
    {
        ClearBackground(W_COLOUR);

        DrawText("Press SPACE to start", (WIN_WIDTH/2)-210, 250, 40, B_COLOUR);
        DrawText(std::to_string(m_LeftScore).c_str(), (WIN_WIDTH/2)-120, (WIN_HEIGHT)-50, 30, B_COLOUR);
        DrawText(std::to_string(m_RightScore).c_str(), (WIN_WIDTH/2)+100, (WIN_HEIGHT)-50, 30, B_COLOUR);
        DrawLine(WIN_WIDTH/2, 0, WIN_WIDTH/2, WIN_HEIGHT, B_COLOUR);
        DrawFPS(10, 10);
    }
    Terminate();
}

void Game::Update()
{

}

void Game::Terminate()
{
    m_GameOver = true;
    EndDrawing();
}
