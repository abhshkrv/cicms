#ifndef D_ARRAY_CPP
#define D_ARRAY_CPP
template<typename T>
class d_array
{
	private:
		T *iA; 
		int numsize, capacity;

	public:

		d_array()
		{
			numsize = 0;
			capacity = 100000;
			iA = new T[capacity];
		}

		int insert(T newInt, int index)
		{
			//only two cases are possible here.
			//case 1: numsize has reached the full capacity.
			if(numsize >= capacity)
			{
				T *temp;
				temp = new T[capacity*2];

				//copy all of the integers from the old array to the new array
				for(int i=0; i<capacity; i++)
				{
					temp[i] = iA[i];
				}

				capacity = capacity*2;
				delete[]iA;
				iA = temp;
				delete[]temp;
			}
			else
			{
				//int index= userIndex-1;
				int pos;
				for (pos= numsize-1; pos >= index; pos--)
					iA[pos+1]=iA[pos];
					iA[index] = newInt;
					numsize++;
		
			}
			return 1;
		}

		int remove(int userIndex)
		{
			int index= userIndex;
			if ((index<0) || (index >= numsize))
				return 0;//cout << "Please enter an index within the accepted range";
			else
			{
				for (int pos = index; pos < numsize-1; pos++)
					iA[pos] = iA[pos+1];
				numsize--;
			}

			return 1;
		}

		int size()
		{
			return numsize;
		}

		T retobj(int userIndex)
		{
			int index = userIndex;
			if ((index<0) || (index >= numsize))
				cout <<"Please enter an index within the acceptable range";
			else
			{
				return iA[index];

			
			//if(idx >=0 && idx <= numsize)
			//	return iA[idx];
			}
		}

		int retsize()
		{
			return numsize;
		}

		/*void print()
		{
			for(int i = 0 ; i < numsize	; i++)
				cout<<iA[i];
		}*/
};
#endif