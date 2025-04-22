
/*
1. Ćwiczenie 3 do wykładu 7.
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;


struct Kolor {
    int red;
    int green;
    int blue;
    Kolor(int r = 0, int g = 0, int b = 0) : red(r), green(g), blue(b) {}
};


struct AlternatywnaPolityka {
    Kolor nieznanyKolor(string nazwa) {
        cout << "Kolor '" << nazwa << "' jest nieznany. Zwracam kolor domyślny.\n";
        return Kolor(0, 0, 255);
    }
};


template <int R, int G, int B>
struct SzablonowaPolityka {
    Kolor nieznanyKolor(string nazwa) {
        cout << "Kolor '" << nazwa << "' jest nieznany. Zwracam kolor domyślny.\n";
        return Kolor(R, G, B);
    }
};

template <typename Polityka>
class FabrykaKolorow {
private:
    Polityka polityka;
    map<string, Kolor> znaneKolory;
public:
    FabrykaKolorow() {
        znaneKolory["czerwony"] = Kolor(255, 0, 0);
        znaneKolory["zielony"] = Kolor(0, 255, 0);
        znaneKolory["niebieski"] = Kolor(0, 0, 255);
    }
    Kolor zwrocKolor(const string& nazwa) {
        if (znaneKolory.find(nazwa) != znaneKolory.end()) {
            return znaneKolory[nazwa];
        } else {
            return polityka.nieznanyKolor(nazwa);
        }
    }
};

int main() {
    FabrykaKolorow<SzablonowaPolityka<255, 0, 0>> fabryka1;
    FabrykaKolorow<AlternatywnaPolityka> fabryka2;

    try {
        cout << "Fabryka kolorow1:\n";
        cout << fabryka1.zwrocKolor("zielony").green << '\n';
    } catch(...) {
        cout << "Zlapano wyjatek.\n";
    }
    cout << endl;

    try {
        cout << "Fabryka kolorow1:\n";
        cout << fabryka1.zwrocKolor("lawendowy").red << '\n';
    } catch(...) {
        cout << "Zlapano wyjatek.\n";
    }
    cout << endl;

    try {
        cout << "Fabryka kolorow2:\n";
        cout << fabryka2.zwrocKolor("granatowy").blue << '\n';
    } catch(...) {
        cout << "Zlapano wyjatek.\n";
    }

    return 0;
}
