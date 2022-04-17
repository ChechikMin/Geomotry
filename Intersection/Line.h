#pragma once
#include <iostream>



struct Point {
    float x = 0;
    float y = 0;
};
struct Line
{
    Point begin{};
    Point end{};
};

template <typename T>
constexpr bool hasIntersection(const Line& line1, const Line& line2) {
    
    T dX1 = line1.begin.x - line1.end.x;
    T dY1 = line1.begin.y - line1.end.y;

    if (!dX1 || !dY1)
        return false;
    T k1 = dY1 / dX1;
    //
    T dX2 = line2.begin.x - line2.end.x;
    T dY2 = line2.begin.y - line2.end.y;
    //
    if (!dX2 || !dY2)
        return false;
    //
    T k2 = dY2 / dX2;

    if (k1 == k2)
        return false;

    T x_ = (-line1.begin.y + line2.begin.y + line1.begin.x * k1 - line2.begin.x * k2) / (k1 - k2);
    T y_ = line1.begin.y + x_ - line1.begin.x * k1;

    return   x_ <= std::max(line1.begin.x, line1.end.x) && x_  >= std::max(line2.begin.x, line2.end.x) &&
             y_  <= std::max(line1.begin.y, line1.end.y) && y_ >= std::max(line2.begin.y, line2.end.y);

};