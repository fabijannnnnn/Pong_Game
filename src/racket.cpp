#include "racket.h"
#include <iostream>

Racket::Racket() :
    m_Height(120),
    m_Width(20),
    m_Speed(500),
    m_Score(0),
    m_CoordX(0),
    m_CoordY(0)
{
    std::cout << "Racket constructed successfully\n";
}

Racket::~Racket()
{
    std::cout << "Racket destructed successfully\n";
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

uint16_t Racket::AddScore()
{
    m_Score++;
    return m_Score;
}
