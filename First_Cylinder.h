#pragma once
#include "Caesar.h"

class First_Cylinder 
{
private:
    int shift;
    std::string text;
public:
    First_Cylinder(int shift_, std::string text_);
    virtual void rotate();
    virtual std::string get_text();
};