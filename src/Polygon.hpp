#pragma once
#include <vector>
#include <raylib.h>

class Polygon {
    std::vector<Vector2> m_points; // of authority

public:
    Polygon(std::initializer_list<Vector2> points);

    auto& getPoints() { return m_points; }

    float flipCollideX(Polygon& other, float xa);
    float flipCollideY(Polygon& other, float ya);

    Rectangle getRect();

    void draw();
    void move(float xa, float ya);
};