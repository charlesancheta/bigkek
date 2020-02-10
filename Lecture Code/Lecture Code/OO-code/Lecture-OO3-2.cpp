//============================================================================
// Name        : lecture-OO3-2.cpp
// Author      : mr
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

struct free_throws {
    string name;
    int made;
    int attempts;
    float percent;
};

void set_pc (free_throws & ft );            // calculates percentage
void display(const free_throws & ft );      // displays values
free_throws & accumulate (free_throws & target, free_throws & source); // accumulate data

void my_fun( free_throws (&array)[2] );

int main(void) {
    
    free_throws one = {"John", 13, 14};
    free_throws two = {"Mike", 7, 9};
    free_throws team = {"all", 0, 0};
    free_throws dup;
    
    free_throws arr[2];
    
    set_pc (one);
    dup = accumulate (team, one);
    
    //two ways of doing this:
    //1
    display(accumulate (team, two));
    
    //2
    accumulate(team,two);
    display(team);
    
    my_fun(arr);
    return 0;
}

void my_fun( free_throws (&array)[2] )
{
    array[1].made=77;
}

void set_pc (free_throws & ft ) {
    if (ft.attempts != 0) {
        ft.percent = 100.0*(float)ft.made/(float)ft.attempts;
    }
    else {
        ft.percent = 0.0;
    }
}

void display(const free_throws & ft ) {
    cout << "Name: " << ft.name << endl;
    cout << "    Made: " << ft.made << endl;
    cout << "Attempts: " << ft.attempts << endl;
    cout << " Percent: " << ft.percent << endl;
    
}

free_throws & accumulate (free_throws & target, free_throws & source) {
    target.attempts += source.attempts;
    target.made += source.made;
    set_pc(target);
    return target;
}
