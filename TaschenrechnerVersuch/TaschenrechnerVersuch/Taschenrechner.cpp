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
int addieren(std::vector<int> vec) {
    int zahlErg=1;
    cout << "Output of begin and end: ";
    for (auto i = vec.begin(); i != vec.end(); ++i)
        zahlErg += *i;
    return zahlErg;
}
int addition() {
    char auswahl;
    int zahlErg =0;
    InputOutput io;
    auswahl = io.askAdd();
    switch (auswahl) {
    case 'T':
    case 't':
        cout << "makeVectorFromTextForAdd";
//        zahlErg = addieren(makeVectorT());
        break;
    case 'F':
    case 'f':
        cout << "makeVectorFromFileForAdd";
//        zahlErg = addieren(makeVectorF());
        break;
    }
    return zahlErg;
}
int multiplizieren(std::vector<int> vec) {
    int zahlErg=1;
    for (auto i = vec.begin(); i != vec.end(); ++i)
        zahlErg *= *i;
    return zahlErg;
}
int multiplikation() {
    char auswahl;
    InputOutput io;
    int zahlErg=0;
    auswahl = io.askAdd();
    switch (auswahl) {
    case 'T':
    case 't':
        cout << "makeVectorFromTextForMulti";
//        zahlErg = multiplikation(makeVectorT());
    case 'F':
    case 'f':
        cout << "makeVectorFromFileForMulti";
//        zahlErg = multiplikation(makeVectorF());
    }
    return zahlErg;
}
float bigSwitch(int zahlOperator) {
    InputOutput io;
    float zahlErg = 0, fzahl1=0, fzahl2=0;
    int zahl1, zahl2, erg;
    switch (zahlOperator) {
    case 1:
        zahlErg = addition();
        break;
    case 2:
        zahl1 = io.askNumber();
        zahl2 = io.askNumber();
        zahlErg = zahl1 - zahl2;
        break;
    case 3:
        zahlErg = multiplikation();
        break;
    case 4:
        zahl1 = io.askNumber();
        zahl2 = io.askNumber();
        if (checkIfZero(zahl2))
            zahlErg = zahl1 / zahl2;
        else
            std::cout << "Ungueltige Eingabe!";
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
    char auswahl;
    float zahlErg = 0, fzahl1, fzahl2;
    int zahlOperator, zahl1, zahl2, erg;
    ladenrechner(1, "Taschenrechner startet ");
    err:
    zahlOperator= io.askTROperation();
    zahlErg = bigSwitch(zahlOperator);
    io.printErgebnis(zahlErg);
}



