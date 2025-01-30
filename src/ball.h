#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <iostream>
#include "game.h"

class Ball {
private:
    int m_CoordX, m_CoordY;
    int m_VelocityX, m_VelocityY;
    float m_Radius;

public:
    Ball();
    ~Ball();

    void Speed(int speedX, int speedY);

    void BallRadius(float val);

    void DrawBall();

};

#endif //PONG_BALL_H
