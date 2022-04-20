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
        if (m_s < 0) throw std::logic_error("wrong input");
    };

    virtual Area area() const noexcept override;
    virtual type getType() const noexcept override;
    virtual Point getCoordinate( nodeNum ) const noexcept override;

  private:

    mutable Line m_radius;
    mutable std::shared_ptr<Point> m_centr;
    mutable Area m_s = 0;
};
///////////////////////////////////
Area Circle ::area() const noexcept
{
    return m_s;
};
///////////////////////////////////
type Circle ::getType() const noexcept
{
    return Polygon::Circle;
}
///////////////////////////////////
Polygon::Point Circle ::getCoordinate( nodeNum nodeNum ) const noexcept
{
    return nodeNum ? Point{ m_radius.getLineLen(),} : Point{ m_centr->x, m_centr->y };
}
///////////////////////////////////


#endif // CIRCLE_H
