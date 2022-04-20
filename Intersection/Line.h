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

template <typename T = float>
constexpr bool hasIntersection(const Line& line1, const Line& line2) {
    
    T dX1 = line1.begin.x - line1.end.x;
    T dY1 = line1.begin.y - line1.end.y;

    if (!dX1 || !dY1)
        return false;
    T k1 = dY1 / dX1;
    //y1 = k1 * x1 + y01  - equation of line
    T dX2 = line2.begin.x - line2.end.x;
    T dY2 = line2.begin.y - line2.end.y;
    
    if (!dX2 || !dY2)
        return false;
    //y2 = k2 * x + y02
    T k2 = dY2 / dX2;
    //line are parellel or the same
    if (k1 == k2)
        return false;

    //-y01 + y02 + k1 * x01 - k2*x02
    //------------------------------ = x_ - point of intersection
    //          k1 - k2

    T x_ = (-line1.begin.y + line2.begin.y + line1.begin.x * k1 - line2.begin.x * k2) / (k1 - k2);
    T y_ = line1.begin.y + x_ - line1.begin.x * k1;

    //if x_  belong{line1.begin.x, line1.end.x, line2.begin.x, line2.end.x}
    //
    //&& y_ belong {line1.begin.y, line1.end.y, line2.begin.y, line2.end.y}
    return   x_ <= std::max(line1.begin.x, line1.end.x) && x_  >= std::max(line2.begin.x, line2.end.x) &&
             y_  <= std::max(line1.begin.y, line1.end.y) && y_ >= std::max(line2.begin.y, line2.end.y);

};