#pragma once
#include<iostream>
using namespace std;
class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string  _PhoneNumber;
public:

	clsPerson(string FirstName, string LastName, string Email, string PhoneNumber)
	{
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_PhoneNumber = PhoneNumber;
	}

	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}

	__declspec(property(get = GetLastName, put = SetLastName))string LastName;


	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	__declspec(property(get = GetEmail, put = SetEmail))string Email;

	void SetPhoneNumber(string PhoneNumber)
	{
		_PhoneNumber = PhoneNumber;
	}

	string GetPhoneNumber()
	{
		return _PhoneNumber;
	}

	__declspec(property(get = GetPhoneNumber, put = SetPhoneNumber))string PhoneNumber;

	string GetFullName()
	{
		return _FirstName + " " + _LastName;
	}

	__declspec(property(get = GetFullName))string FullName;

};

