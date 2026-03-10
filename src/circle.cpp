// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle() {
    radius = 0.0;
    area = 0.0;
    ference = 0.0;
}

double Circle::getArea() const {
    return area;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double _radius) {
    if (_radius < 0.0) {
        throw std::invalid_argument("Radius cannot be negative");
    }
    radius = _radius;
    ference = 2.0 * M_PI * radius;
    area = M_PI * radius * radius;
}

void Circle::setArea(double _area) {
    if (_area < 0.0) {
        throw std::invalid_argument("Area cannot be negative");
    }
    area = _area;
    radius = sqrt(area / M_PI);
    ference = 2.0 * M_PI * radius;
}

void Circle::setFerence(double _ference) {
    if (_ference < 0.0) {
        throw std::invalid_argument("Ference cannot be negative");
    }
    ference = _ference;
    radius = ference / (2.0 * M_PI);
    area = M_PI * radius * radius;
}
