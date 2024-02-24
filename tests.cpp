//  Project 4: tests.cpp
//  Author: Jacky Yip
//  March 18, 2023
//  Description: This file contains many test cases. Every single function that has been used in both header files will have
//  test cases that shows whether they function correctly or not.

/// Provided testing file to implement
/// framework based tests in. The example
/// below uses the Catch testing framework
/// version that uses a single .hpp file.

// This tells Catch to provide a main()
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "shape.h"
#include "canvaslist.h"

using namespace std;

TEST_CASE("(0) no tests") 
{
  //
  // done
  //
}

// #####################################
// I. TEST CASE 1 -  constructor, x and y are 0
// #####################################
TEST_CASE("Shape default constructor") {
    Shape s;
    REQUIRE(s.getX() == 0);
    REQUIRE(s.getY() == 0);
}

// #####################################
// I. TEST CASE 2 -  parameterized constructor, x is 1, y is 3
// #####################################
TEST_CASE("Shape parameterized constructor 1") {
    Shape s(1, 3);
    REQUIRE(s.getX() == 1);
    REQUIRE(s.getY() == 3);
}

// #####################################
// II. TEST CASE 3 -  parameterized constructor, x is 0, y is 0
// #####################################
TEST_CASE("Shape parameterized constructor 2") {
    Shape s(0, 0);
    REQUIRE(s.getX() == 0);
    REQUIRE(s.getY() == 0);
}

// #####################################
// III. TEST CASE 5 -  parameterized constructor, x is a variable, y is a variable
// #####################################
TEST_CASE("Shape parameterized constructor 3") {
    int num1 = 1;
    int num2 = 3;
    Shape s(num1, num2);
    REQUIRE(s.getX() == num1);
    REQUIRE(s.getY() == num2);
}

// #####################################
// I. TEST CASE 6 -  getX for Shape class function, checks is x is returned correctly
// #####################################
TEST_CASE("getX Shape class 1") {
    Shape s(1, 3);
    REQUIRE(s.getX() == 1);
}

// #####################################
// II. TEST CASE 7 -  getX for Shape class function, checks is x is returned correctly
// #####################################
TEST_CASE("getX Shape class 2") {
    Shape s;
    REQUIRE(s.getX() == 0);
}

// #####################################
// I. TEST CASE 8 -  getY for Shape class function, checks is y is returned correctly
// #####################################
TEST_CASE("getY Shape class 1") {
    Shape s;
    REQUIRE(s.getY() == 0);
}

// I. TEST CASE 9 -  getY for Shape class function, checks is y is returned correctly
// #####################################
TEST_CASE("getY Shape class 2") {
    Shape s(1, 3);
    REQUIRE(s.getY() == 3);
}

// I. TEST CASE 10 -  setX for Shape class function, checks is x is set correctly
// #####################################
TEST_CASE("setX Shape class 1") {
    Shape s;
    s.setX(1);
    REQUIRE(s.getX() == 1);
}

// II. TEST CASE 11 -  setX for Shape class function, checks is x is set correctly
// #####################################
TEST_CASE("setX Shape class 2") {
    Shape s(1, 3);
    s.setX(5);
    REQUIRE(s.getX() == 5);
}

// III. TEST CASE 13 -  setX for Shape class function, checks is x is set correctly
// #####################################
TEST_CASE("setX Shape class 3") {
    Shape s(1, 3);
    s.setX(6);
    s.setY(8);
    REQUIRE(s.getX() == 6);
}

// I. TEST CASE 14 -  setY for Shape class function, checks is y is set correctly
// #####################################
TEST_CASE("setY Shape class 1") {
    Shape s;
    s.setY(3);
    REQUIRE(s.getY() == 3);
}

// II. TEST CASE 15 -  setY for Shape class function, checks is y is set correctly
// #####################################
TEST_CASE("setY Shape class 2") {
    Shape s(1, 3);
    s.setY(5);
    REQUIRE(s.getY() == 5);
}

// III. TEST CASE 16 -  setY for Shape class function, checks is y is set correctly
// #####################################
TEST_CASE("setY Shape class 3") {
    Shape s(1, 3);
    s.setX(7);
    s.setY(8);
    REQUIRE(s.getY() == 8);
}

// I. TEST CASE 17 -  copy for Shape class function, checks new object hape is copied correctly
// #####################################
TEST_CASE("Copy Shape class 1") {
    Shape s;
    Shape c = *s.copy();
    REQUIRE(c.getX() == 0);
    REQUIRE(c.getY() == 0);
}

// II. TEST CASE 18 -  copy for Shape class function, checks new object hape is copied correctly
// #####################################
TEST_CASE("Copy Shape class 2") {
    Shape s(1, 3);
    Shape c = *s.copy();
    REQUIRE(c.getX() == 1);
    REQUIRE(c.getY() == 3);
}

// III. TEST CASE 19 -  copy for Shape class function, checks new object hape is copied correctly
// #####################################
TEST_CASE("Copy Shape class 3") {
    Shape s(5, 7);
    Shape c = *s.copy();
    REQUIRE(s.getX() == 5);
    REQUIRE(s.getY() == 7);
    REQUIRE(c.getX() == 5);
    REQUIRE(c.getY() == 7);
}


// #####################################
// I. TEST CASE 20 -  Circle constructor, x and y are 0
// #####################################
TEST_CASE("Circle default constructor") {
    Circle s;
    REQUIRE(s.getX() == 0);
    REQUIRE(s.getY() == 0);
}

// #####################################
// I. TEST CASE 21 -  parameterized constructor, radius is 3, x and y are 0
// #####################################
TEST_CASE("Circle parameterized constructor; radius") {
    Circle s(3);
    REQUIRE(s.getX() == 0);
    REQUIRE(s.getY() == 0);
    REQUIRE(s.getRadius() == 3);
}

// #####################################
// I. TEST CASE 22 -  parameterized constructor, x is 5, y is 8, radius is 10
// #####################################
TEST_CASE("Circle parameterized constructor all values 1") {
    Circle s(5, 8, 10);
    REQUIRE(s.getX() == 5);
    REQUIRE(s.getY() == 8);
    REQUIRE(s.getRadius() == 10);
}

// #####################################
// II. TEST CASE 24 -  parameterized constructor, x is 100, y is 0, radius is 70
// #####################################
TEST_CASE("Circle parameterized constructor all values 2") {
    Circle s(100, 0, 70);
    REQUIRE(s.getX() == 100);
    REQUIRE(s.getY() == 0);
    REQUIRE(s.getRadius() == 70);
}

// #####################################
// I. TEST CASE 25 -  getX for Circle class function, checks is x is returned correctly
// #####################################
TEST_CASE("getX Circle class 1") {
    Circle s(1, 3, 5);
    REQUIRE(s.getX() == 1);
}

// #####################################
// II. TEST CASE 26 -  getX for Circle class function, checks is x is returned correctly
// #####################################
TEST_CASE("getX Circle class 2") {
    Circle s;
    REQUIRE(s.getX() == 0);
}

// #####################################
// I. TEST CASE 27 -  getY for Circle class function, checks is y is returned correctly
// #####################################
TEST_CASE("getY Circle class 1") {
    Circle s;
    REQUIRE(s.getY() == 0);
}

// II. TEST CASE 28 -  getY for Circle class function, checks is y is returned correctly
// #####################################
TEST_CASE("getY Circle class 2") {
    Circle s(1, 3, 8);
    REQUIRE(s.getY() == 3);
}

// #####################################
// I. TEST CASE 29 -  getRadius for Circle class function, checks is radius is returned correctly
// #####################################
TEST_CASE("getRadius Circle class 1") {
    Circle s;
    REQUIRE(s.getRadius() == 0);
}

// #####################################
// II. TEST CASE 30 -  getRadius for Circle class function, checks is radius is returned correctly
// #####################################
TEST_CASE("getRadius Circle class 2") {
    Circle s(5);
    REQUIRE(s.getRadius() == 5);
}

// #####################################
// III. TEST CASE 31 -  getRadius for Circle class function, checks is radius is returned correctly
// #####################################
TEST_CASE("getRadius Circle class 3") {
    Circle s(1, 3, 8);
    REQUIRE(s.getRadius() == 8);
}

// I. TEST CASE 32 -  setX for Circle class function, checks is x is set correctly
// #####################################
TEST_CASE("setX Circle class 1") {
    Circle s;
    s.setX(1);
    REQUIRE(s.getX() == 1);
}

// II. TEST CASE 33 -  setX for Circle class function, checks is x is set correctly
// #####################################
TEST_CASE("setX Circle class 2") {
    Circle s(1, 2, 3);
    s.setX(2);
    REQUIRE(s.getX() == 2);
}

// III. TEST CASE 34 -  setX for Circle class function, checks is x is set correctly
// #####################################
TEST_CASE("setX Circle class 3") {
    Circle s(5, 2, 3);
    s.setX(7);
    s.setY(7);
    REQUIRE(s.getX() == 7);
}

// I. TEST CASE 35 -  setY for Circle class function, checks is y is set correctly
// #####################################
TEST_CASE("setY Circle class 1") {
    Circle s;
    s.setY(3);
    REQUIRE(s.getY() == 3);
}

// II. TEST CASE 36 -  setY for Circle class function, checks is y is set correctly
// #####################################
TEST_CASE("setY Circle class 2") {
    Circle s(1,4,6);
    s.setY(8);
    REQUIRE(s.getY() == 8);
}

// III. TEST CASE 37 -  setX for Circle class function, checks is x is set correctly
// #####################################
TEST_CASE("setY Circle class 3") {
    Circle s(5, 2, 3);
    s.setX(7);
    s.setY(9);
    REQUIRE(s.getY() == 9);
}

// I. TEST CASE 38 -  setRadius for Circle class function, checks is radius is set correctly
// #####################################
TEST_CASE("setRadius Circle class 1") {
    Circle s;
    s.setRadius(3);
    REQUIRE(s.getRadius() == 3);
}

// II. TEST CASE 39 -  setRadius for Circle class function, checks is radius is set correctly
// #####################################
TEST_CASE("setRadius Circle class 2") {
    Circle s(1,4,6);
    s.setRadius(7);
    REQUIRE(s.getRadius() == 7);
}

// III. TEST CASE 40 -  setRadius for Circle class function, checks is radius is set correctly
// #####################################
TEST_CASE("setRadius Circle class 3") {
    Circle s(5, 2, 3);
    s.setX(7);
    s.setY(9);
    s.setRadius(10);
    REQUIRE(s.getRadius() == 10);
}

// I. TEST CASE 41 -  copy for Circle class function, checks new object circle is copied correctly
// #####################################
TEST_CASE("Copy Circle class 1") {
    Circle s;
    Circle c = *s.copy();
    REQUIRE(c.getX() == 0);
    REQUIRE(c.getY() == 0);
    REQUIRE(c.getRadius() == 0);
}

// II. TEST CASE 42 -  copy for Circle class function, checks new object circle is copied correctly
// #####################################
TEST_CASE("Copy Circle class 2") {
    Circle s(5);
    Circle c = *s.copy();
    REQUIRE(c.getX() == 0);
    REQUIRE(c.getY() == 0);
    REQUIRE(c.getRadius() == 5);
}

// II. TEST CASE 43 -  copy for Circle class function, checks new object circle is copied correctly
// #####################################
TEST_CASE("Copy Circle class 3") {
    Circle s(5, 7, 10);
    Circle c = *s.copy();
    REQUIRE(c.getX() == 5);
    REQUIRE(c.getY() == 7);
    REQUIRE(c.getRadius() == 10);
}


// #####################################
// I. TEST CASE 44 -  Rectangle constructor, x, y, width and height are 0
// #####################################
TEST_CASE("Rectangle default constructor") {
    class Rectangle s;
    REQUIRE(s.getX() == 0);
    REQUIRE(s.getY() == 0);
    REQUIRE(s.getWidth() == 0);
    REQUIRE(s.getHeight() == 0);
}

// #####################################
// I. TEST CASE 45 -  Rectangle parameterized constructor, width and height are 1 and 2
// #####################################
TEST_CASE("Rectangle parameterized constructor 1") {
    class Rectangle s(1, 2);
    REQUIRE(s.getX() == 0);
    REQUIRE(s.getY() == 0);
    REQUIRE(s.getWidth() == 1);
    REQUIRE(s.getHeight() == 2);
}

// #####################################
// II. TEST CASE 46 -  Rectangle parameterized constructor, x is 2, y is 5, width and height are 1 and 9
// #####################################
TEST_CASE("Rectangle parameterized constructor 2") {
    class Rectangle s(2, 5, 1, 9);
    REQUIRE(s.getX() == 2);
    REQUIRE(s.getY() == 5);
    REQUIRE(s.getWidth() == 1);
    REQUIRE(s.getHeight() == 9);
}

// #####################################
// I. TEST CASE 47 -  getX for Rectangle class function, checks is x is returned correctly
// #####################################
TEST_CASE("getX Rectangle class") {
    class Rectangle s(5, 2, 5, 6);
    REQUIRE(s.getX() == 5);
}

// #####################################
// I. TEST CASE 48 -  getY for Rectangle class function, checks is y is returned correctly
// #####################################
TEST_CASE("getY Rectangle class") {
    class Rectangle s(7, 7, 7, 7);
    REQUIRE(s.getY() == 7);
}

// #####################################
// I. TEST CASE 49 -  getWidth for Rectangle class function, checks is width is returned correctly
// #####################################
TEST_CASE("getWidth Rectangle class") {
    class Rectangle s(8, 6, 3, 9);
    REQUIRE(s.getWidth() == 3);
}

// #####################################
// I. TEST CASE 50 -  getHeight for Rectangle class function, checks is height is returned correctly
// #####################################
TEST_CASE("getHeight Rectangle class") {
    class Rectangle s(8, 6, 3, 9);
    REQUIRE(s.getHeight() == 9);
}

// I. TEST CASE 51 -  setX for Rectangle class function, checks is x is set correctly
// #####################################
TEST_CASE("setX Rectangle class") {
    class Rectangle s(4,5,6,7);
    s.setX(1);
    REQUIRE(s.getX() == 1);
}

// I. TEST CASE 52 -  setY for Rectangle class function, checks is y is set correctly
// #####################################
TEST_CASE("setY Rectangle class") {
    class Rectangle s(4,5,6,7);
    s.setY(9);
    REQUIRE(s.getY() == 9);
}

// I. TEST CASE 53 -  setWidth for Rectangle class function, checks is width is set correctly
// #####################################
TEST_CASE("setWidth Rectangle class") {
    class Rectangle s(4,5,6,7);
    s.setWidth(4);
    REQUIRE(s.getWidth() == 4);
}

// I. TEST CASE 54 -  setHeight for Rectangle class function, checks is height is set correctly
// #####################################
TEST_CASE("setHeight Rectangle class") {
    class Rectangle s(4,5,6,7);
    s.setHeight(10);
    REQUIRE(s.getHeight() == 10);
}

// I. TEST CASE 55 -  copy for Rectangle class function, checks new object circle is copied correctly
// #####################################
TEST_CASE("Copy Rectangle class 1") {
    class Rectangle s;
    class Rectangle c = *s.copy();
    REQUIRE(c.getX() == 0);
    REQUIRE(c.getY() == 0);
    REQUIRE(c.getWidth() == 0);
    REQUIRE(c.getHeight() == 0);
}

// II. TEST CASE 56 -  copy for Rectangle class function, checks new object circle is copied correctly
// #####################################
TEST_CASE("Copy Rectangle class 2") {
    class Rectangle s(5, 7);
    class Rectangle c = *s.copy();
    REQUIRE(c.getX() == 0);
    REQUIRE(c.getY() == 0);
    REQUIRE(c.getWidth() == 5);
    REQUIRE(c.getHeight() == 7);
}

// III. TEST CASE 57 -  copy for Rectangle class function, checks new object circle is copied correctly
// #####################################
TEST_CASE("Copy Rectangle class 3") {
    class Rectangle s(1,2,3,4);
    class Rectangle c = *s.copy();
    REQUIRE(c.getX() == 1);
    REQUIRE(c.getY() == 2);
    REQUIRE(c.getWidth() == 3);
    REQUIRE(c.getHeight() == 4);
}


// #####################################
// I. TEST CASE 58 -  Right Triangle constructor, x, y, base and height are 0
// #####################################
TEST_CASE("Right Triangle default constructor") {
    RightTriangle s;
    REQUIRE(s.getX() == 0);
    REQUIRE(s.getY() == 0);
    REQUIRE(s.getBase() == 0);
    REQUIRE(s.getHeight() == 0);
}

// #####################################
// I. TEST CASE 59 -  RightTriangle parameterized constructor, base and height are 1 and 2
// #####################################
TEST_CASE("Right Triangle parameterized constructor 1") {
    RightTriangle s(1, 2);
    REQUIRE(s.getX() == 0);
    REQUIRE(s.getY() == 0);
    REQUIRE(s.getBase() == 1);
    REQUIRE(s.getHeight() == 2);
}

// #####################################
// II. TEST CASE 60 -  RightTriangle parameterized constructor, x is 2, y is 5, base and height are 1 and 9
// #####################################
TEST_CASE("Right Triangle parameterized constructor 2") {
    RightTriangle s(2, 5, 1, 9);
    REQUIRE(s.getX() == 2);
    REQUIRE(s.getY() == 5);
    REQUIRE(s.getBase() == 1);
    REQUIRE(s.getHeight() == 9);
}

// #####################################
// I. TEST CASE 61 -  getX for RightTriangle class function, checks is x is returned correctly
// #####################################
TEST_CASE("getX RightTriangle class") {
    RightTriangle s(5, 2, 5, 6);
    REQUIRE(s.getX() == 5);
}

// #####################################
// I. TEST CASE 62 -  getY for RightTriangle class function, checks is y is returned correctly
// #####################################
TEST_CASE("getY RightTriangle class") {
    RightTriangle s(5, 2, 5, 6);
    REQUIRE(s.getY() == 2);
}

// #####################################
// I. TEST CASE 63 -  getBase for RightTriangle class function, checks is width is returned correctly
// #####################################
TEST_CASE("getBase RightTriangle class") {
    RightTriangle s(8, 6, 3, 9);
    REQUIRE(s.getBase() == 3);
}

// #####################################
// I. TEST CASE 64 -  getHeight for RightTriangle class function, checks is height is returned correctly
// #####################################
TEST_CASE("getHeight RightTriangle class") {
    RightTriangle s(8, 6, 3, 9);
    REQUIRE(s.getHeight() == 9);
}

// I. TEST CASE 65 -  setX for RightTriangle class function, checks is x is set correctly
// #####################################
TEST_CASE("setX RightTriangle class") {
    RightTriangle s(4,5,6,7);
    s.setX(1);
    REQUIRE(s.getX() == 1);
}

// I. TEST CASE 66 -  setY for RightTriangle class function, checks is y is set correctly
// #####################################
TEST_CASE("setY RightTriangle class") {
    RightTriangle s(4,5,6,7);
    s.setY(9);
    REQUIRE(s.getY() == 9);
}

// I. TEST CASE 67 -  setBase for RightTriangle class function, checks is width is set correctly
// #####################################
TEST_CASE("setBase RightTriangle class") {
    RightTriangle s(4,5,6,7);
    s.setBase(4);
    REQUIRE(s.getBase() == 4);
}

// I. TEST CASE 68 -  setHeight for RightTriangle class function, checks is height is set correctly
// #####################################
TEST_CASE("setHeight RightTriangle class") {
    RightTriangle s(4,5,6,7);
    s.setHeight(10);
    REQUIRE(s.getHeight() == 10);
}

// I. TEST CASE 69 -  copy for RightTriangle class function, checks new object RightTriangle is copied correctly
// #####################################
TEST_CASE("Copy RightTriangle class 1") {
    RightTriangle s;
    RightTriangle c = *s.copy();
    REQUIRE(c.getX() == 0);
    REQUIRE(c.getY() == 0);
    REQUIRE(c.getBase() == 0);
    REQUIRE(c.getHeight() == 0);
}

// II. TEST CASE 70 -  copy for RightTriangle class function, checks new object RightTriangle is copied correctly
// #####################################
TEST_CASE("Copy RightTriangle class 2") {
    RightTriangle s(5, 7);
    RightTriangle c = *s.copy();
    REQUIRE(c.getX() == 0);
    REQUIRE(c.getY() == 0);
    REQUIRE(c.getBase() == 5);
    REQUIRE(c.getHeight() == 7);
}

// III. TEST CASE 71 -  copy for RightTriangle class function, checks new object RightTriangle is copied correctly
// #####################################
TEST_CASE("Copy RightTriangle class 3") {
    RightTriangle s(1,2,3,4);
    RightTriangle c = *s.copy();
    REQUIRE(c.getX() == 1);
    REQUIRE(c.getY() == 2);
    REQUIRE(c.getBase() == 3);
    REQUIRE(c.getHeight() == 4);
}

// #####################################
// I. TEST CASE 72 -  constructor, CanvasList
// #####################################
TEST_CASE("CanvasList default constructor") {
    CanvasList c;
    REQUIRE(c.isempty() == true);
    REQUIRE(c.front() == nullptr);
}

// #####################################
// I. TEST CASE 73 -  clear, CanvasList
// #####################################
TEST_CASE("CanvasList clear function 1") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_front(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_front(s);
	s = new RightTriangle(1, 2, 3, 4);
	myCanvas.push_front(s);
    myCanvas.clear();

    REQUIRE(myCanvas.isempty() == true);
}

// #####################################
// II. TEST CASE 74 -  clear, CanvasList
// #####################################
TEST_CASE("CanvasList clear function 2") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_front(s);
    myCanvas.clear();

    REQUIRE(myCanvas.isempty() == true);
}

// #####################################
// I. TEST CASE 75 -  insertAfter, CanvasList
// #####################################
TEST_CASE("CanvasList insertAfter function 1") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_front(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_front(s);
	myCanvas.insertAfter(0, new RightTriangle(1, 2, 3, 4));

    REQUIRE(myCanvas.find(1, 2) == 1);
}

// #####################################
// II. TEST CASE 76 -  insertAfter, CanvasList
// #####################################
TEST_CASE("CanvasList insertAfter function 2") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_front(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_front(s);
	myCanvas.insertAfter(1, new RightTriangle(1, 2, 3, 4));
    s = new Circle(6, 8, 3);
    myCanvas.push_front(s);
    s = new Circle(9, 4, 5);
    myCanvas.push_front(s);

    REQUIRE(myCanvas.find(1, 2) == 4);
}

// #####################################
// I. TEST CASE 75 -  push_front, CanvasList
// #####################################
TEST_CASE("CanvasList push_front function 1") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_front(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_front(s);

    REQUIRE(myCanvas.find(2, 4) == 0);
}

// #####################################
// I. TEST CASE 76 -  push_front, CanvasList
// #####################################
TEST_CASE("CanvasList push_front function 2") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_front(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_front(s);
    s = new Circle(6, 8, 3);
    myCanvas.push_front(s);
    s = new Circle(9, 4, 5);
    myCanvas.push_front(s);

    REQUIRE(myCanvas.find(9, 4) == 0);
}

// #####################################
// I. TEST CASE 77 -  push_back, CanvasList
// #####################################
TEST_CASE("CanvasList push_back function 1") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_back(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_back(s);

    REQUIRE(myCanvas.find(2, 4) == 1);
}

// #####################################
// II. TEST CASE 78 -  push_back, CanvasList
// #####################################
TEST_CASE("CanvasList push_back function 2") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_back(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_back(s);
    s = new Circle(6, 8, 3);
    myCanvas.push_back(s);
    s = new Circle(9, 4, 5);
    myCanvas.push_back(s);

    REQUIRE(myCanvas.find(9, 4) == 3);
}

// #####################################
// I. TEST CASE 79 -  removeAt, CanvasList
// #####################################
TEST_CASE("CanvasList removeAt function 1") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_back(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_back(s);
    myCanvas.removeAt(0);

    REQUIRE(myCanvas.find(2, 4) == 0);
}

// #####################################
// II. TEST CASE 80 -  removeAt, CanvasList
// #####################################
TEST_CASE("CanvasList removeAt function 2") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_back(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_back(s);
    s = new Circle(6, 8, 3);
    myCanvas.push_back(s);
    s = new Circle(9, 4, 5);
    myCanvas.push_back(s);
    myCanvas.removeAt(1);

    REQUIRE(myCanvas.find(6, 8) == 1);
}

// #####################################
// I. TEST CASE 81 -  pop_front, CanvasList
// #####################################
TEST_CASE("CanvasList pop_front function 1") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_back(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_back(s);
    Shape *frontHere = myCanvas.shapeAt(0);
    Shape *theFrontPopped = myCanvas.pop_front();

    REQUIRE(frontHere == theFrontPopped);
}

// #####################################
// II. TEST CASE 82 -  pop_front, CanvasList
// #####################################
TEST_CASE("CanvasList pop_front function 2") {
    CanvasList myCanvas;
    Shape *theFrontPopped = myCanvas.pop_front();

    REQUIRE(theFrontPopped == nullptr);
}

// #####################################
// I. TEST CASE 83 -  pop_back, CanvasList
// #####################################
TEST_CASE("CanvasList pop_back function 1") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_back(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_back(s);
    Shape *backHere = myCanvas.shapeAt(1);
    Shape *theBackPopped = myCanvas.pop_back();

    REQUIRE(backHere == theBackPopped);
}

// #####################################
// II. TEST CASE 84 -  pop_back, CanvasList
// #####################################
TEST_CASE("CanvasList pop_back function 2") {
    CanvasList myCanvas;
    Shape *theBackPopped = myCanvas.pop_back();

    REQUIRE(theBackPopped == nullptr);
}

// #####################################
// I. TEST CASE 85 -  front, CanvasList
// #####################################
TEST_CASE("CanvasList front function 1") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_back(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_back(s);
    ShapeNode *theFront = myCanvas.front();

    REQUIRE(theFront->value == myCanvas.shapeAt(0));
}

// #####################################
// I. TEST CASE 86 -  isEmpty, CanvasList
// #####################################
TEST_CASE("CanvasList isEmpty function 1") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_back(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_back(s);
    bool empty = myCanvas.isempty();

    REQUIRE(empty == false);
}

// #####################################
// II. TEST CASE 87 -  isEmpty, CanvasList
// #####################################
TEST_CASE("CanvasList isEmpty function 2") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	s = new Circle(2, 4, 3);
    bool empty = myCanvas.isempty();

    REQUIRE(empty == true);
}

// #####################################
// I. TEST CASE 88 -  size, CanvasList
// #####################################
TEST_CASE("CanvasList size function 1") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_back(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_back(s);
    int theSize = myCanvas.size();

    REQUIRE(theSize == 2);
}

// #####################################
// II. TEST CASE 89 -  size, CanvasList
// #####################################
TEST_CASE("CanvasList size function 2") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	s = new Circle(2, 4, 3);
    int theSize = myCanvas.size();

    REQUIRE(theSize == 0);
}

// #####################################
// I. TEST CASE 90 -  find, CanvasList
// #####################################
TEST_CASE("CanvasList find function 1") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_back(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_back(s);
    int found = myCanvas.find(1, 3);

    REQUIRE(found == 0);
}

// #####################################
// I. TEST CASE 91 -  find, CanvasList
// #####################################
TEST_CASE("CanvasList find function 2") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_back(s);
	s = new Circle(2, 4, 3);
	myCanvas.push_back(s);
    int found = myCanvas.find(2, 4);

    REQUIRE(found == 1);
}

// #####################################
// I. TEST CASE 92 -  shapeAt, CanvasList
// #####################################
TEST_CASE("CanvasList shapeAt function 1") {
    CanvasList myCanvas;
	Shape *s = new Shape(1, 3);
	myCanvas.push_front(s);

    REQUIRE(myCanvas.shapeAt(1) == nullptr);
}