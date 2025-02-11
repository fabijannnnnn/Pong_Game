#include "racket.h"

Racket::Racket(float x, float y, float vX, float vY) :
    Ball(x, y, vX, vY),
    m_Height(RAC_HEIGHT),
    m_Width(RAC_WIDTH)
{
    m_VelocityY = SPEED_FAST;
    std::cout << "Racket constructed successfully\n";
}

Racket::~Racket()
{
    std::cout << "Racket destructed successfully\n";
}

void Racket::DrawRacket(Color c)
{
    DrawRectangleRec(GetRect(), c);
}

void Racket::ResetRacket(float y)
{
    m_CoordY = y;
}

Rectangle Racket::GetRect()
{
    return Rectangle{m_CoordX - m_Width / 2, m_CoordY - m_Height / 2, m_Width, m_Height};
}


