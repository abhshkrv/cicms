#ifndef STORAGE_H
#define STORAGE_H
#include"Product.h"
#include<cstdio>
#include "Perishable.h"
#include<string>
#include<fstream>
#include"linklist.cpp"
#include"d_array.cpp"
using namespace std;
class storage
{	
	d_array<Product*> _market;

public:
	d_array<Product*> readfromfile();
	void writetofile(d_array<Product*>);
	storage(){}
};
#endif