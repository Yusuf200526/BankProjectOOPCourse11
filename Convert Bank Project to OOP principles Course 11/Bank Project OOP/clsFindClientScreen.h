#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsBankClient.h"
#include"C:\Users\YUSUF\My Repos\LIbraries\clsDate.h"
class clsFindClientScreen :protected clsScreen
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

	static void ShowFindClientScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}


		_DrawScreenHeader("\tFind Client Screen");

		string AccountNumber = "";

		cout << "Please Enter Account Number  ";

		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found , Enter another one ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\n\nClient Found :-) ";
		}
		else
		{
			cout << "\nClient was not Found :-(\n";
		}


		cout << "\n\nClient Card\n\n";
		_PrintClient(Client);

	}

};

