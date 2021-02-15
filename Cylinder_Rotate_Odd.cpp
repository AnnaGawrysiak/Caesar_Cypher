#include "Cylinder_Rotate_Odd.h"
#include "Caesar.h"

Cylinder_Rotate_Odd::Cylinder_Rotate_Odd(int shift_, std::string text_)
{
	shift = shift_;
	text = text_;
}

void Cylinder_Rotate_Odd::rotate()
{

	const int move = shift % 26;

	for (unsigned int i = 0; i < text.size(); i++)
	{
		if (text[i] > 96 && text[i] < 123 && text[i] + move > 122 && (i % 2 ==0)) // jesli jest mala litera i po przesunieciu przekracza wartosc 122, przedzial: 97-122
			text[i] = 96 + (text[i] + move - 122);

		else if (text[i] > 64 && text[i] < 91 && text[i] + move > 90 && i % 2 == 0) // jesli jest wielka litera i po przesunieciu przekracza wartosc 90, przedzial: 65-90
			text[i] = 64 + (text[i] + move - 90);

		else if (text[i] > 96 && text[i] < 123 && text[i] + move < 97 && i % 2 == 0) // jest jest mala litera i po przesunieciu w lewo przekracza wartosc 97
			text[i] = 122 + (text[i] + move - 96);

		else if (text[i] > 64 && text[i] < 91 && text[i] + move < 65 && i % 2 == 0) // jest jest mala litera i po przesunieciu w lewo przekracza wartosc 97
			text[i] = 90 + (text[i] + move - 64);
		else
			if(i % 2 == 0)
			text[i] = text[i] + move;
	}

}

std::string Cylinder_Rotate_Odd::get_text()
{
	return text;
}