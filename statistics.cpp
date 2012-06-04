/* ------------------------------------------------------------------------------------------------------------
CG1103 G-Lab 1.
Discussion Group:C07-3
(Names and matric numbers of all group members)
Abhishek Ravi A0074613
Dao The Phuc A0071848
Lim Xinyi A0070559Y
------------------------------------------------------------------------------------------------------------------ */
#include "statistics.h"
#include "d_array.cpp"
#include"Product.h";
#include<iostream>
//#include"linklist.cpp"
using namespace std;

void statistics :: setmkt(d_array<Product*> A)
{
	_mkt = A;
}

void	statistics :: topsellingprod(int a)
{	if(a > _mkt.retsize())
	{	cout<<"Your store isn't that big. Calm down.";
		return;
	}	
	float value=0, prev=0;
	int count=0;
	sort();
	cout << "The top " << a << " selling products are :" << endl;
	for(int i = 0; i < a; i++)
	{	prev = value;
		value = _mkt.retobj(i)->_getprice()*_mkt.retobj(i)->_getpermonthsales();
		if(_mkt.retobj(i)->retper()==1)
			value = value - value*(_mkt.retobj(i)->_returndiscount()/100);
		if(prev!=value)	
		{	++count;
			
		}
		else a++;
		cout<<count<<". "<<_mkt.retobj(i)->_getname()<<"\t value : "<<value<<endl;
				
	}
}
struct	man	{
			string name;
			float revenue;
			};
int ispresent(string test, d_array<man> manlist)
{
	for(int i = 0; i < manlist.retsize(); i++)
		if(test==manlist.retobj(i).name)
			return i;
	return -1;

}
void sort2(d_array<man> &manlist)
{
	
	int k, j , m, n = manlist.retsize();
	man  temp;
	for (k=0; k<n-1; k++)
	{
		m=k;
		for (j=k; j<n; j++)
			if (manlist.retobj(j).revenue>((manlist.retobj(m).revenue)))
				m=j;
		if (m!= k)
		{
			temp = manlist.retobj(k);
			manlist.insert(manlist.retobj(m), k);
			manlist.remove(k+1);
			manlist.insert(temp,m);
			manlist.remove(m+1);
		}
	}
}

void statistics :: topsellingman(int a)
{
	
	int pos;
	d_array<man> manlist;
	man temp;
	for(int i = 0; i < _mkt.retsize(); i++)
	{
			pos = ispresent(_mkt.retobj(i)->_getmanufacturer(), manlist);
			if(pos == -1)
			{	temp.name = _mkt.retobj(i)->_getmanufacturer();
				temp.revenue = 0;
				manlist.insert(temp, manlist.retsize());

			}
	}
	
	for(int i = 0; i < _mkt.retsize(); i++)
	{
		pos = ispresent(_mkt.retobj(i)->_getmanufacturer(),manlist);
		temp.name = _mkt.retobj(i)->_getmanufacturer();
		temp.revenue = (_mkt.retobj(i)->_getprice()*_mkt.retobj(i)->_getpermonthsales()) + manlist.retobj(pos).revenue;
		manlist.remove(pos);
		manlist.insert(temp,pos);
		
	}
	sort2(manlist);
	for(int i = 0; i < manlist.retsize(); i++)
		cout<<manlist.retobj(i).name<<"\t"<<manlist.retobj(i).revenue<<endl;
	cout<<"Top Manufacturer : "<<_mkt.retobj(0)->_getmanufacturer();
	//cout << "The top selling product of manufacturer type " << a << " will be displayed" << endl;


}
void	statistics :: topsellingcat(string a)
{
	sort();
	for(int i = 0 ; i <_mkt.size(); i++)
	if(_mkt.retobj(i)->_getcategory()==a)
		cout<<_mkt.retobj(i)->_getname()<<" is the Top Product of type"<<" "<<a<<endl;
}
void statistics :: printman()
{
	
	cout << "Manufacturer :"<<endl;
	for(int i = 0; i < _mkt.retsize(); i++)
	{
		cout<<i<<"."<<" "<<_mkt.retobj(i)->_getmanufacturer()<<endl;
		
	}
	
}

void statistics :: search()
{
	string temp,junk;
	int tempbc;
	cout<<"Search by : "<<endl<<"1. Name\n2. Barcode\n3. Category\n4.Manufacturer";
	int choice;
	cin>>choice;
	getline(cin,junk);
	int flag=0;
	//Product t1;
	switch(choice)
	{
	case 1:
		cout<<"Enter the Name : ";
		getline(cin,temp);
		//getline(cin,junk);
		for(int i = 0; i < _mkt.retsize(); i++)
		{	
			if(temp == _mkt.retobj(i)->_getname())
			{	_mkt.retobj(i)->printdetails();
				flag = 1;
			}
		}
	
		if(flag==0)
			cout<<" Product not found";
		break;

		
	case 2:
		cout<<"Enter the Barcode : ";
		cin>>tempbc;
		getline(cin,junk);
		for(int i = 0; i < _mkt.retsize(); i++)
		{
			if(tempbc == _mkt.retobj(i)->_getbarcode())
			{	_mkt.retobj(i)->printdetails();	
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		cout<<" Invalid Code";
		break;	

	case 3:
		int flag;
		cout<<"Enter the Manufacturer : ";
		getline(cin,temp);
		for(int i = 0; i < _mkt.retsize(); i++)
		{
			if(temp == _mkt.retobj(i)->_getcategory())
			{	_mkt.retobj(i)->printdetails();		
				flag = 1;
			}
		}
		if(flag == 0)
			cout<<"Product not found";
		break;

	case 4:
		cout<<"Enter the Category : ";
		for(int i = 0; i < _mkt.retsize(); i++)
		{
			if(temp == _mkt.retobj(i)->_getmanufacturer())
			{	_mkt.retobj(i)->printdetails();		
				flag = 1;
			}
		}
		if(flag == 0)
			cout<<"Product not found";
		break;

	default :
		cout<<"Enter Choices 1-4 only";
	}
	

}

void statistics ::printcat()
{
	cout << "Categories :"<<endl;
	for(int i = 0; i < _mkt.retsize(); i++)
	{
		cout<<i<<"."<<" "<<_mkt.retobj(i)->_getcategory()<<endl;
		
	}
}

void statistics :: sort()
{
	
	int k, j , m, n = _mkt.retsize();
	int r1,r2;
	Product * temp;
	for (k=0; k<n; k++)
	{
		m=k;
		for (j=k; j<n; j++)
		{	r1 = (_mkt.retobj(j)->_getprice())*(_mkt.retobj(j)->_getpermonthsales());
			r2 = ((_mkt.retobj(m)->_getprice())*(_mkt.retobj(m)->_getpermonthsales()));
			if(_mkt.retobj(j)->retper()==1)
				r1=r1-r1*(_mkt.retobj(j)->_returndiscount()/100);
			if(_mkt.retobj(m)->retper()==1)
				r2=r2-(r2*(_mkt.retobj(m)->_returndiscount()/100));
			if (r1>r2)
				m=j;
			if (m!= k)
			{
				temp = _mkt.retobj(k);
				_mkt.insert(_mkt.retobj(m), k);
				_mkt.remove(k+1);
				_mkt.insert(temp,m);
				_mkt.remove(m+1);
			}
		}
	}
}