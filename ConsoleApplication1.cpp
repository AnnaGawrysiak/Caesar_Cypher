#include "Caesar.h"
#include "First_Cylinder.h"
#include "test.h"
#include <iostream>
#include <string>

int main()
{
	test* testowa = test::get_instance();
	testowa->run(); // testy maja sie same tworzyc, sprawdzac i wyczyscic. jest enkapsulacja.

	std::string text = "";

	std::cout << "Enter your phrase: " << std::endl;
	getline(std::cin, text);

	Caesar message(text);
	
	message.encrypt();

	std::cout << "Encrypted Message : " << message.get_msg() << std::endl;

	message.decrypt();
	
	std::cout << "Decrypted Message : " << message.get_msg() << std::endl;

	return 0;

}