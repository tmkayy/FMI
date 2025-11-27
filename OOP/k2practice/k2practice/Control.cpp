#include "Control.h"


void Control::copyFrom(const Control& other)
{
    loc = other.loc;
    height = other.height;
    width = other.width;
}

int Control::getHeight() const
{
    return height;
}

int Control::getWidth() const
{
    return width;
}

Location Control::getLoc() const
{
    return loc;
}

void Control::setLoc(int x, int y)
{
    loc.setX(x);
    loc.setY(y);
}

void Control::setHeight(int h)
{
    if (h < 0)
        throw std::invalid_argument("cant be negative");
    height = h;
}

void Control::setWidth(int w)
{
    if (w < 0)
        throw std::invalid_argument("cant be negative");
    width = w;
}

Control::Control(int x, int y, int h, int w)
{
    loc = Location(x, y);
    setHeight(h);
    setWidth(w);
}
