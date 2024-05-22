#ifndef TOUCHBOX_H
#define TOUCHBOX_H


class TouchBox
{
public:
    TouchBox(int _x = 0, int _y = 0, int _w = 0, int _h = 0) : x(_x), y(_y), w(_w), h(_h) {}

    bool isTouch(TouchBox other);
    void setBox(int _x, int _y, int _w, int _h);


public:
    int x;
    int y;
    int w;
    int h;
};

#endif // TOUCHBOX_H
