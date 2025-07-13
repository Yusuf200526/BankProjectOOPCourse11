#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsBankClient.h"
#include"C:\Users\YUSUF\My Repos\LIbraries\clsInputValidate.h"
using namespace std;
class clsUpdateClientScreen :protected clsScreen
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
		Client1.AccountBalance = clsInputValidate::ReadNumber<double>();

	}

public:

	static void ShowUpdateClientScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pUpdateClient))
		{
			return;
		}


		_DrawScreenHeader("\tUpdate Client Screen");

		string AccountNumber = "";

		cout << "\nPlease Enter Client Account Number: ";

		AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumber)))
		{
			cout << "Account Number is not found , choose another one:  ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		char Answer = 'n';
		cout << "\nAre you sure you want to update this client y/n ";
		cin >> Answer;

		if (toupper(Answer) == 'N')
		{
			return;
		}

		cout << "\n\n Update Client Info: ";
		cout << "\n_________________________\n";

		_ReadClientInfo(Client1);

		clsBankClient::enSaveResult SaveResult = Client1.Save();

		switch (SaveResult)
		{
		case clsBankClient::svSucceeded:
		{
			cout << "\Account Updated Successfully :-) ";
			_PrintClient(Client1);
		}
		break;
		case clsBankClient::svFailedEmptyObject:
		{
			cout << "\Error Account wasn't saved  ,because it's Empty ";
		}
		break;
		}
	}

};

