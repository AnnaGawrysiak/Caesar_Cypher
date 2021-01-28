#pragma once
#include <iostream>
#include <string>

class Caesar
{
	std::string text;
	int shift;

public:
	Caesar();				//default constructor, sets shift data to 0
	Caesar(std::string text_, int shift_);

	std::string encrypt(std::string text, int shift);
};

