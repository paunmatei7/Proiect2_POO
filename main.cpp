//  POO - Proiect 2 - Tema 11

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include "element.h"
#include "varza.h"
#include "faina.h"
#include "bere.h"
#include "vin_varsat.h"
#include "vin_soi.h"
#include "cartofi.h"
#include "jucarii.h"

using namespace std;

int main() {
    varza Var(0,0);
    faina Cal1(0, 0), Cal2(0, 0), Cal3(0, 0);
    cartofi * Car;
    jucarii * Juc;
    bere * Br;
    vin_varsat * Vinv;
    vin_soi * Vins;
    int nrr = 0;
    cout << "Stocul magazinului: \n";
    cin >> Var;
    cout << "Faina de calitatea 1:\n";
    cin >> Cal1;
    cout << "Faina de calitatea 2:\n";
    cin >> Cal2;
    cout << "Faina de calitatea 3:\n";
    cin >> Cal3;
    Car = new cartofi [3];
    cin >> Car[1] >> Car[2];
    cout << "Numarul de jucarii: \n";
    cin >> nrr;
    Juc = new jucarii [nrr + 1];
    for(int i = 1; i <= nrr; ++i) {
        cin >> Juc[i];
    }
    Br = new bere [3];
    cin >> Br[1] >> Br[2];
    Vinv = new vin_varsat [2];
    cin >> Vinv[1] >> Vinv[2];
    cout << "Numarul de tipuri de vinuri de soi: \n";
    int nrvs;
    cin >> nrvs;
    Vins = new vin_soi[nrvs + 1];
    for(int i = 1; i <= nrvs; ++i) {
        cin >> Vins[i];
    }
    cout << "Numarul de clienti:\n";
    int n;
    cin >> n;
    int suma = 0;
    for(int i = 1; i <= n; ++i) {
        while(1) {
            int tip, can;
            cout << "Meniu:\n";
            cout << "1.Varza\n2.Faina\n3.Bere\n4.Jucarii\n5.Cartofi\n6.Vin Varsat\n7.Vin Soi\n8.Exit";
            cin >> tip;
            if(tip == 1) {
                cout << "Ce cantitate doriti?\n";
                cin >> can;
                int k = Var.verif(can);
                if(k == -1) {
                    cout << "Ne pare rau dar nu avem cantitatea ceruta";
                }
                else {
                    suma += k;
                }
                Var.afisare();
            }
            if(tip == 2) {
                int tp;
                cout << "Ce tip de faina doriti?\n";
                cin >> tp;
                cout << "Ce cantitate doriti?\n";
                cin >> can;
                if(tp == 1) {
                    int k = Cal1.verif(can);
                    if(k == -1) {
                        cout << "Ne pare rau dar nu avem cantitatea ceruta\n";
                    }
                    else {
                        suma += k;
                    }
                    Cal1.afisare();
                }
                else
                if(tp == 2) {
                    int k = Cal2.verif(can);
                    if(k == -1) {
                        cout << "Ne pare rau dar nu avem cantitatea ceruta\n";
                    }
                    else {
                        suma += k;
                    }
                    Cal2.afisare();
                }
                else
                if(tp == 3) {
                    int k = Cal3.verif(can);
                    if(k == -1) {
                        cout << "Ne pare rau dar nu avem cantitatea ceruta\n";
                    }
                    else {
                        suma += k;
                    }
                    Cal3.afisare();
                }
                else {
                    cout << "Nu avem aceasta calitate de faina\n";
                }
            }
            if(tip == 3) {
                string tp;
                cout << "Ce tip de bere doriti?\n";
                cin >> tp;
                cout << "Ce cantitate doriti?\n";
                cin >> can;
                if(tp[1] == 'l') {
                    int k = Br[1].verif(can);
                    if(k == -1) {
                        cout << "Ne pare rau dar nu avem cantitatea ceruta";
                    }
                    else {
                        if(can >= 3) {
                            cout << "Ai primit o bere gratis!";
                        }
                        suma += k;
                    }
                    Br[1].afisare();
                }
                if(tp[1] == 'r') {
                    int k = Br[2].verif(can);
                    if(k == -1) {
                        cout << "Ne pare rau dar nu avem cantitatea ceruta";
                    }
                    else {
                        suma += k;
                    }
                    Br[2].afisare();
                }
            }
            if(tip == 4) {
                string tp;
                cout << "Ce tip de jucarie doriti?\n";
                cin >> tp;
                cout << "Cate doriti?\n";
                cin >> can;
                int Max = 0;
                int ind = 0;
                for(int j = 1; j <= nrr; ++j) {
                    if(Juc[i].solve(tp, can) != -1) {
                        Max = max(Max, Juc[i].solve(tp, can));
                        if(Max == Juc[i].solve(tp, can)) {
                            ind = i;
                        }
                    }
                }
                if(Max == 0) {
                    cout << "Ne pare rau dar nu avem acest tip de jucarie sau numarul de jucarii dorit\n";
                }
                else {
                    suma += Max;
                    Juc[ind].SetCant(Juc[ind].GetCant() - Max / can);
                }
            }
            if(tip == 5) {
                string tp;
                cout << "Ce tip de cartofi doriti?\n";
                cin >> tp;
                cout << "Ce cantitate doriti?\n";
                cin >> can;
                if(tp[0] == 'r') {
                    int k = Car[1].verif(can);
                    if(k == -1) {
                        cout << "Ne pare rau dar nu avem cantitatea ceruta";
                    }
                    else {
                        suma += k;
                    }
                    Car[1].afisare();
                }
                if(tp[0] == 'a') {
                    int k = Car[2].verif(can);
                    if(k == -1) {
                        cout << "Ne pare rau dar nu avem cantitatea ceruta";
                    }
                    else {
                        suma += k;
                    }
                    Car[2].afisare();
                }
            }
            if(tip == 6) {
                string tp;
                cout << "Ce tip de vin varsat doriti?\n";
                cin >> tp;
                cout << "Ce cantitate doriti?\n";
                cin >> can;
                if(tp[0] == 'r') {
                    int k = Vinv[1].verif(can);
                    if(k == -1) {
                        cout << "Ne pare rau dar nu avem cantitatea ceruta";
                    }
                    else {
                        suma += k;
                    }
                    Vinv[1].afisare();
                }
                else
                if(tp[0] == 'a') {
                    int k = Vinv[2].verif(can);
                    if(k == -1) {
                        cout << "Ne pare rau dar nu avem cantitatea ceruta";
                    }
                    else {
                        suma += k;
                    }
                    Vinv[2].afisare();
                }
                else {
                    cout << "Ne pare rau dar nu avem acest tip de vin";
                }
            }
            if(tip == 7) {
                string tp;
                int An;
                string tara;
                cout << "Ce soi de bvin doriti?\n";
                cin >> tp;
                cout << "Ce cantitate doriti?\n";
                cin >> can;
                cout << "Din ce an doriti? (daca nu aveti vreo preferinta scrieti 0)";
                cin >> An;
                cout << "Din ce tara sa fie? (daca nu aveti vreo preferinta scrieti ' ' ";
                cin >> tara;
                int Max = 0;
                int ind = 0;
                for(int j = 1; j <= nrr; ++j) {
                    if(Vins[i].solve(tp, An, tara, can) != -1) {
                        Max = max(Max, Vins[i].solve(tp, An, tara, can));
                        if(Max == Vins[i].solve(tp, An, tara, can)) {
                            ind = i;
                        }
                    }
                }
                if(Max == 0) {
                    cout << "Ne pare rau dar nu avem acest tip de jucarie sau numarul de jucarii dorit\n";
                }
                else {
                    suma += Max;
                    Vins[ind].SetCant(Vins[ind].GetCant() - Max / can);
                }
            }
            if(tip == 8) {
                break;
            }
        }
        cout << suma;
    }
    return 0;
}
