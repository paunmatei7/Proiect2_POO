#include <cstring>

using namespace std;

class bere : public f1<int>{
protected:
    string brand;
    string bere_tip;
    static int nr;
public:
    bere() {
        SetCant(0);
        SetPret(0);
    }
    bere(string b, string t, int c, int p) {
        brand = b;
        bere_tip = t;
        SetCant(c);
        SetPret(c);
    }
    friend istream& operator >> (istream&, bere&);
    int verif(int& c) {
        if(GetCant() >= c) {
            if(c > nr && c + 1 >= GetCant()) {
                SetCant(GetCant() - c - 1);
            }
            else {
                SetCant(GetCant() - c);
            }
            return GetPret();
        }
        return -1;
    }
    int solve(string Brand, string bt, int c) {
        if(Brand == brand || Brand[0] == ' ') {
            if(bt == bere_tip || bt[0] == ' ') {
                int k = verif(c);
                if(k == -1) {
                    return -1;
                }
                return k * c;
            }
            return -1;
        }
        return -1;
    }
};

int bere:: nr = 3;


istream& operator>>(istream& in, bere& a) {
    int c, p;
    string br, tp;
    cout << "Introduceti brandul berii: ";
    in >> br;
    cout << "Introduceti tipul berii: ";
    in >> tp;
    cout << "Intorduceti cantitatea de bere: ";
    in >> c;
    cout << "Introduceti pretul unei beri: ";
    in >> p;
    bere caca(br, tp, c, p);
    a = caca;
    cout << "\n";
    return in;
}
