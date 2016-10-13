// INFO450SaveMoree.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream> 

using namespace std;

class account
{
public:
	int day;
	const char *accountNum = new char[50];
	const char *accountType = new char[50];
	double interest = 0;
	double bal = 0;

	void display();
	virtual int deposit(double d);
	virtual int withdraw(double w);
};


void account::display()
{
	
	cout << endl;
	cout << "Account Type: " << accountType << endl;
	cout << "Account Number: " << accountNum << endl;
	cout << "Interest Rate: " << interest << '%' << endl;
	cout << "Balance: " << bal << endl;

}
int account::deposit(double d)
{
	
	if (d < 0)
	{
		cout << "Cannot compute" << endl;
		return (-1);
	}
	else
	{
		bal += d;
		return (0);
	}

}

int account::withdraw(double w)
{
	
	if (bal - w < 0)
	{
		cout << "Not enough funds" << endl;
		return(-1);
	}
	else
	{
		bal -= w;
		return(0);
	}
}


class savings : public account
{
public:
	savings()
	{
		accountType = "Savings";
	}
	void checkaccount()
	{
		if (bal >= 10000)
		{
			interest = 2;
		}
		else
		{
			interest = 1;
		}
	}
	void compound(int day)
	{
		if (day == 1)
		{
			bal = bal * (interest / 100);
			checkaccount();
		}
	}
	int deposit(double d)
	{
		account::deposit(d);
		checkaccount();
		return (0);

	}
	int withdraw(double w)
	{
		account::withdraw(w);
		checkaccount();
		return (0);
	}
};

class checking : public account
{

public:
	checking()
	{
		accountType = "Checking";
		interest = 0;
	}
	void checkaccount()
	{
		if (bal < 500)
		{
			bal = bal - 5;
		}
	}
	void orderChecks()
	{
		bal = bal - 15;
	}
	int deposit(double d)
	{
		account::deposit(d);
		checkaccount();
		return (0);

	}
	int withdraw(double w)
	{
		account::withdraw(w);
		checkaccount();
		return (0);
	}
};


class cd : public account
{
public:
	
	int t;
	void checkterm(int term)
	{
		if (term >= 5)
			interest = 10;
		else
			interest = 5;
	}
	cd(int term)
	{
		accountType = "CD";
		checkterm(term);
		t = term;

	}
	void compound(int day)
	{
		if (day == 1)
		{
			bal = bal + (bal * (interest / 100));
		}
	}
	void penalty(int i)
		
	{
		if (i == 1)
		{
			bal = (bal - (bal *(interest / 100)));
		}
	}
	int deposit(double d)
	{
		account::deposit(d);
		checkterm(t);
		return (0);

	}
	int withdraw(double w, int i)
		
	{
		if (i == 1)
		{
			bal = (bal - (bal *(interest / 100)));
		}
		account::withdraw(w);
		checkterm(t);
		return (0);
	}
};

int main()
{
	savings mysave;
	mysave.accountNum = "Savings";
	mysave.deposit(10000);
	checking mycheck;
	mycheck.accountNum = "Checking";
	mycheck.deposit(600);
	cd mycd(3);
	mycd.deposit(10000);
	mycd.accountNum = "CD";
	mysave.display();
	mycheck.display();
	mycd.display();
	mysave.compound(1);
	mycd.compound(1);
	mysave.display();
	mycd.display();
	mycheck.orderChecks();
	mycheck.withdraw(200);
	mysave.withdraw(1000);
	mycd.withdraw(2000, 1);

	mysave.display();
	mycheck.display();
	mycd.display();

	;




}