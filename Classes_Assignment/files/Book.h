#pragma once

#include <iostream>
#include "Date.h"
using namespace std;

const Date default;

class Book {
private:
	string firstName;
	string lastName;
	string title;
	Date checkOut;
	Date due;
public:
	Book(string fName = "", string lname = "", string title = "", Date = default, Date = default); // Put in default values 
	~Book();
	Book & setCheckOutDate(Date);
	Book & setDueDate(Date);
	Book & setFirstName(string);
	Book & setLastName(string);
	Book & setTitle(string);
	string getFirstName();
	string getLastName();
	string getTitle();
	Date getCheckOutDate();
	Date getDueDate();
	
};
