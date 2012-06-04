/* ------------------------------------------------------------------------------------------------------------
CG1103 G-Lab 1.
Discussion Group:C07-3
(Names and matric numbers of all group members)
Abhishek Ravi A0074613
Dao The Phuc A0071848
Lim Xinyi A0070559Y
------------------------------------------------------------------------------------------------------------------ */
#include "UI_input.h"
#include "Perishable.h"
#include<stdlib.h>
using namespace std;

void pause()
{
	system("pause");
	cout<<endl;
}

void UI_input :: getMenuChoice()          //prints menu and controls the flow
{
	

	cout << "CEG Hypermarket Inventory Control and Monitoring System" << endl; 
	cout << endl;
	cout << "1. Add New Product" << endl;
	cout << "2. Delete Product" << endl;
	cout << "3. Reset Product Sales" << endl;
	cout << "4. Sale/Restock Transaction" << endl;
	cout << "5. Generate Statistics" << endl;
	cout << "6. Check Product Expiry"<<endl;
	cout<< "7. Exit"<< endl;
	cout<< "8. Sort Products By Worth"<<endl;
	cout<< "9. Clear Screen"<<endl;
	cout << "What would you like to do? [Please enter number] :" << endl;
	cin >> _menuChoice;
	system("cls");//clears screen
	int i=0;
	int t1;
	switch(_menuChoice)
	{
		case 1:
			addProduct();
			break;
		
		case 2:

			deleteProduct();
			break;

		case 3:
			resetProductSales();
			break;

		case 4:
			getSaleAndRestock();
			break;

		case 5:
			getStatistics();
			break;

		case 6:
			 t1 =act.exp();
			if(t1==0)
				cout<<"Expired";
			else if(t1==1)
				cout<<"Still available";
			else cout<<"product unavailable";
			break;
		case 7:
			return ;
		case 8:
			sortByWorth();
			break;
		case 9:
			i = 1;
			break;
		default:
			pause();
			cout << "Please enter a number from 1 to 5: " << endl;
			getMenuChoice();
			break;
	}
	pause();//
	if(i==1)
		system("cls");//clears screen
	getMenuChoice();//prints the menu agaun
}

void UI_input :: addProduct()
{
	int isPerishable;

	cout << "Is the product to be added perishable?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cout << "3. Return To Main Menu" << endl;
	cout << "Please enter a number : " << endl;
	cin >> isPerishable;

	// At this part, proceed to get product info input ONLY IF 1 or 2 is entered.
	// Or else, print an error message.
	Product temp1;
	Perishable temp2;

	

	switch (isPerishable)
	{
		case 1:
			//if the product to be added is perishable, prompt for product info, expiry date, and discount
			//temp = (Perishable) temp;	

			getProductInfo(temp2);
			cout<<"Enter the date(ddmmyyyy) :"; 
			temp2._setdate();
			temp2._setdiscount();
			act.add(temp2);//adds temp to the market
			break;

		case 2:
			//for non-perishable products, only prompt for product info
			getProductInfo(temp1);//reads product info
			act.add(temp1);
			break;

		case 3:
			//if the user wishes to go back to the main menu
			getMenuChoice();
			break;

		default:
			cout << "Please enter 1, 2, or 3." << endl;
			addProduct();
			break;
	}
}

void UI_input :: getProductInfo(Product &temp)
{	string t;
	int tint;
	float tprice;
	cout << "Please enter the following information about the product: " << endl;
	//prompt a new question for each new input.
	getline(cin,t);
	cout<<"Name : ";
	getline(cin, t);
	temp._readname(t);
	cout<<"Category : ";
	getline(cin, t);
	temp._readcategory(t);
	cout<<"Manufacturer : ";
	getline(cin, t);
	temp._readmanufacturer(t);
	cout<<"Stock : ";
	cin>>tint;
	temp._readstock(tint);
	cout<<"Barcode : ";
	cin>>tint;
	temp._readbarcode(tint);
	cout<<"Price : ";
	cin>>tprice;
	temp._readprice(tprice);
	cout<<"Per Month Sales";
	cin>>tint;
	temp._readpermonthsales(tint);
	return;
}

void UI_input :: deleteProduct()
{	int code = getBarcode();
	int success = act.idelete(code);
	if(success ==1) cout<<"Product Deleted"<<endl;
	else cout << "Invalid code"<<endl;
}

long int UI_input :: getBarcode()
{
	long int barcode;

	cout << "Please enter the barcode number: " << endl;
	cin >> barcode;
	return barcode;
}

void UI_input :: resetProductSales()
{	long int code = getBarcode();
	int success = act.reset(code,0);
	if(success == 1) cout<<"Product Sales have been reset"<<endl;
	else cout << "Invalid code"<<endl;
}

void UI_input :: getSaleAndRestock()
{
	int choice, number_restocked,sf; 
	long int barcode;
	cout<<"1. Sale Transaction"<<endl;
	cout << "2. Change Sales Figures" << endl;
	cout << "3. Restock" << endl;
	cout << "4. Return To Main Menu" << endl;
	cout << "Please enter a number: " << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:	barcode = getBarcode();
			if(act.sale(barcode))
				cout<<"Transaction complete";
			else cout<<"Invalid Product";
			break;

		case 2:
			barcode = getBarcode();
			cout<<"Enter the new sales figure : ";
			cin>>sf;
			if(act.restock(barcode,sf))
				cout << "The sales figure of the item (barcode: " << barcode << ") has been reset to 0." << endl;
			else cout<<"Invalid code";
			break;

		case 3:
			barcode = getBarcode();
			cout<<"Enter the number of items to be restocked : ";
			cin >> number_restocked;
			if(act.restock(barcode,number_restocked))
				cout << "Item (barcode: " << barcode << ") has been restocked." << endl;
			else cout<<"Invalid code";
			break;

		case 4:
			getMenuChoice();
			break;

		default:
			cout << "Please enter 1, 2, 3 or 4" << endl;
			getSaleAndRestock();
			break;
	}
}

void UI_input :: getStatistics()
{
	int statsChoice, X;
	string category;
	cout << "Generate Statistics" << endl;
	cout << "1. Top X Selling Products" << endl;
	cout << "2. Best Selling Product In A Category" << endl;
	cout << "3. Best Selling Manufacturer" << endl;
	cout<<"4. Search"<<endl;
	cout << "5. Return To Main Menu" << endl;
	cout << "Please enter a number: " << endl;
	cin >> statsChoice;
	stat.setmkt(act.retmkt());
	switch(statsChoice)
	{

		case 1:
			cout << "Enter value of X: " << endl;
			cin >> X;
			stat.topsellingprod(X);
			break;

		case 2:
			cout << "Categories available: " << endl;
			stat.printcat();
			cout << "Please enter a category number: " << endl; 
			cin >> category;
			stat.topsellingcat(category);
			break;

		case 3:
			
			//cout << "Manufacturers available: " << endl;
			//stat.printman();
			//cout << "Please enter a manufacturer's number: " << endl;
			//cin >> manufacturer_number;
			stat.topsellingman(1);
			break;

		case 4:
			stat.search();
			break;

		case 5:
			return;

		default:
			cout << "Please enter 1, 2, 3, or 4. " << endl;
			getStatistics();
			break;
	}
}

void UI_input :: sortByWorth()
{
	act.sort();

}