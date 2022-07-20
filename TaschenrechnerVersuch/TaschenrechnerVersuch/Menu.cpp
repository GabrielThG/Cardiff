#include "Menu.h"
#include "Taschenrechner.h"
#include "Funktionsrechner.h"
#include <iostream>
#include "InputOutput.h"




Menu::Menu() {
    
    InputOutput io;
    Taschenrechner TR;
    Funktionsrechner FR;
    
    char auswahl = io.askMain();
        while (auswahl!='n') {
        switch (auswahl) {
        case 'T':
        case 't':
            TR.TRBerechnen();
            break;
        case 'F':
        case 'f':
            FR.FRBerechnen();
            break;
        }
        auswahl = io.askAgain();
    }
}
