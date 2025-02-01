#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
using namespace std;
class clsBankClient : public clsPerson
{
private :
	enum enMode {EmptyMode=0,UpdateMode=1};
	enMode _Mode ;
	string _AccountNumber = "";
	string _PinCode = "";
	double _Balance = -1;

	static clsBankClient _ConvertLineToClientObject(string Line,string Separator = "#//#") {
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Separator);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}
	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "",0);
	}
	void _Update() {

	}


public :
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, double Balance)
		:clsPerson(FirstName,LastName,Email,Phone)
	{
		_Mode = Mode;
		this->_AccountNumber = AccountNumber;
		this->_PinCode = PinCode;
		this->_Balance=Balance;
	}
	string GetAccountNumber() {
		return _AccountNumber;
	}
	// PinCode set and Get
	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	// the Balance set and get
	void SetBalance(double Balance) {
		_Balance = Balance;
	}
	double GetBalance() {
		return _Balance;
	}
	__declspec(property(get = GetBalance, put = SetBalance))double Balance;
	
	 bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string  FullName() {
		return FirstName + " " + LastName;
	}

	void Print() {
		cout << "\n__________________________________";
		cout << "\nFirstName        :" << FirstName;
		cout << "\nLastName         :" << LastName;
		cout << "\nFullName         :" << FullName();
		cout << "\nEmail            :" << Email;
		cout << "\nPhone            :" << Phone;
		cout << "\nGetAccountNumber :" << GetAccountNumber();
		cout << "\nPinCode          :" << PinCode;
		cout << "\nBalance          :" << Balance;
		cout << "\n__________________________________";
	}

	static clsBankClient Find(string AccountNumber) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);// read Mode
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber) {
					MyFile.close();
					return Client;
				}
				
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client._AccountNumber == AccountNumber && Client.PinCode == PinCode) {
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject =0, svSecceded=1};

	enSaveResults Save() {
		switch (_Mode) {
		case enMode::EmptyMode:
			return enSaveResults::svFaildEmptyObject;
			break;
		case enMode::UpdateMode:
			_Update();
			return enSaveResults::svSecceded;
			break;
		}
	}

};

