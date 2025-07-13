#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"C:\Users\YUSUF\My Repos\LIbraries\clsInputValidate.h"
class clsDepositScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card : ";
		cout << "\n___________________________";
		cout << "\nFirst Name       :" << Client.FirstName;
		cout << "\nLast Name        :" << Client.LastName;
		cout << "\nFull Name        :" << Client.FullName;
		cout << "\nEmail            :" << Client.Email;
		cout << "\nPhone            :" << Client.PhoneNumber;
		cout << "\nAcc.Number       :" << Client.AccountNumber;
		cout << "\nPassword         :" << Client.PinCode;
		cout << "\nBalance          :" << Client.AccountBalance;
		cout << "\n___________________________\n";
	}


public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t Deposit Screen");

		cout << "Please Enter Account Number  ";
		string AccountNumber = "";

		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number wasn't found , Enter another one ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease Enter deposit amount ?  ";
		Amount = clsInputValidate::ReadPostiveNumber<double>("Deposit Amount Must be positive!  ");

		cout << "\nAre you sure you want to perform this transaction y/n ?  ";
		char Answer = 'n';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Client1.Deposit(Amount);
			cout << "\nAmount Deposited successfully :-) . \n";
			cout << "New Balance is " << Client1.AccountBalance;
		}
		else
		{
			cout << "\n Operation was cancelled :-( . \n";
		}
	}
};

