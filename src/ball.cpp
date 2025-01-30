#include "ball.h"
#include "raylib.h"

Ball::Ball() :
        m_CoordX(WIN_HEIGHT/2),
        m_CoordY(WIN_HEIGHT/2),
        m_Radius(10.0f),
        m_VelocityX(500),
        m_VelocityY(500)
{
    std::cout << "Construction successful\n";
}

Ball::~Ball() {
    std::cout << "Destruction successful\n";
}

void Ball::Speed(int speedX, int speedY) {
    m_VelocityX = speedX;
    m_VelocityY = speedY;
}

void Ball::BallRadius(float val) {
    m_Radius = val;
}

void Ball::DrawBall() {
    DrawCircle(m_CoordX, m_CoordY, m_Radius, B_COLOUR);
}
