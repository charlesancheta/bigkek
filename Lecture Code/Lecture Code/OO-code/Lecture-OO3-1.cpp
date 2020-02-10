//============================================================================
// Name        : lecture-OO3-1.cpp
// Author      : mr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void swap_ref(int &a, int &b);
void swap_ptr(int *a, int *b);

int main() {
    int x = 5;
    int y = 7;
    
    cout << "before:           x = " << x << ", y = " << y << endl;
    cout << &x << endl;
    swap_ref(x, y);
    cout << "after swap_ref(): x = " << x << ", y = " << y << endl;
    swap_ptr(&x, &y);
    cout << "after swap_ptr(): x = " << x << ", y = " << y << endl;
    
    return 0;
}

void swap_ref(int &a, int &b) {
    int temp;
    temp = a;
    cout << &a << endl;
    a = b;
    b = temp;
}

void swap_ptr(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
