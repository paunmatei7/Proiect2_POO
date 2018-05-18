#include <iostream>
using namespace std;
template <class T>

class f1 {
private:
    T cant;
    int pret;
public:
    f1() {
        pret = 0;
        cant = 0;
    }
    T GetCant() const{
        return cant;
    }
    double GetPret() const {
        return pret;
    }
    void SetCant(T c) {
        this->cant = c;
    }
    void SetPret(int p) {
        this->pret = p;
    }
    f1 (T c, int p) {
        this->cant = c;
        this->pret = p;
    }
    virtual ~f1() {};
    virtual void afisare() {
        cout << "Cantitatea ramasa este : " << cant;
    }
    virtual int verif(T&) = 0;
};
