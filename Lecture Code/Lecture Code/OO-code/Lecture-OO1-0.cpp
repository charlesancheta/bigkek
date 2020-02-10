//============================================================================
// Name        : lecture-OO.cpp
// Author      : mr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define NAME_MAXL 20

struct UofAStudent {
    char Name[NAME_MAXL];
    int studentID;
};

void printNameS(struct UofAStudent stu);
int  lengthNameS(struct UofAStudent stu);

int main() {
    
    struct UofAStudent stu1;
    
    strcpy(stu1.Name, "John");
    printNameS(stu1);
    cout << "(1) His name is " << lengthNameS(stu1) << " bytes long." << endl;
    
    return 0;
}

void printNameS(struct UofAStudent stu) {
    cout << "This is " << stu.Name << "." << endl;
}

int lengthNameS(struct UofAStudent stu) {
    return (int)strlen(stu.Name);
}

/*
 #include <iostream>
 using namespace std;
 
 
 
 #define NAME_MAXL 20
 
 class car {
	char manufacturer[NAME_MAXL];
	int serialNo;
	int engineCC;
	int year;
	void assignYear(int year);
 public:
	car();
	car(char *n, int sNO);
	car(char *n, int sNO, int engCC);
	car(char *n, int sNO, int engCC, int year);
	void assignManuf(char *n);
	void assignEngineCC(int cc);
	int readEngineCC();
 };
 
 int main()
 {
	char name[] = "Honda";
	car Honda(name);
 }
 
 
 car :: car() {
	strcpy(manufacturer,"first");
	serialNo = 0;
	engineCC = 0;
	year = 0;
 }
 car :: car(char *n, int sNO) {
	strcpy(manufacturer,n);
	serialNo = sNO;
	engineCC = 0;
	year = 0;
 }
 
 car :: car(char *n, int sNO, int engCC) {
	strcpy(manufacturer,n);
	serialNo = sNO;
	engineCC = engCC;
	year = 0;
 }
 
 car :: car(char *n, int sNO, int engCC, int yr) {
	strcpy(manufacturer,n);
	serialNo = sNO;
	engineCC = engCC;
	year = yr;
 }
 */
