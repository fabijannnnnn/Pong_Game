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
