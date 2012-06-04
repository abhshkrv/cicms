#ifndef LINKLIST_CPP
#define LINKLIST_CPP
template <typename T>
class list
{
	struct node
	{
		node * next;
		T item;
	};

	node* fhead;

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
	list()
	{	//cout<<"fhead set to null";
		fhead = new node;
		fhead->next = NULL;
		_size = 0;
	}
	
	list(list& l1)
	{	fhead = new node;
		fhead->next = NULL;
		_size = 0;
		for(int i = 0; i< l1.retsize(); i++)
			insert(l1.retobj(i),i);
	}

	bool insert(T item, int pos)
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

	T retobj(int pos)
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

#endif








/*template <typename T>
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