#ifndef PONG_BALL_H
#define PONG_BALL_H

#include "raylib.h"
#include "settings.h"

class Ball {
private:
    float m_CoordX, m_CoordY, m_VelocityX, m_VelocityY;

public:
    Ball(float x, float y);
    ~Ball();

    float GetX() const;
    float GetY() const;

    void SetX(float x);
    void SetY(float y);

    float GetSpeedX() const;
    float GetSpeedY() const;

    void SetSpeedX(float vX);
    void SetSpeedY(float vY);

    void DrawBall(Color c) const;
    void UpdateSpeed(float velX, float velY);
    void ResetBall();
};

#endif //PONG_BALL_H
