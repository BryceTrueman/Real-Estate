#include "Residential.h"

Residential::Residential(string type_property, bool rental, double value, bool R_occupancy, string address) : Property(type_property, rental, value, address)
{
	this->R_occupancy = R_occupancy;
}

Residential::~Residential(){}


double Residential::Taxes ()
{
	if (R_occupancy == true)
	{
		taxes_due = R_tax_rate_occupied * value;
	}
	else
	{
		taxes_due = R_tax_rate_vacant * value;
	}
	return taxes_due;
}


bool Residential::GetOccupancy()
{
	return R_occupancy;
}

string Residential::toString()
{
	stringstream ss;
	ss << Property::toString();
	if (R_occupancy == true)
	{
		ss << "Occupied";
	}
	else
	{
		ss << "Vacant";
	}
	return ss.str();
}
