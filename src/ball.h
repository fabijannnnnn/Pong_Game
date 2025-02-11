#ifndef PONG_BALL_H
#define PONG_BALL_H

#include "settings.h"

class Ball {

protected:
    float m_CoordX, m_CoordY, m_SpeedX, m_SpeedY;

public:
    Ball(float coordX, float coordY, float speedX, float speedY);
    ~Ball();

    float GetX() const;
    float GetY() const;

    void SetX(float coordX);
    void SetY(float coordY);

    float GetSpeedX() const;
    float GetSpeedY() const;

    void SetSpeedX(float speedX);
    void SetSpeedY(float speedY);

    void UpdateSpeed();

    void DrawBall(Color c, float bRadius) const;
    void ResetBall(float speedX, float speedY);
    void MoveBall(float deltaTime);

    void CheckWallCollision();
};

#endif //PONG_BALL_H
