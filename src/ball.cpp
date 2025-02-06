#include "ball.h"

Ball::Ball(float x, float y) :
        m_CoordX(x / 2),
        m_CoordY(y/2),
        m_Radius(15.0f),
        m_VelocityX(500),
        m_VelocityY(500)
{
    std::cout << "Construction successful\n";
}

Ball::~Ball() {
    std::cout << "Destruction successful\n";
}

void Ball::Speed(float speedX, float speedY) {
    m_VelocityX = speedX;
    m_VelocityY = speedY;
}

void Ball::BallRadius(float val) {
    m_Radius = val;
}

void Ball::DrawBall(Color c) {
    DrawCircle(int(m_CoordX), int(m_CoordY), m_Radius, c);
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


