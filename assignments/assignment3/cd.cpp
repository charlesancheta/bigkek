#include <iostream>
#include <cstring>

using namespace std;

char* stringAlloc(char* str) {
  char* string = new char[strlen(str) + 1];
  strcpy(string, str);
  return string;
}

class CD {
protected:
    //char label[LABEL_LEN];
    char *label;
    int no_tracks;
    double playtime;
public:
    CD(char *label_n, int no, double time) : no_tracks(no), playtime(time) {
      label = stringAlloc(label_n);
    };
    ~CD() {
      // use delete[] instead of delete when deleting
      //  arrays or else it will only free the pointer (first character)
      delete[](label); 
    };
    void display();
};

void CD::display() {
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
    popRockCD(char * label_n, int no, double time, 
              char * title_n, char * artist_n) : CD(label_n, no, time) {
      title = stringAlloc(title_n);
      artist = stringAlloc(artist_n);
    };
    ~popRockCD() {
      delete[](title);
      delete[](artist);
    };
    void display();
};

void popRockCD::display() {
  cout << "*****" << endl;
  cout << "Title: " << title << endl;
  cout << "Artist: " << artist << endl;
  CD::display(); // call the parent class method
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
    classicCD(char *label_n, int no, double time, char *title_n, 
              char *composer_n, char *performer_n) : CD(label_n, no, time) {
      title = stringAlloc(title_n);
      composer = stringAlloc(composer_n);
      performer = stringAlloc(performer_n);
    };
    ~classicCD() {
      delete[](title);
      delete[](composer);
      delete[](performer);
    };
    void display();
};

void classicCD::display() {
  cout << "*****" << endl;
  cout << "Title: " << title << endl;
  cout << "Composer: " << composer << endl;
  cout << "Performer: " << performer << endl;
  CD::display(); // call the parent class method
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


