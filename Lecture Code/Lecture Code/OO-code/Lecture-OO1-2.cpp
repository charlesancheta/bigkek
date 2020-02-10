//============================================================================
// Name        : lecture-OO1-2.cpp
// Author      : mr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

 #include <iostream>
 using namespace std;
 
 #define NAME_MAXL 20
 
 class UofAStudent {
 private:
	char Name[NAME_MAXL];
	int studentID;
 public:
	void assignN(char *fname) {
 strcpy(Name, fname);
	}
	void assignID(int value) {
 studentID = value;
	}
 void printName() {
 cout << "This is " << Name << "." << endl;
	}
	int lengthName() {
 return strlen(Name);
	}
 
 };
 
 int main() {
 
	UofAStudent stu1;
	char fn[] = "John";
 
	stu1.assignN(fn);
	stu1.assignID(123456789);
	stu1.printName();
	cout << "(4) His name is: " << stu1.lengthName() << " bytes long." << endl;
 
	return 0;
 }


