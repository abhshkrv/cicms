/* ------------------------------------------------------------------------------------------------------------
CG1103 G-Lab 1.
Discussion Group:C07-3
(Names and matric numbers of all group members)
Abhishek Ravi A0074613
Dao The Phuc A0071848
Lim Xinyi A0070559Y
------------------------------------------------------------------------------------------------------------------ */
#include"actions.h"

void actions :: add(Product a)
{	
	//cout<<"Product will be added here"<<endl;
	Product * temp = new Product(a);
	cout<< "Product to be added : " << temp->_getname() <<endl;
	if(_market.insert(temp,_market.retsize()))
		cout<<"Added successfully";
	
}
int actions :: idelete(long int a)
{	//cout<<"Current stuff : ";
//for(int i = 0; i < _market.retsize(); i++)
	//cout<<_market.retobj(i)->_getname()<<" ";
	int flag = ispresent(a); 
	if(flag!= -1)
	{	_market.remove(flag);
		cout<<"The item with the barcode "<<a<<" has been deleted"<<endl;
		return 1;
	}
	else
		//cout<<"Product not found";
		return 0;
}

int actions :: ispresent(long int a)
{
int i = 0;
	for(i; i < _market.retsize(); i++)
	{
			if(_market.retobj(i)->_getbarcode()== a)
			return i;
	}
return -1;
}
int actions :: reset( long int code,int sales)
{
	int flag = ispresent(code); 
	if(flag!= -1)
	{	Product * temp = _market.retobj(flag);
		temp->setsales();
		_market.remove(flag);
		_market.insert(temp,flag);
		//cout<<"The item with the barcode "<<a<<" has been deleted"<<endl;
		return 1;
	}
	else
		//cout<<"Product not found";
		return 0;
}

void actions :: calltopsellingprod(int x)
{	
	
	stat.topsellingprod(x);

}

int actions ::sale(long int code)
{
	int flag = ispresent(code); 
	if(flag!= -1)
	{	Product * temp = _market.retobj(flag);
		temp->_readpermonthsales(temp->_getpermonthsales()+1);
		temp->_readstock(temp->_getstock()+1);
		_market.remove(flag);
		_market.insert(temp,flag);
		//cout<<"The item with the barcode "<<a<<" has been deleted"<<endl;
		return 1;
	}
	else
		cout<<"Product not found";
		return 0;
}

int actions :: restock( long int code, int  stock)
{
	int flag = ispresent(code); 
	if(flag!= -1)
	{	Product * temp = _market.retobj(flag);
	temp->setstock(stock+_market.retobj(flag)->_getstock());
		_market.remove(flag);
		_market.insert(temp,flag);
		//cout<<"The item with the barcode "<<a<<" has been deleted"<<endl;
		return 1;
	}
	else
		cout<<"Product not found";
		return 0;
}

void actions :: removestock( long int code)
{
	int flag = ispresent(code); 
	if(flag!= -1)
	{	Product * temp = _market.retobj(flag);
	temp->setstock(0);
		_market.remove(flag);
		_market.insert(temp,flag);
		//cout<<"The item with the barcode "<<a<<" has been deleted"<<endl;
		//return 1;
	}
	else
		cout<<"Product not found";
		//return 0;
}
