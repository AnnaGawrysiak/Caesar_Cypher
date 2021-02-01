#include "Cylinder_Rotate_3rd.h"
#include "Caesar.h"

// Rotates every 3rd element
Cylinder_Rotate_3rd::Cylinder_Rotate_3rd(int shift_, std::string text_)
{
	shift = shift_;
	text = text_;
}

void Cylinder_Rotate_3rd::rotate()
{
	int move = 0;

	if (shift > 26 || shift < -26)
		move = shift % 26;
	else
		move = shift;

	int size = static_cast<int>(text.size());

	for (int i = 0; i < size; i++)
	{
		if (text[i] > 96 && text[i] < 123 && text[i] + move > 122 && i % 3 == 0) // jesli jest mala litera i po przesunieciu przekracza wartosc 122, przedzial: 97-122
			text[i] = 96 + (text[i] + move - 122);

		else if (text[i] > 64 && text[i] < 91 && text[i] + move > 90 && i % 3 == 0) // jesli jest wielka litera i po przesunieciu przekracza wartosc 90, przedzial: 65-90
			text[i] = 64 + (text[i] + move - 90);

		else if (text[i] > 96 && text[i] < 123 && text[i] + move < 97 && i % 3 == 0) // jest jest mala litera i po przesunieciu w lewo przekracza wartosc 97
			text[i] = 122 + (text[i] + move - 96);

		else if (text[i] > 64 && text[i] < 91 && text[i] + move < 65 && i % 3 == 0) // jest jest mala litera i po przesunieciu w lewo przekracza wartosc 97
			text[i] = 90 + (text[i] + move - 64);
		else if (i % 3 == 0)
			text[i] = text[i] + move;
	}

}

std::string Cylinder_Rotate_3rd::get_text()
{
	return text;
}