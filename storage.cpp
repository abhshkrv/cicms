#include "storage.h"
#include <iostream>
d_array<Product*> storage :: readfromfile()
{	ifstream readFile("data-xs.txt") ;
	int totalItems, i;
	int barcode, stock, permonthsales;
	string expiry;
	float discount;
	double price;
	//the string newlines stores all newline characters.
	string name, category, manufacturer, testPerishable, newlines;

	Product *tempProduct;
	Perishable *tempPerishable;
	
	//list *;
	string junk;
	//getline(readFile,junk);

	readFile >> totalItems;
	getline(readFile,junk);
	getline(readFile,junk);
	for(i=0; i < totalItems; i++)
	{
		//read in details as shown in the order above.
		getline(readFile, name);
		//getline(readFile,junk);
		getline(readFile, category);
		//getline(readFile,junk);
		readFile >> barcode;
		getline(readFile,junk);
		readFile >> price;
		getline(readFile,junk);
		getline(readFile, manufacturer);
		//getline(readFile,junk);
		readFile >> stock;
		getline(readFile,junk);
		readFile >> permonthsales;
		getline(readFile,junk);
		//getline(readFile,junk);

		//this part checks whether the product being read is perishable
		getline(readFile,testPerishable);

		//if the next line is not the newline character, it is perishable.
		//Read in expiry and discount.
		if(testPerishable != "")
		{
			expiry = testPerishable;
			readFile >> discount;

			//assign values of variables to tempPerishable object
			tempPerishable = new Perishable(name, category, manufacturer, stock, barcode, price, permonthsales, expiry, discount);
			//let pointer from linkedlist point to tempPerishable object
			
			//testPerishable is currently a pointer, you may have to change it according to your code.
			_market.insert(tempPerishable,i);
			getline(readFile,newlines);
			getline(readFile,newlines);
		}

		else
		{
			//assign values of variables to tempProduct
			tempProduct = new Product(name, category, manufacturer, stock, barcode, price, permonthsales);
			//let pointer from linkedlist point to tempProduct object
			
			//testProduct is currently a pointer, you may have to change it according to your code.
			_market.insert(tempProduct,i);
			//getline(readFile,newlines);
			//continue;	
		}
		
	}

	readFile.close();
	return _market;
}

void storage ::writetofile(d_array<Product*> mkt)
{
	
	ofstream writeFile;
    writeFile.open("data-xs.txt");
	writeFile <<mkt.retsize() ;
    writeFile << endl << endl;

	for(int i = 0; i < mkt.retsize(); i++)
    {
        writeFile << mkt.retobj(i)->_getname() << endl;
        writeFile << mkt.retobj(i)->_getcategory() << endl;
        writeFile << mkt.retobj(i)->_getbarcode() << endl;
        writeFile << mkt.retobj(i)->_getprice() << endl;
        writeFile << mkt.retobj(i)->_getmanufacturer() << endl;
        writeFile << mkt.retobj(i)->_getstock() << endl;
        writeFile << mkt.retobj(i)->_getpermonthsales() << endl;
//
		if(mkt.retobj(i)->retper() == 1)
        {
            writeFile << mkt.retobj(i)->_returnexpiry() << endl;
            writeFile << mkt.retobj(i)->_returndiscount() << endl;
        }
//       
        writeFile << endl;
    }
    writeFile.close();
}





