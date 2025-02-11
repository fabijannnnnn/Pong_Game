#ifndef PONG_RACKET_H
#define PONG_RACKET_H

#include "ball.h"

class Racket : public Ball{

private:
    float m_Width, m_Height;

public:
    Racket(float posX, float posY, float vX, float vY);
    ~Racket();

    void DrawRacket(Color c);
    void ResetRacket(float posY);
    Rectangle GetRect();

};


#endif //PONG_RACKET_H
