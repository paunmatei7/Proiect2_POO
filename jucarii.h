#include <cstring>

using namespace std;

class jucarii : public f1<int> {
protected:
    string tip;
public:
    jucarii() {
        SetCant(0);
        SetPret(0);
    }
    jucarii (string a, int c, int p) {
        tip = a;
        SetCant(c);
        SetPret(p);
    }
    ~jucarii() {};
    friend istream& operator >> (istream&, jucarii&);
    int verif(int& c) {
        if(GetCant() >= c) {
            ///SetCant(GetCant() - c);
            return GetPret();
        }
        return -1;
    }
    int solve(string t, int c) {
        if(t == tip || t[0] == ' ') {
            int k = verif(c);
            if(k == -1) {
                return -1;
            }
            return k * c;
        }
        return -1;
    }
};

istream& operator>>(istream& in, jucarii& a) {
    int c, p;
    string tp;
    cout << "Introduceti tipul jucariei: ";
    in >> tp;
    cout << "Introduceti numarul de jucarii: ";
    in >> c;
    cout << "Introduceti pretul unei jucarii: ";
    in >> p;
    jucarii data(tp, c, p);
    a = data;
    cout << "\n";
    return in;
}
