

#ifndef  _PLAYLIST_H
#define _PLAYLIST_H
#include "song.h"

class Playlist{

    public:
    Playlist();
    ~Playlist();
    void Add(Song a);
    void Search(const char * t) const;
    void Delete(const char *t);
    void Show() const;
    void ShowCategory(const char t) const;
    void Show_size() const;
    int TotalSize() const;
    void Sort(char t);
    

    private:
    int Find(const char* t) const;
    void Grow();
    void Shrink();
    
    unsigned int MaxSize;
    unsigned int CurrentSize;
    Song *pSongList;
    void Swap(Song &a,Song &b);
    
    
};

#endif
