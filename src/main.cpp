#include "game.h"

int main() {
    Game game;

    game.Start();
    return 0;
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


//    void Game::Update(float deltaT)
//    {
//        static float fadeAlpha = 1.0f;  // Fully visible at start
//        static float fadeDuration = 1.5f;  // Fade duration in seconds
//        static float elapsedTime = 0.0f;  // Timer
//
//        if(!m_GameStarted)
//        {
//            // Handle game start logic
//            StartScreen(elapsedTime, fadeAlpha, deltaT);
//        }
//        else
//        {
//            // Handle game running logic
//            GameLogic(elapsedTime, fadeAlpha, fadeDuration, deltaT);
//        }
//    }
//
//    void Game::StartScreen(float& elapsedTime, float& fadeAlpha, float deltaT)
//    {
//        int textWidth = MeasureText("Press SPACE to Start", 60);
//        DrawText("Press SPACE to Start", WIN_WIDTH/2 - textWidth/2, WIN_HEIGHT/2 - 50, 60, Fade(B_COLOUR, fadeAlpha));
//
//        if(IsKeyPressed(KEY_SPACE))
//        {
//            m_GameStarted = true;
//            elapsedTime = 0.0f;
//        }
//    }
//
//    void Game::GameLogic(float& elapsedTime, float& fadeAlpha, float& fadeDuration, float deltaT)
//    {
//        // Fade effect logic
//        if (fadeAlpha > 0.0f)
//        {
//            elapsedTime += deltaT;
//            fadeAlpha = 1.0f - (elapsedTime / fadeDuration);
//
//            if (fadeAlpha < 0.0f) fadeAlpha = 0.0f;
//
//            DrawRectangle(0, 0, WIN_WIDTH, WIN_HEIGHT, Fade(B_COLOUR, fadeAlpha));
//        }
//
//        // Update ball position
//        ball.SetX(ball.GetX() + ball.GetSpeedX() * deltaT);
//
//        // Ball collision with top and bottom
//        if(ball.GetY() < 0 || ball.GetY() > WIN_HEIGHT) {
//            ball.SetSpeedY(ball.GetSpeedY() * -1); // Reversing vertical speed
//        }
//
//        // Check collisions with paddles
//        if (ball.GetX() < 100 || ball.GetX() > WIN_WIDTH - 100) {
//            if (CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, ball.GetRadius(), leftRacket.GetRect())) {
//                if (ball.GetSpeedX() < 0) ball.UpdateSpeed(550, 550);
//            }
//
//            if (CheckCollisionCircleRec(Vector2{ball.GetX(), ball.GetY()}, ball.GetRadius(), rightRacket.GetRect())) {
//                if (ball.GetSpeedX() > 0) ball.UpdateSpeed(-550, -550);
//            }
//        }
//
//        // Score update logic
//        if(ball.GetX() < 0 || ball.GetX() > WIN_WIDTH) {
//            UpdateScore();
//        }
//
//        // Check for winning conditions
//        if(m_LeftScore == 10 || m_RightScore == 10) {
//            int textWidth = MeasureText("L / R player has won", 50);
//            if(m_LeftScore == 10)
//            {
//                DrawText("Left player has won", WIN_WIDTH/2 - textWidth/2, WIN_HEIGHT/2 - 50, 60, B_COLOUR);
//            }
//            else
//            {
//                DrawText("Right player has won", WIN_WIDTH/2 - textWidth/2, WIN_HEIGHT/2 - 50, 60, B_COLOUR);
//            }
//        }
//    }
//
//    void Game::Render()
//    {
//        ClearBackground(W_COLOUR);
//
//        // Draw the scores
//        DrawText(std::to_string(m_LeftScore).c_str(), WIN_WIDTH/2 - 120, WIN_HEIGHT - 50, 30, B_COLOUR);
//        DrawText(std::to_string(m_RightScore).c_str(), WIN_WIDTH/2 + 100, WIN_HEIGHT - 50, 30, B_COLOUR);
//        DrawLine(WIN_WIDTH/2, 0, WIN_WIDTH/2, WIN_HEIGHT, B_COLOUR);
//
//        // Draw paddles and ball
//        ball.DrawBall(B_COLOUR);
//        rightRacket.DrawRacket(B_COLOUR);
//        leftRacket.DrawRacket(B_COLOUR);
//
//        DrawFPS(10, 10);
//    }
