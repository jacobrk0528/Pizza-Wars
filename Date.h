#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date {
private:
	int month;
	int day;
	int year;
public:
	Date(); // Default constructor
	Date(int month, int day, int year); // Parameterized constructor

	Date operator+(int days); // overloaded operators
	Date operator-(int days);
	Date operator++(void); // prefix
	Date operator++(int); // postfix
	Date operator--(void); // prefix
	Date operator--(int); // postfix

	int getMonth();
	int getDay();
	int getYear();
	std::string getDayOfWeek(); // Declaration for the day of the week function
	std::string toString();
};

#endif // DATE_H

