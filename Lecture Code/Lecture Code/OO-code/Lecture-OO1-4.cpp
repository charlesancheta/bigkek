//============================================================================
// Name        : lecture-OO1-4.cpp
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
	int ID;
	int studentID;
 public:
	UofAStudent();
	UofAStudent(char *n, int sid);
	void assignN(char *n);
	void printName();
	int lengthName();
 };
 
 int main() {
 
	char jn[] = "John";
 
	UofAStudent stu1;
	UofAStudent stu2(jn,1234567);
 
	//stu1.assignN(jn);
	stu1.printName();
	stu2.printName();
 
	cout << "(3) His name is " << stu1.lengthName() << "bytes long." << endl;
 
	return 0;
 }
 
 
 UofAStudent :: UofAStudent() {
	strcpy(Name,"first");
	studentID = 0;
 }
 UofAStudent :: UofAStudent(char *n, int sid) {
	strcpy(Name,n);
	studentID = sid;
 }
 void UofAStudent :: assignN(char *n) {
	strcpy(Name,n);
 }
 void UofAStudent :: printName() {
	cout << "This is " << Name << "." << endl;
 }
 int UofAStudent :: lengthName() {
	return strlen(Name);
 }

