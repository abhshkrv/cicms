/* ------------------------------------------------------------------------------------------------------------
CG1103 G-Lab 1.
Discussion Group:C07-3
(Names and matric numbers of all group members)
Abhishek Ravi A0074613
Dao The Phuc A0071848
Lim Xinyi A0070559Y
------------------------------------------------------------------------------------------------------------------ */
#include "Product.h"
#include <string>
#include<iostream>
using namespace std;

string Product :: _getname()
{
return _name;
}
string Product:: _getcategory()
{
return _category;
}
	string Product :: _getmanufacturer()
	{
		return _manufacturer;
	}
int Product ::_getstock()
{
	return _stock;
}
int Product :: _getbarcode()
{
	return _barcode;
}
	
float Product :: _getprice()
{
	return _price;
}
	
int Product :: _getpermonthsales()
{
	return _permonthsales;
}
	//functions to read/modify data members
void Product :: _readname(string name)
{
	_name = name;
}

void Product :: _readcategory(string cat)
{
	_category = cat;
}
	
void Product:: _readmanufacturer(string manf)
{
	_manufacturer = manf;
}
	void Product :: _readstock(int stock)
	{
		_stock = stock;
	}
	void Product :: _readbarcode(int bc)
	{
	_barcode = bc;
	}

	void Product :: _readprice(float price)
	{
		_price = price;
	}
	
	void Product :: _readpermonthsales(int sales)
	{
		_permonthsales = sales;
	}

	void Product ::setsales()
	{
		_permonthsales = 0;
	}

	void Product :: setstock(int s)
	{
		_stock = s;
	}

	

	void Product :: printdetails()

	{
		

		cout << "Name of the product: "<<_name<<endl;
		cout << "Category the product belongs to: "<<_category<<endl;
		cout << "Manufacturer of the product: "<<_manufacturer<<endl;
		cout << "Stock of the product: "<< _stock<<endl;
		cout << "Barcode of the product: "<<_barcode<<endl;
		cout << "Price of the product: "<<_price<<endl;
		cout << "Sale permonth of the product: "<<_permonthsales<<endl;
		if(isperishable ==1)
			cout<<"Expiry date :"<<_returnexpiry()<<endl;
	}

	void Product :: setstockrank(int stockrank)
	{
		_stockrank = stockrank;
	}

	void Product :: setpricerank(int pricerank)
	{
		_pricerank = pricerank;
	}

	void Product :: setworth()
	{
		_worth = _pricerank + _stockrank; 
	}

	void Product :: setworthrank(int worthrank)
	{
		_worthrank = worthrank;
	}

	int Product :: _getworthrank()
	{
		return _worthrank;
	}

	int Product :: _getpricerank()
	{
		return _pricerank;
	}