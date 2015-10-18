#include "Commercial.h"

using namespace std;

Commercial::Commercial(string type_property, bool rental, double value, bool C_tax_discounted, double C_discount_rate, string address) : Property(type_property, rental, value, address)
{
	this->C_tax_discounted = C_tax_discounted;
	this->C_discount_rate = C_discount_rate;
}

Commercial::~Commercial(){}

double Commercial::Taxes()
{
	if (rental == true)
	{
		taxes_due = C_tax_rental * (value * (1 - C_discount_rate));
	}
	else
	{
		taxes_due = C_tax_non * (value * (1 - C_discount_rate));
	}
	return taxes_due;
}

bool Commercial::GetDiscounted()
{
	return C_tax_discounted;
}

double Commercial::GetDiscountRate()
{
	return C_discount_rate;
}

string Commercial::toString()
{
	stringstream ss;
	ss << Property::toString();
	if (C_tax_discounted == true)
	{
		ss << "Discounted ";
		ss << "The Discount rate is: " << C_discount_rate;
	}
	else if (C_tax_discounted == false)
	{
		ss << "Not Discounted";
	}
	return ss.str();
}
