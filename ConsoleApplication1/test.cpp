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
	std::string cypher = "abc";
	std::string expected_result = "def";

	Caesar test(cypher);

	int overlap = 3;

	First_Cylinder* first = new First_Cylinder(overlap, cypher);
	first->rotate();
	cypher = first->get_text();

	std::string result = first->get_text();

	if (result == expected_result)
		return true;

	return false;
}


bool test::test2()
{
	std::string cypher = "xyz";
	std::string expected_result = "abc";

	Caesar test(cypher);

	int overlap = 3;

	First_Cylinder* first = new First_Cylinder(overlap, cypher);
	first->rotate();
	cypher = first->get_text();

	std::string result = first->get_text();

	if (result == expected_result)
		return true;

	return false;
}


bool test::test3()
{
	
	std::string cypher = "ABc";
	std::string expected_result = "DEf";

	Caesar test(cypher);

	int overlap = 3;

	First_Cylinder* first = new First_Cylinder(overlap, cypher);
	first->rotate();
	cypher = first->get_text();

	std::string result = first->get_text();

	if (result == expected_result)
		return true;

	return false;
}


bool test::test4()
{
	std::string cypher = "XYZ";
	std::string expected_result = "ABC";

	Caesar test(cypher);

	int overlap = 3;

	First_Cylinder* first = new First_Cylinder(overlap, cypher);
	first->rotate();
	cypher = first->get_text();

	std::string result = first->get_text();

	if (result == expected_result)
		return true;

	return false;
}


bool test::test5()
{
	std::string cypher = "ABC";
	std::string expected_result = "DBF";

	Caesar test(cypher);

	int overlap = 3;

	Cylinder_Rotate_Odd* first = new Cylinder_Rotate_Odd(overlap, cypher);
	first->rotate();
	cypher = first->get_text();

	std::string result = first->get_text();

	if (result == expected_result)
		return true;

	return false;
}


bool test::test6()
{
	std::string cypher = "XYZ";
	std::string expected_result = "UYW"; 

	Caesar test(cypher);

	int overlap = -3;

	Cylinder_Rotate_Odd* first = new Cylinder_Rotate_Odd(overlap, cypher);
	first->rotate();
	cypher = first->get_text();

	std::string result = first->get_text();

	if (result == expected_result)
		return true;

	return false;
}

bool test::test7()
{
	std::string cypher = "ABCDEFG";
	std::string expected_result = "DBCGEFJ";

	Caesar test(cypher);

	int overlap = 3;

	Cylinder_Rotate_3rd* first = new Cylinder_Rotate_3rd(overlap, cypher);
	first->rotate();
	cypher = first->get_text();

	std::string result = first->get_text();

	if (result == expected_result)
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


}
