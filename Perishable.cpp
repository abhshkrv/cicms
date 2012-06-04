/* ------------------------------------------------------------------------------------------------------------
CG1103 G-Lab 1.
Discussion Group:C07-3
(Names and matric numbers of all group members)
Abhishek Ravi A0074613
Dao The Phuc A0071848
Lim Xinyi A0070559Y
------------------------------------------------------------------------------------------------------------------ */
#include "Perishable.h"
#include <iostream>
using namespace std;
string Perishable :: _returnexpiry()//returns the expiry date
{
	return _expiry;
}
float Perishable :: _returndiscount()//returns discount %
{
	return _discount;
}

void Perishable :: _setdate()
{
	cin>>_expiry;
}
void Perishable :: _setdiscount()
{
	cout << "Enter the discount : ";
	cin >> _discount;
}

