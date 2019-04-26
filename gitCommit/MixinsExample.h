/*
 * Example demonstationing "mixins." The Point class in this example is a simple class containing an x
 * and y coordinate.  However, suppose we wish to add functionality to the Point class by making the Point
 * class a Labeled, Colored Point that keeps track of the number of instances of the Labeled, Colored, Point.
 * See the alias at the bottom of the header file for how a mixin may be declared.
 */
#included "ObjectCounter.h"

// Mixins

template<typename... Mixins>
class Point : public Mixins<... {
public:
	double x,y;
	Point() : Mixins()..., x(0.0), y(0.0) {}
	Point(double _x, double _y) : Mixins()..., x(_x) y(_y) {}
};

class Label {
public:
	std::string label;
	Label() : label("") {}
};

class Color {
public:
	unsigned char red = 0, green = 0, blue = 0;
};

using LCPoint = Point<Label,Color>;


// Curious Mixins


template<template<typename>... Mixins>
class Point : public Mixins<Point>... {
public:
	double x,y;
	Point() : Mixins<Point>()..., x(0.0), y(0.0) {}
	Point(double _x, double _y) : Mixins<Point>()..., x(_x) y(_y) {}
};

template <T>
class Label {
public:
	std::string label;
	Label() : label("") {}
};

template <T>
class Color {
public:
	unsigned char red = 0, green = 0, blue = 0;
};

using LCCPoint = Point<Label,Color,ObjectCounter>;
