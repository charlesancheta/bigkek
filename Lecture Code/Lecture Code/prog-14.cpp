//============================================================================
// Name        : lecture-OO6-2.cpp
// Author      : mr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define NAME_MAXL 40
#define ASSIGN_NO 5
#define LAB_MEM_NO 5

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

class lab {
private:
    ece220UofAStudent *list[LAB_MEM_NO];
    int counter;
public:
    lab();
    lab operator+(ece220UofAStudent &stu);
    void display();
};


//============================================================================
int main(void) {

    char fn[] = "John";
    char ffn[] = "Joe";
    char fffn[] = "Susan";
    double marks[] = {89.5, 88.0, 92.5, 95.0, 91.5};

    ece220UofAStudent stu1(fffn, 987654321);
    stu1.assignMT(89.0);
    stu1.assignF(74.0);
    stu1.assignA(marks);
    ece220UofAStudent stu2(fn, 987654321);
    ece220UofAStudent stu3(ffn, 987651234);
    stu3.printRecord();
    stu3.UofAStudent::printRecord();
    stu3.operator [](56.5);
    stu3[44.5];

    lab lab_group_01;
    lab_group_01 = lab_group_01 + stu1;
    lab_group_01 = lab_group_01 + stu2;
    lab_group_01 = lab_group_01 + stu3;
    lab_group_01.display();

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
//============================================================================



//============================================================================
// Methods of lab
//============================================================================
lab :: lab() {
    counter = 0;
}
lab lab :: operator+(ece220UofAStudent &stu){
    lab sum;
    sum.counter = counter;
    for(int i=0; i<counter; i++) {
        sum.list[i] = list[i];
    }
    if (counter < LAB_MEM_NO) {
        sum.list[sum.counter++] = &stu;
    }
    else {
        cout << "SORRY - NO MORE SPACE" << endl;
    }
    return sum;
}
void lab :: display() {
    cout << "there are " << counter << " students:" << endl;
    for(int i=0; i<counter; i++) {
        cout << "*****" << endl;
        list[i]->printRecord();
    }
}
//============================================================================
