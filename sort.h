#ifndef SORT_H
#define SORT_H
#include <string>
#include <iostream>
#include "Product.h"
#include "Perishable.h"
#include "storage.h"
#include "d_array.cpp"
using namespace std;

class sort
{
	private:
		d_array<Product*> _arrayptr;
		storage s1;

	public:
		sort()
		{
			_arrayptr = s1.readfromfile();
		}

		sort(d_array<Product*> arrayptr)
		{
			_arrayptr = arrayptr;
		}

		void mergeSort(int low, int high, string datatype);

		void merge(int low, int mid, int high, string datatype);

		int retsize();

		void printSortedList();

};

#endif