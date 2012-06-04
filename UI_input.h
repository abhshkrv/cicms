/* ------------------------------------------------------------------------------------------------------------
CG1103 G-Lab 1.
Discussion Group:C07-3
(Names and matric numbers of all group members)
Abhishek Ravi A0074613
Dao The Phuc A0071848
Lim Xinyi A0070559Y
------------------------------------------------------------------------------------------------------------------ */

#ifndef UI_INPUT_H
#define UI_INPUT_H
#include <iostream>
#include "perishable.h"
#include "actions.h"
#include "statistics.h"
#include "listsort.cpp"
using namespace std;

class UI_input
{
	int _menuChoice;				//stores the menu choice
	actions act;					//to perform various actions on products
	statistics stat;				//to generate statistics
	storage s1;
	//markt mysort;					//to perform merge sort
public:
	void getMenuChoice();			//The magic. Controls the flow of the main
	void addProduct();				//calls act.add() to add a product to the market
	void getProductInfo(Product&);	//accepts input from the user
	void getExpiry();				//reads expiry date
	void getDiscount();				//reads discount
	long int getBarcode();			//reads barcode
	void getSaleAndRestock();		//calls act.restock to restock a product
	void getStatistics();			//prints out the stats available
	void deleteProduct();			//calls act.delete() which deletes a product
	void resetProductSales();		//calls act.reset() which sets product sales to 0
	void sortByWorth();				//uses a merge sorting algorithm to sort the products by their Worth
	UI_input(){}
	
};
#endif

