#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginScreen.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeMainScreen.h"
#include"C:\Users\YUSUF\My Repos\LIbraries\clsInputValidate.h"
#include"Global.h"
using namespace std;
class clsMainScreen : protected clsScreen
{
private:

	enum enMainMenueOptions {
		eShowListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eShowManageUsersMenue = 7, eLoginRegister = 8, eCurrencyExchange = 9, eLogout = 10
	};


	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "choose what you wants to do?  [1 to 10]? ";
		return clsInputValidate::ReadNumberBetween<int>(1, 10, "Choose from 1 to 10 only ");
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
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionMenue()
	{
		clsTransactionScreen::ShowTransactionMenueScreen();
	}

	static void _ShowManageUsersMenue()
	{
		/*cout << " Manage users Menue screeen will be here soon \n";*/
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	static void _ShowLoginRegisterScreen()
	{
		//cout << "Login Register screen will be here just a minute ...";
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeMainScreen()
	{
		//cout << "Currency Exchange Screen will be here soon...";
		clsCurrencyExchangeMainScreen::ShowCurrenciesMenueItems();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		//clsLoginScreen::ShowLoginScreen();  // Wrong will cause error (circular calling) 
		// then it will go back to login screen
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
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eShowManageUsersMenue:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeMainScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eLogout:
		{
			system("cls");
			_Logout();
			break;
		}
		}
	}



public:

	static void ShowMainMenue()
	{
		system("cls");

		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t\t  Main Menue Screen\n";
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << " [1] Show Client Screen.\n";
		cout << setw(37) << left << "" << " [2] Add New Client.\n";
		cout << setw(37) << left << "" << " [3] Delete Client.\n";
		cout << setw(37) << left << "" << " [4] Update Client.\n";
		cout << setw(37) << left << "" << " [5] Find Client.\n";
		cout << setw(37) << left << "" << " [6] Transactions\n";
		cout << setw(37) << left << "" << " [7] Manage Users.\n";
		cout << setw(37) << left << "" << " [8] Login Register.\n";
		cout << setw(37) << left << "" << " [9] Currency Exchange.\n";
		cout << setw(37) << left << "" << " [10] Logout.\n";
		cout << setw(37) << left << "" << "=========================================\n";

		_PerformMainMenueOption((enMainMenueOptions)(_ReadMainMenueOption()));
	}

};

