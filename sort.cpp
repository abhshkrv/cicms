#include "sort.h"

void sort :: mergeSort(int low, int high, string datatype)
{
	if(low < high) 
	{
		int mid = (low + high) / 2;
		mergeSort(low, mid, datatype);
		mergeSort(mid+1, high, datatype);
		merge(low, mid, high, datatype);
	}
}

/*void sort :: merge(int low, int mid, int high, string datatype)
{
		int n = high - low + 1;
		//mergingarray is the extra array used for the merge sort.
		d_array<Product*> *mergingarray = new d_array<Product*>;   
		int left = low, right = mid + 1, bIdx = 0;
		
		while(left <= mid && right <= high) 
		{
			if(datatype == "stock")
			{
				if(_arrayptr.retobj(left)->_getstock() <= _arrayptr.retobj(right)->_getstock())
					mergingarray->insert(_arrayptr.retobj(left++), bIdx++ );
				else
					mergingarray->insert(_arrayptr.retobj(right++), bIdx++ );
			}

			else if(datatype == "price")
			{
				if(_arrayptr.retobj(left+1)->_getprice() <= _arrayptr.retobj(right+1)->_getprice())
					mergingarray->insert(_arrayptr.retobj(1+left++), 1 + bIdx++ );
				else
					mergingarray->insert(_arrayptr.retobj(1+right++), 1 + bIdx++ );			
			}

			else if(datatype == "worth")
			{
				if(_arrayptr.retobj(left+1)->_getworth() <= _arrayptr.retobj(right+1)->_getworth())
					mergingarray->insert(_arrayptr.retobj(1+left++), 1 + bIdx++ );
				else
					mergingarray->insert(_arrayptr.retobj(1+right++), 1 + bIdx++ );			
			}
		}

		while(left <= mid)
			mergingarray->insert(_arrayptr.retobj(1+left++), 1 + bIdx++ );

		while(right <= high)
			mergingarray->insert(_arrayptr.retobj(1+right++), 1 + bIdx++ );
			
		for(int k = 0; k < n; ++k)
			_arrayptr.insert(_arrayptr.retobj(k+1), low+k+1);

		delete mergingarray;
}*/

int sort :: retsize()
{
	return _arrayptr.retsize();
}

void sort :: printSortedList()
{
	int i;
	
	for(i=0; i < _arrayptr.retsize(); i++)
		cout << _arrayptr.retobj(i)->_getbarcode() << endl;
}