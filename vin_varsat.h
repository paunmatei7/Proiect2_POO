#include <cstring>

using namespace std;

class vin_varsat : public f1<int>{
protected:
    string varsat_tip;
public:
    vin_varsat() {
        SetCant(0);
        SetPret(0);
    }
    vin_varsat(string t, int c, int p) {
        varsat_tip = t;
        SetCant(c);
        SetPret(p);
    }
    friend istream& operator >> (istream&, vin_varsat&);
    int verif(int& c) {
        if(GetCant() >= c) {
            SetCant(GetCant() - c);
            return 1;
        }
        return -1; /// nu a fost gasita cantitatea necesara
    }
    int solve(string v, int c) {
        if(varsat_tip == v || v[0] == ' ') {
            int k = verif(c);
            if(k == -1) {
                return -1;
            }
            return k * c;
        }
        return -1;
    }
};

istream& operator>>(istream& in, vin_varsat& a) {
    int c, p;
    string tp;
    cout << "Introduceti tipul vinului: ";
    in >> tp;
    cout << "Intorduceti cantitatea de vin: ";
    in >> c;
    cout << "Introduceti pretul unui litru vin: ";
    in >> p;
    vin_varsat caca(tp, c, p);
    a = caca;
    return in;
}
