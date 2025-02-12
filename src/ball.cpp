#include "ball.h"

Ball::Ball(float x, float y, float vX, float vY) :
        m_CoordX(x),
        m_CoordY(y),
        m_SpeedX(vX),
        m_SpeedY(vY)
        {}

Ball::~Ball() = default;

void Ball::DrawBall(Color c, float bR) const
{
    DrawCircle(int(m_CoordX), int(m_CoordY), bR, c);
}

float Ball::GetX() const
{
    return m_CoordX;
}

float Ball::GetY() const
{
    return m_CoordY;
}

void Ball::SetX(float x)
{
    m_CoordX = x;
}

void Ball::SetY(float y)
{
    m_CoordY = y;
}

float Ball::GetSpeedX() const
{
    return m_SpeedX;
}

float Ball::GetSpeedY() const
{
    return m_SpeedY;
}

void Ball::SetSpeedX(float sX)
{
    m_SpeedX = sX;
}

void Ball::SetSpeedY(float sY)
{
    m_SpeedY = sY;
}

void Ball::ResetBall(float sX, float sY)
{
    m_CoordX = WIN_W_HALF;
    m_CoordY = WIN_H_HALF;
    m_SpeedX = sX;
    m_SpeedY = sY;
}

void Ball::CheckWallCollision()
{
    if(m_CoordY < BALL_RADIUS || m_CoordY > WIN_HEIGHT - BALL_RADIUS)
    {
        m_CoordY = m_CoordY < BALL_RADIUS ? BALL_RADIUS : WIN_HEIGHT - BALL_RADIUS;
        m_SpeedY = -m_SpeedY;
    }
}

void Ball::MoveBall(float dT)
{
    m_CoordX += m_SpeedX * dT;
    m_CoordY += m_SpeedY * dT;
}

void Ball::UpdateSpeed()
{
    if(abs(m_SpeedY) == SPEED_SLOW)
    {
        m_SpeedY = m_SpeedY < 0 ? -SPEED_FAST : SPEED_FAST;
        m_SpeedX = m_SpeedX < 0 ? -SPEED_FAST : SPEED_FAST;
    } else
        return;
}
