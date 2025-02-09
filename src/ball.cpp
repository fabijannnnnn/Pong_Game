#include "ball.h"

Ball::Ball(float x, float y) :
        m_CoordX(x),
        m_CoordY(y),
        m_VelocityX(SPEED_SLOW),
        m_VelocityY(SPEED_SLOW)
{
//    std::cout << "Construction successful\n";
}

Ball::~Ball() {
//    std::cout << "Destruction successful\n";
}

void Ball::DrawBall(Color c) const {
    DrawCircle(int(m_CoordX), int(m_CoordY), BALL_RADIUS, c);
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

void Ball::ResetBall()
{
    m_CoordX = WIN_W_HALF;
    m_CoordY = WIN_H_HALF;
    m_VelocityX = SPEED_SLOW;
    m_VelocityY = SPEED_SLOW;
}

void Ball::UpdateSpeed(float velX, float velY)
{
    m_VelocityX = velX;
    m_VelocityY = velY;
}
