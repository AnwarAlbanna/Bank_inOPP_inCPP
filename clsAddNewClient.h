#pragma once
#include "clsBankClient.h"
#include "clsUtil.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iostream>
#include <iomanip>
using namespace std;
class clsAddNewClient :protected clsScreen
{
private:
   static void ReadClientInfo(clsBankClient& Client) {
        cout << "\nFirstName is :";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nLastName is :";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nPhone is :";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEmail is :";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nPinCode is :";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nAccount Balance is :";
        Client.AccountBalance = clsInputValidate::ReadDblNumber();
    }

public :

   static void ShowAddNewClientScreen() {
       system("cls");
       string Title = "\t  Add Client Screen ";
       _DrawScreenHeader(Title);

        string AccountNumber = "";
        cout << " Please Added AccountNumber ?";
        AccountNumber = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(AccountNumber)) {
            cout << "the AccountNumber is Alredy Use ,choose anther one :";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
        ReadClientInfo(NewClient);
        clsBankClient::enSaveResults SaveResult;
        SaveResult = NewClient.Save();
        switch (SaveResult) {
        case clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "the Client Added is Succeeded ";
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "the Client Can't Added try anther time Because AccountNumber is Exist. ";
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "the Client Can't Added try anther time Because EmptyObject. ";
            break;
        }
        }

    }





    
   
    void PrintListToTotalBalance(clsBankClient Client) {
        cout << "|" << left << setw(15) << Client.AccountNumber();
        cout << "|" << left << setw(30) << Client.FullName();
        cout << "|" << left << setw(15) << Client.AccountBalance;
    }

    void ShowTotalBalance() {
    
        vector<clsBankClient> vClient = clsBankClient::GetClientsList();
        cout << "\n-------------------------------------------------------------------------------------\n";
        cout << "\n\t\t\t\Total Balance List (" << vClient.size() << ") Client(s)\n";
        cout << "-------------------------------------------------------------------------------------\n";
        cout << "|" << left << setw(15) << "Account Number";
        cout << "|" << left << setw(30) << " Full Name ";
        cout << "|" << left << setw(15) << "Account Balance";
        cout << "\n-------------------------------------------------------------------------------------\n";
        if (vClient.size() == 0)
        {
            cout << "The Data is Not avalible Sorry!";
        }
        else {

            for (clsBankClient& C : vClient) {
                PrintListToTotalBalance(C);
                cout << endl;
            }
        }


        cout << "\n-------------------------------------------------------------------------------------\n";
        double TotalBalance = clsBankClient::GetTotalBalances();
        cout << "\n\t\t\t\tTotal Balance is (" << TotalBalance << ")" << endl;
        //cout << "\n\t\t" << clsUtil::NumberToText(TotalBalance) << endl;
    }
    
};

