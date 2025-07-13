#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"C:\Users\YUSUF\source\repos\Libraries\clsString.h"
using namespace std;
class clsCurrency
{
private:
	enum enMode { EmptyMode = 1, UpdateMode = 2 };
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	double _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsString::Split(Line, Seperator);

		return  clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
			stod(vCurrencyData[3]));

	}



	static vector <clsCurrency> _LoadCurrencyDataFromFile()
	{
		fstream MyFile;


		vector <clsCurrency> _vCurrencies;

		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				if (Line != "")
				{
					clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
					_vCurrencies.push_back(Currency);
				}
			}
			MyFile.close();
		}
		return _vCurrencies;
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency,string Seperator="#//#")
	{
		string stCurrencyDataLine;

		stCurrencyDataLine = Currency.Country + Seperator;
		stCurrencyDataLine += Currency.CurrencyCode + Seperator;
		stCurrencyDataLine += Currency.CurrencyName + Seperator;
		stCurrencyDataLine += to_string(Currency.Rate);

		return stCurrencyDataLine;
	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency> _vCurrencies)
	{
		fstream MyFile;

		MyFile.open("Currencies.txt", ios::out); //overwrite

		if (MyFile.is_open())
		{
			string DataLine;
			for (clsCurrency& Currency : _vCurrencies)
			{
				DataLine = _ConvertCurrencyObjectToLine(Currency);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsCurrency> _vCurrencies;
		_vCurrencies = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : _vCurrencies)
		{
			if (C.CurrencyCode == CurrencyCode)
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(_vCurrencies);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:


	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, double Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}


	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string GetCountry() // Read only property.
	{
		return _Country;
	}

	string GetCurrencyCode() // Read only property.
	{
		return _CurrencyCode;
	}

	string GetCurrencyName() // Read only propery.
	{
		return _CurrencyName;
	}

	double GetRate() // Read and write property , but write trough UpdateRate Function.
	{
		return _Rate;
	}

	void UpdateRate(double Rate)
	{
		_Rate = Rate;
		_Update();
	}

	__declspec(property(get = GetCountry)) string Country;
	__declspec(property(get = GetCurrencyCode)) string CurrencyCode;
	__declspec(property(get = GetCurrencyName)) string CurrencyName;  
	__declspec(property(get = GetRate, put = UpdateRate)) double Rate;

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);// Active 

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in); // Read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line); 

				if (Currency.CurrencyCode == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string Country)
	{
		fstream MyFile;
		Country = clsString::UpperAllString(Country);

		MyFile.open("Currencies.txt", ios::in);//read mode.

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if ((clsString::UpperAllString(Currency.Country)) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return(!Currency.IsEmpty());
	}


	static vector<clsCurrency> GetCurrencyList()
	{
		return _LoadCurrencyDataFromFile();
	}

	double ConvertToUsd(double Amount)
	{
		return (double)(Amount / Rate);
	}

	double ConvertToOtherCurrency(double Amount, clsCurrency Currency2)
	{
		double AmountInUSD = ConvertToUsd(Amount);

		if (Currency2.CurrencyCode == "USD")
		{
			return AmountInUSD;
		}

		return (double)(AmountInUSD * Currency2.Rate);
	}

};

