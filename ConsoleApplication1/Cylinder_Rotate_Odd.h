#pragma once
#include "Caesar.h"

class Cylinder_Rotate_Odd
{
private:
    int shift;
    std::string text;
public:
    Cylinder_Rotate_Odd(int shift_, std::string text_);
    void rotate();
    std::string get_text();
};
