#pragma once
#include<iostream>
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
	}
};

