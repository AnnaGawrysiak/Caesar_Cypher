#pragma once
#include "Caesar.h"
#include "Cylinder.h"

class Cylinder_Rotate_3rd : public Cylinder
{
private:
    int shift;
    std::string text;
public:
    Cylinder_Rotate_3rd(int shift_, std::string text_);
    void rotate() override;;
    std::string get_text() override;;
    void set_shift(int shift_) override;
    int get_shift();
};

