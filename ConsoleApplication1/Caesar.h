#pragma once
#include <iostream>
#include <string>
#include "First_Cylinder.h"

class Caesar
{
public:
	std::string msg;

public:
	Caesar();		

	Caesar(std::string msg_);

	void encrypt();

};

