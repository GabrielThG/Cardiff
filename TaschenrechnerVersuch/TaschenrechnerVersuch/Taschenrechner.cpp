#include "Taschenrechner.h"
#include <iostream>
#include "Check.h"
#include <iomanip>
#include "Ladezeichen.h"
#include "InputOutput.h"
#include <vector>


bool checkIfZero(float x) {
    if (x < 0.000000001)
        return false;
    else
        return true;
}
int vecAdd(std::vector<int> vec) {
    int zahlErg=1;
    for (auto i = vec.begin()+1; i != vec.end(); ++i)
        zahlErg += *i;
    return zahlErg;
}
int vecSub(std::vector<int> vec) {
    int zahlErg = 1;
    for (auto i = vec.begin() + 1; i != vec.end(); ++i)
        zahlErg -= *i;
    return zahlErg;
}
int vecMul(std::vector<int> vec) {
    int zahlErg = 1;
    for (auto i = vec.begin() + 1; i != vec.end(); ++i)
        zahlErg *= *i;
    return zahlErg;
}
int vecDiv(std::vector<int> vec) {
    int zahlErg = 1;
    for (auto i = vec.begin() + 1; i != vec.end(); ++i)
        zahlErg /= *i;
    return zahlErg;
}
float bigSwitch(int zahlOperator) {
    InputOutput io;
    float zahlErg = 0, fzahl1=0, fzahl2=0;
    int zahl1, zahl2, erg;
    switch (zahlOperator) {
    case 1:
        zahl1 = io.askNumber();
        zahl2 = io.askNumber();
        zahlErg = zahl1 + zahl2;
        break;
    case 2:
        zahl1 = io.askNumber();
        zahl2 = io.askNumber();
        zahlErg = zahl1 - zahl2;
        break;
    case 3:
        zahl1 = io.askNumber();
        zahl2 = io.askNumber();
        zahlErg = zahl1 * zahl2;
        break;
    case 4:
        zahl1 = io.askNumber();
        zahl2 = io.askNumber();
        if (checkIfZero(zahl2))
            zahlErg = zahl1 / zahl2;
        else
            cout << "Ungueltige Eingabe!";
        break;
    case 5:
        zahl1 = io.askNumber();
        zahl2 = io.askNumber();
        zahlErg = zahl1 % zahl2;
        break;
    case 6:
        zahl1 = io.askNumber();
        zahl2 = io.askNumber();
        zahlErg = pow(zahl1, zahl2);
        break;
    case 7:
        zahl1 = io.askNumber();
        zahl2 = io.askNumber();
        zahlErg = pow(fzahl1, 1.0 / fzahl2);
        break;
    default:
        io.printError();
        break;
    }
    return zahlErg;
}
void Taschenrechner::TRBerechnen() {
    InputOutput io;
    float zahlErg = 0;
    int zahlOperator;
    ladenrechner(1, "Taschenrechner startet ");
    zahlOperator= io.askTROperation();
    zahlErg = bigSwitch(zahlOperator);
    io.printErgebnis(zahlErg);
}



