#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"C:/Users/YUSUF/source/repos/Libraries/clsInputValidate.h"
class clsWithdrawScreen: protected clsScreen
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

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t Withdraw Screen");

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
		cout << "\nPlease Enter Withdraw amount ?  ";
		Amount = clsInputValidate::ReadPostiveDblNumber("Withdraw Amount Must be positive!  ");

		cout << "\nAre you sure you want to perform this transaction y/n ?  ";
		char Answer = 'n';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << "\nAmount Withdrawed successfully :-) . \n";
				cout << "New Balance is " << Client1.AccountBalance;
			}
			else
			{
				cout << "cannot to withdraw, Insuffecient balance! \n";
				cout << "\n\nAmount to withdraw " << Amount << "\n";
				cout << "your Balance is " << Client1.AccountBalance;
			}
		}
		else
		{
			cout << "\n Operation was cancelled :-( . \n";
		}
	}
};

