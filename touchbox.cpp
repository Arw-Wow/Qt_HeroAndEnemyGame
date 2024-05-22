#include "touchbox.h"


bool TouchBox::isTouch(TouchBox other)
{
    if (x + w >= other.x && x <= other.x + other.w && y + h >= other.y && y <= other.y + other.h)
        return true;
    return false;
}

void TouchBox::setBox(int _x, int _y, int _w, int _h)
{
    x = _x;
    y = _y;
    w = _w;
    h = _h;

}
