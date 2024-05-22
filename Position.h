#ifndef POSITION_H
#define POSITION_H


struct Position {

public:

    Position(int x = 0, int y = 0) : x(x), y(y) {}

    void setPosition(int _x, int _y) {
        this->x = _x;
        this->y = _y;
    }


public:

    int x, y;


};






#endif // POSITION_H
