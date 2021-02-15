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

void Caesar::modify_msg(Cylinder* cylinder)
{
	cylinder->rotate();
	msg = cylinder->get_text();
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

	std::vector<Cylinder*> cylinders_configuration;

	int overlap = (std::rand() % 1000) + 1;
	//keys.push_back(overlap);
	cylinders_configuration.push_back(new First_Cylinder(overlap, msg));
	cylinders_configuration.at(0)->rotate();
	msg = cylinders_configuration.at(0)->get_text();

	overlap = (std::rand() % 1000) + 1;
	//keys.push_back(overlap);
	cylinders_configuration.push_back(new Cylinder_Rotate_Odd(overlap, msg));
	cylinders_configuration.at(1)->rotate();
	msg = cylinders_configuration.at(1)->get_text();

	overlap = (std::rand() % 1000) + 1;
	keys.push_back(overlap);
	cylinders_configuration.push_back(new Cylinder_Rotate_3rd(overlap, msg));
	cylinders_configuration.at(2)->rotate();
	msg = cylinders_configuration.at(2)->get_text();

	/*
	std::vector<std::shared_ptr<Cylinder>> cylinders_configuration;

	int overlap = (std::rand() % 1000) + 1;
	keys.push_back(overlap);
	cylinders_configuration.push_back(std::shared_ptr<First_Cylinder>(new First_Cylinder(overlap, msg)));
	cylinders_configuration.at(0)->rotate();
	msg = cylinders_configuration.at(0)->get_text();

	overlap = (std::rand() % 1000) + 1;
	keys.push_back(overlap);
	cylinders_configuration.push_back(std::shared_ptr<Cylinder_Rotate_Odd>(new Cylinder_Rotate_Odd(overlap, msg)));
	cylinders_configuration.at(1)->rotate();
	msg = cylinders_configuration.at(1)->get_text();

	overlap = (std::rand() % 1000) + 1;
	keys.push_back(overlap);
	cylinders_configuration.push_back(std::shared_ptr<Cylinder_Rotate_3rd>(new Cylinder_Rotate_3rd(overlap, msg)));
	cylinders_configuration.at(2)->rotate();
	msg = cylinders_configuration.at(2)->get_text();

	//int choice_of_cylinder = rand() % 2;  
	//cylinders_configuration.push_back(available_cylinders.at(choice_of_cylinder));

	*/
}

void Caesar::decrypt()
{
	cylinders_configuration.at(0)->set_shift((-1) * cylinders_configuration.at(0)->get_shift());
	std::cout << "Minus shift:" << cylinders_configuration.at(0)->get_shift() << std::endl;

	for (unsigned int i = cylinders_configuration.size(); i > 0; i--)
	{
		cylinders_configuration.at(i)->set_shift((-1)*cylinders_configuration.at(i)->get_shift());
		std::cout << "Minus shift:" << cylinders_configuration.at(i)->get_shift() << std::endl;
		cylinders_configuration.at(i)->rotate();
		msg = cylinders_configuration.at(i)->get_text();
	}

	/*
	First_Cylinder* first = new First_Cylinder((-1)*keys[0], msg);
	first->rotate();
	msg = first->get_text();

	Cylinder_Rotate_Odd* second = new Cylinder_Rotate_Odd((-1) * keys[1], msg);
	second->rotate();
	msg = second->get_text();

	Cylinder_Rotate_3rd* third = new Cylinder_Rotate_3rd((-1) * keys[2], msg);
	third->rotate();
	msg = third->get_text();
	*/

	for (auto it = std::begin(position_of_spaces); it != std::end(position_of_spaces); ++it) 
	{
		msg.insert(*it, " ");
	}

	// empty the container
	keys.clear();
	cylinders_configuration.clear();
}

std::string Caesar::get_msg()
{
	return msg;
}