#include <string>
using namespace std;
class Student {
public:
	unsigned int indeks;
	string imie;
	string nazwisko;
	Student(unsigned int indeks, string imie, string nazwisko);
	void print();
	unsigned int getIndeks();
	string getImie();
	string getNazwisko();
};

