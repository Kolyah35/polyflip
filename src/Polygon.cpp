#include <Polygon.hpp>
#include <raymath.h>

Polygon::Polygon(std::initializer_list<Vector2> points) {
    m_points = points;
}

float Polygon::flipCollideX(Polygon& other, float xa) {
    auto otherarr = other.getPoints();

    for(auto i = m_points.begin(); i != m_points.end(); i++) {
        auto next = (i + 1 == m_points.end() ? m_points.begin() : i + 1);
        auto vc = *i;
        auto vn = *next;

        for (auto j = otherarr.begin(); j != otherarr.end(); j++) {
            auto ov = *j;

            if((vc.y >= ov.y && vn.y < ov.y) || (vc.y < ov.y && vn.y >= ov.y)) {
                auto lineH = vn.y - vc.y;
                auto lineW = vn.x - vc.x;
                auto lineX = (ov.y - vc.y) / lineH * lineW + vc.x;

                if (xa > 0.f && ov.x <= lineX)
                    xa = std::min(lineX - ov.x - 0.1f, xa);

                if (xa < 0.f && ov.x >= lineX)
                    xa = std::max(xa, lineX - ov.x + 0.1f);
            }
        }
    }

    return xa;
}

float Polygon::flipCollideY(Polygon& other, float ya) {
    auto otherarr = other.getPoints();

    for(auto i = m_points.begin(); i != m_points.end(); i++) {
        auto next = (i + 1 == m_points.end() ? m_points.begin() : i + 1);
        auto vc = *i;
        auto vn = *next;

        for (auto j = otherarr.begin(); j != otherarr.end(); j++) {
            auto ov = *j;

            if((vc.x >= ov.x && vn.x < ov.x) || (vc.x < ov.x && vn.x >= ov.x)) {
                auto lineH = vn.y - vc.y;
                auto lineW = vn.x - vc.x;
                auto lineY = (ov.x - vc.x) / lineW * lineH + vc.y;

                if (ya > 0.f && ov.y <= lineY)
                    ya = std::min(lineY - ov.y - 0.1f, ya);

                if (ya < 0.f && ov.y >= lineY)
                    ya = std::max(ya, lineY - ov.y + 0.1f);
            }
        }
    }

    return ya;
}

void Polygon::draw() {
    for (int current = 0; current < m_points.size(); current++) {
       int next = current + 1;

       if (next == m_points.size()) next = 0;

       auto vc = m_points[current];    // c for "current"
       auto vn = m_points[next];       // n for "next"

       DrawLine(vc.x, vc.y, vn.x, vn.y, GREEN);
   }
}

void Polygon::move(float xa, float ya) {
    for(auto& vec : m_points) {
        vec.x += xa;
        vec.y += ya; 
    }
}

Rectangle Polygon::getRect() {
    Rectangle ret = {FLT_MAX, FLT_MAX, FLT_MIN, FLT_MIN};
    
    for(auto& vec : m_points) {
        ret.x = std::min(ret.x, vec.x);
        ret.y = std::min(ret.y, vec.y);
        ret.width = std::max(ret.x, ret.x - vec.x);
        ret.height = std::max(ret.y, ret.y - vec.y);
    }

    return ret;
}