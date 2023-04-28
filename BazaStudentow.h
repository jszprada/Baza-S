#include <vector>
#include "Student.h"
using namespace std;
class BazaStudentow
{
public:
	vector<Student> bazaStudentow;
	void add(unsigned int index, string imie, string nazwisko);
	void print();
	void search(unsigned int index);
	bool deleteS(unsigned int index);
	void save();
	void read();
	void deleteDatabase();
};

