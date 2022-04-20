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

        for (std::shared_ptr<Line> p : m_lines) {
            int cnt = std::count_if(m_lines.begin(), m_lines.end(), [&](std::shared_ptr<Line>& line)
                { return p->begin.x == line.get()->begin.x && line.get()->begin.y == p->begin.y; });

            int cnt1 = std::count_if(m_lines.begin(), m_lines.end(), [&](std::shared_ptr<Line>& line)
                { return p->begin.x == line.get()->begin.x || line.get()->begin.y == p->begin.y; });

            if (cnt > 1 || cnt1 > 2) // 3 - if point lay on 1 line. 1 - if equal points
                throw std::logic_error("wrong input point Triangle");

        }

        for ( std::shared_ptr<Line> l : m_lines )
            p += l->getLineLen() / 2;

        for ( std::shared_ptr<Line> l : m_lines )
            m_s = m_s * ( p - l->getLineLen() );

        m_s *= p;

        m_s = std::sqrt( m_s );
        if ( m_s < 0 ) throw std::logic_error( "wrong input" );
    };

    virtual Area area() const noexcept override;
    virtual type getType() const noexcept override;
    virtual Point getCoordinate( nodeNum ) const noexcept override;

  private:
    std ::list<std::shared_ptr<Line>> m_lines{ 4 };
    mutable Area m_s = 1;
};

Area Triangle ::area() const noexcept
{
    return m_s;
}

type Triangle ::getType() const noexcept
{
    return Polygon::Triangle;
}

Polygon::Point Triangle ::getCoordinate( nodeNum nodeNum ) const noexcept
{
    int cnt = 0;
    for ( std::shared_ptr<Line> l : m_lines )
        if ( cnt++ == nodeNum ) return l->begin;
}


#endif // TRIANGLE_H
