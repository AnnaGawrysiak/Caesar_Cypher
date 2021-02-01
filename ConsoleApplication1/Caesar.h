#pragma once
#include <iostream>
#include <string>
#include<vector>
#include "First_Cylinder.h"

class Caesar
{
private:
	std::string msg;
	std::vector<int> keys;

public:
	Caesar();		

	Caesar(std::string msg_);

	void encrypt();

	void decrypt();

	std::string get_msg();

};

