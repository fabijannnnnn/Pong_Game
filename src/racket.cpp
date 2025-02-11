#include "racket.h"

Racket::Racket(float x, float vY) :
    Ball(x, WIN_H_HALF, 0, vY),
    m_Height(RAC_HEIGHT),
    m_Width(RAC_WIDTH)
{
    m_SpeedY = SPEED_FAST;
}

Racket::~Racket() = default;

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
//    changes the centre of the rectangle to the middle
    return Rectangle{m_CoordX - m_Width / 2, m_CoordY - m_Height / 2, m_Width, m_Height};
}
