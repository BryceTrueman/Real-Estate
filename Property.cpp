#include "Property.h"
#include <sstream>

Property::Property(string type_property, bool rental, double value, string address)
{
	this->type_property = type_property;//this specifies that it is from this class, not passed in
	this->rental = rental;
	this->value = value;
	this->address = address;
}

Property::~Property(){}

string Property::toString()
{
	stringstream ss;
	ss << "Address: " << address << " ";
	if (rental == true)
	{
		ss << "Rental ";
	}
	else
	{
		ss << "Not Rental ";
	}
	ss << "Value: " << value << " ";
	return ss.str();
}

string Property::GetPropertyType()
{
	return type_property;
}

bool Property::GetRental()
{
	return rental;
}

double Property::GetValue()
{
	return value;
}

string Property::GetAddress()
{
	return address;
}
