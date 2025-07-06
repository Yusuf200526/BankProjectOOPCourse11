#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>
class clsListUserScreen : protected clsScreen
{

private:

	static void _PrintUserRecordLine(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << left << setw(15) << User.UserName;
		cout << "| " << left << setw(20) << User.FullName;
		cout << "| " << left << setw(12) << User.PhoneNumber;
		cout << "| " << left << setw(20) << User.Email;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(12) << User.Permissions;
	}



public:

	static void ShowUsersList()
	{
		vector<clsUser> vUsers = clsUser::GetUsersList();

		string Title = "\t Users List Screen";
		string SubTitle = "\t   (" + to_string(vUsers.size()) + ") User(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n\n";
		cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions" << "\n\n";
		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n\n";

		if (vUsers.size() == 0)
		{
			cout << "\t\t\t\t\n No Users Available in the System! ";
		}
		else
			for (clsUser& U : vUsers)
			{
				_PrintUserRecordLine(U);
				cout << endl;
			}

		cout << setw(8) << left << "" << "_____________________________________________________________________" <<
			"_____________________________\n\n\n";
	}
};

