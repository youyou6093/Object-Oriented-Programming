#include "song.h"
#include <iomanip>
#include <cstring>
using namespace std;

ostream& operator<<(ostream& os, const Song& s){
    //formated output
    double ss=s.size/1000.0;
    os<<setw(36);
    os<<left<<s.title;
    os<<setw(21);
    os<<left<<s.artist;
    os<<setw(15);
    switch (s.category) {
        case 0:
            os<<left<<"Pop";break;
        case 1:
            os<<left<<"Rock";break;
        case 2:
            os<<left<<"Alt";break;
        case 3:
            os<<left<<"Ctry";break;
        case 4:
            os<<left<<"HH";break;
        case 5:
            os<<left<<"Par";break;
        default:
            break;
    }
    //os<<left<<s.category;
    os<<setw(8);
    os<<fixed<<showpoint<<setprecision(1);
    os<<right<<ss;
    return os;
}

Song::Song(){
    //call song
    size=0;
}

void Song:: Set(const char* t,const char *a,Style st,int sz){//need to check!
    //check size,st,t,s
    if(sz>0)    size=sz;
    else    size=0;
    strcpy(title,t);
    strcpy(artist,a);
    category=st;
    
}

const char * Song::GetTitle() const{
    return title;
}

const char * Song::GetArtist() const{
    return artist;
}

int Song::GetSize() const{
    return size;
}

Style Song::GetCategory() const{
    return category;
    
}






