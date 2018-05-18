class faina : public f1<int> {
public:
    faina(int c, int p) : f1<int>(c, p) {}
    ~faina(){};
    friend istream& operator >> (istream&, faina&);
    void afisare() {
        f1<int>::afisare();
    }
    int verif(int& cant) {
        if(GetCant() < cant) {
            return -1;
        }
        SetCant(GetCant() - cant);
        return GetPret();
    }
};

istream& operator>>(istream& in, faina& a) {
    int c, p;
    cout << "Introduceti cantitatea de faina: ";
    in >> c;
    a.SetCant(c);
    cout << "Introduceti pretul unui kg de faina: ";
    in >> p;
    a.SetPret(p);
    cout << "\n";
    return in;
}
