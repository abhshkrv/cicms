/* ------------------------------------------------------------------------------------------------------------
CG1103 G-Lab 1.
Discussion Group:C07-3
(Names and matric numbers of all group members)
Abhishek Ravi A0074613
Dao The Phuc A0071848
Lim Xinyi A0070559Y
------------------------------------------------------------------------------------------------------------------ */
#include"password.h"
#include<iostream>
using namespace std;
void password :: authenticate()
{
	cout << "Username : ";
	cin >> username;
	cout << "Password : ";
	cin >> pass;
	if ((username == "admin") && (pass == "password"))//checks if username and password is valid
		return ;
	else authenticate();//recursion, asks for the input again
}

