//============================================================================
// Name        : lecture-OO1-3.cpp
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
	UofAStudent () {
        studentID = 0;
	}
	UofAStudent (char *fn, int id) {
        strcpy(Name,fn);
        studentID = id;
	}
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
        return (int)strlen(Name);
	}
 };
 
 int main() {
 
	UofAStudent stu1;
	char fn[] = "John";
	char ffn[] = "Joe";
 
	stu1.printName();
	stu1.assignN(fn);
	stu1.assignID(123456789);
	stu1.printName();
	cout << "(5) His name is: " << stu1.lengthName() << " bytes long." << endl;
 
	UofAStudent stu2(ffn, 987654321);
	stu2.printName();
	cout << "(5) His name is: " << stu2.lengthName() << " bytes long." << endl;
     
	return 0;
 }


