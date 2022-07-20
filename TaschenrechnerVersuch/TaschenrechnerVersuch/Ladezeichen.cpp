
#include "Ladezeichen.h"
#include <iostream>
#include <windows.h>
using namespace std;

void ladenrechner(int time, string string) {

	for (int i = 0; i < time; i++)
	{
		cout << string+"-";
		Sleep(150);
		system("CLS");
		cout << string+"\\";
		Sleep(150);
		system("CLS");
		cout << string+"|";
		Sleep(150);
		system("CLS");
		cout << string+"/";
		Sleep(150);
		system("CLS");
	}
}
