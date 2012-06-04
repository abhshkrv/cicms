/* ------------------------------------------------------------------------------------------------------------
CG1103 G-Lab 1.
Discussion Group:C07-3
(Names and matric numbers of all group members)
Abhishek Ravi A0074613
Dao The Phuc A0071848
Lim Xinyi A0070559Y
------------------------------------------------------------------------------------------------------------------ */
#ifndef PERISHABLE_H
#define PERISHABLE_H
#include "Product.h"
class date
{
	int _day;
	int _month;
	int _year;
public :
	//int _getday();
	//int _getmonth();
	//int _getyear();
	void _setdate();//reads the date
	//void _setmonth();
	//void _setyear();
};
class Perishable : public Product
{
	string _expiry;//stores expiry date
	float _discount;
public:
	float _returndiscount();
	string _returnexpiry();
	Perishable(string name,string category,string manufacturer,int stock,int barcode,float price,int permonthsales, string d1, float disc):Product( name, category, manufacturer, stock, barcode, price, permonthsales)

	{
		_name = name;
	 _category = category;
	 _manufacturer = manufacturer;
	 _stock = stock;
	 _barcode = barcode;
	 _price = price;
	 _permonthsales = permonthsales;
	_expiry = d1;
		_discount = disc;
	isperishable = 1;
	}
		Perishable()
	{}
	
//virtual	string _returnexpiry();
//virtual	float _returndiscount();
	void _setdate();
	void _setdiscount();
};
#endif

