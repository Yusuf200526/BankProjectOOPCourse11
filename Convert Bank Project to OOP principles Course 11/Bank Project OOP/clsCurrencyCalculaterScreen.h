#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"C:/Users/YUSUF/source/repos/Libraries/clsInputValidate.h"
class clsCurrencyCalculaterScreen : protected clsScreen
{

private:

	static void _PrintCurrencyCard(clsCurrency Currency,string Title="Currency Card")
	{
		cout << "\n" << Title << endl;
		cout << "\n___________________________";
		cout << "\nCountry          :" << Currency.Country;
		cout << "\nCode             :" << Currency.CurrencyCode;
		cout << "\nName             :" << Currency.CurrencyName;
		cout << "\nRate(1$)         :" << Currency.Rate;
		cout << "\n___________________________\n\n";
	}

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode;
		cout << Message;
		

		CurrencyCode = clsInputValidate::ReadString();

		cout << endl;

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found , choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}

	static void _PrintCalculationResult(double Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		_PrintCurrencyCard(CurrencyFrom, "Convert From:");

		double AmountInUSD = CurrencyFrom.ConvertToUsd(Amount);

		cout << Amount << " " << CurrencyFrom.CurrencyCode
			<< " = " << AmountInUSD << " USD\n";

		if (CurrencyTo.CurrencyCode == "USD")
		{
			return;
		}

		cout << "\nConverting From USD to:\n";

		_PrintCurrencyCard(CurrencyTo, "To:");

		double AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);

		cout << Amount << " " << CurrencyFrom.CurrencyCode
			<< " = " << AmountInCurrencyTo << " " << CurrencyTo.CurrencyCode;
	}


public:

	static void ShowCurrencyCalculaterScreen()
	{
		char Continue = 'y';

		while (toupper(Continue) == 'Y')
		{
			system("cls");

			_DrawScreenHeader("\tUpdate Currency Screen");

			clsCurrency CurrencyFrom = _GetCurrency("Please Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("Please Enter Currency2 Code: ");

			cout << "Enter Amount To Exchange ";
			double Amount = clsInputValidate::ReadPostiveDblNumber();

			_PrintCalculationResult(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calcualtion? y/n? ";
			cin >> Continue;
		}
	}
};

