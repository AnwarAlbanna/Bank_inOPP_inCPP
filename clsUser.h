#pragma once
#include <iostream>
#include <fstream>
#include "clsString.h"
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;
class clsUser : public clsPerson
{
private:
	enum enMode {
		EmptyMode = 0, UpdateMode = 1, AddNewMode = 2
	};
	enMode _Mode;
	string _UserName = "";
	string _Password = "";
	short  _Permeations = 0;

	bool _MarkedForDelete = false;

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string UserName, string Password, short Permeations) :clsPerson(FirstName, LastName, Email, Phone) {
		this->_UserName = UserName;
		this->_Password = Password;
		this->_Permeations = Permeations;
	}
	void SetUserName(string UserName) {
		this->_UserName = UserName;
	}
	string GetUserName() {
		return _UserName;
	}
	__declspec(property(get =GetUserName,put =SetUserName)) string UserName;
	void SetPassword(string Password) {
		this->_Password = Password;
	}
	string GetPassword() {
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;
	void SetPermeations(short Permeations) {
		this->_Permeations = Permeations;
	}
	short GetPermeations() {
		return _Permeations;
	}
	__declspec(property(get = GetPermeations, put = SetPermeations)) string Permeations;


};

