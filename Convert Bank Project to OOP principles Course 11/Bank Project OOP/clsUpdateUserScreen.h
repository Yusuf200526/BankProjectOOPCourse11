#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"C:\Users\YUSUF\My Repos\LIbraries\clsInputValidate.h"
class clsUpdateUserScreen: clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card : ";
		cout << "\n___________________________";
		cout << "\nUser Name        :" << User.UserName;
		cout << "\nFirst Name       :" << User.FirstName;
		cout << "\nLast Name        :" << User.LastName;
		cout << "\nFull Name        :" << User.FullName;
		cout << "\nEmail            :" << User.Email;
		cout << "\nPhone            :" << User.PhoneNumber;
		cout << "\nPassword         :" << User.Password;
		cout << "\nBalance          :" << User.Permissions;
		cout << "\n___________________________\n";
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

		cout << "\nShow Client List ? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd new Client ? y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client ?  y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client ?  y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClient;
		}

		cout << "\nFind Client ?  y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions Menue ?  y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}

		cout << "\nManage Users Menue ?  y/n ? ";
		cin >> Answer;


		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nShow Login Register  ?  y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Permissions += clsUser::enPermissions::pLoginRegister;
		}

		return Permissions;
	}


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

		cout << "\nEnter Password: ";
		User1.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions: ";
		User1.Permissions = _ReadPermissionsToSet();
	}


public:

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\tUpdate User Screen");

		string UserName = "";

		cout << "\nPlease Enter User Name: ";

		UserName = clsInputValidate::ReadString();

		while (!(clsUser::IsUserExist(UserName)))
		{
			cout << "Uesr Name is not found, choose another one : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser Client1 = clsUser::Find(UserName);
		_PrintUser(Client1);

		char Answer = 'n';
		cout << "\nAre you sure you want to update this User y/n ";
		cin >> Answer;

		if (toupper(Answer) == 'N')
		{
			return;
		}

		cout << "\n\n Update User Info: ";
		cout << "\n_________________________\n";

		_ReadUserInfo(Client1);

		clsUser::enSaveResult SaveResult = Client1.Save();

		switch (SaveResult)
		{
		case clsUser::svSucceeded:
		{
			cout << "\nUser Updated Successfully :-) ";
			_PrintUser(Client1);
		}
		break;
		case clsUser::svFailedEmptyObject:
		{
			cout << "\Error User wasn't saved  ,because it's Empty ";
		}
		break;
		}
	}

};

