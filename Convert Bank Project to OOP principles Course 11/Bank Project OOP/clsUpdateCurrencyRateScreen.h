#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"C:/Users/YUSUF/source/repos/Libraries/clsInputValidate.h"
using namespace std;
class clsUpdateCurrencyRateScreen: protected clsScreen
{
private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\n\nCurrency Card : ";
		cout << "\n___________________________";
		cout << "\nCountry          :" << Currency.Country;
		cout << "\nCode             :" << Currency.CurrencyCode;
		cout << "\nName             :" << Currency.CurrencyName;
		cout << "\nRate(1$)         :" << Currency.Rate;
		cout << "\n___________________________\n";
	}


public:

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader(" Update Currency Rate Screen");

		cout << "\nPlease Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is Not Correct , Enter agian ";
		    CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		_PrintCurrency(Currency);

		
		cout << "\nAre you sure you want to update rate of this currency y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			cout << "\n\n";
			cout << "Update Currency Rate\n";
			cout << "___________________________\n\n";
			cout << "Enter New Rate: ";
			Currency.Rate = clsInputValidate::ReadPostiveDblNumber();
	
			cout << "\nCurrency Rate Updated Successfully :-)\n";

			_PrintCurrency(Currency);
		}

	}
};

