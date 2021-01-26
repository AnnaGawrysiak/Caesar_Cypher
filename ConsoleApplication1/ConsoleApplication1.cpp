#include <iostream>
#include <string>
// szyfr Cezara - kazda litere przesuwa sie o okreslona liczbe miejsc np. o 3
std::string koduj(std::string tekst) // aby to nie bylo zawsze + 3, tylko niech uzytkownik wskazuje o ile chce przesunac. dla dowolne < 26
{// szyfr w lewo i prawo. ustaw kierunek. najpier test, ktory sie nie uda + skrajne przypadki. na koniec kilkuwarstwowy szyfr
	//  ASCII a - 97 . 26 jest malych liter
	char primo = tekst[0] + 3; // beben musi byc osobna klasa. dla kazdego bebna o ile oraz czy w lewo czy w prawo + skladanie na koniec
	if (primo > 122) // + rozkoduj. obsluga spacji i znakow specjalnych. 
		primo = primo - 26;
	std::cout << "pierwsza: " << primo << std::endl;
	char secundo = tekst[1] + 3;
	if (secundo > 122)
		secundo = secundo - 26;
	std::cout << "druga: " << secundo << std::endl;
	char tertio = tekst[2] + 3;
	if (tertio > 122)
		tertio = tertio - 26; // mozemy od razu do trzecia sprawdzac czy jest wieksza niz 22 i doejmwoac 26
	

	std::string nowy = "";

	nowy += primo;
	nowy += secundo;
	nowy += tertio;
	

	std::cout << nowy << std::endl;

	return nowy;
}


bool test1() // test przeszedl - zostaje na wieki
{
	std::string szyfr;
	szyfr = "abc";
	std::string oczekiwany_wynik = "def";
	
	std::string  wynik = koduj(szyfr);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}

bool test2() // test przeszedl - zostaje na wieki
{
	std::string szyfr;
	szyfr = "xyz"; // skrajnosci
	std::string oczekiwany_wynik = "abc";

	std::string  wynik = koduj(szyfr);

	if (wynik == oczekiwany_wynik)
		return true;

	return false;
}


int main()
{

	if (test1())
		std::cout << "Sukces! " << std::endl;
	else
		std::cout << "Porazka " << std::endl;

	if (test2())
		std::cout << "Test 2 Sukces! " << std::endl;
	else
		std::cout << "Test 2 Porazka " << std::endl;

}

// faza czerwona TDD, faza zielona, refactoring
// chcemy napisac test, ktory ma dzialac. czerwony - nie przechodzi, zielony - przechodzi
// teraz drugi test testujacy innego stringa. teraz poprawiamy