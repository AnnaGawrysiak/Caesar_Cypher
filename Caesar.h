#pragma once
#include <iostream>
#include <string>
#include<vector>
#include "Cylinder.h"


class Caesar
{
private:
	std::string msg;
	std::vector<std::shared_ptr<Cylinder>> cylinders_configuration;
	std::vector<int> position_of_spaces;
	void modify_msg(std::vector<std::shared_ptr<Cylinder>> cylinders_configuration_);
	
public:
	Caesar();		

	Caesar(std::string msg_);

	void encrypt();

	void decrypt();

	std::string get_msg();

};

