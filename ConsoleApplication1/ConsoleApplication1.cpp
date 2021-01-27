#include "Caesar.h"
#include <iostream>
#include <string>

std::string encrypt(std::string text, int shift) 
{// szyfr w lewo i prawo. ustaw kierunek. najpier test, ktory sie nie uda + skrajne przypadki. na koniec kilkuwarstwowy szyfr
	//  ASCII a - 97 . 26 jest malych liter
	int move = 0;

	if (shift > 26)
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
		else
		text[i] = text[i] + move;
	}

	return text;
}

bool test1()
{
	std::string szyfr;
	szyfr = "abc";
	std::string oczekiwany_wynik = "def";

	std::string  wynik = encrypt(szyfr, 3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test2() 
{
	std::string szyfr;
	szyfr = "xyz"; // skrajnosci
	std::string oczekiwany_wynik = "abc";

	std::string  wynik = encrypt(szyfr, 3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test3()
{
	std::string szyfr;
	szyfr = "ABc"; 
	std::string oczekiwany_wynik = "DEf";

	std::string  wynik = encrypt(szyfr, 3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test4()
{
	std::string szyfr;
	szyfr = "XYZ";
	std::string oczekiwany_wynik = "ABC";

	std::string  wynik = encrypt(szyfr, 3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test5()
{
	std::string szyfr;
	szyfr = "abc";
	std::string oczekiwany_wynik = "def";

	std::string  wynik = encrypt(szyfr, 29);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

int main()
{
	std::string text;

	int key;

	std::cout << "Enter your phrase: " << std::endl;
	getline(std::cin, text);

	std::cout << "Please choose a number(key) for which you wants the alphabets to be shifted:  " << std::endl;
	std::cout<< "The key can either be positive (forward shifting), negative (backward shifting) or zero (no shifting). " << std::endl;

	std::cin >> key;

	//const Caesar message;

	//std::cout << "Encrypted Message : " << message.encrypt(text, key) << std::endl;


	if (test1())
		std::cout << "Test 1: Sukces! " << std::endl;
	else
		std::cout << "Test 1: Porazka " << std::endl;

	if (test2())
		std::cout << "Test 2: Sukces! " << std::endl;
	else
		std::cout << "Test 2: Porazka " << std::endl;

	if (test3())
		std::cout << "Test 3: Sukces! " << std::endl;
	else
		std::cout << "Test 3: Porazka " << std::endl;

	if (test4())
		std::cout << "Test 4: Sukces! " << std::endl;
	else
		std::cout << "Test 4: Porazka " << std::endl;

	if (test5())
		std::cout << "Test 5: Sukces! " << std::endl;
	else
		std::cout << "Test 5: Porazka " << std::endl;

	return 0;

}