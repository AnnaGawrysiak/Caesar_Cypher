#pragma once
#include "Cylinder.h"
#include <string>

class Cylinder 
{
	int shift;
	std::string msg;

public:
	Cylinder() {};
	virtual ~Cylinder() = 0; // Pure virtual destructor 
	virtual void rotate() = 0;
	virtual std::string get_text() = 0;
	virtual void set_shift(int shift) = 0;
	virtual int get_shift() = 0;
};

