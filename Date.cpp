#include <iostream>
#include "MysteryMachine.h"
#include "Date.h"

using namespace std;

// constructor
Date::Date() {
	month = 1;
	day = 1;
	year = 2000;
}

// overloaded constructor
Date::Date(int month, int day, int year) {
	this->month = month;
	this->day = day;
	this->year = year;
}


// accessors for date values
int Date::getMonth() {
	return month;
}
int Date::getDay() {
	return day;
}
int Date::getYear() {
	return year;
}

// Add days onto date object
Date Date::operator+(int days) {
	while (days > 0) {
		int daysInMonth;

		if (month == 2) {
		    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			daysInMonth = 29;
		    } else {
			daysInMonth = 28;
		    }
		} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		    daysInMonth = 30;
		} else {
		    daysInMonth = 31;
		}

		if (day + days > daysInMonth) {
		    days -= (daysInMonth - day + 1);
		    day = 1;
		    if (month == 12) {
			month = 1;
			year++;
		    } else {
			month++;
		    }
		} else {
		    day += days;
		    break;
		}
	}
	return *this;
}

// subtract days from date object
Date Date::operator-(int days) {
	while (days > 0) {
		if (day - days < 1) {
			if (month == 1) {
				month = 12;
				year--;
			} else {
				month--;
			}

			int daysInPreviousMonth;

			if (month == 2) {
				if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
					daysInPreviousMonth = 29;
					} else {
						daysInPreviousMonth = 28;
					}
			} else if (month == 4 || month == 6 || month == 9 || month == 11) {
				daysInPreviousMonth = 30;
		    	} else {
				daysInPreviousMonth = 31;
			}

		   	day = daysInPreviousMonth - (days - day);
			days = 0;
		} else {
		   	day -= days;
		    	break;
		}
	}
	return *this;
}
// ++
Date Date::operator++(void) { // prefix
	*this = *this + 1;
	return *this;
}
Date Date::operator++(int) { // postfix
	Date temp = *this;
	*this = *this + 1;
	return temp;
}

// --
Date Date::operator--(void) {
	*this = *this - 1;
	return *this;
}
Date Date::operator--(int) {
	Date temp = *this;
	*this = *this - 1;
	return temp;
}

// return the day of the week of date object
std::string Date::getDayOfWeek() {
	return MysteryMachine::getDayOfWeek(*this);
}

// return date object in string form
std::string Date::toString() {
	return std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year);
}

