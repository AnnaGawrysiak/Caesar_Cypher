#include <iostream>
#include <string>
#include "Caesar.h"
#include "Cylinder_Rotate_Odd.h"
#include "Cylinder_Rotate_3rd.h"
#include <ctime>
#include <cstdlib>


Caesar::Caesar() 
{
}

Caesar::Caesar(std::string msg_)
{
	msg = msg_;
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
	keys.push_back(overlap);

	First_Cylinder* first = new First_Cylinder(overlap, msg);
	first->rotate();
	msg = first->get_text();

	overlap = (std::rand() % 1000) + 1;
	keys.push_back(overlap);

	Cylinder_Rotate_Odd* second = new Cylinder_Rotate_Odd(overlap, msg);
	second->rotate();
	msg = second->get_text();

	overlap = (std::rand() % 1000) + 1;
	Cylinder_Rotate_3rd* third = new Cylinder_Rotate_3rd(overlap, msg);
	third->rotate();
	msg = third->get_text();

	keys.push_back(overlap);
}

void Caesar::decrypt()
{
	First_Cylinder* first = new First_Cylinder((-1)*keys[0], msg);
	first->rotate();
	msg = first->get_text();

	Cylinder_Rotate_Odd* second = new Cylinder_Rotate_Odd((-1) * keys[1], msg);
	second->rotate();
	msg = second->get_text();

	Cylinder_Rotate_3rd* third = new Cylinder_Rotate_3rd((-1) * keys[2], msg);
	third->rotate();
	msg = third->get_text();

	for (auto it = std::begin(position_of_spaces); it != std::end(position_of_spaces); ++it) 
	{
		msg.insert(*it, " ");
	}

}



std::string Caesar::get_msg()
{
	return msg;
}