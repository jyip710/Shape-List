//  Project 4: shape.h
//  Author: Jacky Yip
//  March 18, 2023
//  Description: This is a header file that will be used in another header file "canvaslist.h". The main purpose of both header files are to create a linked list
//  using nodes that have the value of shapes. This linked list will be able to "draw" or print out each node, as well as it's properties, it's shape, x value,
//  y value, and addition values if the shape has any. There are 5 different shapes. The purpose of this header file is to create the shapes/values that
//  the link list will contain. This file declares 5 classes, each being for one shape. Each class has a constructor, and a paramaterized constructor, which
//  will contain the data of the shapes. Each class can also copy another one of that type of shape's data. Each shape has an x and y value, however
//  some shapes may have addition values that other shapes may not have. Finally, all classes are able to print it's data with a defined print function.

#pragma once

using namespace std;
#include <iostream>

class Shape
{
    protected:
        int x;
        int y;

    public: 
        Shape();
        Shape(int x, int y);

        virtual ~Shape();
        virtual Shape* copy();

        int getX() const;
        int getY() const;
        void setX(int);
        void setY(int);
        
        virtual void printShape() const;
};


class Circle : public Shape 
{
    private:
        int radius;

    public: 
        Circle();
        Circle(int r);
        Circle(int x, int y, int r);

        virtual ~Circle();
        virtual Circle* copy();
        
        int getRadius() const;
        void setRadius(int);
        
        virtual void printShape() const;
};


class Rectangle : public Shape 
{
    private:
        int width;
        int height;

    public: 
        Rectangle();
        Rectangle(int w, int h);
        Rectangle(int x, int y, int w, int h);
        
        virtual ~Rectangle();
        virtual Rectangle* copy();
        
        int getWidth() const;
        int getHeight() const;
        void setWidth(int);
        void setHeight(int);
        
        virtual void printShape() const;
};

class RightTriangle : public Shape 
{
    private:
        int base;
        int height;

    public: 
        RightTriangle();
        RightTriangle(int b, int h);
        RightTriangle(int x, int y, int b, int h);
        
        virtual ~RightTriangle();
        virtual RightTriangle* copy();
        
        int getBase() const;
        int getHeight() const;
        void setBase(int);
        void setHeight(int);

        virtual void printShape() const;
};

//Default constructor for Shape(), sets it's values private data members to 0
Shape::Shape()
{
    x = 0;
    y = 0;
}

//Constructor overloading with different parameter sets for the Shape() function. Sets the private members x and y values.
Shape::Shape(int x, int y)
{
    this->x = x;
    this->y = y;
}

//Set function for Shape(), sets the variable x
void Shape::setX(int x)
{
    this->x = x;
}

//Set function for Shape(), sets the variable y
void Shape::setY(int y)
{
    this->y = y;
}

//Get function for Shape(), gets the variable x
int Shape::getX() const
{
    return x;
}
//Get function for Shape(), gets the variable y
int Shape::getY() const
{
    return y;
}

//Returns a new copied shape of an already made object. This new object has it's own memory location, but has the same values as the original object.
Shape *Shape::copy()
{
    Shape *copied = new Shape();
    *copied = *this;
    return copied;
}

void Shape::printShape() const
{
    cout << "It's a Shape at x: " << getX() << ", y: " << getY() << endl;
}

//Shape() destructor
Shape::~Shape()
{
}

//Default constructor for Circle(), sets it's values private data members to 0
Circle::Circle()
{
    x = 0;
    y = 0;
    radius = 0;
}

//Constructor overloading with different parameter set for the Circle() function, in this function only radius is inputted and will be set to that value.
Circle::Circle(int r)
{
    x = 0;
    y = 0;
    radius = r;
}

//Constructor overloading with different parameter sets for the Circle() function. Sets x, y, and radius values.
Circle::Circle(int x, int y, int r)
{
    this->x = x;
    this->y = y;
    radius = r;
}

//Circle() destructor
Circle::~Circle()
{
}

//Returns a new copied circle of an already made object. This new object has it's own memory location, but has the same values as the original object.
Circle *Circle::copy()
{
    Circle *copied = new Circle();
    *copied = *this;
    return copied;
}

//Get function for Circle(), gets the variable radius and returns it.
int Circle::getRadius() const
{
    return radius;
}

//Set function for Circle(), sets the variable radius
void Circle::setRadius(int r)
{
    radius = r;
}

//Prints the statement that the object is a circle and also prints out it's properties, x, y, and the radius.
void Circle::printShape() const
{
    cout << "It's a Circle at x: " << getX() << ", y: " << getY() << ", radius: " << getRadius() << endl;
}

//Default constructor for Rectangle(), sets it's values private data members to 0
Rectangle::Rectangle()
{
    x = 0;
    y = 0;
    width = 0;
    height = 0;
}

//Constructor overloading with different parameter set for the Rectangle() function, in this function both width and height is inputted and will be set to
//those values.
Rectangle::Rectangle(int w, int h)
{
    x = 0;
    y = 0;
    width = w;
    height = h;
}

//Constructor overloading with different parameter sets for the Rectangle() function. Sets x, y, width, and height values.
Rectangle::Rectangle(int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    width = w;
    height = h;
}

//Rectangle() destructor
Rectangle::~Rectangle()
{
}

//Returns a new copied rectangle of an already made object. This new object has it's own memory location, but has the same values as the original object.
Rectangle *Rectangle::copy()
{
    Rectangle *copied = new Rectangle();
    *copied = *this;
    return copied;
}

//Get function for Rectangle(), gets the variable width and returns it.
int Rectangle::getWidth() const
{
    return width;
}

//Get function for Rectangle(), gets the variable height and returns it.
int Rectangle::getHeight() const
{
    return height;
}

//Set function for Rectangle(), sets the variable width
void Rectangle::setWidth(int w)
{
    width = w;
}

//Set function for Rectangle(), sets the variable height
void Rectangle::setHeight(int h)
{
    height = h;
}

//Prints the statement that the object is a rectangle and also prints out it's properties, x, y, width and height.
void Rectangle::printShape() const
{
    cout << "It's a Rectangle at x: " << getX() << ", y: " << getY() << " with width: " << getWidth() << " and height: " << getHeight() << endl;
}

//Default constructor for RightTriangle(), sets it's values private data members to 0
RightTriangle::RightTriangle()
{
    x = 0;
    y = 0;
    base = 0;
    height = 0;
}

//Constructor overloading with different parameter set for the RightTriangle() function, in this function both base and height is inputted and will be set to
//those values.
RightTriangle::RightTriangle(int b, int h)
{
    x = 0;
    y = 0;
    base = b;
    height = h;
}

//Constructor overloading with different parameter sets for the RightTriangle() function. Sets x, y, base, and height values.
RightTriangle::RightTriangle(int x, int y, int b, int h)
{
    this->x = x;
    this->y = y;
    base = b;
    height = h;
}

//RightTriangle() destructor
RightTriangle::~RightTriangle()
{
}

//Returns a new copied RightTriangle of an already made object. This new object has it's own memory location, but has the same values as the original object.
RightTriangle *RightTriangle::copy()
{
    RightTriangle *copied = new RightTriangle();
    *copied = *this;
    return copied;
}

//Get function for RightTriangle(), gets the variable width and returns it.
int RightTriangle::getBase() const
{
    return base;
}

//Get function for RightTriangle(), gets the variable height and returns it.
int RightTriangle::getHeight() const
{
    return height;
}

//Set function for RightTriangle(), sets the variable width
void RightTriangle::setBase(int b)
{
    base = b;
}

//Set function for RightTriangle(), sets the variable height
void RightTriangle::setHeight(int h)
{
    height = h;
}

//Prints the statement that the object is a rectangle and also prints out it's properties, x, y, width and height.
void RightTriangle::printShape() const
{
    cout << "It's a Right Triangle at x: " << getX() << ", y: " << getY() << " with base: " << getBase() << " and height: " << getHeight() << endl;
}