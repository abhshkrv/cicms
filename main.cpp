/* ------------------------------------------------------------------------------------------------------------
CG1103 G-Lab 1.
Discussion Group:C07-3
(Names and matric numbers of all group members)
Abhishek Ravi A0074613
Dao The Phuc A0071848
Lim Xinyi A0070559Y
------------------------------------------------------------------------------------------------------------------ */
#include "UI_input.h"
#include "statistics.h"
#include "actions.h"
#include "Perishable.h"
#include "Product.h"
#include "password.h";
#include "d_array.cpp";
#include "storage.h"
#include "bprocessing2.cpp";
#include <Windows.h>

//#include "GUI_output.h"
using namespace std;
int main()
{	
	HANDLE hConsole;
	hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
	//list<Product*> mkt;
	password p1;//object to authenticate user
	p1.authenticate();
	int choice;
	cout<<"1.Process Jobs	2.UI	3.Exit:";
	cin>>choice;
	//UI_input g1;//object to use the UI
	//storage s1;
	//s1.readfromfile();
	///////////////////////////////////////////////////////////////////////////////*ROW ONE*/
//pink text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "          ########  ";
//red text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "####  ";

//blue text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"########  ";
//green text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"####   ####  ";
//yellow text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#########     " << endl;


///////////////////////////////////////////////////////////////////////////////*ROW TWO*/
//pink text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "          #      #  ";
//red text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "#  #  ";

//blue text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"#      #  ";
//green text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#   # #   #  ";
//yellow text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#       #     " << endl;


///////////////////////////////////////////////////////////////////////////////*ROW THREE*/
//pink text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "          #  #####  ";
//red text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "#  # ";

//blue text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<" #  #####  ";
//green text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#   ###   #  ";
//yellow text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#  ######     " << endl;


//////////////////////////////////////////////////////////////////////////////*ROW FOUR*/
//pink text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "          #  #      ";
//red text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "#  # ";

//blue text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<" #  #      ";
//green text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#  # # #  #  ";
//yellow text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#  #          " << endl;


//////////////////////////////////////////////////////////////////////////////*ROW FIVE*/
//pink text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "          #  #      ";
//red text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "#  #  ";

//blue text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"#  #      ";
//green text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#  #   #  #  ";
//yellow text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#  ######     " << endl;


//////////////////////////////////////////////////////////////////////////////*ROW SIX*/
//pink text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "          #  #####  ";
//red text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "#  #  ";

//blue text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"#  #####  ";
//green text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#  #   #  #  ";
//yellow text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#       #     " << endl;


//////////////////////////////////////////////////////////////////////////////*ROW SEVEN*/
//pink text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "          #      #  ";
//red text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "#  #  ";

//blue text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"#      #  ";
//green text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#  #   #  #  ";
//yellow text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"######  #     " << endl;


//////////////////////////////////////////////////////////////////////////////*ROW EIGHT*/
//pink text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "          ########  ";
//red text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	cout << "####  ";

//blue text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"########  ";
//green text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"####   ####       ";
//yellow text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#  #     " << endl;


//////////////////////////////////////////////////////////////////////////////*ROW NINE*/
//cyan text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "          ---------------------------------------";

//yellow text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"######  #     " << endl;

//////////////////////////////////////////////////////////////////////////////*ROW TEN*/
//cyan text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "          |   C07-3   Abhishek | Phuc | Xinyi    ";

//yellow text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#       #     " << endl;

//////////////////////////////////////////////////////////////////////////////*ROW ELEVEN*/
//cyan text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "          ---------------------------------------";

//yellow text
	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"#########     " << endl;	
//////////////////////////////////////////////end of CICMS title

	SetConsoleTextAttribute
	(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
	while(choice!=3)
	if(choice ==1)
	{
		//cout<<"Murali";
		prcsng p;
		p.readfromfile1();
		p.execute();
		system("cls");
	//g1.getMenuChoice();
		cout<<"1.Process Jobs	2.UI	3.Exit:";
	cin>>choice;
	}
	else
	{
		UI_input u1;
		u1.getMenuChoice();
		system("cls");
		cout<<"1.Process Jobs	2.UI	3.Exit:";
	cin>>choice;
	}

	return 0;
}