#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"C:/Users/YUSUF/source/repos/Libraries/clsInputValidate.h"
using namespace std;
class clsAddNewClientScreen :protected clsScreen
{
private:

	static void _ReadClientInfo(clsBankClient& Client1)
	{
		cout << "\nEnter First Name: ";
		Client1.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name: ";
		Client1.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client1.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone Number: ";
		Client1.PhoneNumber = clsInputValidate::ReadString();

		cout << "\nEnter Pin Code: ";
		Client1.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance: ";
		Client1.AccountBalance = clsInputValidate::ReadDblNumber();

	}

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

	static void ShowAddNewClient()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}


		_DrawScreenHeader("\tAdd New Client Screen");

		string AccountNumber = "";

		cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account Number Is already used , choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResult SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::svSucceeded:
		{
			cout << "\nAccount Added Successfully :-) ";
			_PrintClient(NewClient);
		}
		break;
		case clsBankClient::svFailedEmptyObject:
		{
			cout << "\nError Account wasn't saved  ,because it's Empty ";
		}
		break;
		case clsBankClient::enSaveResult::svFailedAccountNumberExists:
		{
			cout << "\nError Account wasn't saved , because it is already exists ";
		}
		}
	}
};
