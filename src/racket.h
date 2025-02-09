#ifndef PONG_RACKET_H
#define PONG_RACKET_H

#include "raylib.h"
#include <string>

class Racket {
private:
    float m_CoordX, m_CoordY, m_Speed, m_Width, m_Height;
    uint16_t m_Score;

public:
    explicit Racket();
//     constructor made explicit in order to prevent of unwanted accidental conversions
    ~Racket();

    void Position(float x, float y);

    void DrawRacket(Color c);

    Rectangle GetRect();

    uint16_t AddScore();
};


#endif //PONG_RACKET_H
