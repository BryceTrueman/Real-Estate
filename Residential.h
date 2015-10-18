#pragma once
#include "Property.h"

using namespace std;

class Residential : public Property
{
private:
	bool R_occupancy;
	//double taxes_due;
	const double R_tax_rate_occupied = .006;
	const double R_tax_rate_vacant = .009;
public:
	Residential(string type_property, bool rental, double value, bool R_occupancy, string address);
	~Residential();
	double Taxes();
	bool GetOccupancy();
	virtual string toString();
	
	//virtual void Paint(string newColor);
};
