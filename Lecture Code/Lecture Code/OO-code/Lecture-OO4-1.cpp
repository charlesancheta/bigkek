//============================================================================
// Name        : lecture-OO4-1.cpp
// Author      : mr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define ASSIGN_NO 5
#define NAME_MAXL 40
#define LAB_NO 2


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
    void assignA(double *marks);
    void printRecord();
    double average();
    void operator[] (double val);
};

class lab {
private:
    ece220UofAStudent *list[LAB_NO];
    int counter;
public:
    lab();
    lab operator+(ece220UofAStudent &stu);
    void display();
};

int main() {
    
    char fn[] = "John";
    char ffn[] = "Joe";
    char fffn[] = "Susan";
    double marks[] = {89.5, 88.0, 92.5, 95.0, 91.5};
    
    ece220UofAStudent test;
    ece220UofAStudent stu1(fffn, 987654321);
    stu1.assignMT(89.0);
    stu1.assignF(74.0);
    stu1.assignA(marks);
    stu1.printRecord();
    cout << "The average mark is: " << stu1.average() << "." << endl;
    ece220UofAStudent stu2(fn, 987654321);
    stu2.printRecord();
    
    ece220UofAStudent stu3(ffn, 987651234);
    stu3.operator [](56.5);
    stu3[44.5];
    stu3.printRecord();
    
    cout << "***LAB***" << endl;
    lab lab220;
    // operator notation
    lab220 = lab220 + stu1;
    lab220 = lab220 + stu2;
    // function notation
    lab220 = lab220.operator+(stu3);
    lab220.display();
    
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
char * UofAStudent :: retN() {
    return Name;
}
void UofAStudent :: assignID(int value) {
    studentID = value;
}
void UofAStudent :: printRecord() {
    cout << "*****" << endl;
    cout << "This is " << Name << "." << endl;
    cout << "ID is " << studentID << "." << endl;
}


ece220UofAStudent :: ece220UofAStudent () {
    midterm = 0.0;
    final = 0.0;
    assign_counter = 0;
}
ece220UofAStudent :: ece220UofAStudent (char *fn, int id) : UofAStudent(fn, id), midterm(0.0), final(0.0) {
    int i;
    for (i=0; i<ASSIGN_NO; i++) {
        assignment[i] = 0.0;
    }
    assign_counter = 0;
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
void ece220UofAStudent :: printRecord() {
    UofAStudent :: printRecord();
    cout << "midterm: " << midterm << "." << endl;
    cout << "final  : " << final << "." << endl;
    for(int i=0; i<assign_counter; i++) {
        cout << "assign["<<i<<"]: " << assignment[i] << endl;
    }
}

void ece220UofAStudent :: operator[] (double val) {
    assignment[assign_counter++] = val;
}


lab :: lab() {
    counter = 0;
}

lab lab :: operator+(ece220UofAStudent &stu){
    lab sum;
    sum.counter = counter;
    for(int i=0; i<counter; i++) {
        sum.list[i] = list[i];
    }
    if (counter < LAB_NO) {
        sum.list[sum.counter++] = &stu;
    }
    else {
        cout << "SORRY NO MO SPACE" << endl;
    }
    return sum;
}
void lab :: display() {
    cout << "*****" << endl;
    cout << "there are " << counter << " students:" << endl;
    for(int i=0; i<counter; i++) {
        list[i]->printRecord();
    }
}
