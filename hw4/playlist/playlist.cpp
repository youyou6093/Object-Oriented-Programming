#include "playlist.h"
#include <iomanip>
#include <cstring>

Playlist::Playlist(){
    MaxSize=5;
    CurrentSize=0;
    pSongList=new Song[MaxSize];
}

Playlist::~Playlist(){
    delete []pSongList;

}

void Playlist::Grow(){
    MaxSize=CurrentSize+5;
    Song* newList=new Song[MaxSize];
    for (int i=0;i<CurrentSize;i++)
        newList[i]=pSongList[i];
    delete []pSongList;
    pSongList=newList;
}


void Playlist::Shrink(){
    MaxSize=MaxSize-5;
    Song* newList=new Song[MaxSize];
    for(int i=0;i<CurrentSize;i++)
        newList[i]=pSongList[i];
    delete []pSongList;
    pSongList=newList;
}


void Playlist::Add(Song newsong){
    if (MaxSize==CurrentSize){
        Grow();
        cout<<"The playlist is resized to: "<<MaxSize<<" slots"<<endl;
    }
    pSongList[CurrentSize++]=newsong;
}


void Playlist::Search(const char* t) const{
    bool found=0;
    for(int i=0;i<CurrentSize;i++){
        if (strcmp(t,pSongList[i].GetTitle())==0 || strcmp(t,pSongList[i].GetArtist())==0){
            cout<<pSongList[i]<<endl;
            found=1;
        }
        
    }
    if (found==0)
        cout<<"found nothing"<<endl;
    //return
}

void Playlist::Show() const{
    cout<<setw(36);
    cout<<left<<"Title";
    cout<<setw(21);
    cout<<left<<"Artist";
    cout<<setw(15);
    cout<<left<<"Style";
    cout<<setw(8);
    cout<<right<<"Size(Mb)";
    cout<<endl;
    for(int i=0;i<CurrentSize;i++)
        cout<<pSongList[i]<<endl;
}

void Playlist::Show_size() const{
    cout<<CurrentSize<<' '<<MaxSize<<endl;
}

int  Playlist::Find(const char* t) const{
    //bool found=0;
    for(int i=0;i<CurrentSize;i++){
        if (strcmp(t,pSongList[i].GetTitle())==0)
            return i;
    }
    //cout<<"not found"<<endl;
    return -1;
        
}

void Playlist::Delete(const char *t){
    int a=Find(t);
    if (a==-1)
        cout<<t<<" not found"<<endl;
    else{
        for(int i=a+1;i<CurrentSize;i++)
            pSongList[i-1]=pSongList[i];
        CurrentSize--;
        if( CurrentSize==(MaxSize-5)){
            Shrink();
            cout<<"playist is resized to: "<<MaxSize<<" slots"<<endl;
        }
    }
}

void Playlist::ShowCategory(char t) const{
    double size=0.0;
    int num=0;
    Style cat;
    t=toupper(t);
    switch(t){
        case 'P': cat=POP;break;
        case 'R': cat=ROCK;break;
        case 'A': cat=ALTERNATIVE;break;
        case 'C': cat=COUNTRY;break;
        case 'H':cat=HIPHOP;break;
        case 'Y':cat=PARODY;break;
        default:break;
    }
    for(int i=0;i<CurrentSize;i++){
        if (pSongList[i].GetCategory()==cat){
            cout<<pSongList[i]<<endl;
            size+=pSongList[i].GetSize()/1000.0;
            num+=1;
        }
    }
    cout<<"total number in this category="<<num<<endl;
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"total size in this category="<<size<<"mb"<<endl;
    
}



int Playlist::TotalSize() const{
    int total=0;
    for(int i=0;i<CurrentSize;i++)
        total+=pSongList[i].GetSize();
    return total;
}

void Playlist::Swap(Song& a,Song &b){
    Song c;
    c=a;
    a=b;
    b=c;
}


void Playlist::Sort(char t){
    t=toupper(t);
    for(int i=0;i<CurrentSize-1;i++){
        for(int j=0;j<CurrentSize-1-i;j++){
            if(t=='A'){
                if (strcmp(pSongList[j].GetArtist(),pSongList[j+1].GetArtist())>0)
                    Swap(pSongList[j],pSongList[j+1]);
            }
            else if(t=='T'){
                if (strcmp(pSongList[j].GetTitle(),pSongList[j+1].GetTitle())>0)
                    Swap(pSongList[j],pSongList[j+1]);
            }
        }
    }
}
