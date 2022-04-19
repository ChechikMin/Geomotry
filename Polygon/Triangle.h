#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon
{
  public:
    explicit Triangle( const std ::list<std::shared_ptr<Line>> & lines )
      : m_lines( lines )
    {
        float p = 0;
        for ( std::shared_ptr<Line> l : m_lines )
            p += l->getLineLen() / 2;

        for ( std::shared_ptr<Line> l : m_lines )
            m_s = m_s * ( p - l->getLineLen() );

        m_s *= p;

        m_s = std::sqrt( m_s );
        if ( m_s < 0 ) throw std::logic_error( "infinity area" );
    };

    virtual Area area() const override;
    virtual type getType() const override;
    virtual Point getCoordinate( nodeNum ) const override;

  private:
    std ::list<std::shared_ptr<Line>> m_lines{ 4 };
    mutable Area m_s = 1;
};

Area Triangle ::area() const
{
    return m_s;
}

type Triangle ::getType() const
{
    return Polygon::Triangle;
}

Polygon::Point Triangle ::getCoordinate( nodeNum nodeNum ) const
{
    int cnt = 0;
    for ( std::shared_ptr<Line> l : m_lines )
        if ( cnt++ == nodeNum ) return l->begin;
}


#endif // TRIANGLE_H
