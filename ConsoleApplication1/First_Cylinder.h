#pragma once
#include "Caesar.h"

class First_Cylinder 
{
public:
    int shift;
    std::string text;
public:
    First_Cylinder(int shift_, std::string text_);
    void rotate();
};