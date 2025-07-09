#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"C:\Users\YUSUF\source\repos\Libraries\clsInputValidate.h"
#include"Global.h"
class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________________";
		cout << "\nFull Name        :" << Client.FullName;
		cout << "\nAcc.Number       :" << Client.AccountNumber;
		cout << "\nBalance          :" << Client.AccountBalance;
		cout << "\n___________________________";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\n\nPlease Enter Account Number to Transfer From:  ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Clinet isn't found , please Enter another one  ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient &SourceClient)
	{
		float Amount = 0;

		cout << "\n\nEnter Transfer Amount? ";

		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "Amount Exeeds The Balance , Enter another Amount ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		return Amount;
	}
	

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClientCard(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClientCard(DestinationClient);

		float Amount = _ReadAmount(SourceClient);

		
		char Answer = 'n';

		cout << "\n\nAre you sure you want to perform this operation? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\n\nTransfer Done Successfully\n\n";
			}
			else
			{
				cout << "\n\nTransfer Faild\n";
			}
			_PrintClientCard(SourceClient);
			_PrintClientCard(DestinationClient);
		}
	}
};

