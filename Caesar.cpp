#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <memory>
#include "Caesar.h"
#include "First_Cylinder.h"
#include "Cylinder_Rotate_Odd.h"
#include "Cylinder_Rotate_3rd.h"

Caesar::Caesar() 
{
}

Caesar::Caesar(std::string msg_)
{
	msg = msg_;
}

void Caesar::modify_msg(std::vector<std::shared_ptr<Cylinder>> cylinders_configuration_)
{
	static int i = 0;

	cylinders_configuration_.at(i)->rotate();
	msg = cylinders_configuration_.at(i)->get_text();
	i++;
}

void Caesar::encrypt()
{
	srand((unsigned int)time(NULL));

	int count = 0;

	for (unsigned int i = 0; i < msg.size(); i++)
	{
		if (msg[i] == ' ')
		{
			position_of_spaces.push_back(i + count);
			count++;
			msg.erase(msg.begin() + i);
		}
	}


	int overlap = (std::rand() % 1000) + 1;
	cylinders_configuration.push_back(std::shared_ptr<First_Cylinder>(new First_Cylinder(overlap, msg)));
	modify_msg(cylinders_configuration);
	
	overlap = (std::rand() % 1000) + 1;
	cylinders_configuration.push_back(std::shared_ptr<Cylinder_Rotate_Odd>(new Cylinder_Rotate_Odd(overlap, msg)));
	modify_msg(cylinders_configuration);
	
	overlap = (std::rand() % 1000) + 1;
	cylinders_configuration.push_back(std::shared_ptr<Cylinder_Rotate_3rd>(new Cylinder_Rotate_3rd(overlap, msg)));
	modify_msg(cylinders_configuration);
	
}

void Caesar::decrypt()
{
	
	for (int i = 2; i >= 0; i--)
	{
		cylinders_configuration.at(i)->set_shift((-1)*cylinders_configuration.at(i)->get_shift());
		cylinders_configuration.at(i)->rotate();
		msg = cylinders_configuration.at(i)->get_text();
	}

	for (auto it = std::begin(position_of_spaces); it != std::end(position_of_spaces); ++it) 
	{
		msg.insert(*it, " ");
	}
	
	cylinders_configuration.clear();
}

std::string Caesar::get_msg()
{
	return msg;
}