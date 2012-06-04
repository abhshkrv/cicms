/* ------------------------------------------------------------------------------------------------------------
CG1103 G-Lab 1.
Discussion Group:C07-3
(Names and matric numbers of all group members)
Abhishek Ravi A0074613
Dao The Phuc A0071848
Lim Xinyi A0070559Y
--------------------------------------------	---------------------------------------------------------------------- */
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;

class Product
{	
protected :
	string _name;
	string _category;
	string _manufacturer;
	int _stock;
	int _barcode;
	float _price;
	int _permonthsales;
	int isperishable;
	int _stockrank;
	int _pricerank;
	int _worthrank;
	int _worth;

public : 
	//function to return data members 
	Product(string name,string category,string manufacturer,int stock,int barcode,float price,int permonthsales)
	{
	 _name = name;
	 _category = category;
	 _manufacturer = manufacturer;
	 _stock = stock;
	 _barcode = barcode;
	 _price = price;
	 _permonthsales = permonthsales;
	isperishable;
	_stockrank;
	_pricerank;
	_worthrank;
	}

	Product()
	{	isperishable = 0;
	}

	string _getname();
	string _getcategory();
	string _getmanufacturer();
	int _getstock();
	int _getbarcode();
	float _getprice();
	int _getpermonthsales();
	//functions to read/modify data members
	int retper(){return isperishable;};
	virtual float _returndiscount(){return 0.0;};
	virtual string _returnexpiry(){return "null";};
	void _readname(string);
	void _readcategory(string);
	void _readmanufacturer(string);
	void _readstock(int);
	void printdetails();
	void _readbarcode(int);
	void _readprice(float);
	void _readpermonthsales(int);
	void setsales();
	void setstock(int);
	void setstockrank(int);
	void setpricerank(int);
	void setworthrank(int);
	int _getpricerank();
	int _getworthrank();
	int _getworth(){return _worth;}
	void setworth();
};

#endif