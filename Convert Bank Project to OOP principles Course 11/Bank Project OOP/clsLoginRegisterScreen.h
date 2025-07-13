#pragma once
#include<iostream>
#include<vector>
#include"clsScreen.h"
#include"clsUser.h"
#include"C:\Users\YUSUF\My Repos\LIbraries\clsInputValidate.h"
class clsLoginRegisterScreen : protected clsScreen
{
private:
	static void _PrintRegisteredUserRecordLine(clsUser::stLoginRegisterRecord Record)
	{
		cout << setw(8) << left << "" << "| " << left << setw(30) << Record.DateTime;
		cout << "| " << left << setw(20) << Record.UserName;
		cout << "| " << left << setw(22) << Record.Password;
		cout << "| " << left << setw(20) << Record.Permissions;
	}

public:

	static void ShowLoginRegisterScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}

		vector<clsUser::stLoginRegisterRecord>LoginRegisterRecord = clsUser::GetLoginRegisterList();

		string Title = "    Login Register List Screen";
		string SubTitle = "\t   (" + to_string(LoginRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n\n";
		cout << setw(8) << left << "" << "| " << left << setw(30) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(22) << "Password";
		cout << "| " << left << setw(20) << "Permissions\n\n";
		cout <<""<< " _____________________________________________________________________" <<
			"_____________________________\n\n\n";

		if (LoginRegisterRecord.size() == 0)
		{
			cout << "\t\t\t\t\n No Registerd Users Available in the System! ";
		}
		else
		{
			for (clsUser::stLoginRegisterRecord &Record : LoginRegisterRecord)
			{
				_PrintRegisteredUserRecordLine(Record);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n\n";
	}
};

