#pragma once
#include "Cylinder.h"
#include <string>

class Cylinder 
{

public:
	Cylinder() {};
	virtual ~Cylinder() = 0; // Pure virtual destructor 
	virtual void rotate() = 0;
	virtual std::string get_text() = 0;
};

