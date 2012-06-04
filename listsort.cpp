#ifndef LISTSORT_CPP
#define LISTSORT_CPP
#include<iostream>
#include<fstream>
#include"linklist.cpp"
#include"Product.h"
#include"d_array.cpp"
using namespace std;
//template <typename T>
class markt
{
	struct node
	{
		node * next;
		Product* item;
	};

	node* fhead;

	void bubsort()
	{	float  f1, f2;
		Product*  temp;
		for(node * curi = fhead->next; curi->next!=NULL; curi=curi->next)
			for(node * curj = curi->next; curj!=NULL; curj=curj->next)
			{	f1 = curi->item->_getprice();
				f2 = curj->item->_getprice();
				if(curi->item->retper()==1)
					f1=f1*(1-(curi->item->_returndiscount()/100));
				if(curj->item->retper()==1)
					f2=f2*(1-(curj->item->_returndiscount()/100));
				if(f1> f2)
				{
					temp = curi->item;
					curi->item=curj->item;
					curj->item = temp;
				}
			}
	int i = 0;
		for(node * curi = fhead->next; curi!=NULL; curi=curi->next)
		{
			curi->item->setpricerank(i++);
		}

			
		//	Product*  temp;
		for(node * curi = fhead->next; curi->next!=NULL; curi=curi->next)
			for(node * curj = curi->next; curj!=NULL; curj=curj->next)
			{
				if(curi->item->_getstock()> curj->item->_getstock())
				{
					temp = curi->item;
					curi->item=curj->item;
					curj->item = temp;
				}
			}

			i=0;
			for(node * curi = fhead->next; curi!=NULL; curi=curi->next)
		{
			curi->item->setstockrank(i);
			curi->item->setworth();
			i++;
		}
			
			for(node * curi = fhead->next; curi->next!=NULL; curi=curi->next)
				for(node * curj = curi->next; curj!=NULL; curj=curj->next)
			{
				if(curi->item->_getworth()> curj->item->_getworth())
				{
					temp = curi->item;
					curi->item=curj->item;
					curj->item = temp;
				}
			}



	}

	node* moveto(int pos)
	{	//cout<<"pos = "<<pos<<" size = "<<_size;
		if(pos<0 || pos>_size)
			return NULL;
		node* cur = fhead;
		//cout<<"here";
		for(int i=0;i<pos;++i)
		{
			cur=cur->next;
		}

		return cur;
	}
	int _size;


public:
	markt()
	{	//cout<<"fhead set to null";
		fhead = new node;
		fhead->next = NULL;
		_size = 0;
	}
	
	void bsort()
	{
		ofstream fout;
		bubsort();
		fout.open("output.txt");
		for(node *cur = fhead->next; cur!=NULL; cur=cur->next)
			fout<<cur->item->_getbarcode()<<endl;
		fout.close();
	}

	void copy(d_array<Product*> l1)
	{	fhead = new node;
		fhead->next = NULL;
		_size = 0;
		for(int i = 0; i< l1.retsize(); i++)
			insert(l1.retobj(i),i);
	}

	bool insert(Product* item, int pos)
	{	//cout<<"here";
		if(pos<0 || pos>_size)
			return false;
		//cout<<"here";
		node* temp = new node;
		node* cur;
		cur = moveto(pos);
		temp->item = item;
		temp->next = cur->next;
		cur->next = temp;
		_size++;
		return true;
	}

	bool remove(int pos)
	{
		if(pos<0 || pos> _size||(_size == 0))
			return false;
		node* cur = moveto(pos);
		node* temp = cur->next;
		//item =  (temp)->item;
		cur->next = temp->next;
		delete temp;
		temp = NULL;
		_size--;
		return true;
		
	}

	int retsize()
	{
		return _size;
	}

	Product* retobj(int pos)
	{
		node* temp = fhead->next;
		int i = 0;
		while(i<pos)
		{
			
			//cout<<endl<<temp->item;
			temp = temp->next;
			i++;
		}
		return temp -> item;
	}

};









/*template <typename Product>
class dclist {

	struct node {
		Product item;
		node * prev;
		node * next;
	};

	node * tail;

	int _size;
public:
	dclist()
	{
		_size = 0;
		tail = NULL;
	
	}
	int retsize()
	{
		return _size;
	}
	node * moveto(int pos)
	{
		if(pos<0 || pos>_size)
			return NULL;
		node * cur = tail;
		//cur = cur->next;
		for(int i=0;i<pos;i++)
			cur=cur->next;
		return cur;
	
	}
	bool insert(T item, int pos)
	{pos--;
		if(pos>_size||pos<0)
			return false;
		//pos --;
		node * temp = new node;
		temp->item = item;
		temp->prev = NULL;
		temp->next = NULL;
		if(_size == 0)
		{
			temp->next = temp;
			temp->prev = temp;
			tail = temp;
			tail->next = temp;
		}
		
		else
		{
			node * cur = moveto(pos);
			temp->next = cur->next;
			temp->prev = cur;
			cur->next = temp;
					
		}

		if(pos == _size - 1)
			tail = tail->next;
	
		
		_size++;
	return true;
	}

	bool remove(int pos)
	{	pos--;
		if(pos<0 || pos>_size)
			return false;
		//pos--;
		node * cur = moveto(pos);
		node * temp = cur->next;
		cur->next = cur->next->next;
		cur->next->prev = cur;
		_size--;
		return true;
	}

	T retobj(int pos)
	{	
		node * cur = tail;
		for(int i = 1; i < pos; i++)
		{
			cur = cur->next;
		}

		return cur->item;

	}

};
*/
#endif