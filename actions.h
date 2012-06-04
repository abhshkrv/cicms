//#include "GUI_input.h"
#ifndef actions_h
#define actions_h
#include<string.h>
/* ------------------------------------------------------------------------------------------------------------
CG1103 G-Lab 1.
Discussion Group:C07-3
(Names and matric numbers of all group members)
Abhishek Ravi A0074613
Dao The Phuc A0071848
Lim Xinyi A0070559Y
------------------------------------------------------------------------------------------------------------------ */
#include<iostream>
#include "Product.h"
#include"linklist.cpp"
#include "storage.h"
#include"statistics.h"
//#include<vector>
#include"d_array.cpp"
#include"listsort.cpp"
using namespace std;


class actions
{
	d_array<Product*> _market;//we can define our own data type instead of vector later
	storage s1;
	markt marksort;
	statistics stat;
public:
//these functions are called by an object in the UI, and modify the data in the _market. 
//at the end of program execution,the data will be written to file
	void add(Product);
	int idelete(long int);
	int reset(long int,int);
	int ispresent(long int);
	int restock(long int, int);
	void calltopsellingprod(int);
	void removestock(long int);
	int sale(long int);
	actions(){_market = s1.readfromfile();}
	actions(d_array<Product*> _m1 )
	{
		_market = _m1;
	}
	int exp()
	{	string cur;
		long int code;
		cout<<"Enter the current date : ";
		cin>>cur;
		cout<<"Enter the barcode :";
		cin>>code;
		int pos = ispresent(code);
		if(ispresent(code)!=-1)
			return(checkexpiry(cur, _market.retobj(pos)->_returnexpiry()));
		else return -1;
	}
	int checkexpiry(string cur, string prd)
	{	
		char a[8] = {cur[4], cur[5], cur[6], cur[7], cur[2], cur[3], cur[0], cur[1] };
		char b[8] = {prd[4], prd[5], prd[6], prd[7], prd[2], prd[3], prd[0], prd[1] };
		if(strcmp(a,b)>0)
			return 0;
		else return 1;
	}

	Product* retProduct(int code)
	{
		int pos = ispresent(code);
		Product * temp;
		temp = _market.retobj(pos);
		return temp;
	}

	string retdate(int code)
	{
		//if(
	}
	d_array<Product*> retmkt()
	{
		return _market;
	}

	void sort()
	{
	marksort.copy(_market);
	marksort.bsort();
	
	}

	~actions()
	{
		s1.writetofile(_market);
		cout<<"BYE!!!\n";
	}
};
#endif