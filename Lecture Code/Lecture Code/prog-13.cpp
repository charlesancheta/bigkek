//============================================================================
// Name        : lecture-OO6-1.cpp
// Author      : mr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define NAME_MAXL 40
#define ASSIGN_NO 2

class UofAStudent {
private:
    char Name[NAME_MAXL];
    int studentID;
public:
    UofAStudent ();
    UofAStudent (char *fn, int id);
    void assignN(char *fname);
    char *retN();
    void assignID(int value);
    void printRecord();
};

class ece220UofAStudent : public UofAStudent {
private:
    double midterm;
    double final;
    double assignment[ASSIGN_NO];
    int assign_counter;
public:
    ece220UofAStudent ();
    ece220UofAStudent (char *fn, int id);
    void assignMT(double value);
    void assignF(double value);
    void assignA(double *mark);
    void printRecord();
    double average();
    void operator[] (double val);
};


//============================================================================
int main(void) {

    char fn[] = "Susan";
    char ffn[] = "John";
    char *n;

    UofAStudent stu1(fn, 123456789);
    n = stu1.retN();

    ece220UofAStudent stu3(ffn, 987651234);
    stu3.operator [](56.5);
    stu3[44.5];
    stu3.printRecord();

    return 0;
}
//============================================================================



//============================================================================
// Methods of UofAStudent
//============================================================================
UofAStudent :: UofAStudent() {
    Name[0] = 'x';
    studentID = 0;
}
UofAStudent :: UofAStudent (char *my_name, int id) {
    strcpy(Name, my_name);
    studentID = id;
}
void UofAStudent :: assignID(int a) {
    studentID = a;
}
void UofAStudent :: assignN(char *string) {
    strcpy(Name, string);
}
void UofAStudent :: printRecord () {
    cout << "Name is: " << Name << "." << endl;
    cout << "ID is: " << studentID << "." << endl;
}
char* UofAStudent :: retN() {
    return Name;
}
//============================================================================



//============================================================================
// Methods of ece220UofAStudent
//============================================================================
ece220UofAStudent :: ece220UofAStudent () {
    midterm = 0.0;
    final = 0.0;
    assign_counter = 0;
}
ece220UofAStudent :: ece220UofAStudent (char *fn, int id)
        : UofAStudent(fn, id), midterm(0.0), final(0.0) {
    int i;
    for (i=0; i<ASSIGN_NO; i++) {
        assignment[i] = 0.0;
    }
    assign_counter = 0;
}
void ece220UofAStudent :: assignMT(double a) {
    midterm = a;
}
void ece220UofAStudent :: assignF(double a) {
    final = a;
}
void ece220UofAStudent :: assignA(double *a) {
    int i;
    for (i = 0; i<ASSIGN_NO; i++) {
        assignment[i] = a[i];
    }
    assign_counter = ASSIGN_NO;
}
double ece220UofAStudent :: average() {
    int i;
    double av;
    double as_av = 0;
    for (i = 0; i<assign_counter; i++) {
        as_av +=assignment[i];
    }
    as_av /= assign_counter;
    av = 0.4*final + 0.3*midterm + 0.3*as_av;
    return av;
}
void ece220UofAStudent :: printRecord() {
    int i;
    UofAStudent ::printRecord();
    cout << "Midterm mark is: " << midterm << "." << endl;
    cout << "Final mark is: " << final << "." << endl;
    for (i=0; i<assign_counter; i++) {
        cout << "Assignement[" << i << "] mark is: " << assignment[i] << "." << endl;
    }
};
void ece220UofAStudent :: operator[] (double val) {
    assignment[assign_counter++] = val;
}


