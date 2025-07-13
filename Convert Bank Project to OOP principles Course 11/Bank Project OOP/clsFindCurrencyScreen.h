#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"C:\Users\YUSUF\My Repos\LIbraries\clsInputValidate.h"
using namespace std;
class clsFindCurrencyScreen : protected clsScreen
{

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\n\nCurrency Card : ";
		cout << "\n___________________________";
		cout << "\nCountry          :" <<Currency.Country;
		cout << "\nCode             :" << Currency.CurrencyCode;
		cout << "\nName             :" << Currency.CurrencyName;
		cout << "\nRate(1$)         :" << Currency.Rate;
		cout << "\n___________________________\n";
	}

	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency is not Found :-(\n";
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country ? ";
		short Answer = 1;

		Answer = clsInputValidate::ReadNumberBetween<int>(1, 2);

		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease Enter Currency Code: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResult(Currency);
		}
		else
		{
			string Country;
			cout << "\nPlease Enter Country Name: ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResult(Currency);
		}
		
	}
};

