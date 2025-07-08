#pragma once
#include<iostream>
#include<iomanip>
#include"C:/Users/YUSUF/source/repos/Libraries/clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"

using namespace std;
class clsTransactionScreen : protected clsScreen
{
private:

	enum enTransactionMenueOptions
	{
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalancesScreen = 3, eShowMainMenue = 4
	};

	static short _ReadTransactionMenueOption()
	{
		cout << setw(37) << left << "" << "choose what you wants to do?  [1 to 4]?  ";
		return clsInputValidate::ReadIntNumberBetween(1, 4, "Choose from 1 to 8 only ");
	}

	 
	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _GoBackToTransactionMenue()
	{
		cout << setw(8) << left << "" << "\n\npress any key to go back to main Menue...\n";
		system("pause>0");
		ShowTransactionMenueScreen();
	}



	static void _PerformTransactionMenueOption(enTransactionMenueOptions TransactionMenueOption)
	{
		switch (TransactionMenueOption)
		{
		case enTransactionMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOptions::eShowTotalBalancesScreen:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionMenueOptions::eShowMainMenue:
		{
			// Do nothing here tha main screen will hundle it soon :-) ;
		}
		}
	}



public:

	static void ShowTransactionMenueScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return;
		}


		system("cls");

		_DrawScreenHeader("\tTransaction Menue");

		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transaction Menue Screen\n";
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << " [1] Deposit. \n";
		cout << setw(37) << left << "" << " [2] Withdraw . \n";
		cout << setw(37) << left << "" << " [3] Total Balances. \n";
		cout << setw(37) << left << "" << " [4] Main Menue. \n";
		cout << setw(37) << left << "" << "=========================================\n";

		_PerformTransactionMenueOption((enTransactionMenueOptions)_ReadTransactionMenueOption());

	}

};

