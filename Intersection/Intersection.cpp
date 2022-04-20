#include "Line.h"

int main()
{
    Point point1 = { 1, 2.1 };
    Point point2 = { -2, 2.1 };

    Point point3 = { -1, 2.1 };
    Point point4 = { 2, -2.1 };

    Line line1 = { point1, point2 };
    Line line2 = { point3, point4 };

    std::cout << hasIntersection(line1, line2) << "\n";
    std::cout << hasIntersection(Line{1, 2, 5, 7}, Line {3, 3, 4, 5} ) << "\n";
    std::cout << hasIntersection(Line{ 1, -2, 1, 2 }, Line{ 1, 2, -1, 2 }) << "\n";
    std::cout << hasIntersection<(Line{ 1, 2, -1, 0 }, Line{ 1, -2, -1, -2 }) << "\n";
}

