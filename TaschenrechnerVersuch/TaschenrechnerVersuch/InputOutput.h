#pragma once
class InputOutput
{
public:
	void printError();
	void printErgebnis(float x);
	void printFileError();

	char askDR();
	char askAgain();
	char askAdd();
	char askMain();
	char askMethode();
	
	int askNumberMax(int begrenzung);
	int askNumber();
	int askTROperation();
	int askFROperation();
};