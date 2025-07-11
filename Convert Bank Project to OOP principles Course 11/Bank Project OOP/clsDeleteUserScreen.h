#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
class clsDeleteUserScreen : protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card : ";
		cout << "\n___________________________";
		cout << "\nUser  Name       :" << User.UserName;
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
	static void ShowDeleteUserScreen()
	{

		_DrawScreenHeader("\t Delete User Screen");

		string UserName = "";

		cout << "Please Enter User Name ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User Name isn't found , Enter another one please ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);

		_PrintUser(User1);

		cout << "\nAre you sure you want to delete this User y/n?  ";

		char Answer = 'Y';
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (User1.Delete())
			{
				cout << "\nUser Deleted successfully :-)\n";
				_PrintUser(User1);
			}
			else
			{
				cout << "\nError User wasn't deleted\n";
			}
		}

	}
};

