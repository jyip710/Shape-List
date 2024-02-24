//  Project 4: canvaslist.h
//  Author: Jacky Yip
//  March 18, 2023
//  Description: This is a header file that will use another header file "shape.h". The main purpose of both header files are to create a linked list using
//  nodes that have the value of shapes. This linked list will be able to "draw" or print out each node, as well as it's properties, it's shape, x value,
//  y value, and addition values if the shape has any. There are 5 different shapes. The purpose of this header file "canvaslist.h", is to create the
//  nodes that will store the shapes, and also create the linked list along with it's functions by creating two classes. The first class declared is the
//  "ShapeNode" class. This class is the node that will be used in the linked list. It contains the values of the shapes with all it's properties and
//  the address of the next node. The other class is called "CanvasList". This will contain the size of the list, the address of the first node in the
//  list, and contains many functions that are used to create or change the list. The class has constructors that will build the linked list, destructors
//  that will delete the whole list as well as it's nodes and shapes which will free memory. The class also has many defined functions that cpp file
//  can use to create or change the list. The class also has a function that can print through the whole list and print out it's addresses.

#pragma once

#include "shape.h"
#include <iostream>

using namespace std;

class ShapeNode
{
    public:
        Shape *value;
        ShapeNode *next;
};

class CanvasList
{
    private:
        int listSize;
        ShapeNode *listFront;

    public:
        CanvasList();
        CanvasList(const CanvasList &);
        CanvasList operator=(const CanvasList &);
        
        virtual ~CanvasList();
        void clear();
        
        void insertAfter(int, Shape *);
        void push_front(Shape *);
        void push_back(Shape *);
        
        void removeAt(int);
        Shape* pop_front();
        Shape* pop_back();

        ShapeNode* front() const;
        bool isempty() const;
        int size() const;

        int find(int x, int y) const;
        Shape* shapeAt(int) const;
        
        void draw() const;
        void printAddresses() const;
};

//Default constructor for CanvasList(). This will set the list size to be 0 and the front of the list as nullptr.
CanvasList::CanvasList()
{
    listSize = 0;
    listFront = nullptr;
}

//CanvasList() destructor. This will delete all nodes and objects, which will free memory automactically once the program finishes running.
CanvasList::~CanvasList()
{
    if(isempty() != true){
        ShapeNode *node = listFront;
        while(node != nullptr){
            Shape *shapePtr = listFront->value;
            node = node->next;
            delete shapePtr;
            delete listFront;
            listFront = node;
        }
        listSize = 0;
    }
}

//A copy constructor for CanvasList. This will create a copy of an already made linked list, with the same values as the original. However this copy will have
//different addresses for both the nodes and objects.
CanvasList::CanvasList(const CanvasList &copy)
{
    listFront = nullptr;

    ShapeNode *copied = copy.listFront;

    while(copied != nullptr){
        Shape *newShape = copied->value;
        Shape *copyShape = newShape->copy();
        this->push_back(copyShape);
        copied = copied->next;
    }
}

//The assignment constructor for CanvasList. This will be used when an already made list is called to copy another already made list. To do this, the old list
//must be deleted. I used the clear function to delete all the nodes and so now the list can copy another list.
CanvasList CanvasList::operator=(const CanvasList &copy)
{
    this->clear();

    listFront = nullptr;
    ShapeNode *copied = copy.listFront;

    while(copied != nullptr){
        Shape *newShape = copied->value;
        Shape *copyShape = newShape->copy();
        this->push_back(copyShape);
        copied = copied->next;
    }
    return *this;
}

//Checks if the list is empty. If it is empty, the list will return true, if not it will return false.
bool CanvasList::isempty() const
{
    if(listFront == nullptr){
        return true;
    }
    return false;
}

//Puts the inputed shape to the front of the linked list
void CanvasList::push_front(Shape *s)
{
    ShapeNode *node = new ShapeNode;
    node->value = s;
    node->next = listFront;
    listFront = node;
    listSize += 1;
}

//Traverses the linked list and prints out the shape of the node and it's x and y values by using the printShape function.
void CanvasList::draw() const
{
    if(listFront == nullptr){
        return;
    }
    ShapeNode *node = listFront;
    while(node != nullptr){
        node->value->printShape();
        node = node->next;
    }
}

//Returns the size of the list, using the private data member listSize.
int CanvasList::size() const
{
    return listSize;
}

//Resets the state of the linked list, and releases memory by deleting the nodes.
void CanvasList::clear()
{
    while(listFront != nullptr){
        ShapeNode *node = listFront->next;
        Shape *shape = listFront->value;
        delete shape;
        delete listFront;
        listFront = node;
    }
    listSize = 0;
}

//Inserts the inputted shape at the end of the linked list by traversing through the list and when it reaches the end, it adds the input shape.
void CanvasList::push_back(Shape *s)
{
    ShapeNode *node = new ShapeNode;
    node->value = s;
    node->next = nullptr;
    if(listFront == nullptr){
        listFront = node;
    }
    else{
        ShapeNode *pTemp = listFront;
        while(pTemp->next != nullptr){
            pTemp = pTemp->next;
        }
        pTemp->next = node;
    }
    listSize += 1;
}

//This function will take in an index and a node shape object. The function will traverse the list until the inputted index is reached. When the index is
//reached the function will then add the shape to the list's next index, while making the what used to be next node, to the previous node.
void CanvasList::insertAfter(int index, Shape *s)
{
    if(index > listSize){
        return;
    }
    ShapeNode *node = listFront;
    int current = 0;
    ShapeNode *prev = nullptr;

    while(node != nullptr){
        if(current == index){
            prev = node;
            node = node->next;
            ShapeNode *add = new ShapeNode;
            listSize += 1;
            add->value = s;

            if(prev != nullptr){
                prev->next = add;
            }
            else{
                listFront = add;
            }
            add->next = node;
            break;
        }
        prev = node;
        node = node->next;
        current++;
    }
}

//Traveres through the list until the list reaches the inputted index. At the inputted index, the node at that index will be deleted. The function will
//then change the current node to the previous since it has been kept track of at the start of the function call. After that, the function will subtract
//the size of the list by 1, and then break out of the while loop.
//This function will return and do nothing if the index is out of range.
void CanvasList::removeAt(int index)
{
    ShapeNode *node = listFront;
    int current = 0;
    ShapeNode *prev = nullptr;

    while(node != nullptr){
        if(current == index){
            if(prev != nullptr){
                prev->next = node->next;
            }
            else{
                listFront = node->next;
            }
            delete node;
            listSize -= 1;
            break;
        }
        prev = node;
        node = node->next;
        current += 1;
    }
}

//Returns a pointer to the shape of the first node/shape. This will also remove the first node by using the removeAt function. If the list is empty, the
//function will return nullptr.
Shape* CanvasList::pop_front()
{
    if(listSize == 0){
        return nullptr;
    }
    else{
        Shape* shape = this->shapeAt(0);
        this->removeAt(0);
        return shape;
    }
}

//Returns a pointer to the shape of the last node/shape. This will also remove the last node by using the removeAt function. If the list is empty, the
//function will return nullptr.
Shape* CanvasList::pop_back()
{
    if(listSize == 0){
        return nullptr;
    }
    else{
        Shape* shape = this->shapeAt(listSize - 1);
        this->removeAt(listSize - 1);
        return shape;
    }
}

//Finds the location of the first shape that has the same x and y values as the inputted x and y integers. If this is found the function will return
//the index of the shape. If there is no shape that has the same x and y values as the input, then it will return -1.
int CanvasList::find(int x, int y) const
{
    int index = 0;
    if(listFront == nullptr){
        return -1;
    }
    ShapeNode *node = listFront;
    while(node != nullptr){
        if(node->value->getX() == x && node->value->getY() == y){
            return index;
        }
        node = node->next;
        index += 1;
    }
    return -1;
}

//Traverses the list until it reaches the inputted index location. When the index is reached the function will return the pointer to the shape of that
//index. If the index is not in the list, the function will return nullptr.
Shape* CanvasList::shapeAt(int index) const
{
    ShapeNode *node = listFront;
    int current = 0;

    while(node != nullptr){
        if(current == index){
            return node->value;
        }
        node = node->next;
        current += 1;
    }
    return nullptr;
}

//Traveres through the list and prints each node's address, as well as that node's shape and the address of that shape. This function will print as it
//goes through each node until the end of the list.
void CanvasList::printAddresses() const
{
    if(listFront == nullptr){
        return;
    }
    ShapeNode *node = listFront;
    while(node != nullptr){
        cout << "Node Address: " << node << "\t" << "Shape Address: " << node->value << endl;
        node = node->next;
    }
}

//Returns the private data member listFront, which is the pointer that points to the front of the list.
ShapeNode* CanvasList::front() const
{
    return listFront;
}