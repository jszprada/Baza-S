#include "BazaStudentow.h"
#include <vector>
#include <fstream>
#include <iostream>
void BazaStudentow::add(unsigned int index, string imie, string nazwisko) {
	this->bazaStudentow.push_back(Student(index, imie, nazwisko));
}
void BazaStudentow::print() {
	for (Student& s : bazaStudentow) {
		s.Student::print();
	}
}
void BazaStudentow::search(unsigned int index) {
	for (Student& s : bazaStudentow) {
		if (s.getIndeks() == index) {
			s.Student::print();
			return;
		}
	}
}
bool BazaStudentow::deleteS(unsigned int index) {
	int i = -1;
	for (Student& s : bazaStudentow) {
		i++;
		if (s.getIndeks() == index) {
			bazaStudentow.erase(bazaStudentow.begin() + i);
			return true;
		}
	}
	return false;
}
void BazaStudentow::deleteDatabase() {
	bazaStudentow.clear();
}
void BazaStudentow::save() {
	ofstream myfile;
	myfile.open("bazaStudentow.txt");
	for (Student& s : bazaStudentow) {
		myfile << s.getIndeks()<<" "<<
			s.getImie() << " " <<
			s.getNazwisko() << endl;
	}
	myfile.close();
}
void BazaStudentow::read() {
	ifstream file("bazaStudentow.txt");
	string str;
	while (std::getline(file, str)) {
		cout << str << endl;
	}
}