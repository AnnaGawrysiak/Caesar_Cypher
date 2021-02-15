#pragma once
#include "Caesar.h"

class First_Cylinder : public Cylinder
{
private:
    int shift;
    std::string text;
public:
    First_Cylinder(int shift_, std::string text_);
    void rotate() override;;
    std::string get_text() override;;
    void set_shift(int shift_) override;
    int get_shift() override;
};