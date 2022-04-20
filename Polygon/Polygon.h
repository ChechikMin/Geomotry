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

  public:

      enum
      {
          Triangle,
          Square,
          Circle
      };

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

    virtual Area area() const noexcept = 0;
    virtual Point getCoordinate( nodeNum ) const noexcept = 0;
    virtual type getType() const noexcept = 0;


    virtual ~Polygon() = default;
};

#endif // POLYGON_H
