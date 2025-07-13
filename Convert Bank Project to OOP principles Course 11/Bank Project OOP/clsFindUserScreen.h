#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"C:\Users\YUSUF\source\repos\Libraries\clsInputValidate.h"
class clsFindUserScreen :protected clsScreen
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

public:

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\tFind User Screen");

		string UserName = "";

		cout << "Please Enter User Name  ";

		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is not found , Enter another one ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\n\nUser Found :-) ";
		}
		else
		{
			cout << "\nUser was not Found :-(\n";
		}


		_PrintUser(User);

	}

};

