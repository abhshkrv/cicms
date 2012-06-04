#ifndef bprocessing2_cpp
#define bprocessing2_cpp
#include<iostream>
#include<sstream>
#include<fstream>
#include"stack.cpp"
#include"queue.cpp"
#include"actions.h"
#include"Product.h"
using namespace std;

struct job
{
	string name;
	string prodname;
	int barcode;
	string date;
	string category;
	float Price;
	string manufacturer;
	int stock;
	
};

class person {
	
	string name;
	queue<job> jobq;
	job j1;
public:
	void insertjob(job j)
	{
		jobq.push(j);
	}
	void setname(string name1)
	{
		name = name1;
	}
	job jpop(){job temp = jobq.front();jobq.pop();return temp;}

	int retjobsize(){return jobq.size();}

	void clear(){jobq.empty();}
	
	string retname(){return name;}
};




class prcsng
{
	stack<person>pstack;
	actions act;
public:
	prcsng(){}
	void readfromfile1()
{	
	int n,nofjobs;
	job j;
	
	ifstream fin("batchjobs-s.txt");
	fin>>n;
	string junk;
	string pername,jobname,tempdate;
	getline(fin,junk);
	getline(fin,junk);
for(int i = 0; i < n ; i++)	
{	person p;
	getline(fin,pername);
	p.setname(pername);
	fin>>nofjobs;
	getline(fin,junk);
	getline(fin,junk);
	if(nofjobs!=0)
	for(int k = 0; k < nofjobs ; k++)
	{	job j;
		getline(fin,j.name);
		if(j.name=="DELETE")
		{	fin>>j.barcode;
			getline(fin,junk);
			getline(fin,junk);
			p.insertjob(j);
		}
		else if(j.name == "RESTOCK")
		{
			fin>>j.barcode;
			getline(fin,junk);
			fin>>j.stock;
			getline(fin,junk);
			getline(fin,junk);
			p.insertjob(j);
		}
		else if(j.name == "DISPOSE")
		{
			fin>>j.barcode;
			getline(fin,junk);
			getline(fin,j.date);
			getline(fin,junk);
			p.insertjob(j);
		}
		else if(j.name == "SALE")
		{
			fin>>j.barcode;
			getline(fin,junk);
			fin>>j.stock;
			getline(fin,junk);
			getline(fin,junk);
			p.insertjob(j);
		}
		else if(j.name =="ADD")
		{
			getline(fin,j.prodname);
			getline(fin,j.category);
			fin>>j.barcode;
			getline(fin,junk);
			fin>>j.Price;
			getline(fin,junk);
			getline(fin,j.manufacturer);
			fin>>j.stock;
			getline(fin,junk);
			getline(fin,junk);
			p.insertjob(j);
		
		}
	}
	if(nofjobs!=0)
	{pstack.push(p);
	p.clear();}
}
fin.close();
}

	void writelog(int barcode, string jobType, string userName)
{
	ofstream fout;
    fout.open("log-s.txt",ios::app);
	
	fout << barcode << " ";
    fout << jobType << " ";// << endl;
    fout << userName << endl;
	
}

	void execute()
		{
	//cout<<"HELLO";
	person p;	
	job j;
	int size,size1=pstack.size();
	while(size1!=0)
	{	p=pstack.top();
	size = p.retjobsize();
		while(size!=0)
		{	j = p.jpop();
		performJob(j,p.retname());
			size--;
		
		}
		pstack.pop();
		size1--;
	}

}

	//void writelog();

	void performJob(job j, string name)
	{
	if(j.name == "ADD")
	{
		//if barcode already exists, write to log. use ispresent(long int barcode) function from actions class
		if(act.ispresent(j.barcode)!=-1)
		writelog(j.barcode, j.name, name);

		//else, add a new product
		else
		{
			Product p(j.prodname, j.category,j.manufacturer,j.stock,j.barcode,j.Price,0);
			act.add(p);	
		}
	}

	else if(j.name == "DELETE")
	{
		if(act.ispresent(j.barcode)!=-1)
		act.idelete(j.barcode);

		else
		writelog(j.barcode, j.name, name);
		
	}

	else if(j.name == "RESTOCK")
	{
		if(act.ispresent(j.barcode)!=-1)
		act.restock(j.barcode,j.stock);

		else
		writelog(j.barcode, j.name, name);

	}

	else if(j.name == "DISPOSE")
	{	
		//if(act.checkexpiry(j.date,act.retProduct(j.barcode)._returnexpiry()))
			//act.idelete(j.barcode);
			;

		//not sure if you want the code above, so I just added mine below :P
		//if product not perishable/not expired yet/barcode does not exist, write to log
		//I don't know how to use the checkexpiry() function from actions, so that part might be wrong.
		//Abhishek, could you add an isPerishable(long int barcode); function in the actions class? Thanks!
	
	//cout<<endl<<act.ispresent(j.barcode);
		//cout<<" "<<act.retProduct(j.barcode).retper();
		//	cout<<j.date;
			//cout<<act.retProduct(j.barcode)->_returnexpiry();
			//cout<<" "<<act.checkexpiry(j.date,act.retProduct(j.barcode)->_returnexpiry());
	if((act.ispresent(j.barcode)!=-1)&&(act.retProduct(j.barcode)->retper()==1)&&act.checkexpiry(j.date,act.retProduct(j.barcode)->_returnexpiry())==0)
		act.removestock(j.barcode);	
	else	writelog(j.barcode, j.name, name);
	}

	else if(j.name == "SALE")
	{	
		//if no. sold < current stock AND barcode exists, edit sales of product
		//Abhishek, could you add a getsales(long int barcode); function in the actions class too? Thanks!
		if((j.stock < act.retProduct(j.barcode)->_getstock()) &&( act.ispresent(j.barcode)!=-1))
		act.sale(j.barcode);

		else
		writelog(j.barcode, j.name, name);
	}
}


};

/*void prcsng ::execute()
{
	cout<<"HELLO";
	person p;	
	job j;
	int size,size1=pstack.size();
	while(size1!=0)
	{	p=pstack.top();
	size = p.retjobsize();
		while(size!=0)
		{	j = p.jpop();
		performJob(j,p.retname());
			size--;
		
		}
		pstack.pop();
		size1--;
	}

}
*/
/*void prcsng :: readfromfile()
{	
	int n,nofjobs;
	job j;
	
	ifstream fin("batchjobs-m.txt");
	fin>>n;
	string junk;
	string pername,jobname,tempdate;
	getline(fin,junk);
	getline(fin,junk);
for(int i = 0; i < n ; i++)	
{	person p;
	getline(fin,pername);
	p.setname(pername);
	fin>>nofjobs;
	getline(fin,junk);
	getline(fin,junk);
	for(int k = 0; k < nofjobs ; k++)
	{	job j;
		getline(fin,j.name);
		if(j.name=="DELETE")
		{	fin>>j.barcode;
			getline(fin,junk);
			getline(fin,junk);
			p.insertjob(j);
		}
		else if(j.name == "RESTOCK")
		{
			fin>>j.barcode;
			getline(fin,junk);
			fin>>j.stock;
			getline(fin,junk);
			getline(fin,junk);
			p.insertjob(j);
		}
		else if(j.name == "DISPOSE")
		{
			fin>>j.barcode;
			getline(fin,junk);
			getline(fin,j.date);
			getline(fin,junk);
			p.insertjob(j);
		}
		else if(j.name == "SALE")
		{
			fin>>j.barcode;
			getline(fin,junk);
			fin>>j.stock;
			getline(fin,junk);
			getline(fin,junk);
			p.insertjob(j);
		}
		else if(j.name =="ADD")
		{
			getline(fin,j.prodname);
			getline(fin,j.category);
			fin>>j.barcode;
			getline(fin,junk);
			fin>>j.Price;
			getline(fin,junk);
			getline(fin,j.manufacturer);
			fin>>j.stock;
			getline(fin,junk);
			getline(fin,junk);
			p.insertjob(j);
		
		}
	}
	pstack.push(p);
	p.clear();
}
fin.close();
}
*/
/*void prcsng :: writelog(int barcode, string jobType, string userName)
{
	ofstream fout;
    fout.open("log-m.txt",ios::app);
	
	fout << barcode << " ";
    fout << jobType << " ";// << endl;
    fout << userName << endl;
	
}*/

#endif

