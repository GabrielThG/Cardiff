#include "Menu.h"
#include "Taschenrechner.h"
#include "Funktionsrechner.h"
#include <iostream>
#include "InputOutput.h"
#include "Filerechner.h"
#include "GleichseitigesVieleck.h"




Menu::Menu() {

    InputOutput io;
    Taschenrechner TR;
    Funktionsrechner FR;
    Filerechner file;
    GleichseitigesVieleck vieleck;

    char auswahl = io.askMain();
    while (auswahl != 'n') {
        switch (auswahl) {
        default:
            break;
        case 'T':
            TR.TRBerechnen();
            break;
        case 'F':
            FR.FRBerechnen();
            break;
        case 'M':
            file.makeVectorF();
            break;
        case 'K':
            vieleck.gsVieleck();
            break;
        }    
        auswahl = io.askAgain();
    }
    
}

