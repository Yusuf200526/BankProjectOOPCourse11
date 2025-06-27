#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"C:/Users/YUSUF/source/repos/Libraries/clsInputValidate.h"
using namespace std;
class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenueOptions { eShowListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6, eShowManageUsersMenue = 7, eLogout = 8 };


	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "choose what you wants to do?  [1 to 8] \n";
		return clsInputValidate::ReadIntNumberBetween(1, 8, "Choose from 1 to 8 only ");
	}

	static void _GoBackToMainMenue()
	{
		cout << setw(8) << left << "" << "\n\npress any key to go back to main Menue...\n";
		system("pause>0");
		ShowMainMenue();
	}


	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientList();
	}

	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClient();
	}

	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		cout << " Update client screeen will be here soon \n";
	}

	static void _ShowFindClientScreen()
	{
		cout << " Find client screeen will be here soon \n";
	}

	static void _ShowTransactionMenue()
	{
		cout << " Transaction Menue screeen will be here soon \n";
	}

	static void _ShowManageUsersMenue()
	{
		cout << " Manage users Menue screeen will be here soon \n";
	}


	static void _PerformMainMenueOption(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOptions::eShowListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		}

		case enMainMenueOptions::eUpdateClient:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionMenue();
			break;
		}
		case enMainMenueOptions::eShowManageUsersMenue:
		{
			system("cls");
			_ShowManageUsersMenue();
			break;
		}
		case enMainMenueOptions::eLogout:
		{
			system("cls");
		/*	Login();*/
			break;
		}
		}
	}



public:

	static void ShowMainMenue()
	{
		system("cls");

		_DrawScreenHeader("\t\tMain Menue");

		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t\t  Main Menue Screen\n";
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << " [1] Show Client Screen. \n";
		cout << setw(37) << left << "" << " [2] Add New Client. \n";
		cout << setw(37) << left << "" << " [3] Delete Client. \n";
		cout << setw(37) << left << "" << " [4] Update Client. \n";
		cout << setw(37) << left << "" << " [5] Find Client. \n";
		cout << setw(37) << left << "" << " [6] Transactions\n";
		cout << setw(37) << left << "" << " [7] Manage Users. \n";
		cout << setw(37) << left << "" << " [8] Logout. \n";
		cout << setw(37) << left << "" << "=========================================\n";

		_PerformMainMenueOption((enMainMenueOptions)(_ReadMainMenueOption()));
	}

};

