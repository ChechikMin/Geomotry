#include "Utils.h"


class Work
{
public:
    void action(Polygon* polygon) const;

private:
};

void Work::action(Polygon* polygon) const
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
    Polygon::Point p{ 1, 1 };
    Polygon::Line r{p, {2,2}};

    Polygon::Point p1{ 1, 1 };
    Polygon::Point p2{ 1, 2 };
    Polygon::Point p3{ 2, 2 };
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

    Polygon::Point p4{ 1, 1 };
    Polygon::Point p5{ 1, 2 };
    Polygon::Point p6{ 2, 2 };
    Polygon::Point p7{ 2, 1 };

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

    try {

        std::unique_ptr<Polygon*> poly2 = std::make_unique<Polygon*>(new Triangle( points ));
        std::unique_ptr<Polygon*> poly3 = std::make_unique<Polygon*>(new Rectangle( points1 ));
        std::unique_ptr<Polygon*> poly1 = std::make_unique<Polygon*>(new Circle( p, r ));

        Work * work = new Work;

        work->action( *poly1 );
        work->action( *poly2 );
        work->action( *poly3 );
        

        delete work;

    } catch ( std::exception & ex ) {
        std::cerr << ex.what() << "\n";
    }

    //    delete poly1;

    //    delete poly3;

    return 0;
}
