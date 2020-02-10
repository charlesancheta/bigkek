//============================================================================
// Name        : lecture-OO1-1.cpp
// Author      : mr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

 #include <iostream>
 using namespace std;
 
 #define NAME_MAXL 20
 
 class UofAStudent {
	public:
	char Name[NAME_MAXL];
	int studentID;
 };
 
 void printNameN(UofAStudent stu);
 int  lengthNameN(UofAStudent stu);
 
 int main() {
 
	UofAStudent stu1;
 
	strcpy(stu1.Name, "John-oo");
	printNameN(stu1);
	cout << "(2) His name is " << lengthNameN(stu1) << " bytes long." << endl;
 
	return 0;
 }
 
 void printNameN(UofAStudent stu) {
	cout << "This is " << stu.Name << "." << endl;
 }
 
 int lengthNameN(UofAStudent stu) {
	return strlen(stu.Name);
 }

