#include <cstring>

using namespace std;

class vin_soi : public f1<int> {
protected:
    string soi_tip;
    int an;
    string tara;
public:
    vin_soi() {
        SetCant(0);
        SetPret(0);
        an = 0;
    }
    vin_soi(string s, int c, int p, int a, string t) {
        soi_tip = s;
        SetCant(c);
        SetPret(c);
        an = a;
        tara = t;
    }
    friend istream& operator >> (istream&, vin_soi&);
    int verif(int &c) {
        if(GetCant() >= c) {
            ///SetCant(GetCant() - c);
            return GetPret();
        }
        return -1; /// nu a fost gasita cantitatea ceruta
    }
    int solve(string s, int a, string t, int c) {
        if(s == soi_tip || s[0] == ' ') {
            if(a == an || a == 0) {
                if(t == tara || t[0] == ' '){
                    int k = verif(c);
                    if(k == -1) {
                        return -1;
                    }
                    return k * c;
                }
            }
        }
        return -1;
    }
};

istream& operator>>(istream& in, vin_soi& a) {
    int c, p;
    int An;
    string tp, tr;
    cout << "Introduceti tipul vinului: ";
    in >> tp;
    cout << "Introduceti anul in care s-a facut: ";
    in >> An;
    cout <<"\nIntroduceti tara in care s-a facut: ";
    in >> tr;
    cout << "Intorduceti cantitatea de vin: ";
    in >> c;
    cout << "Introduceti pretul unui litru vin: ";
    in >> p;
    vin_soi caca(tp, c, p, An, tr);
    a = caca;
    cout << "\n";
    return in;
}
