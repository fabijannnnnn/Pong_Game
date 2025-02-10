#ifndef PONG_RACKET_H
#define PONG_RACKET_H

#include "settings.h"
#include "ball.h"

class Racket : public Ball{

private:
    float m_CoordX, m_CoordY, m_Speed, m_Width, m_Height;

public:
    explicit Racket(float x);
//     constructor made explicit in order to prevent of unwanted accidental conversions
    ~Racket();

    void Position(float x, float y);

    void DrawRacket(Color c);

    Rectangle GetRect();

    float GetY() const;

    void SetY(float y);

    void


};


#endif //PONG_RACKET_H
