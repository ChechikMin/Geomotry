#pragma once
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <vector>

namespace Utils {


    static std::string serializeToString(const Polygon* polygon)
    {
        std::string serialized = "";
        int msgSize = 0;
        switch (polygon->getType()) {

        case Polygon::Triangle:
            serialized += "Triangle\n";
            msgSize = 3;
            break;
        case Polygon::Rectangle:
            serialized += "Rectangle\n";
            msgSize = 4;
            break;
        case Polygon::Circle:
            serialized += "Circle\nr = " + std::to_string(polygon->getCoordinate(1).x) + "\n";
            msgSize = 1;
            break;
        }
        for (int i = 0; i < msgSize; i++)
            serialized += "(x" + std::to_string(i) + ",y" + std::to_string(i) + "): ("
            + std::to_string(polygon->getCoordinate(i).x) + ","
            + std::to_string(polygon->getCoordinate(i).y) + ")\n";

        return serialized;
        ;
    };

    static Polygon* deSerializeFromString(std::string& serialized)
    {
        std::string tmp = serialized.substr(0, serialized.find("\n") );
        std::regex r(R"([-+]?\d*\.?\d+(?:[eE][-+]?\d+)?)");
        int j = 0;
        float radius = 0.f;


        std::vector<float> data;

        for (std::sregex_iterator i = std::sregex_iterator(serialized.begin(), serialized.end(), r);
            i != std::sregex_iterator();
            ++i)
        {
            std::smatch m = *i;
            data.push_back(std::stof(m.str()));
        }

        if (tmp == "Circle")
        {
           
            return new Circle({ data[3], data[4] }, { { data[3], data[4] }, { data[3] + data[0], data[4] + data[0]}});
        }
        else if (tmp == "Rectangle") 
        {

            Polygon::Point p4{ data[3], data[4] };
            Polygon::Point p5{ data[6], data[7] };
            Polygon::Point p6{ data[9], data[10] };
            Polygon::Point p7{ data[12], data[13] };

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
            r4->end = p4;

            std::list<std::shared_ptr<Polygon::Line>> points1 = { r1, r2, r3, r4 };
            return new Rectangle(points1);
        }


        Polygon::Point p4{ data[3], data[4] };
        Polygon::Point p5{ data[6], data[7] };
        Polygon::Point p6{ data[9], data[10] };
        std::shared_ptr<Polygon::Line> l1 = std::make_shared<Polygon::Line>();
        l1->begin = p4;
        l1->end = p5;
        std::shared_ptr<Polygon::Line> l2 = std::make_shared<Polygon::Line>();
        ;
        l2->begin = p5;
        l2->end = p6;
        std::shared_ptr<Polygon::Line> l3 = std::make_shared<Polygon::Line>();
        ;
        l3->begin = p6;
        l3->end = p4;

        std::list<std::shared_ptr<Polygon::Line>> points = { l1, l2, l3 };

        return new Triangle(points);
    };

}