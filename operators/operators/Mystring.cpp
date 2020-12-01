#pragma warning(disable  : 4996)
#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
using std::string;
Mystring::Mystring()
	: str{ nullptr } {
	str = new char[1];
	*str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s)
	: str{ nullptr } {
	if (s == nullptr) {
		str = new char[1];
		*str = '\0';
	}
	else {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}
}

// Copy constructor
Mystring::Mystring(const Mystring &source)
	: str{ nullptr } {
	str = new char[strlen(source.str) + 1];
	strcpy(str, source.str);
	//       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring(Mystring &&source)
	:str(source.str) {
	source.str = nullptr;
	        std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring() {
	delete[] str;
	    std::cout << "Using Destructor" << std::endl;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
	//    std::cout << "Using copy assignment" << std::endl;
	if (this == &rhs)
		return *this;
	delete[] str;
	str = new char[strlen(rhs.str) + 1];
	strcpy(str, rhs.str);
	return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs) {
	//   std::cout << "Using move assignment" << std::endl;
	if (this == &rhs)
		return *this;
	delete[] str;
	str = rhs.str;
	rhs.str = nullptr;
	return *this;
}


// Display method
void Mystring::display() const {
	std::cout << str << " : " << get_length() << std::endl;
}

// getters
int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
	os << rhs.str;
	return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
	char *buff = new char[1000];
	in >> buff;
	rhs = Mystring{ buff };
	delete[] buff;
	return in;
}

bool Mystring ::operator==(const Mystring &rhs) const{
	return !(strcmp(this->get_str(), rhs.get_str()));
}

bool Mystring ::operator!=(const Mystring &rhs) const {
	return (strcmp(this->get_str(), rhs.get_str()));
}

bool Mystring ::operator<(const Mystring &rhs) const {
	return this->get_length() < rhs.get_length();
}

bool Mystring ::operator>(const Mystring &rhs) const {
	return this->get_length() > rhs.get_length();
}

Mystring Mystring ::operator-()const {
	
	
	char *buff = new char[(this->get_length()) + 1];
	int i;

	for (i = 0; i < this->get_length(); i++) {
		buff[i] = tolower(this->get_str()[i]);
	}
	buff[i] = '\0';

	Mystring temp{ buff };
	delete []buff;
	return temp;
}

Mystring Mystring ::operator+(const Mystring &rhs) const {
	char *buff = new char[this->get_length() + rhs.get_length() + 1];
	
	strcpy(buff, str);
	strcat(buff, rhs.str);
	Mystring temp{ buff };

	delete[]buff;

	return temp;
}

void Mystring ::operator+=(const Mystring &rhs) {
	*this = *this + rhs;
}

Mystring Mystring ::operator*(int rhs)const {
	char *buff = new char[this->get_length() * rhs + 1];

	strcpy(buff, this->get_str());
	for (int i = 1; i < rhs; i++) {
		strcat(buff, this->get_str());
	}
	Mystring temp{ buff };

	delete[]buff;

	return temp;
}

void Mystring ::operator*=(int rhs) {
	*this = *this * rhs;
}

Mystring& Mystring ::operator++() {
	for (int i = 0; i < this->get_length(); i++) {
		this->str[i] = toupper(this->str[i]);
	}

	return *this;
}

Mystring& Mystring ::operator++(int) {
	for (int i = 0; i < this->get_length(); i++) {
		this->str[i] = tolower(this->str[i]);
	}

	return *this;
}