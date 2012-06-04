#ifndef DCLL_CPP
#define DCLL_CPP
#include<iostream>
using namespace std;
template <typename T>
class dclist {

	struct node {
		T item;
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

		else if(pos <= _size/2)
		{
			node * cur = tail;
			for(int i=1; i<pos; i++)
				cur=cur->next;
		}

		else
		{ 
			node *cur = tail;
			for(int j = 1; j<_size-pos+2; j++)
				cur = cur->prev;
		}
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


#endif