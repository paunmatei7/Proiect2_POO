#include <cstring>

using namespace std;

class cartofi : public f1<int> {
protected:
    string tip;
public:
    cartofi() {
        SetCant(0);
        SetPret(0);
    }
    cartofi(string t, int c, int p) {
        SetCant(c);
        SetPret(p);
        tip = t;
    }
    cartofi(int c, int p) {
        SetCant(c);
        SetPret(p);
    }
    ~cartofi() {};
    friend istream& operator >> (istream&, cartofi&);
    int verif(int& c) {
        if(GetCant() >= c) {
            SetCant(GetCant() - c);
            return GetPret();
        }
        return -1;
    }
    int solve(string t, int c) {
        if(t == tip || t[0] == ' '){
            int k = verif(c);
            if(k == -1) {
                return -1;
            }
            return k * c;
        }
        return -1;
    }
};

istream& operator>>(istream& in, cartofi& a) {
    int c, p;
    cout << "Introduceti cantitatea de cartofi: ";
    in >> c;
    a.SetCant(c);
    cout << "Introduceti pretul unui kg de cartofi: ";
    in >> p;
    a.SetPret(p);
    return in;
}
