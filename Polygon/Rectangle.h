#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Polygon.h"

class Rectangle : public Polygon
{
  public:
    explicit Rectangle( const std ::list<std::shared_ptr<Line>> & lines )
      : m_lines( lines )
    {

        m_s = m_lines.front()->getLineLen() * m_lines.front()->getLineLen();
    }

    virtual float area() const override;
    virtual type getType() const override;
    virtual float getParam() const override;
    virtual Polygon * deSerialize( std::string & serialized ) override;
    virtual Point getCoordinate( nodeNum ) const override;

  private:
    std ::list<std::shared_ptr<Line>> m_lines{ 3 };
    mutable Area m_s = 0;
};

float Rectangle ::area() const
{
    return m_s;
}
float Rectangle ::getParam() const
{
    return m_s;
}
type Rectangle ::getType() const
{
    return Polygon::Rectangle;
}
Polygon::Point Rectangle ::getCoordinate( nodeNum nodeNum ) const
{
    int cnt = 0;
    for ( std::shared_ptr<Line> p : m_lines )
        if ( cnt++ == nodeNum ) return p->begin;
}
Polygon * Rectangle ::deSerialize( std::string & serialized )
{
    size_t digits1 = serialized.find_last_of( "1234567890+-" );
    m_s = digits1;
    return this;
}

#endif // RECTANGLE_H
