#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Polygon.h"

class Rectangle : public Polygon
{
public:
    explicit Rectangle(const std::list<std::shared_ptr<Line>>& lines)
        : m_lines(lines)
    {

        m_s = m_lines.front()->getLineLen() * m_lines.front()->getLineLen();
        if (m_s < 0) throw std::logic_error("wrong input");
    }

    virtual float area() const noexcept override;
    virtual type getType() const noexcept override;
    virtual Point getCoordinate(nodeNum) const noexcept override;

private:
    std::list<std::shared_ptr<Line>> m_lines{ 3 };
    mutable Area m_s = 0;
};

float Rectangle::area() const noexcept
{
    return m_s;
}

type Rectangle::getType() const noexcept
{
    return Polygon::Rectangle;
}
Polygon::Point Rectangle::getCoordinate(nodeNum nodeNum) const noexcept
{
    int cnt = 0;
    for (std::shared_ptr<Line> p : m_lines)
        if (cnt++ == nodeNum) return p->begin;
}

#endif // RECTANGLE_H