#include <iostream>
#include <cstring>

using namespace std;
/* 
  NOTE: This does not use dynamic memory allocation but instead uses initializer
  lists I don't really know if this is in the scope of your course
*/

class CD {
protected:
    //char label[LABEL_LEN];
    char *label;
    int no_tracks;
    double playtime;
public:
    CD(char *label_n, int no, double time) : label(label_n), no_tracks(no), playtime(time) {};
    // change the name so it will not be overriden 
    // by the subclasses' display() methods
    void displayL(); 
};

void CD::displayL() {
  cout << "Label: " << label << endl;
  cout << "No of tracks: " << no_tracks << endl;
  cout << "Time: " << playtime << endl;

}
class popRockCD : public CD {
private:
    //char title[NAME_LEN];
    char *title;
    //char artist[ARTIST_LEN];
    char * artist;
public:
    popRockCD(char * label_n, int no, double time, char * title_n, char * artist_n) 
              : CD(label_n, no , time), title(title_n), artist(artist_n) {};
    void display();
};

void popRockCD::display() {
  cout << "*****" << endl;
  cout << "Title: " << title << endl;
  cout << "Artist: " << artist << endl;
  displayL();
  cout << "*****" << endl;
} 

class classicCD : public CD {
private:
    //char title[NAME_LEN];
    char *title;
    //char composer[COMPOSER_LEN];
    char *composer;
    //char performer[PERFORMER_LEN];
    char *performer;
public:
    classicCD(char * label_n, int no, double time, char * title_n, char * composer_n, char * performer_n)
              : CD(label_n, no, time), title(title_n), composer(composer_n), performer(performer_n) {};
    void display();
};

void classicCD::display() {
  cout << "*****" << endl;
  cout << "Title: " << title << endl;
  cout << "Composer: " << composer << endl;
  cout << "Performer: " << performer << endl;
  displayL();
  cout << "*****" << endl;
}

int main() {
    char label_pR[] = "Columbia";
    char title_pR[] = "Western Stars";
    char artist_pR[] = "Bruce Springsteen";
    popRockCD CD1(label_pR, 14, 51.00, title_pR, artist_pR);

    char label_c[] = "DG";
    char title_c[] = "Symphonies";
    char composer_n[] = "Mozart";
    char performer_n[] = "Karl Bohm";
    classicCD CD2(label_c, 23, 146.00, title_c, composer_n, performer_n);

    CD1.display();
    CD2.display();

    return 0;
}


