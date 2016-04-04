#include <iostream>
#include "Book.h"

Book::Book(string fName, string lName, string title_, Date current, Date due_) {
	
	firstName = fName;
	lastName = lName;
	title = title_;
	checkOut = current;
	due = due_;

}// Put in default values 

Book::~Book() {

}
Book & Book::setCheckOutDate(Date currentDate) {
	checkOut = currentDate;
	return *this;
}
Book & Book::setDueDate(Date dueDate) {
	due = dueDate;
	return *this;
}
Book & Book::setFirstName(string fName) {
	firstName = fName;
	return *this;
}
Book & Book::setLastName(string lName) {
	lastName = lName; 
	return *this;
}
Book & Book::setTitle(string title_) {
	title = title_;
	return *this;
}
string Book::getFirstName() {
	return firstName;
}
string Book::getLastName() {
	return lastName;
}
string Book::getTitle() {
	return title;
}
Date Book::getCheckOutDate() {
	return checkOut;
}
Date Book::getDueDate() {
	return due;
}