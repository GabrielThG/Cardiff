#include "Menu.h"
#include "Taschenrechner.h"
#include "Funktionsrechner.h"
#include <iostream>
#include "InputOutput.h"
#include "Filerechner.h"




Menu::Menu() {
    
    InputOutput io;
    Taschenrechner TR;
    Funktionsrechner FR;
    Filerechner file;
    
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
        case 'G':
        case 'g':
            file.fileBerechnen();
            break;
        }

        auswahl = io.askAgain();
    }
}
