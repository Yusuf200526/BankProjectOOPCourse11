#pragma once
#include"clsScreen.h"
#include<iostream>
#include"clsBankClient.h"
#include<iomanip>
#include"string"
using namespace std;
class clsClientListScreen:protected clsScreen
{
	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout <<setw(8)<<left<<""<< "| " << left << setw(15) << Client.AccountNumber;
		cout << "| " << left << setw(20) << Client.FullName;
		cout << "| " << left << setw(12) << Client.PhoneNumber;
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}



public:
	
	static void ShowClientList()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;
		}


		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "\t Client List Screen";
		string SubTitle = "\t   (" + to_string(vClients.size()) + ") Client(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n\n";
		cout <<setw(8)<<left<<""<< "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance"<<  "\n\n";
		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n\n";

		if (vClients.size() == 0)
		{
			cout << "\t\t\t\t\n No Clients Available in the System! ";
		}
		else
			for (clsBankClient& C : vClients)
			{
				_PrintClientRecordLine(C);
				cout << endl;
			}

		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n\n";
	}
};

