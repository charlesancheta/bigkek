//============================================================================
// Name        : lecture-OO3-3.cpp
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
    char *Name;
    int studentID;
public:
    UofAStudent ();
    UofAStudent (char *fn, int id);
    ~UofAStudent ();
    void assignN(char *fname);
    void assignID(int value);
    void printRecord();
    int lengthName();
    
};

int main() {
    
    char nJohn[] = "John";
    char nMike[] = "Mike";
    char nSusan[] = "Susan";
    
    
    UofAStudent class220[5] = { {nJohn,123}, {nMike,432}, UofAStudent(nSusan,987)};
    
    UofAStudent *ptr_class220[5] = { new UofAStudent(nJohn,123), new UofAStudent(nMike,123) };
    
    
    UofAStudent *stu1 = new UofAStudent;
    UofAStudent *stu2 = new UofAStudent(nJohn, 123456789);
    
    
    class220[1].assignN(nJohn);
    ptr_class220[0]->lengthName();
    
    
    stu1->assignN(nMike);
    stu1->assignID(987654321);
    
    (*stu1).printRecord();
    stu2->printRecord();
    
    delete stu1;
    delete stu2;
    
    return 0;
}

UofAStudent :: UofAStudent () {
    Name = new char[4];
    Name[0] = 0;
    studentID = 0;
}
UofAStudent :: UofAStudent (char *fn, int id) {
    int len = (int)strlen(fn);
    Name = new char[len];
    strcpy(Name,fn);
    studentID = id;
}
UofAStudent :: ~UofAStudent() {
    delete [] Name;
}

void UofAStudent :: assignN(char *fname) {
    strcpy(Name, fname);
}
void UofAStudent :: assignID(int value) {
    studentID = value;
}
void UofAStudent :: printRecord() {
    cout << "This is " << Name << "." << endl;
    cout << "ID is " << studentID << "." << endl;
}
int UofAStudent :: lengthName() {
    return (int)strlen(Name);
}








