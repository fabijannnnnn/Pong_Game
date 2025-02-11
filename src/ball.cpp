#include "ball.h"

Ball::Ball(float x, float y, float vX, float vY) :
        m_CoordX(x),
        m_CoordY(y),
        m_VelocityX(vX),
        m_VelocityY(vY)
{
//    std::cout << "Ball construction successful\n";
}

Ball::~Ball()
{
//    std::cout << "Ball destruction successful\n";
}

void Ball::DrawBall(Color c, float bR) const {
    DrawCircle(int(m_CoordX), int(m_CoordY), bR, c);
}

float Ball::GetX() const {
    return m_CoordX;
}

float Ball::GetY() const {
    return m_CoordY;
}

void Ball::SetX(float x) {
    m_CoordX = x;
}

void Ball::SetY(float y) {
    m_CoordY = y;
}

float Ball::GetSpeedX() const {
    return m_VelocityX;
}

float Ball::GetSpeedY() const {
    return m_VelocityY;
}

void Ball::SetSpeedX(float vX) {
    m_VelocityX = vX;
}

void Ball::SetSpeedY(float vY) {
    m_VelocityY = vY;
}

void Ball::ResetBall(float vX, float vY)
{
    m_CoordX = WIN_W_HALF;
    m_CoordY = WIN_H_HALF;
    m_VelocityX = vX;
    m_VelocityY = vY;
}

//void Ball::UpdateSpeed(float velX, float velY)
//{
//    m_VelocityX = velX;
//    m_VelocityY = velY;
//}
