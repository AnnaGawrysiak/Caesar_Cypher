#include "Caesar.h"
#include "test.h"
#include <iostream>
#include <string>

int main()
{
	test* testowa = test::get_instance();
	testowa->run(); // testy maja sie same tworzyc, sprawdzac i wyczyscic. jest enkapsulacja.


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

	return 0;

}