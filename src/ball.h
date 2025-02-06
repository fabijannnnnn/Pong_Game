#ifndef PONG_BALL_H
#define PONG_BALL_H

#include "raylib.h"
#include <iostream>

class Ball {
private:
    float m_CoordX, m_CoordY, m_VelocityX, m_VelocityY, m_Radius;

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

    float GetRadius() const;

//    void Speed(float speedX, float speedY);

//    void BallRadius(float val);

    void DrawBall(Color c);

    void ResetBall(float x, float y);

};

#endif //PONG_BALL_H
