#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"C:\Users\YUSUF\My Repos\LIbraries\clsInputValidate.h"
#include"clsCurrenciesListScreen.h";
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculaterScreen.h"
using namespace std;
class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:

	enum enCurrencyExchangeMainScreenOptions {
		eListCurrencies = 1, eFindCurrencies = 2, eUpdateRate = 3
		, eCurrencyCalculater = 4, eMainMenue = 5
	};

	static short _ReadCurrencyExchangeMainScreenOption()
	{
		cout << setw(37) << left << "" << "choose what you wants to do?  [1 to 5]? ";
		return clsInputValidate::ReadNumberBetween<int>(1, 5, "Choose from 1 to 5 only ");
	}

	static void _GoBackToCurrencyExchangeMainScreen()
	{
		cout << setw(8) << left << "" << "\n\npress any key to go back to Currency Exchange Main Screen...\n";
		system("pause>0");
		ShowCurrenciesMenueItems();
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "List Currencies Screen will be here soon...";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrenciesScreen()
	{
		//cout << "Find Currencies Screen will be here soon...";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		//cout << "Update Rate Screen will be here soon...";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculaterScreen()
	{
		//cout << "Currency Calculater will be here soon...";
		clsCurrencyCalculaterScreen::ShowCurrencyCalculaterScreen();
	}
 
	static void _PerformCurrencyExchangeMainScreenOption(
		enCurrencyExchangeMainScreenOptions CurrencyExchangeMainScreenOption)
	{
		switch (CurrencyExchangeMainScreenOption)
		{
		case enCurrencyExchangeMainScreenOptions::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMainScreen();
			break;
		}
		case enCurrencyExchangeMainScreenOptions::eFindCurrencies:
		{
			system("cls");
			_ShowFindCurrenciesScreen();
			_GoBackToCurrencyExchangeMainScreen();
			break;
		}
		case enCurrencyExchangeMainScreenOptions::eUpdateRate:
		{
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrencyExchangeMainScreen();
			break;
		}

		case enCurrencyExchangeMainScreenOptions::eCurrencyCalculater:
		{
			system("cls");
			_ShowCurrencyCalculaterScreen();
			_GoBackToCurrencyExchangeMainScreen();
			break;
		}
		case enCurrencyExchangeMainScreenOptions::eMainMenue:
		{
			// Do nothing here
		}
		}
	}




public:

	static void ShowCurrenciesMenueItems()
	{
		system("cls");

		_DrawScreenHeader("   Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t Currency Exchange Menue Screen\n";
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << " [1] List Currencies.\n";
		cout << setw(37) << left << "" << " [2] Find Currencies.\n";
		cout << setw(37) << left << "" << " [3] Update Rate.\n";
		cout << setw(37) << left << "" << " [4] Currency Calculater.\n";
		cout << setw(37) << left << "" << " [5] Main Menue.\n";
		cout << setw(37) << left << "" << "=========================================\n";
		_PerformCurrencyExchangeMainScreenOption(
			(enCurrencyExchangeMainScreenOptions)_ReadCurrencyExchangeMainScreenOption());
	}




};

