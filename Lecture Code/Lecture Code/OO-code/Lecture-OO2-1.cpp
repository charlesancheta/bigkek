//============================================================================
// Name        : lecture-OO2-1.cpp
// Author      : mr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define ASSIGN_NO 5
#define NAME_MAXL 20

class UofAStudent {
private:
    char Name[NAME_MAXL];
    int studentID;
public:
    UofAStudent ();
    UofAStudent (char *fn) { strcpy(Name,fn);studentID = 0;};
    UofAStudent (int id) {studentID = id;};
    UofAStudent (char *fn, int id);
    void assignN(char *fname);
    void assignID(int value);
    void printRecord();
    
};

class ece220UofAStudent : public UofAStudent {
private:
    double midterm;
    double final;
    double assignment[ASSIGN_NO];
public:
    ece220UofAStudent ();
    ece220UofAStudent (char *fn, int id);
    void assignMT(double value);
    void assignF(double value);
    void assignA(double *marks);
    double average();
    using UofAStudent :: printRecord;
    void printRecord(int value);
};


int main() {
    
    UofAStudent stu1;
    char fn[] = "John";
    char ffn[] = "Joe";
    char fffn[] = "Susan";
    double marks[] = {89.5, 88.0, 92.5, 95.0, 91.5};
    
    stu1.printRecord();
    stu1.assignN(fn);
    stu1.assignID(123456789);
    stu1.printRecord();
    
    UofAStudent stu2(ffn, 987654321);
    stu2.printRecord();
    
    ece220UofAStudent stu3(fffn, 987654321);
    stu3.assignMT(89.0);
    stu3.assignF(74.0);
    stu3.assignA(marks);
    
    stu3.printRecord();
    stu3.UofAStudent::printRecord();
    
    
    cout << "The average mark is: " << stu3.average() << "." << endl;
    
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
void UofAStudent :: printRecord() {
    cout << "This is " << Name << "." << endl;
    cout << "ID is " << studentID << "." << endl;
}



ece220UofAStudent :: ece220UofAStudent () {
    midterm = 0.0;
    final = 0.0;
}
ece220UofAStudent :: ece220UofAStudent (char *fn, int id) : UofAStudent(fn, id), midterm(0.0), final(0.0) {
    int i;
    for (i=0; i<ASSIGN_NO; i++) {
        assignment[i] = 0.0;
    }
}
void ece220UofAStudent :: assignMT(double value) {
    midterm = value;
}
void ece220UofAStudent :: assignF(double value) {
    final = value;
}
void ece220UofAStudent :: assignA(double *marks) {
    int i;
    for (i=0; i<ASSIGN_NO; i++) {
        assignment[i] = marks[i];
    }
}
double ece220UofAStudent :: average() {
    int i;
    double sum = 0;
    for (i=0; i<ASSIGN_NO; i++) {
        sum += assignment[i];
    }
    return 0.4*final + 0.2*midterm + 0.4*sum/ASSIGN_NO;
}

void ece220UofAStudent :: printRecord(int value) {
    cout << "ece220:   " << value << endl;
    UofAStudent :: printRecord();
    cout << "This is midterm: " << midterm << "." << endl;
    cout << "This is final: " << final << "." << endl;
}

