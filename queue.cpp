#include<iostream>
using namespace std;
template<typename T>
class queue
{

 private:
	 int size1;
	 struct listnode
	 {
		 T item;
		 listnode*next;
	 };
	 listnode* top1, *rear1;
public:
	queue();
	//~queue();
	void empty()
	{
	while(!size1)
		pop();
	}
	void push(T newitem);
	void pop();
	T front();
	int size(){return size1;}
	void display();

};

//template<class T> linkedlist <T>::ListNode* template <class T> linkedlist::traverseTo(int index)
template<class T> queue<T> ::queue()
{
	top1=NULL;
	size1=0;
}
/*template<class T> queue<T> ::~queue()
{
	while(size1)
		pop();
}*/
template<class T> void queue<T>::push(T newitem)
{
	listnode*newptr=new listnode;
	newptr->item=newitem;
	newptr->next=NULL;
	if(!size1)
	{
		top1=newptr;
		rear1=newptr;
	}
	else
	{
		rear1->next = newptr;
		rear1 = newptr;
	}
	size1++;
	return;
}
template<class T> void queue<T>  ::pop()
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

template<class T> T queue<T>  :: front()
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