/* ------------------------------------------------------------------------------------------------------------
CG1103 G-Lab 1.
Discussion Group:C07-3
(Names and matric numbers of all group members)
Abhishek Ravi A0074613
Dao The Phuc A0071848
Lim Xinyi A0070559Y
------------------------------------------------------------------------------------------------------------------ */
#ifndef statistics_h
#define statistics_h
#include<vector>
#include"Product.h"
//#include"GUI_input.h"
#include<string>
#include"linklist.cpp"
#include"d_array.cpp"
using namespace std;

class statistics
{	
	d_array <Product*> _mkt;//we can use our own data type later

public:
	void setmkt(d_array<Product*>);
	void	topsellingprod(int);//prints the top selling product
	void	topsellingman(int);//prints the top selling manufacturer
	void	topsellingcat(string);//prints the top selling category
	void printman();//Prints list of manufacturers
	void printcat();//Prints list of  categories
	void search();
	void sort();
	statistics()
	{}

};
#endif