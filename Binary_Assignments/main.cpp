//
//  main.cpp
//  short_return_to_binary
//
//  Created by Angel on 3/23/16.
//  Copyright © 2016 Angel Jimenez. All rights reserved.
//
/*
4.	Write 4 very short C++ programs: one that opens a text file, write 2 integers to it, and closes it(basically the first part of the above),
one that opens the text file you wrote to, reads the 2 integers from it and prints them out to the screen(basically the second part of above).
The other two does basically the same thing but with a binary file, using write() to write to the binary file, and read() to read from the binary
file.For read() and write() you can use the sizeof() function to get the size of an integer.Run the programs that write to the files first and
then run the programs that read from them afterwards.

5.	Open the two files you created using NotePad(or other simple text editor) and take screen shots of the contents.
--------------------------------------------------------------------------------------------------------------------------------------------------------------

1.	Create a class with two public members: an integer and a double.  Repeat 4 and 5, but instead of 2 integers, use 2 objects of your class (put in whatever values you wish).  
You can use sizeof() to get the size of your object.

2.	Create an fstream to a binary file that you can both write to and read from.  Write 5 objects of your class to your binary file.  Then see if you can read them all back in 
order and print them to the screen.  Next, see if you can retrieve the third object directly from the file by using seekg() and an offset from the file beginning of 2 object size.

*/


#include <iostream>
#include <fstream>
using namespace std;

class NumClass {
public:
	int intNum;
	double doubleNum;

	NumClass() {

	}

	~NumClass() {

	}

};


ostream& operator<<(ostream& os, const NumClass& nc)
{
	os << "NumClass Object:\n" << "Integer Variable: " << nc.intNum << "\nDouble Variable: " << nc.doubleNum << endl << endl;

	return os;
}


int main() {

	NumClass num1;
	NumClass num2;
	NumClass num3;
	NumClass num4;
	NumClass num5;
	NumClass readNum;

	ofstream outFile;
	ifstream inFile;

	num1.intNum = 21;
	num1.doubleNum = 21.21;

	num2.intNum = 22;
	num2.doubleNum = 22.22;

	num3.intNum = 23;
	num3.doubleNum = 23.23;

	num4.intNum = 24;
	num4.doubleNum = 24.24;

	num5.intNum = 25;
	num5.doubleNum = 25.25;

	outFile.open("classToBin", ios::binary);

	if (outFile) {

		outFile.write((char*)&num1, sizeof(NumClass));
		outFile.write((char*)&num2, sizeof(NumClass));
		outFile.write((char*)&num3, sizeof(NumClass));
		outFile.write((char*)&num4, sizeof(NumClass));
		outFile.write((char*)&num5, sizeof(NumClass));

		outFile.close();
	}
	else {
		cout << "Could not open file to write\n";
	}

	inFile.open("classToBin", ios::binary);

	if (inFile) {
		inFile.read((char*)&num1, sizeof(NumClass));
		inFile.read((char*)&num2, sizeof(NumClass));
		inFile.read((char*)&num3, sizeof(NumClass));
		inFile.read((char*)&num4, sizeof(NumClass));
		inFile.read((char*)&num5, sizeof(NumClass));

		cout << num1 << num2 << num3 << num4 << num5;

		inFile.close();
	}
	else {
		cout << "Could not open file to read\n";
	}


	inFile.open("classToBin", ios::binary);

	if (inFile) {
		inFile.seekg(2*sizeof(NumClass),inFile.beg);
		
		inFile.read((char*)&readNum, sizeof(NumClass));

		cout << "The third object in the file is: \n" << readNum;

		inFile.close();
	}
	else {
		cout << "Could not open file to seekg()\n";
	}
	
	system("pause");
	return 0;
}