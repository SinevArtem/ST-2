// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"
#include <cmath>
#include <stdexcept>
#include <utility>

double resolveEarthAndCordTask() {
    const double EARTH_RADIUS_KM = 6378.1;
    const double ADDED_LENGTH_M = 1.0;
    
    Circle earth;
    earth.setRadius(EARTH_RADIUS_KM * 1000.0);
    
    double newFerence = earth.getFerence() + ADDED_LENGTH_M;
    
    Circle newCircle;
    newCircle.setFerence(newFerence);
    
    return newCircle.getRadius() - earth.getRadius();
}

std::pair<double, double> resolvePoolTask() {
    const double POOL_RADIUS = 3.0;
    const double PATH_WIDTH = 1.0;
    const double CONCRETE_PRICE = 1000.0;
    const double FENCE_PRICE = 2000.0;
    
    Circle pool;
    pool.setRadius(POOL_RADIUS);
    
    Circle poolWithPath;
    poolWithPath.setRadius(POOL_RADIUS + PATH_WIDTH);
    
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double concreteCost = pathArea * CONCRETE_PRICE;
    
    double fenceLength = poolWithPath.getFerence();
    double fenceCost = fenceLength * FENCE_PRICE;
    
    return std::make_pair(concreteCost, fenceCost);
}
