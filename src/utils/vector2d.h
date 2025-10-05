// point/vector math

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <cmath>
#include <SDL.h>

class Vector2D
{
public:
    float x, y;

    Vector2D() : x(0), y(0) {}
    Vector2D(float x, float y) : x(x), y(y) {}

    Vector2D operator+(const Vector2D &v) const
    {
        return Vector2D(x + v.x, y + v.y);
    }

    Vector2D operator-(const Vector2D &v) const
    {
        return Vector2D(x - v.x, y - v.y);
    }

    Vector2D operator*(float scalar) const
    {
        return Vector2D(x * scalar, y * scalar);
    }

    Vector2D operator/(float scalar) const
    {
        return Vector2D(x / scalar, y / scalar);
    }

    bool operator==(const Vector2D &v) const
    {
        return x == v.x && y == v.y;
    }

    bool operator!=(const Vector2D &v) const
    {
        return !(*this == v);
    }

    float length() const
    {
        return std::sqrt(x * x + y * y);
    }

    double distanceTo(const Vector2D &v) const
    {
        return (*this - v).length();
    }

    Vector2D normalized() const
    {
        float len = length();
        if (len == 0)
            return Vector2D(0, 0);
        return Vector2D(x / len, y / len);
    }

    SDL_Point toSDLPoint() const
    {
        return SDL_Point{static_cast<int>(x), static_cast<int>(y)};
    }
};

#endif // VECTOR2D_H