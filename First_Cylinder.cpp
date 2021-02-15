#include "First_Cylinder.h"
#include "Caesar.h"

First_Cylinder::First_Cylinder(int shift_, std::string text_)
{
	shift = shift_;
	text = text_;
}

void First_Cylinder::rotate()
{
	const int move = shift % 26;

	for (unsigned int i = 0; i < text.size(); i++)
	{	
		 if (text[i] > 96 && text[i] < 123 && text[i] + move > 122) // jesli jest mala litera i po przesunieciu przekracza wartosc 122, przedzial: 97-122
			text[i] = 96 + (text[i] + move - 122);

		else if (text[i] > 64 && text[i] < 91 && text[i] + move > 90) // jesli jest wielka litera i po przesunieciu przekracza wartosc 90, przedzial: 65-90
			text[i] = 64 + (text[i] + move - 90);

		else if (text[i] > 96 && text[i] < 123 && text[i] + move < 97) // jest jest mala litera i po przesunieciu w lewo przekracza wartosc 97
			text[i] = 122 + (text[i] + move - 96);

		else if (text[i] > 64 && text[i] < 91 && text[i] + move < 65) // jest jest mala litera i po przesunieciu w lewo przekracza wartosc 97
			text[i] = 90 + (text[i] + move - 64);
		else
			text[i] = text[i] + move;
	}

}

std::string First_Cylinder::get_text()
{
	return text;
}