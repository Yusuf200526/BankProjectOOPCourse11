#include<iostream>
#include"clsBankClient.h"
#include"clsMainScreen.h"
using namespace std;


//void UpdateClient()
//{
//	string AccountNumber = "";
//
//	cout << "\nPlease Enter Client Account Number: ";
//
//	AccountNumber = clsInputValidate::ReadString();
//
//	while (!(clsBankClient::IsClientExist(AccountNumber)))
//	{
//		cout << "Account Number is not found , choose another one:  ";
//		AccountNumber = clsInputValidate::ReadString();
//	}
//
//	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
//	Client1.Print();
//
//	
//	cout << "\n\n Update Client Info: ";
//	cout << "\n_________________________\n";
//
//	ReadClientInfo(Client1);
//
//	clsBankClient::enSaveResult SaveResult = Client1.Save();
//
//	switch (SaveResult)
//	{
//	case clsBankClient::svSucceeded:
//	{
//		cout << "\Account Updated Successfully :-) ";
//		Client1.Print();
//	}
//	break;
//	case clsBankClient::svFailedEmptyObject:
//	{
//		cout << "\Error Account wasn't saved  ,because it's Empty ";
//	}
//	break;
//	}
//
//
//}
//
//}

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