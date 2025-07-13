#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsMainScreen.h"
#include"C:\Users\YUSUF\My Repos\LIbraries\clsInputValidate.h"
#include"Global.h"
#include <thread>
#include <chrono>
using namespace std;
class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		string UserName;
		string Password;

		bool LoginFaild = false;
		short FaildLoginCount = 0;

		do
		{
			

			if (LoginFaild)
			{
				FaildLoginCount++;

				cout << "\nInvalid UserName/Password!\n";
				cout << "You have " << (3 - FaildLoginCount) << " Trial(s) to login.\n\n";
				_SetLoginFailedColor();
			}

			if (FaildLoginCount == 3)
			{
				cout << "\n\nYou are locked after 3 faild trials\n\n";
				return false;
			}

			cout << "Enter User Name: ";
			UserName = clsInputValidate::ReadString();

			cout << "Enter Password: ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();


		} while (LoginFaild);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;
	}

	static void _SetLoginFailedColor()
	{
		for (short i = 1; i <= 3; i++)
		{
			system("color 4F");
			std::this_thread::sleep_for(std::chrono::milliseconds(200)); 
			system("color 0F");
			std::this_thread::sleep_for(std::chrono::milliseconds(200));  
		}
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}
};
   
   