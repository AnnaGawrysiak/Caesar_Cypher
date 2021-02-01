#include <iostream>
#include <string>
#include "Caesar.h"


Caesar::Caesar() 
{
}

Caesar::Caesar(std::string msg_)
{
	msg = msg_;
}

void Caesar::encrypt()
{
	int overlap = 3;

	First_Cylinder first(overlap, msg);
	first.rotate();

	msg = first.text;
}