#include <iostream>
#include <string>
#include "Caesar.h"

Caesar::Caesar() 
{
}

Caesar::Caesar(std::string text_, int shift_)
{
	text = text_;
	shift = shift_;
}

std::string Caesar::encrypt(std::string text, int shift)
{// szyfr w lewo i prawo. ustaw kierunek. najpier test, ktory sie nie uda + skrajne przypadki. na koniec kilkuwarstwowy szyfr
	//  ASCII a - 97 . 26 jest malych liter
	int move = 0;

	if (shift > 26 || shift < -26)
		move = shift % 26;
	else
		move = shift;

	int size = static_cast<int>(text.size());

	for (int i = 0; i < size; i++)
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

	return text;
}

std::string Caesar::decrypt(std::string text, int shift)
{
	
	Caesar decode;
	std::string decoded = decode.encrypt(text, (-1)*shift);

	return decoded;

}