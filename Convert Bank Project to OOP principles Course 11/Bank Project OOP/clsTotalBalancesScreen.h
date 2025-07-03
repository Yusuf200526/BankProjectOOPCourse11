#pragma once
#include<iostream>
#include<iomanip>
#include<string>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"C:/Users/YUSUF/source/repos/Libraries/clsInputValidate.h"
#include"C:/Users/YUSUF/source/repos/Libraries/clsUtil.h"
class clsTotalBalancesScreen :protected clsScreen
{

private:

	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(8) << left << "" << "| " << left << setw(15) << Client.AccountNumber;
		cout << "| " << left << setw(40) << Client.FullName;
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}

public:

	static void ShowTotalBalances()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		_DrawScreenHeader("\t Balances List Screen","\t    ("+to_string(vClients.size())+")"+"Client(s).");

		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n\n";
		cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance" << "\n\n";
		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n\n";

		double TotalBalances = clsBankClient::GetTotalBalances();


		if (vClients.size() == 0)
		{
			cout << "\t\t\t\t No Clients Available in the System! ";
		}
		else
			for (clsBankClient& C : vClients)
			{
				_PrintClientRecordBalanceLine(C);
				cout << endl;
			}

		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n\n";
		cout << "\t\t\t\t\t Total Balances = " << TotalBalances << "\n";
		cout << "\t\t\t ( " << clsUtil::NumberToText(TotalBalances) << " ) " << endl;

	}
};

