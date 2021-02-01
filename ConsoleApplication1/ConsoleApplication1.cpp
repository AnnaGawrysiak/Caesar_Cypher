#include "Caesar.h"
#include "First_Cylinder.h"
#include "test.h"
#include <iostream>
#include <string>

int main()
{
	//test* testowa = test::get_instance();
	//testowa->run(); // testy maja sie same tworzyc, sprawdzac i wyczyscic. jest enkapsulacja.

	std::string text = "";

	std::cout << "Enter your phrase: " << std::endl;
	getline(std::cin, text);

	//Cezar* szyfr = new Cezar();
	//auto msg = szyfr->Koduj();
	Caesar message(text);
	
	message.encrypt();

	std::cout << "Encrypted Message : " << message.msg << std::endl;

	//std::cout << "Decrypted Message : " << message.decrypt(text, key) << std::endl;

	return 0;

}