#include "racket.h"

Racket::Racket(float x) :
    m_Height(RAC_HEIGHT),
    m_Width(RAC_WIDTH),
    m_Speed(SPEED_FAST),
    m_CoordX(x),
    m_CoordY(RAC_POS_Y)
{
    std::cout << "Racket constructed successfully\n";
}

Racket::~Racket()
{
    std::cout << "Racket destructed successfully\n";
}

float Racket::GetY() const
{
    return m_CoordY;
}

void Racket::SetY(float y)
{
    m_CoordY = y;
}

void Racket::Position(float x, float y)
{
    m_CoordX = x;
    m_CoordY = y;
}

Rectangle Racket::GetRect()
{
    return Rectangle{(m_CoordX - m_Width / 2), (m_CoordY - m_Height / 2), m_Width, m_Height};
}

void Racket::DrawRacket(Color c)
{
    DrawRectangleRec(GetRect(), c);
}


