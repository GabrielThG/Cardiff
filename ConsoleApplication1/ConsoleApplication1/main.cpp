// ConsoleApplication1.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Rectangle.h"
#include "Cricle.h"
#include "Triangle.h"
#include "InputOutput.h"
#include "EquilateralTriangle.h"
#include "Isosceles.h"
#include "Square.h"
#include <list>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>
#include <map>
char ctos(std::string str) {
	return str[0];
}

typedef std::list<Shape*> ShapeList;

void bigSwitch(char objvar, std::vector<std::string> item, ShapeList& shapeList, int* count) {
	switch (toupper(objvar)) {
	case 'C':
		shapeList.push_back(new Cricle(stod(item[1])));
		break;
	case 'T':
		shapeList.push_back(new Triangle(stod(item[1]), stod(item[2]), stod(item[3])));
		break;
	case 'R':
		shapeList.push_back(new Rectangle(stod(item[1]), stod(item[2])));
		break;
	case 'E':
		shapeList.push_back(new EquilateralTriangle(stod(item[1])));
		break;
	case 'I':
		shapeList.push_back(new Isosceles(stod(item[1]), stod(item[2])));
		break;
	default:

		break;
	/*case 'S':
		shapeList.push_back(new Square(stod(item[1])));
		count[1] += 1;
		break;*/
	}
}

void zaehle(std::map<std::string, int> counts, Shape* item) {
	if (item->getType() == "Kreis") {
		counts["Kreis"] += 1;
	}
	else if (item->getType() == "Dreieck" || item->getType() == "gleichseitiges Dreieck" || item->getType() == "gleichschenkeliges Dreieck") {
		counts["Dreieck"] += 1;
	}
	else if (item->getType() == "Rechteck" || item->getType() == "Quadrat") {
		counts["Rechteck"] += 1;
	}
}
void zaehle(int* counts, Shape* item) {
	if (item->getType() == "Kreis") {
		counts[0] += 1;
	}
	else if (item->getType() == "Dreieck" || item->getType() == "gleichseitiges Dreieck" || item->getType() == "gleichschenkeliges Dreieck") {
		counts[1] += 1;
	}
	else if (item->getType() == "Rechteck" || item->getType() == "Quadrat") {
		counts[2] += 1;
	}
}
int main()
{
	int count[3] = { 0,0,0 }; 
	//std::map<std::string, int> counts{ {"Kreis", 0}, {"Rechteck", 0}, {"Dreieck", 0} };
	InputOutput io;
	ShapeList shapeList;
	std::list< std::vector< std::string >> veclist = io.makeVectorF();
	std::cout << "R->Rechteck, T->Dreieck, I->gleichschänkeliges Dreieck, E->gleichseitiges Dreieck, C->Kreis" << std::endl;
	for (auto item:veclist) {
		char objvar = ctos(item[0]);
		bigSwitch(objvar, item, shapeList,count);
	}
	for (Shape* item : shapeList) {
		item->berechneFlaeche();
		item->berechneUmfang();
		std::cout << "Es ist ein " << item->getType() << ".\n" << "Die Flaeche ist: " << item->getFlaeche() << "\nDer Umfang " << item->getUmfang() << std::endl; // actual output done here
		zaehle(count, item);
	}
	std::cout << "Es sind " << count[0] << " Kreise, " << count[2] << " Rechtecke und " << count[1] << " Dreiecke (insgesamt " << count[0] + count[1] + count[2] << ") in der Liste" << std::endl;
	
	//std::cout << "Es sind " << counts["Kreis"] << " Kreise, " << counts["Rechteck"] << " Rechtecke und " << counts["Dreieck"] << " Dreiecke (insgesamt " << counts["Dreieck"] + counts["Rechteck"] + counts["Kreis"] << ") in der Liste";
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
