#ifndef CIRCLE_H
#define CIRCLE_H
#include "Polygon.h"
#include <algorithm>
class Circle : public Polygon
{
  public:
    explicit Circle(const Point & point, const float & radius )
      : m_centr( std::make_shared<Point>(point) )
      , m_radius( radius )
    {
        m_s = M_PI * m_radius * m_radius;
    };

    virtual Polygon * deSerialize( std::string & serialized ) override;

    virtual float getParam() const override;
    virtual Area area() const override;
    virtual type getType() const override;
    virtual Point getCoordinate( nodeNum ) const override;

  private:
    mutable float m_radius;
    mutable std::shared_ptr<Point> m_centr;
    mutable Area m_s = 0;
};
float Circle ::getParam() const
{
    return m_radius;
}

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
    return { m_centr->x, m_centr->y };
}

Polygon * Circle ::deSerialize( std::string & serialized )
{

    return this;
}

#endif // CIRCLE_H
