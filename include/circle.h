// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_
#include <cstdint>


class Circle {
    double radius;
    double ference;
    double area;

public:
    Circle();

    void setRadius(double _radius);
    void setFerence(double _ference);
    void setArea(double _area);
    
    double getRadius() const;
    double getFerence() const;
    double getArea() const;

};

#endif  // INCLUDE_CIRCLE_H_
