#include<iostream>

using namespace std;
template<typename T>

class stack
{

 private:
	 int size1;
	 struct listnode
	 {
		 T item;
		 listnode*next;
	 };
	 listnode*top1;
public:
	stack();
//	~stack();
	void empty()
	{
	while(size1)
		pop();
	}
	void push(T newitem);
	void pop();
	T top();
	int size(){return size1;}
	void display();

};

//template<class T> linkedlist <T>::ListNode* template <class T> linkedlist::traverseTo(int index)
template<class T> stack<T> ::stack()
{
	top1=NULL;
	size1=0;
}
/*template<class T> stack<T> ::~stack()
{
	while(size1)
		pop();
}*/
template<class T> void stack<T>::push(T newitem)
{
	listnode*newptr=new listnode;
	newptr->item=newitem;
	newptr->next=NULL;
	if(!size1)
	{
		top1=newptr;
	}
	else
	{
		newptr->next=top1;
		top1=newptr;
	}
	size1++;
	return;
}
template<class T> void stack<T>  ::pop()
{
	listnode*cur;
	if(!size1)
		return ;
	else
	{
		cur=top1;
		top1=top1->next;
	}
	--size1;
	delete cur;
	cur=NULL;
	
	return ;
}

template<class T> T stack<T>  :: top()
{
	return top1->item;
}
/*void stack::display()
{
	listnode*cur=top;
	for(int i=0;i<size;i++)
	{
		cout<<cur->item<<' ';
		cur=cur->next;
	}
}*/