
/*
3. Zaimplementuj szablon funkcji SongFactory tak aby obiekt ‘song’
był wskaźnikiem typu unique_ptr dla obiektów klasy Song.

auto song = SongFactory(L"Michael Jackson", L"Beat It");

oraz przedstaw działanie konstruktora i destruktora obiektu
przechowywanego przez wskaźnik we wnętrzu inteligentnego wskaźnika.
Wypełnij std::vector<std::unique_ptr<Song>> songs i pokaż, że zakresowa
pętla „for” musi wykorzystywać referencje.
*/

#include <iostream>
#include <memory>
#include <vector>

using namespace std;


struct Song {
    wstring artist;
    wstring title;
    Song(const wstring& artist_, const wstring& title_) : artist{artist_}, title{title_} {
        cout << "created object" << endl;
    }

    ~Song() {
        cout << "destroyed object" << endl;
    }
};

unique_ptr<Song> SongFactory(const std::wstring& artist, const std::wstring& title)
{
    return make_unique<Song>(artist, title);
}


void MakeSongs()
{
    auto song = SongFactory(L"Michael Jackson", L"Beat It");

}

void SongVector()
{
    vector<unique_ptr<Song>> songs;
    
    // Create a few new unique_ptr<Song> instances
    // and add them to vector using implicit move semantics.
    songs.push_back(make_unique<Song>(L"B'z", L"Juice")); 
    songs.push_back(make_unique<Song>(L"Namie Amuro", L"Funky Town")); 
    songs.push_back(make_unique<Song>(L"Kome Kome Club", L"Kimi ga Iru Dake de")); 
    songs.push_back(make_unique<Song>(L"Ayumi Hamasaki", L"Poker Face"));

    // Pass by const reference when possible to avoid copying.
    for (const auto& song : songs)
    {
        wcout << L"Artist: " << song->artist << L"   Title: " << song->title << endl; 
    }  
}



int main()
{
    MakeSongs();
    SongVector();

    return 0;
}