#pragma once
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <vector>

namespace Utils {

    std::string serializeToString(const Polygon* polygon)
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
        {
            serialized += "(x";
            serialized += 'A' + i;
            serialized += ",y";
            serialized += 'A' + i;
            serialized += "): (" + std::to_string(polygon->getCoordinate(i).x) + ","
                + std::to_string(polygon->getCoordinate(i).y) + ")\n";;
        }

        return serialized;
        ;
    };

    Polygon* deSerializeFromString(std::string& serialized)
    {
        std::string header = serialized.substr(0, serialized.find_first_of("\n"));
        std::regex r(R"([-+]?\d*\.?\d+(?:[eE][-+]?\d+)?)");
        std::vector<float> data;

        for (std::sregex_iterator i = std::sregex_iterator(serialized.begin(), serialized.end(), r);
            i != std::sregex_iterator();
            ++i)
        {
            std::smatch m = *i;
            data.push_back(std::stof(m.str()));
        }

        if (header == "Circle")
        {
           
            return new Circle({ data[1], data[2] }, { { data[1], data[2] }, { data[1] , data[2] + data[0]}});
        }
        
        Polygon::Point p1{ data[0], data[1] };
        Polygon::Point p2{ data[2], data[3] };
        Polygon::Point p3{ data[4], data[5] };

        std::shared_ptr<Polygon::Line> l1 = std::make_shared<Polygon::Line>();

        l1->begin = p1;
        l1->end = p2;
        std::shared_ptr<Polygon::Line> l2 = std::make_shared<Polygon::Line>();

        l2->begin = p2;
        l2->end = p3;
        std::shared_ptr<Polygon::Line> l3 = std::make_shared<Polygon::Line>();
        
        if (header == "Rectangle")
        {

            
            Polygon::Point p4{ data[6], data[7] };

            l3->begin = p3;
            l3->end = p4;
            std::shared_ptr<Polygon::Line> l4 = std::make_shared<Polygon::Line>();
            l4->begin = p4;
            l4->end = p1;

            std::list<std::shared_ptr<Polygon::Line>> points1 = { l1, l2, l3, l4 };
            return new Rectangle(points1);
        }
        
        l3->begin = p3;
        l3->end = p1;

        std::list<std::shared_ptr<Polygon::Line>> points = { l1, l2, l3 };

        return new Triangle(points);
    };

}