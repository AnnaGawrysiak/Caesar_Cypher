#include "test.h"

test::test()
{
}

test* test::wsk = nullptr;

test* test::get_instance()
{
	if (!wsk)
		wsk = new test(); // przez new nalezy explicite konstruktor wywolac

	return wsk;

}

bool test::test1()
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

bool test::test2()
{
	std::string szyfr;
	szyfr = "xyz"; // skrajnosci
	std::string oczekiwany_wynik = "abc";

	Caesar test;

	std::string wynik = test.encrypt(szyfr, 3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test::test3()
{
	std::string szyfr;
	szyfr = "ABc";
	std::string oczekiwany_wynik = "DEf";
	
	Caesar test;

	std::string wynik = test.encrypt(szyfr, 3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test::test4()
{
	std::string szyfr;
	szyfr = "XYZ";
	std::string oczekiwany_wynik = "ABC";

	Caesar test;

	std::string wynik = test.encrypt(szyfr, 3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test::test5()
{
	std::string szyfr;
	szyfr = "abc";
	std::string oczekiwany_wynik = "def";

	Caesar test;

	std::string wynik = test.encrypt(szyfr, 29);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test::test6()
{
	std::string szyfr;
	szyfr = "def";
	std::string oczekiwany_wynik = "abc";

	Caesar test;

	std::string wynik = test.encrypt(szyfr, -3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test::test7()
{
	std::string szyfr;
	szyfr = "abc";
	std::string oczekiwany_wynik = "xyz";

	Caesar test;

	std::string wynik = test.encrypt(szyfr, -29);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test::test8()
{
	std::string szyfr;
	szyfr = "ABC";
	std::string oczekiwany_wynik = "XYZ";

	Caesar test;

	std::string wynik = test.encrypt(szyfr, -29);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test::test9()
{
	std::string szyfr;
	szyfr = "def";
	std::string oczekiwany_wynik = "abc";

	Caesar test;

	std::string wynik = test.decrypt(szyfr, 3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test::test10()
{
	std::string szyfr;
	szyfr = "abc";
	std::string oczekiwany_wynik = "xyz";

	Caesar test;

	std::string wynik = test.decrypt(szyfr, 3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test::test11()
{
	std::string szyfr;
	szyfr = "XYZ";
	std::string oczekiwany_wynik = "ABC";

	Caesar test;

	std::string wynik = test.decrypt(szyfr, -3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test::test12()
{
	std::string szyfr;
	szyfr = "DEF";
	std::string oczekiwany_wynik = "ABC";

	Caesar test;

	std::string wynik = test.decrypt(szyfr, 3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test::test13()
{
	std::string szyfr;
	szyfr = "xyZ";
	std::string oczekiwany_wynik = "abC";

	Caesar test;

	std::string wynik = test.decrypt(szyfr, -3);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

void test::run()
{
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

	if (test9())
		std::cout << "Test 9: Sukces! " << std::endl;
	else
		std::cout << "Test 9: Porazka " << std::endl;

	if (test10())
		std::cout << "Test 10: Sukces! " << std::endl;
	else
		std::cout << "Test 10: Porazka " << std::endl;

	if (test11())
		std::cout << "Test 11: Sukces! " << std::endl;
	else
		std::cout << "Test 11: Porazka " << std::endl;

	if (test12())
		std::cout << "Test 12: Sukces! " << std::endl;
	else
		std::cout << "Test 12: Porazka " << std::endl;

	if (test13())
		std::cout << "Test 13: Sukces! " << std::endl;
	else
		std::cout << "Test 13: Porazka " << std::endl;
	
}