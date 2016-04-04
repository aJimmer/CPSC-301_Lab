#pragma once

#include <iostream>
#include <string>

using namespace std;

class Date {
	friend ostream &operator<<(ostream &, const Date &);
private:
	int month;
	int day;
	int year;

	static const int days[];         // array of days per month
	static const string monthName[]; // array of month names
	void helpIncrement();

public:
	Date(int m = 1, int d = 1, int y = 1900); // constructor, note the default values
	void setDate(int, int, int); // set the date
	bool operator<(Date other) const;  // You need to implement this
	void operator+=(int); // add days, modify object
	bool leapYear() const;    // is this a leap year?
	bool endOfMonth() const;  // is this end of month?
	int getMonth() const; 		// You need to implement this
	int getDay() const;			// You need to implement this
	int getYear() const; 			// You need to implement this
	string getMonthString() const;  // You need to implement this
          // utility function
};
