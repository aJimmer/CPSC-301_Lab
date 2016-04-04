

/*
[LEVEL 0]-----------------------------------------------------------------

Open CheckedOutBooks.txt containing info on currently check out books
Info is read and stored as an array of Books

user enters current date into 'date' param

while text file is open

	Displays list of options:
	[C]	Check out book
	[D] Check book back in
	[T] List of books checked out 
	[Q] Quit the program

	enter choice

	[C][D][T][Q]

	over write Book[] to file
	close file

[Level 1]-----------------------------------------------------------------

[C] checkOutBook()

Read user input for 'fName', 'lName', 'title'.
checkout date = current date
duedate += 14 days
Enter info into a table

[D]checkInBook()

Read userInput for 'fName', 'lName', 'title'.
search Book[] for  userInput
if !userInput
	print "book not found"
else
	if dueDate > currentDate
		Book is overdue
delete book from array
		
[T] printCheckedOutBooks()

Print table of books with chekout and due dates

[Q] quit()

write to file
close the program


*/

#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "Date.h"
using namespace std;

Book checkOutBook(Date&);
void checkInBook(Date &,Book bookList[],int &);
void printCheckedOutBooks(Book bookList[], int);

int main() {

	string firstName, lastName, title;
	int dates[3],  month, day, year, count = 0, fileCount = 0;
	Date date, dueDate, tempDate;
	ifstream inFile;
	ofstream outFile;
	char choice;
	Book bookList[100];
	

	inFile.open("CheckedOutBooks.txt");

	if (inFile) {
		while (!inFile.eof()) {
			inFile >> firstName >> lastName;
			bookList[fileCount].setFirstName(firstName);
			bookList[fileCount].setLastName(lastName);

			inFile.ignore();
			getline(inFile, title);
			bookList[fileCount].setTitle(title);

			inFile >> dates[0] >> dates[1] >> dates[2];
			tempDate.setDate(dates[0], dates[1], dates[2]);
			bookList[fileCount].setCheckOutDate(tempDate);

			inFile >> dates[0] >> dates[1] >> dates[2];
			tempDate.setDate(dates[0], dates[1], dates[2]);
			bookList[fileCount].setDueDate(tempDate);
		
			fileCount++;
			count = fileCount;
		}
		inFile.close();
	}	

	else {
		cout << "File did not open.";
	}
	
		cout << "Welcome to CS library program." << endl
			<< "Please enter the date in integers according to the following format - mm dd yyyy: " << endl << endl;
		cin >> month;
		cin >> day;
		cin >> year;

		date.setDate(month, day, year);

		do {

			cout << "Please enter your one letter choice as follows: " << endl
				<< "\t C: Check out a book" << endl
				<< "\t D: Check in a book" << endl
				<< "\t T: Print all books currently checked out" << endl
				<< "\t Q: quit this program" << endl << endl;
			cin >> choice;

			switch (toupper(choice)) {

			case 'C': bookList[count] = checkOutBook(date);
				count++;
				cout << "There are " << count << " books in the array" << endl;
				break;
			case 'D': checkInBook(date, bookList, count);
				break;
			case 'T': printCheckedOutBooks(bookList, count);
				break;
			case 'Q':
				break;
			default: cout << "That was not an option!" << endl;
			}
		} while (toupper(choice) != 'Q');
	
		outFile.open("CheckedOutBooks.txt");

			if (outFile) {
					for (int i = 0; i < count; i++) {
						outFile << endl << bookList[i].getFirstName() << " "
							<< bookList[i].getLastName() << " " 
							<< bookList[i].getTitle() << endl

							<< bookList[i].getCheckOutDate().getMonth() << " "
							<< bookList[i].getCheckOutDate().getDay() << " "
							<< bookList[i].getCheckOutDate().getYear() << " "

							<< bookList[i].getDueDate().getMonth() << " "
							<< bookList[i].getDueDate().getDay() << " "
							<< bookList[i].getDueDate().getYear();
					}
			}

			outFile.close();
	
	return 0;
}

Book checkOutBook(Date & currentDate) {
	string fName, lName, title;
	Book book;
	Date dueDate = currentDate;
	dueDate += 14;

	cout << "Please enter one line consisting the first and last name of the author followed by the title of the book. " << endl;
	cin >> fName;
	cin >> lName;
	cin.ignore();
	getline(cin,title);
	
	book.setFirstName(fName);
	book.setLastName(lName);
	book.setTitle(title);
	book.setCheckOutDate(currentDate);
	book.setDueDate(dueDate);

	return book;
}

void checkInBook(Date & currentDate, Book bookList[], int & count) {

	string fName, lName, title;
	Date default;
	bool found = false;
	int i = 0;

	cout << "Please enter one line consisting the first and last names of the author followed by the title of the book.\n" << endl;
	cin >> fName;
	cin >> lName;
	cin.ignore();
	getline(cin, title);

	while ((i < count)&&(found == false)) {
		
		if ((bookList[i].getFirstName() == fName) && (bookList[i].getLastName() == lName) && (bookList[i].getTitle() == title)) {

			found = true;

			if (bookList[i].getDueDate() < currentDate) {
				cout << "This book is over due." << endl;
			}
			else {
				cout << "Thank you. Your book will be checked in!" << endl;
			}

			for (int j = i; j < count-1; j++) {
				bookList[j] = bookList[j+1];
			}

			cout << "Here are the current checked out books: " << endl;
			cout << "First Name" << "\t" << "Last Name" << "\t" << "Title" << "\t" << "Checkout Date" << "\t" << "Due Date" << endl;
			count--;
			for (int k = 0; k < count; k++) {
			
				cout << bookList[k].getFirstName() << "\t"
					<< bookList[k].getLastName() << "\t"
					<< bookList[k].getTitle() << "\t" 
					<< bookList[k].getCheckOutDate() << "\t"
					<< bookList[k].getDueDate() << "\t" << endl;
			}

			cout << "There are " << count << " books in the array" << endl;
		}	
		i++;
		
	}
}
	


void printCheckedOutBooks(Book bookList[], int count) {
	cout << "Author" << "\t" << "Title" << "\t" << "Checkout Date" << "\t" << "Due Date" << endl;

	for (int k = 0; k < count; k++) {

		cout << bookList[k].getFirstName() << "\t"
			<< bookList[k].getLastName() << "\t"
			<< bookList[k].getTitle() << "\t" 
			<< bookList[k].getCheckOutDate() << "\t"
			<< bookList[k].getDueDate() << "\t"			
			<< endl; 
	}
	cout << endl;
}

