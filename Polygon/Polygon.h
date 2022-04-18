#ifndef POLYGON_H
#define POLYGON_H
#define _USE_MATH_DEFINES
#include <list>
#include <cmath>
#include <memory>
#include <regex>
#include <string>

using Area = float;
using type = uint8_t;
using nodeNum = int;

class Polygon
{
  protected:
    enum
    {
        Triangle,
        Rectangle,
        Circle
    };

  public:
    struct Point
    {
        float x;
        float y;
    };

    struct Line
    {
        Point begin;
        Point end;

        float getLineLen() const
        {
            return std::sqrt( std::pow( begin.x - end.x, 2 ) + std::pow( begin.y - end.y, 2 ) );
            ;
        };
    };

  public:
    static std::string serialize( const Polygon * polygon )
    {
        std::string serialized = "";
        int msgSize = 0;
        switch ( polygon->getType() ) {

            case Triangle:
                msgSize = 3;
                break;
            case Rectangle:
                msgSize = 4;
                break;
            case Circle:
                msgSize = 1;
                break;
        }
        for ( int i = 0; i < msgSize; i++ )
            serialized += "(x" + std::to_string( i ) + ",y" + std::to_string( i ) + "): ("
                          + std::to_string( polygon->getCoordinate( i ).x ) + ","
                          + std::to_string( polygon->getCoordinate( i ).y ) + ")\n";

        return serialized;
        ;
    };

    virtual Polygon * deSerialize( std::string & serialized ) = 0;
    virtual Area area() const = 0;
    virtual Point getCoordinate( nodeNum ) const = 0;
    virtual float getParam() const = 0;
    virtual type getType() const = 0;

    virtual ~Polygon() = default;
};

#endif // POLYGON_H
