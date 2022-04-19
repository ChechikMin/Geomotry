#ifndef CIRCLE_H
#define CIRCLE_H
#include "Polygon.h"
#include <algorithm>
class Circle : public Polygon
{
  public:
    explicit Circle(const Point & point, const Line & radius )
      : m_centr( std::make_shared<Point>(point) )
      , m_radius( radius )
    {
        m_s = M_PI * m_radius.getLineLen() * m_radius.getLineLen();
    };

    virtual Area area() const override;
    virtual type getType() const override;
    virtual Point getCoordinate( nodeNum ) const override;

  private:
    mutable Line m_radius;
    mutable std::shared_ptr<Point> m_centr;
    mutable Area m_s = 0;
};

Area Circle ::area() const
{
    return m_s;
};

type Circle ::getType() const
{
    return Polygon::Circle;
}

Polygon::Point Circle ::getCoordinate( nodeNum nodeNum ) const
{
    return nodeNum ? Point{ m_radius.getLineLen(),} : Point{ m_centr->x, m_centr->y };
}


#endif // CIRCLE_H
