#pragma once
#include <string>
#include <sstream>

using namespace std;

class Property
{
protected://use protected instead of private when using inheritance 
	string type_property;
	bool rental;
	double value;
	string address;
	double taxes_due = 0;
public:
	Property(string type_property, bool rental, double value, string address);
	~Property();
	virtual string GetPropertyType();
	virtual bool GetRental();
	virtual double GetValue();
	virtual string GetAddress();
	virtual string toString();
	virtual double Taxes() = 0;
	//virtual void Paint(string newColor) = 0;//the 0 at the end sets it as a pure virtual function

};
