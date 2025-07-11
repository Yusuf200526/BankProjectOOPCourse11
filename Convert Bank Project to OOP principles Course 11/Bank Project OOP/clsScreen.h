#pragma once
#include<iostream>
#include"clsUser.h"
#include"Global.h"
#include"c:\Users\YUSUF\source\repos\Libraries\clsDate.h"
#include <thread>
#include <chrono>
using namespace std;
class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t____________________________________";
		cout <<"\n\n\t\t\t\t\t"<< Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t" << SubTitle;
		}
		cout << "\n\t\t\t\t\t____________________________________\n\n";
		cout << "\t\t\t\t\tUser: " << CurrentUser.UserName << "\n";
		cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";
	}

	static bool _CheckAccessRights(clsUser::enPermissions Permissions)
	{
		if (!CurrentUser.CheckAccessPermissions(Permissions))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t______________________________________\n\n";
			_SetAccessDeniedColor();
			return false;
		}
		else
		{
			return true;
		}
	}

	static void _SetAccessDeniedColor()
	{
		for (short i = 1; i <= 3; i++)
		{
			system("color 4F");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
			system("color 0F");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
	}
    

};

