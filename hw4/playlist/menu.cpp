#include "playlist.h"
#include <cstring>
#

void DisplayMenu(){
    cout<<"A: Add a song to the playlist"<<endl;
    cout<<"F: Find a song on the playlist"<<endl;
    cout<<"D: Delete a song from the playlist"<<endl;
    cout<<"S: Show the entire playlist"<<endl;
    cout<<"C: Category summary"<<endl;
    cout<<"Z: Show playlist size"<<endl;
    cout<<"M: Show this Menu"<<endl;
    cout<<"X: eXit the programming"<<endl;
    cout<<"O: Sort the Playlist"<<endl;
    
}

Style transform(char a){
    int flag=0;
    
    while (flag==0){
        a=toupper(a);
        switch(a){
            case 'P': return POP;
            case 'R': return ROCK;
            case 'A': return ALTERNATIVE;
            case 'C': return COUNTRY;
            case 'H': return HIPHOP;
            case 'Y': return PARODY;
            default:
                flag=0;
                cout<<"please re-enter:";
                a=cin.get();
                cin.ignore(256,'\n');
        }
    }
    return POP;
}


int main(){
    Playlist my_list;    // create a playlist
    Song newsong;
    char title[36],artist[21];
    Style cat;
    int size;
    char type,key; //create song info
    bool bad=false; //check
    DisplayMenu();
    cout<<"Type command:";
    char command;
    cin>>command;
    cin.ignore(256,'\n'); //very important
    command=toupper(command);
    while (command!='X'){
        switch (command) {
            case 'A':
                cout<<"Adding a new song"<<endl;
                cout<<"Title is:";
                cin.getline(title,36);
                cout<<"Artist is:";
                cin.getline(artist,21);
                cout<<"Type is:";
                type=cin.get();
                cin.ignore(256,'\n');
                cat=transform(type);
                cout<<"Size is:";
                do{
                    
                    cin>>size;
                    bad=cin.fail();
                    if(bad)
                        cout<<"Error!Re-enter:";
                    cin.clear();
                    cin.ignore(10,'\n');
                    if(size<0){
                        cout<<"Negative number is not allowed,please re-enter:";
                        bad=1;
                    }
                }while(bad);
                while(size<0){
                    
                    cin>>size;
                }
                
                newsong.Set(title,artist,cat,size);
                my_list.Add(newsong);
                break;
            case 'F':
                cout<<"Enter the title or artist you want to find:";
                cin.getline(title,36);
                my_list.Search(title);
                break;
            case 'D':
                cout<<"Enter the title you want to delete:";
                cin.getline(title,36);
                my_list.Delete(title);
                break;
            case 'S':
                cout<<"The playlist is:\n";
                my_list.Show();
                break;
            case 'C':
                cout<<"Which category you want to find:";
                type=cin.get();
                cin.ignore(256,'\n');
                my_list.ShowCategory(type);
                break;
            case 'Z':
                cout<<"Total size of the playlist is:"<<my_list.TotalSize()<<"kb"<<endl;
                break;
            case 'M':
                DisplayMenu();
                break;
            case 'O':
                cout<<"Enter the keyword you want to sort:";
                key=cin.get();
                my_list.Sort(key);
                cout<<"Play list after sort"<<endl;
                my_list.Show();
                break;
            default:
                cout<<"Wrong command"<<endl;
                break;
    
        }
        cout<<"Type command:";
        cin>>command;
        cin.ignore(256,'\n');
        command=toupper(command);
    }
    
}
