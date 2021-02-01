#pragma once
#include "Caesar.h"

class Cylinder_Rotate_3rd
{
private:
    int shift;
    std::string text;
public:
    Cylinder_Rotate_3rd(int shift_, std::string text_);
    void rotate();
    std::string get_text();
};

