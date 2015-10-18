#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Property.h"
#include "Residential.h"
#include "Commercial.h"
#include <fstream>
#include <sstream>

using namespace std;

bool loadFile(vector <Property*>& properties)
{
	string type_property;
	string address;
	double value = 0;
	bool rental;
	bool R_occupancy;
	bool C_tax_discounted = 0;//discounted = 1, not discounted = 0
	double C_discount_rate = 0;//will be entered like .20
	string in_file_name;
	string property_object;

	cout << "Please enter the file name that you want to upload: ";
	cin.sync();
	getline(cin, in_file_name);
	ifstream in;
	in.open(in_file_name);
	
	if (in.is_open())
	{
		while (getline(in, property_object))
		{
			
			stringstream ss;
			ss << property_object;
			ss >> type_property;
			if (type_property == "Residential")
			{
				if (ss >> rental >> value >> R_occupancy && getline(ss, address) && (R_occupancy == true || R_occupancy == false))
				{
					properties.push_back(new Residential(type_property, rental, value, R_occupancy, address));
				}
				else
				{
					cout << endl;
					cout << "Ignoring unknown types of properties appearing in the input file:  " << property_object << endl;
					cout << endl;
				}
			}
			else if (type_property == "Commercial")
			{
				if (ss >> rental >> value >> C_tax_discounted >> C_discount_rate && getline(ss, address))
				{
					properties.push_back(new Commercial(type_property, rental, value, C_tax_discounted, C_discount_rate, address));
				}
				else
				{
					cout << endl;
					cout << "Ignoring unknown types of properties appearing in the input file:  " << property_object << endl;
					cout << endl;
				}
			}
			else
			{
				cout << endl;
				cout << "Ignoring unknown types of properties appearing in the input file:  " << property_object << endl;
				cout << endl;
			}
		}
	}
	else
	{
		cout << endl;
		cout << "Bad file" << endl;
		return false;
	}
	
	in.close();
	return true;
}


int main()
{
	vector<Property*> properties;
	
	if (loadFile(properties))
	{
		cout << endl; cout << endl;
		cout << "All Valid Properties: " << endl;
		cout << endl;
		for (int i = 0; i < properties.size(); i++)
		{
			cout << "Property ID: " << i << " ";
			cout << properties[i]->toString();
			cout << endl;
		}
		cout << endl;
		cout << "NOW PRINTING TAX REPORT: " << endl;
		cout << endl;
		for (int i = 0; i < properties.size(); i++)
		{
			cout << "Taxes due for the property at:\t\t\t" << properties[i]->GetAddress() << endl;
			cout << "     Property ID: \t\t\t\t\t" << i << endl;
			cout << "     This property has an estimated value of: \t\t" << properties[i]->GetValue() << endl;
			cout << "     Taxes due on this property are: \t\t\t" << properties[i]->Taxes() << endl;
			cout << endl;
		}
	}
	system("pause");
	return 0;
}


