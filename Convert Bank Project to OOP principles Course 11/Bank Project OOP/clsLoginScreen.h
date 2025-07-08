#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsMainScreen.h"
#include"C:\Users\YUSUF\source\repos\Libraries\clsInputValidate.h"
#include"Global.h"
#include <thread>
#include <chrono>
class clsLoginScreen : protected clsScreen
{
private:

	static void _Login()
	{
		string UserName;
		string Password;

		bool LoginFaild = false;

		do
		{
			if (LoginFaild)
			{
				cout << "\nInvalid UserName/Password!\n\n";
				_SetLoginFailedColor();
			}

			cout << "Enter User Name Please: ";
			UserName = clsInputValidate::ReadString();

			cout << "Enter Password Please: ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();


		} while (LoginFaild);

		clsMainScreen::ShowMainMenue();
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

	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		_Login();
	}
};

