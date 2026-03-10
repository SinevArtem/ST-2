// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include <utility>
#include "circle.h"
#include "tasks.h"

const double EPSILON = 1e-8;

TEST(CircleTest, DefaultConstructor) {
    Circle c;
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, SetRadius) {
    Circle c;
    c.setRadius(5.0);
    EXPECT_DOUBLE_EQ(5.0, c.getRadius());
    EXPECT_DOUBLE_EQ(2.0 * M_PI * 5.0, c.getFerence());
    EXPECT_DOUBLE_EQ(M_PI * 25.0, c.getArea());
}

TEST(CircleTest, SetRadiusZero) {
    Circle c;
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, SetRadiusNegativeThrows) {
    Circle c;
    EXPECT_THROW(c.setRadius(-5.0), std::invalid_argument);
}

TEST(CircleTest, SetFerence) {
    Circle c;
    double ference = 10.0;
    c.setFerence(ference);
    double expectedRadius = ference / (2.0 * M_PI);
    EXPECT_DOUBLE_EQ(expectedRadius, c.getRadius());
    EXPECT_DOUBLE_EQ(ference, c.getFerence());
    EXPECT_DOUBLE_EQ(M_PI * expectedRadius * expectedRadius, c.getArea());
}

TEST(CircleTest, SetFerenceZero) {
    Circle c;
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, SetFerenceNegativeThrows) {
    Circle c;
    EXPECT_THROW(c.setFerence(-10.0), std::invalid_argument);
}

TEST(CircleTest, SetArea) {
    Circle c;
    double area = 50.0;
    c.setArea(area);
    double expectedRadius = std::sqrt(area / M_PI);
    EXPECT_NEAR(expectedRadius, c.getRadius(), EPSILON);
    EXPECT_NEAR(2.0 * M_PI * expectedRadius, c.getFerence(), EPSILON);
    EXPECT_NEAR(area, c.getArea(), EPSILON);
}

TEST(CircleTest, SetAreaZero) {
    Circle c;
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(0.0, c.getRadius());
    EXPECT_DOUBLE_EQ(0.0, c.getFerence());
    EXPECT_DOUBLE_EQ(0.0, c.getArea());
}

TEST(CircleTest, SetAreaNegativeThrows) {
    Circle c;
    EXPECT_THROW(c.setArea(-50.0), std::invalid_argument);
}

TEST(CircleTest, ConsistencyCheck) {
    Circle c;
    c.setRadius(10.0);
    double radius = c.getRadius();
    double ference = c.getFerence();
    double area = c.getArea();
    
    c.setFerence(ference);
    EXPECT_DOUBLE_EQ(radius, c.getRadius());
    EXPECT_DOUBLE_EQ(ference, c.getFerence());
    EXPECT_NEAR(area, c.getArea(), EPSILON);
}

TEST(CircleTest, LargeRadius) {
    Circle c;
    c.setRadius(1e6);
    EXPECT_DOUBLE_EQ(1e6, c.getRadius());
    EXPECT_DOUBLE_EQ(2.0 * M_PI * 1e6, c.getFerence());
    EXPECT_DOUBLE_EQ(M_PI * 1e12, c.getArea());
}

TEST(CircleTest, SmallRadius) {
    Circle c;
    c.setRadius(1e-6);
    EXPECT_DOUBLE_EQ(1e-6, c.getRadius());
    EXPECT_DOUBLE_EQ(2.0 * M_PI * 1e-6, c.getFerence());
    EXPECT_DOUBLE_EQ(M_PI * 1e-12, c.getArea());
}

TEST(EarthRopeTest, ReturnsCorrectGap) {
    double gap = resolveEarthAndCordTask();
    
    double expectedGap = 1.0 / (2.0 * M_PI);
    EXPECT_NEAR(expectedGap, gap, 1e-8);
    EXPECT_NEAR(0.159154943091895, gap, 1e-8);
}

TEST(EarthRopeTest, GapInCentimeters) {
    double gapM = resolveEarthAndCordTask();
    double gapCm = gapM * 100.0;
    
    EXPECT_NEAR(15.9154943091895, gapCm, 1e-6);
}

TEST(EarthRopeTest, GapIsPositive) {
    double gap = resolveEarthAndCordTask();
    EXPECT_GT(gap, 0.0);
}

TEST(EarthRopeTest, GapIsReasonable) {
    double gap = resolveEarthAndCordTask();
    EXPECT_GT(gap, 0.15);
    EXPECT_LT(gap, 0.17);
}

TEST(EarthRopeTest, GapMathematicalProof) {
    double gap = resolveEarthAndCordTask();
    
    Circle testCircle;
    testCircle.setRadius(1000.0);
    double testFerence = testCircle.getFerence() + 1.0;
    testCircle.setFerence(testFerence);
    double testGap = testCircle.getRadius() - 1000.0;
    
    EXPECT_NEAR(gap, testGap, 1e-10);
}

TEST(PoolTest, ReturnsPairOfDoubles) {
    auto result = resolvePoolTask();
    
    bool isPair = std::is_same<decltype(result), std::pair<double, double>>::value;
    EXPECT_TRUE(isPair);
}

TEST(PoolTest, ConcreteCost) {
    auto result = resolvePoolTask();
    double concreteCost = result.first;
    
    EXPECT_NEAR(21991.1485751286, concreteCost, 1e-4);
}

TEST(PoolTest, FenceCost) {
    auto result = resolvePoolTask();
    double fenceCost = result.second;
    
    EXPECT_NEAR(50265.4824574366, fenceCost, 1e-4);
}

TEST(PoolTest, TotalCost) {
    auto result = resolvePoolTask();
    double totalCost = result.first + result.second;
    
    EXPECT_NEAR(72256.6310325652, totalCost, 1e-4);
}

TEST(PoolTest, ConcreteCostPositive) {
    auto result = resolvePoolTask();
    EXPECT_GT(result.first, 0.0);
}

TEST(PoolTest, FenceCostPositive) {
    auto result = resolvePoolTask();
    EXPECT_GT(result.second, 0.0);
}

TEST(PoolTest, PathArea) {
    auto result = resolvePoolTask();
    double concreteCost = result.first;
    double pathArea = concreteCost / 1000.0;
    
    double expectedPathArea = M_PI * (4.0*4.0 - 3.0*3.0);
    EXPECT_NEAR(expectedPathArea, pathArea, 1e-7);
}

TEST(PoolTest, FenceLength) {
    auto result = resolvePoolTask();
    double fenceCost = result.second;
    double fenceLength = fenceCost / 2000.0;
    
    double expectedFenceLength = 2.0 * M_PI * 4.0;
    EXPECT_NEAR(expectedFenceLength, fenceLength, 1e-7);
}

TEST(PoolTest, PathAreaDirect) {
    Circle pool;
    pool.setRadius(3.0);
    
    Circle poolWithPath;
    poolWithPath.setRadius(4.0);
    
    double pathArea = poolWithPath.getArea() - pool.getArea();
    EXPECT_NEAR(21.9911485751286, pathArea, 1e-10);
}

TEST(PoolTest, FenceLengthDirect) {
    Circle poolWithPath;
    poolWithPath.setRadius(4.0);
    
    double fenceLength = poolWithPath.getFerence();
    EXPECT_NEAR(25.1327412287183, fenceLength, 1e-10);
}

TEST(PoolTest, ConcreteCostCalculation) {
    Circle pool;
    pool.setRadius(3.0);
    
    Circle poolWithPath;
    poolWithPath.setRadius(4.0);
    
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double concreteCost = pathArea * 1000.0;
    
    auto result = resolvePoolTask();
    EXPECT_NEAR(concreteCost, result.first, 1e-7);
}

TEST(PoolTest, FenceCostCalculation) {
    Circle poolWithPath;
    poolWithPath.setRadius(4.0);
    
    double fenceLength = poolWithPath.getFerence();
    double fenceCost = fenceLength * 2000.0;
    
    auto result = resolvePoolTask();
    EXPECT_NEAR(fenceCost, result.second, 1e-7);
}

TEST(PoolTest, CostRounding) {
    auto result = resolvePoolTask();
    
    double concreteKopecks = result.first * 100;
    double fenceKopecks = result.second * 100;
    double totalKopecks = (result.first + result.second) * 100;
    
    EXPECT_NEAR(concreteKopecks, round(concreteKopecks), 1);
    EXPECT_NEAR(fenceKopecks, round(fenceKopecks), 1);
    EXPECT_NEAR(totalKopecks, round(totalKopecks), 1);
}
