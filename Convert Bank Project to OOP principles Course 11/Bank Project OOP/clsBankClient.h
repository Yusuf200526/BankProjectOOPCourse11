#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"clsPerson.h"
#include"C:/Users/YUSUF/source/repos/Libraries/clsString.h"
using namespace std;
class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	bool _MarkForDelete = false;

	double _AccountBalance;

	static clsBankClient _ConvertLineToClientObject(string Line,string Seperater= "#//#")
	{
		vector <string> vClientData = clsString::Split(Line, Seperater);

		return clsBankClient(clsBankClient::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
			vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}


	static vector <clsBankClient>  _LoadClientsDataFromFile()
	{
		fstream MyFile;

		
		vector <clsBankClient> _vClients;

		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				if (Line != "")
				{
					clsBankClient Client = _ConvertLineToClientObject(Line);
					_vClients.push_back(Client);
				}
			}
			MyFile.close();
		}
		return _vClients;
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.PhoneNumber + Seperator;
		stClientRecord += Client.AccountNumber + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}

	static void _SaveClientsDataToFile(const vector<clsBankClient> &vClient)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (const clsBankClient& C : vClient)
			{
				if (C._MarkForDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(C);

					if (DataLine != "")
					{
						MyFile << DataLine << endl;
					}
				}
			}
			MyFile.close();
		}
	}


    void _Update()
	{
		vector<clsBankClient> _vClients;

		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);

	}

	static void _AddDataLineToFile(string stClient)
	{
		fstream MyFile;

		MyFile.open("Clients.txt", ios::app);

		if (MyFile.is_open())
		{
			if (stClient != "")
			{
				MyFile << stClient << endl;
			}
			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}


public:

	clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string PhoneNumber, string AccountNumber
		, string PinCode, double AccountBalance) : clsPerson(FirstName,LastName,Email,PhoneNumber)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(clsBankClient::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	
	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	__declspec(property(get = GetAccountNumber))string AccountNumber;

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))double AccountBalance;

	void SetMarkForDelete(bool MarkForDelete)
	{
		_MarkForDelete = MarkForDelete;
	}

	bool GetMarkForDelete()
	{
		return _MarkForDelete;
	}

	__declspec(property(get = GetMarkForDelete, put = SetMarkForDelete))bool MarkForDelete;

	
	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				
					if (Client.AccountNumber == AccountNumber)
					{
						MyFile.close();
						return Client;
					}
					vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);

				if (Client.AccountNumber == AccountNumber && Client.PinCode==PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	
	bool Delete()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C._MarkForDelete = true;
				break;
			}
		}

		_SaveClientsDataToFile(vClients);

		*this = _GetEmptyClientObject();

		return true;

	}




	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);

		return (!Client.IsEmpty());
	}


	enum enSaveResult { svFailedEmptyObject = 1, svSucceeded = 2,svFailedAccountNumberExists };

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResult::svFailedEmptyObject;
			}
		}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResult::svSucceeded;
		}
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(AccountNumber))
			{
				return enSaveResult::svFailedAccountNumberExists;
			}
			else
			{
				_AddNew();

				_Mode = clsBankClient::UpdateMode;

				return enSaveResult::svSucceeded;
			}
		}
	    }
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient> vClients = _LoadClientsDataFromFile();

		double TotalBalances = 0;

		for (clsBankClient& C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}

		return TotalBalances;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		else
		{
			AccountBalance -= Amount;
			Save();
		}
		return true;
	}

};

