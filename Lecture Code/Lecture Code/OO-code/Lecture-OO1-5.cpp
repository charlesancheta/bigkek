//============================================================================
// Name        : lecture-OO1-5.cpp
// Author      : mr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//=============================================================================

#include <iostream>
using namespace std;

#define NAME_MAXL 20

class UofAStudent {
private:
    char Name[NAME_MAXL];
    int studentID;
public:
    UofAStudent ();
    UofAStudent (char *fn, int id);
    void assignN(char *fname);
    void assignID(int value);
    void printName();
    int lengthName();
    
};

int main() {
    
    UofAStudent stu1;
    UofAStudent stu12;
    
    char fn[] = "John";
    char ffn[] = "Joe";
    
    stu1.printName();
    stu1.assignN(fn);
    stu1.assignID(123456789);
    stu1.printName();
    cout << "(6) His name is: " << stu1.lengthName() << " bytes long." << endl;
    
    UofAStudent stu2(ffn, 987654321);
    stu2.printName();
    cout << "(6) His name is: " << stu2.lengthName() << " bytes long." << endl;
    return 0;
}

UofAStudent :: UofAStudent () {
    studentID = 0;
}
UofAStudent :: UofAStudent (char *fn, int id) {
    strcpy(Name,fn);
    studentID = id;
}
void UofAStudent :: assignN(char *fname) {
    strcpy(Name, fname);
}
void UofAStudent :: assignID(int value) {
    studentID = value;
}
void UofAStudent :: printName() {
    cout << "This is " << Name << "." << endl;
}
int UofAStudent :: lengthName() {
    return (int)strlen(Name);
}

