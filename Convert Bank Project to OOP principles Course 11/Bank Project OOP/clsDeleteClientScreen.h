#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsBankClient.h"
#include"C:/Users/YUSUF/source/repos/Libraries/clsInputValidate.h"
using namespace std;
class clsDeleteClientScreen :protected clsScreen
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
	static void ShowDeleteClientScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}


		_DrawScreenHeader("\t Delete Client Screen");

		string AccountNumber = "";

		cout << "Please Enter Account Number ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number isn't found , Enter another one please ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		cout << "\nAre you sure you want to delete this client y/n?  ";

		char Answer = 'Y';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (Client1.Delete())
			{
				cout << "\nClient Deleted successfully :-)\n";
				_PrintClient(Client1);
			}
			else
			{
				cout << "\nError Client wasn't deleted\n";
			}
		}

	}

	
};

