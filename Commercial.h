#pragma once
#include "Property.h"

using namespace std;

class Commercial : public Property
{
private:
	bool C_tax_discounted;
	double C_discount_rate = 0;
	const double C_tax_rental = .012;
	const double C_tax_non = .01;
	//double taxes_due = 0;
public:
	Commercial(string type_property, bool rental, double value, bool C_tax_discounted, double C_discount_rate, string address);
		~Commercial();
		double Taxes();
		bool GetDiscounted();
		double GetDiscountRate();
		virtual string toString();
};
