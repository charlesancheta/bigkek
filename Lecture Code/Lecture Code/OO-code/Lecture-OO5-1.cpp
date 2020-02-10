//============================================================================
// Name        : lecture-OO5-1.cpp
// Author      : mr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class UofAStudent {
protected:
    char Name[10];
    int studentID;
public:
    UofAStudent(void);
    UofAStudent (char *my_name, int id);
    UofAStudent (int id) ;
    UofAStudent (char *my_name);
    void setStudentID(int a);
    void setName(char *string);
    void printName ();
    int lengthName();
    ~UofAStudent () { cout << "bye" << endl;};
};

class ece220student : public UofAStudent {
private:
    double midterm;
    double final;
public:
    ece220student() { midterm = 0; final = 0;};
    ece220student(int id);
    ece220student(char *n, int id) : UofAStudent(n, id){
        midterm = 0.0;
        final = 0.0;
    };
    void printName();
};


int main(void) {
    
    char student_name1[] = "John";
    char student_name2[] = "Betty";
    
    UofAStudent stu;

    UofAStudent stu1(student_name1, 1234567);
    
    ece220student stu2(student_name2, 8888);
    
    ece220student stu3;
    
    
    stu1.printName();
    
    stu2.printName();
    
    stu2.UofAStudent::printName();
    
    return 0;
}



ece220student :: ece220student(int id) : UofAStudent(id) {
    midterm = 0.0;
    final = 0.0;
};

void ece220student :: printName() {
    cout << studentID << endl;
    UofAStudent ::printName();
    cout << "... funny ..." << endl;
};

UofAStudent :: UofAStudent() {
    Name[0] = 'x';
    studentID = 10;
}
UofAStudent :: UofAStudent (char *my_name, int id) {
    strcpy(Name, my_name);
    studentID = id;
}

UofAStudent :: UofAStudent (int id) {
    studentID = id;
}
UofAStudent :: UofAStudent (char *my_name) {
    strcpy(Name, my_name);
}

void UofAStudent :: setStudentID(int a) {
    studentID = a;
}
void UofAStudent :: setName(char *string) {
    strcpy(Name, string);
}
void UofAStudent :: printName () {
    cout << "this is " << Name << "." << endl;
}
int UofAStudent :: lengthName() {
    return (int)strlen(Name);
}
