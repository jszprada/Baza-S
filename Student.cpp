#include "Student.h"
#include <string>
#include <iostream>
using namespace std;
Student::Student(unsigned int indeks, string imie, string nazwisko) {
	this->indeks = indeks;
	this->imie = imie;
	this->nazwisko = nazwisko;
}
void Student::print() {
	cout << "Indeks: " <<
		this->indeks << ", imie: " <<
		this->imie << ", nazwisko: " <<
		this->nazwisko << endl;
}

unsigned int Student::getIndeks() {
	return this->indeks;
}
string Student::getImie() {
	return this->imie;
}
string Student::getNazwisko() {
	return this->nazwisko;
}