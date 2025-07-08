#include<iostream>
#include"clsLoginScreen.h"
using namespace std;
int main()
{
	
	/*clsMainScreen::ShowMainMenue();*/

	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
			break;
	}


	return 0;
} 