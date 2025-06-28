#include<iostream>
#include"clsBankClient.h"
#include"clsMainScreen.h"
using namespace std;



//void ShowTotalBalances()
//{
//	vector<clsBankClient> vClients = clsBankClient::GetClientsList();
//
//	cout << "\t\t\t\t\t" << "Balances List (" << vClients.size() << ") Client(s).\n";
//	cout << "_____________________________________________________________________" <<
//		"__________________________________________________\n\n\n";
//	cout << "| " << left << setw(15) << "Account Number";
//	cout << "| " << left << setw(40) << "Client Name";
//	cout << "| " << left << setw(12) << "Balance" << "\n\n";
//	cout << "_____________________________________________________"
//		<< "__________________________________________________________________\n\n";
//
//	double TotalBalances = clsBankClient::GetTotalBalances();
//
//
//	if (vClients.size() == 0)
//	{
//		cout << "\t\t\t\t No Clients Available in the System! ";
//	}
//	else
//		for (clsBankClient& C : vClients)
//		{
//			PrintClientRecordBalanceLine(C);
//			cout << endl;
//		}
//		
//	cout << "_____________________________________________________"
//		<< "__________________________________________________________________\n\n\n\n";
//	cout << "\t\t\t\t\t Total Balances = " << TotalBalances << "\n";
//	cout << "\t\t\t ( " << clsUtil::NumberToText(TotalBalances) << " ) " << endl;
//
//}

//void PrintClientRecordBalanceLine(clsBankClient Client)
//{
//	cout << "| " << left << setw(15) << Client.AccountNumber;
//	cout << "| " << left << setw(40) << Client.FullName;
//	cout << "| " << left << setw(12) << Client.AccountBalance;
//}



int main()
{
	
	clsMainScreen::ShowMainMenue();
	

	system("pause>0");

	return 0;
}