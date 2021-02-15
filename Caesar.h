#pragma once
#include <iostream>
#include <string>
#include<vector>
#include "Cylinder.h"


class Caesar
{
private:
	std::string msg;
	std::vector<int> keys;
	std::vector<int> position_of_spaces;
	void modify_msg(Cylinder* cylinder);
	
public:
	Caesar();		

	Caesar(std::string msg_);

	void encrypt();

	void decrypt();

	std::string get_msg();

};

