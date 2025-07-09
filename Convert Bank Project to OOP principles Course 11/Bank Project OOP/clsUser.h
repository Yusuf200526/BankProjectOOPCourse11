#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"clsPerson.h"
#include"C:/Users/YUSUF/source/repos/Libraries/clsString.h"
#include"C:/Users/YUSUF/source/repos/Libraries/clsDate.h"
using namespace std;
class clsUser: public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permessions;

	bool _MarkForDelete = false;

	static clsUser _ConvertLineToUserObject(string Line, string Seperater = "#//#")
	{
		vector <string> vUserData = clsString::Split(Line, Seperater);

		return clsUser(clsUser::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3]
			, vUserData[4], vUserData[5], stoi(vUserData[6]));
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}


	static vector <clsUser>  _LoadUsersDataFromFile()
	{
		fstream MyFile;


		vector <clsUser> _vUser;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				if (Line != "")
				{
					clsUser Client = _ConvertLineToUserObject(Line);
					_vUser.push_back(Client);
				}
			}
			MyFile.close();
		}
		return _vUser;
	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string stUserRecord = "";
		stUserRecord += User.FirstName + Seperator;
		stUserRecord += User.LastName + Seperator;
		stUserRecord += User.Email + Seperator;
		stUserRecord += User.PhoneNumber + Seperator;
		stUserRecord += User.UserName + Seperator;
		stUserRecord += User.Password + Seperator;
		stUserRecord += to_string(User.Permissions);

		return stUserRecord;
	}

	static void _AddDataLineToFile(string stUser)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::app);

		if (MyFile.is_open())
		{
			if (stUser != "")
			{
				MyFile << stUser << endl;
			}
			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	static void _SaveUsersDataToFile(const vector<clsUser>& vUser)
	{
		fstream MyFile;

		MyFile.open("Users.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for (const clsUser& U : vUser)
			{
				if (U._MarkForDelete == false)
				{
					DataLine = _ConvertUserObjectToLine(U);

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
		vector<clsUser> _vUser;

		_vUser = _LoadUsersDataFromFile();

		for (clsUser& U : _vUser)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}
		}

		_SaveUsersDataToFile(_vUser);

	}

    string _PrepareLogInRecord(string Seperator="#//#")
	{
		string LoginRecord = "";
		LoginRecord = clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += UserName + Seperator;
		LoginRecord += Password + Seperator;
		LoginRecord += to_string(Permissions);
		return LoginRecord;
	}

	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLineToLoginRegisterRecord(string Line,string Seperator="#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;

		vector<string> vLoginRegisterDataLine = clsString::Split(Line, Seperator);

		LoginRegisterRecord.DateTime = vLoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = vLoginRegisterDataLine[1];
		LoginRegisterRecord.Password = vLoginRegisterDataLine[2];
		LoginRegisterRecord.Permissions = stoi(vLoginRegisterDataLine[3]);

		return LoginRegisterRecord;

	}

public:

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64,
		pLoginRegister = 128
	};

	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};


	clsUser(enMode Mode, string FirstName, string LastName,
		string Email, string PhoneNumber, string UserName, string Password,
		int Permessions) :
		clsPerson(FirstName, LastName, Email, PhoneNumber)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permessions = Permessions;
	}


	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	bool GetMarkForDelete()
	{
		return _MarkForDelete;
	}

	__declspec(property(get = GetMarkForDelete)) bool MarkForDelete;

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	string GetUserName()
	{
		return _UserName;
	}

	__declspec(property(get = GetUserName,put=SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_Permessions = Permissions;
	}

	int GetPermissions()
	{
		return _Permessions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;


	static clsUser Find(string UserName)
	{
		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{
		vector <clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);

		return (!User.IsEmpty());
	}

	enum enSaveResult { svFailedEmptyObject = 1, svSucceeded = 2, svFailedAccountNumberExists };

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
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResult::svFailedAccountNumberExists;
			}
			else
			{
				_AddNew();

				_Mode = clsUser::UpdateMode;

				return enSaveResult::svSucceeded;
			}
		}
		}
	}

	bool Delete()
	{
		vector <clsUser> vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.UserName == UserName)
			{
				U._MarkForDelete = true;
				break;
			}
		}

		_SaveUsersDataToFile(vUsers);

		*this = _GetEmptyUserObject();

		return true;

	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(clsUser::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermissions(enPermissions Permissions)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((this->Permissions & Permissions) == Permissions)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void RegisterLogIn(string Seperator="#//#")
	{
		string stDataLine = _PrepareLogInRecord();

		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}

	static vector<stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector<stLoginRegisterRecord> vLoginRegisterRecord;

		fstream MyFile;

		MyFile.open("LoginRegister.txt", ios::in);//read mode

		if (MyFile.is_open())
		{
			string Line;

			stLoginRegisterRecord LoginRegisterRecord;

			while (getline(MyFile, Line))
			{
				LoginRegisterRecord = _ConvertLineToLoginRegisterRecord(Line);
				vLoginRegisterRecord.push_back(LoginRegisterRecord);
			}
			MyFile.close();
		}
		return vLoginRegisterRecord;
	}
};

