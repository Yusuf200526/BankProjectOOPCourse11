#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include<vector>
#include<string>
using namespace std;
class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.Country;;
		cout << "| " << left << setw(10) << Currency.CurrencyCode;
		cout << "| " << left << setw(40) << Currency.CurrencyName;
		cout << "| " << left << setw(20) << Currency.Rate;
	}


public:

	static void ShowCurrenciesListScreen()
	{
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrencyList();

		string Title = "\tCurrencies List Screen";
		string SubTitle = "\t  (" + to_string(vCurrencies.size()) + ") Currency.";

		_DrawScreenHeader(Title, SubTitle);


		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n";
		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(10) << "Code";
		cout << "| " << left << setw(40) << "Name";
		cout << "| " << left << setw(20) << "Rate/(1$)" << "\n";
		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n";

		if (vCurrencies.size() == 0)
		{
			cout << "\t\t\t\t\nNo Currencies Available in the System! ";
		}
		else
			for (clsCurrency& Currency : vCurrencies)
			{
				_PrintCurrencyRecordLine(Currency);
				cout << endl;
			}

		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n";

	}

};

