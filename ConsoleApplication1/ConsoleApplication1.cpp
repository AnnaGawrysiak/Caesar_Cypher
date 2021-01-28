#include "Caesar.h"
#include <iostream>
#include <string>

bool test1()
{
	std::string szyfr;
	szyfr = "abc";
	std::string oczekiwany_wynik = "def";

	Caesar test;

	std::string wynik = test.encrypt(szyfr, 3);
	

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}
/*
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

bool test6()
{
	std::string szyfr;
	szyfr = "def";
	std::string oczekiwany_wynik = "abc";

	std::string  wynik = encrypt(szyfr, -3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test7()
{
	std::string szyfr;
	szyfr = "abc";
	std::string oczekiwany_wynik = "xyz";

	std::string  wynik = encrypt(szyfr, -29);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test8()
{
	std::string szyfr;
	szyfr = "ABC";
	std::string oczekiwany_wynik = "XYZ";

	std::string  wynik = encrypt(szyfr, -29);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}
*/
int main()
{
	
	std::string text;

	char task;
	std::cout << "What would you like to do? Enter 'E' for encoding, enter 'D' for decoding (enter 'D'), or enter 'Q' to quit. " << std::endl;
	std::cin >> task;

	do
{
	switch(task)
	{
	case 'E':
	{
		int key;

		std::cout << "Please choose a number(key) for which you want the alphabets to be shifted:  " << std::endl;
		std::cout << "The key can either be positive (forward shifting), negative (backward shifting) or zero (no shifting). ";
		std::cin >> key;

		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');

		std::cout << "Enter your phrase: " << std::endl;
		getline(std::cin, text);

		Caesar message;

		std::cout << "Encrypted Message : " << message.encrypt(text, key) << std::endl;

		break;
	}

	case 'D':
			// decode words
	break;

	case 'Q':
			exit(0);
	break;

	default: 
	std::cout<<"Nie ma takiej opcji w menu!";
	}

	std::cout << "What would you like to do? Enter 'E' for encoding, enter 'D' for decoding (enter 'D'), or enter 'Q' to quit. " << std::endl;
	std::cin >> task;

} while(!(task == 'Q'));

	if (test1())
		std::cout << "Test 1: Sukces! " << std::endl;
	else
		std::cout << "Test 1: Porazka " << std::endl;

	/*
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

	if (test6())
		std::cout << "Test 6: Sukces! " << std::endl;
	else
		std::cout << "Test 6: Porazka " << std::endl;

	if (test7())
		std::cout << "Test 7: Sukces! " << std::endl;
	else
		std::cout << "Test 7: Porazka " << std::endl;

	if (test8())
		std::cout << "Test 8: Sukces! " << std::endl;
	else
		std::cout << "Test 8: Porazka " << std::endl;
	*/
	return 0;

}