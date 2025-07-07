#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsListUserScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"
#include"C:\Users\YUSUF\source\repos\Libraries\clsInputValidate.h"
class clsManageUsersScreen : protected clsScreen
{
private:// Abstracted // Built skeleton of the manage users menue screen useing stabs
	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3
		, eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};

	static short _ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what you wants to do? [1 to 6]? ";
		return clsInputValidate::ReadIntNumberBetween(1, 6, "Choose from 1 to 6 only ");
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << setw(8) << left << "" << "\n\npress any key to go back to Manage Users Menue...\n";
		system("pause>0");
		ShowManageUsersMenue();
	}

	// stabs
	static void _ShowListUsersScreen()
	{
		/*cout << "List User Screen will be here soon...\n";*/
		clsListUserScreen::ShowUsersList();
	}

	static void _AddNewUserScreen()
	{
		//cout << "Add New user screen will be here soon...\n";
		clsAddNewUserScreen::ShowAddUserClient();
	}

	static void _DeleteUserScreen()
	{
		//cout << "Delete User Screen will be here soon...\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _UpdateUserScreen()
	{
		//cout << "Update User Screen will be here soon...\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _FindUserScreen()
	{
		//cout << "Find User Screen will be here soon...\n";
		clsFindUserScreen::ShowFindUserScreen();
	}


	static void _PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
	{
		switch (ManageUsersMenueOption)
		{
		case enManageUsersMenueOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eAddNewUser:
		{
			system("cls");
			_AddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eDeleteUser:
		{
			system("cls");
			_DeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eUpdateUser:
		{
			system("cls");
			_UpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eFindUser:
		{
			system("cls");
			_FindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eMainMenue:
		{
			//do nothing in here
		}
		}
	}

public:

	static void ShowManageUsersMenue()
	{
		system("cls");

		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue \n";
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "  [1] List Users. \n";
		cout << setw(37) << left << "" << "  [2] Add New User. \n";
		cout << setw(37) << left << "" << "  [3] Delete User. \n";
		cout << setw(37) << left << "" << "  [4] Update User. \n";
		cout << setw(37) << left << "" << "  [5] Find User. \n";
		cout << setw(37) << left << "" << "  [6] Main Menue. \n";
		cout << setw(37) << left << "" << "=========================================\n";

		_PerformManageUsersMenueOption(enManageUsersMenueOptions(_ReadManageUsersMenueOption()));
	}


};

