
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
using namespace std;

void ReadClientInfo(clsBankClient& Client) {
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
    Client.Balance = clsInputValidate::ReadDblNumber();
}

void UpdateClient() {


    string AccountNumber = "";
    cout << "Please Enter Account to Clinet : ";
    AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(AccountNumber)) {
        cout << "the AccountNubmer is not found, Choose anther one: ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();
    cout << "\n___ Update Clietn ___\n";
    cout << "_____________________\n";
    ReadClientInfo(Client);
    cout << "_____________________\n";


}

 

int main()
{
    
    system("pause>0");
    return 0;
}

