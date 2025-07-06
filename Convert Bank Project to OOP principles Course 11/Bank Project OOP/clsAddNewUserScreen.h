#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
class clsAddNewUserScreen : protected clsScreen
{
private:

	static void _ReadUserInfo(clsUser& User1)
	{
		cout << "\nEnter First Name: ";
		User1.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name: ";
		User1.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User1.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone Number: ";
		User1.PhoneNumber = clsInputValidate::ReadString();

		cout << "\nEnter Password : ";
		User1.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions to Set: ";
		User1.Permissions = _ReadPermissionsToSet();
	}

	static int _ReadPermissionsToSet()
	{
		char Answer = 'n';
		int Permissions = 0;

		cout << "\n\nDo you want to give full access? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			return -1;
		}

		cout << "Do you want to give access to :\n\n";

		cout << "Show Client List ? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << " Add new Client ? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "Delete Client ?  y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "Update Client ?  y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClient;
		}

		cout << "Find Client ?  y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "Transactions Menue ?  y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}

		cout << "Manage Users Menue ?  y/n ? ";
		cin >> Answer;


		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		return Permissions;
	}

	static void _PrintClient(clsUser User)
	{
		cout << "\nClient Card : ";
		cout << "\n___________________________";
		cout << "\nAcc.Number       :" << User.UserName;
		cout << "\nFirst Name       :" << User.FirstName;
		cout << "\nLast Name        :" << User.LastName;
		cout << "\nFull Name        :" << User.FullName;
		cout << "\nEmail            :" << User.Email;
		cout << "\nPhone            :" << User.PhoneNumber;
		cout << "\nPassword         :" << User.Password;
		cout << "\nBalance          :" << User.Permissions;
		cout << "\n___________________________\n";
	}

public:

	static void ShowAddUserClient()
	{
		_DrawScreenHeader("\tAdd New User Screen");

		string UserName = "";

		cout << "Please Enter User Name: ";
		UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name Is already used , choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResult SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::svSucceeded:
		{
			cout << "\nUser Added Successfully :-) ";
			_PrintClient(NewUser);
		}
		break;
		case clsUser::svFailedEmptyObject:
		{
			cout << "\nError User wasn't saved  ,because it's Empty ";
		}
		break;
		case clsUser::enSaveResult::svFailedAccountNumberExists:
		{
			cout << "\nError User wasn't saved , because it is already exists ";
		}
		}
	}
};

