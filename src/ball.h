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

    void Speed(float speedX, float speedY);

    void BallRadius(float val);

    void DrawBall(Color c);

};

#endif //PONG_BALL_H
