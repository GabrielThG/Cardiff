#pragma once
class InputOutput
{
public:
	void printError();
	void printErgebnis(float x);

	char askDR();
	char askAgain();
	char askAdd();
	char askMain();

	int askNumberMax(int begrenzung);
	int askNumber();
	int askTROperation();
	int askFROperation();

//	vector<int> makeVectorT();
//	vector<int> makeVectorF();
};