#include "Utils.h"


class Work
{
public:
    void process(Polygon* polygon) const;

private:
};

void Work::process(Polygon* polygon) const
{
    std::string str = Utils::serializeToString(polygon);
    std::cout << str;
    std::cout << "Area:" << polygon->area() << "\n";

    Polygon* dePoly = Utils::deSerializeFromString(str);

    std::cout << "Area deSerialized:" << dePoly->area() << "\n";
    std::cout << "|||||||||||||||||||||||||||||||\n";
    delete dePoly;
}

int main( int argc, char * argv[] )
{
    ///Number of Nodes for input like
    //
    // 2 -- 3
    // |    |
    // |    |
    // 1    4
    // 
    // for Circle
    // 
    // one point is center, second point lay on circle
    // 
    // 
    //////////////////////////
    Polygon::Point p{ 0, 0 };
    Polygon::Line r{p, {0,0}};
    //////////////////////////Circle
    Polygon::Point p1{ 1, -0 };
    Polygon::Point p2{ 1, 2 };
    Polygon::Point p3{ 5, 3 };
    std::shared_ptr<Polygon::Line> l1 = std::make_shared<Polygon::Line>();
    l1->begin = p1;
    l1->end = p2;
    std::shared_ptr<Polygon::Line> l2 = std::make_shared<Polygon::Line>();
    ;
    l2->begin = p2;
    l2->end = p3;
    std::shared_ptr<Polygon::Line> l3 = std::make_shared<Polygon::Line>();
    ;
    l3->begin = p3;
    l3->end = p1;

    std::list<std::shared_ptr<Polygon::Line>> points = { l1, l2, l3 };
    ///////////////////////Triangle

    Polygon::Point p4{ 1, 1 };
    Polygon::Point p5{ 1, 8.02};
    Polygon::Point p6{ 3, 8.02 };
    Polygon::Point p7{ 3, 1 };

    std::shared_ptr<Polygon::Line> r1 = std::make_shared<Polygon::Line>();
    ;
    r1->begin = p4;
    r1->end = p5;
    std::shared_ptr<Polygon::Line> r2 = std::make_shared<Polygon::Line>();
    ;
    r2->begin = p5;
    r2->end = p6;
    std::shared_ptr<Polygon::Line> r3 = std::make_shared<Polygon::Line>();
    ;
    r3->begin = p6;
    r3->end = p7;
    std::shared_ptr<Polygon::Line> r4 = std::make_shared<Polygon::Line>();
    r4->begin = p7;
    r4->end = p1;

    std::list<std::shared_ptr<Polygon::Line>> points1 = { r1, r2, r3, r4 };
    //////////////////////////////Rectangle

    try {

        std::unique_ptr<Polygon*> poly2 = std::make_unique<Polygon*>(new Triangle( points ));
        std::unique_ptr<Polygon*> poly3 = std::make_unique<Polygon*>(new Square( points1 ));
        std::unique_ptr<Polygon*> poly1 = std::make_unique<Polygon*>(new Circle( p, r ));

        Work * work = new Work;

        work->process( *poly1 );
        work->process( *poly2 );
        work->process( *poly3 );
        

        delete work;

    } catch ( std::exception & ex ) {
        std::cerr << ex.what() << "\n";
    }
    ////////////////////////Process

    //    delete poly1;

    //    delete poly3;

    return 0;
}


/*
Output

Circle
r = 1.414214
(xA,yA): (1.000000,1.000000)
Area:6.28319
Area deSerialized:6.28319
|||||||||||||||||||||||||||||||
Triangle
(xA,yA): (1.000000,1.000000)
(xB,yB): (1.000000,2.000000)
(xC,yC): (2.000000,2.000000)
Area:0.5
Area deSerialized:0.5
|||||||||||||||||||||||||||||||
Rectangle
(xA,yA): (1.000000,1.000000)
(xB,yB): (1.000000,2.000000)
(xC,yC): (2.000000,2.000000)
(xD,yD): (2.000000,1.000000)
Area:1
Area deSerialized:1
|||||||||||||||||||||||||||||||
*/