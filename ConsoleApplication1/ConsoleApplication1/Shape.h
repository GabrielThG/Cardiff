#pragma once
#include <iostream>
class Shape
{
public:
	virtual double getFlaeche() = 0;
	virtual double getUmfang() = 0;
	virtual void berechneFlaeche()=0;
	virtual void berechneUmfang()=0;
	virtual std::string getType()=0;
	//friend std::ostream& operator<< (std::ostream& out, Shape& point);
};

